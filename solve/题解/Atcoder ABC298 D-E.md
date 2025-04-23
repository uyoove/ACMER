# Atcoder ABC298 D-F

## D - Writing a Numeral

### **链接:** 

[D - Writing a Numeral (atcoder.jp)](https://atcoder.jp/contests/abc298/tasks/abc298_d)

### **简要题意:**

- #### 问题陈述

  我们有一个字符串 $S$ 。初始值为 $S=$ `1`.  
  按以下格式依次处理 $Q$ 查询。
  
  - `1 x`：在 $S$ 的末尾添加一个数字 $x$ 。
  - `2`：删除 $S$ 开头的数字。
  - `3` : 以十进制形式打印 $S$ 所代表的数字，取模 $998244353$ 。

### **思路:**

- 我们直接用双端队列模拟题目中的操作
- 注意点是删除s开头的字符,这边的删除是取模意义下的,所以总结答案时候要加上模数再取模
- **两个取模的结果进行相减操作时（易知前面的数理论上应该大，但取模之后可能小于后面的数）此时应该加上MOD的倍数，再对相减结果进行取模，从而保证输出为正**

### 代码:

```c++
const int N = 200005;
ll powerMod(ll x, ll n, ll mod){ //快速幂
    ll ans = 1;
    while (n > 0){
        if  (n & 1)
            ans = (ans * x) % mod;
        x = (x * x) % mod;
        n >>= 1;
    }
    return ans;
}
void solve(){
    int q;
    cin >> q;
    int mod = 998244353;
    deque<int> dq;
    dq.push_back(1);
    int ans = 1;
    while(q--){
        int op;
        cin >> op;
        if(op==1){
            int x;
            cin >> x;
            dq.push_back(x);
            ans = (ans*10%mod + x)%mod;
        }else if(op==2){
            int sz = dq.size();
            ans=(ans - dq.front()*powerMod(10,sz - 1,mod)%mod +mod)%mod;
            dq.pop_front();
        }else{
            cout << ans <<endl;
        }
    }
}
```

## E - Unfair Sugoroku

### **链接:** 

[E - Unfair Sugoroku (atcoder.jp)](https://atcoder.jp/contests/abc298/tasks/abc298_e)

### **简要题意:**

- #### 问题陈述

  高桥从 $A$ 点开始，青木从 $B$ 点开始。他们将轮流掷骰子。 
  高桥的骰子显示 $1, 2, \ldots, P$ ，概率相同；青木的骰子显示 $1, 2, \ldots, Q$ ，概率相同。 
  当在 $x$ 点的棋手掷出骰子，结果显示 $i$ 时，他就会下到 $\min(x + i, N)$ 点。 
  最先到达点 $N$ 的棋手获胜。 
  求高桥先下的概率，模为 $998244353$ 。

### **思路:**

- 数据量很小,又是求概率所以一眼dp

- 设置 $dp[i][j][0/1] $ 表示:先手走到$i$这个地方,后手走到$j$ 这个地方,当前是先手走还是后手走的概率

- 用刷表法dp

- 最后统计a在n位置上的 b在其他合法位置的总概率累加和

- 注意开long long 笔者是define int long long的

### 代码:

```c++
int mod = 998244353;
int ksm(int x,int n){
    int res = 1;
    while(n){
        if(n&1) res = res*x%mod;
        x = x*x%mod;
        n>>=1;
    }
    return res;
}
int iv(int i){
    return ksm(i,mod - 2);
}
void solve(){
    int n,a,b,p,q;
    cin >> n >> a >> b >> p >> q;
    int dp[n + 1][n + 1][2]; //1先手,0后手
    memset(dp,0,sizeof dp);
    dp[a][b][1] = 1;
    for(int i = a;i< n;i++){
        for(int j = b;j < n;j++){
            for(int k = 0;k<=1;k++){
                if(k){
                    for(int t = 1;t<=p;t++){
                        dp[min(i+t,n)][j][0] = (dp[min(i+t,n)][j][0] + dp[i][j][1]*iv(p)%mod)%mod;
                    }
                }else{
                    for(int t = 1;t<=q;t++){
                        dp[i][min(j+t,n)][1] = (dp[i][min(j+t,n)][1] + dp[i][j][0]*iv(q)%mod)%mod;
                    }
                }
            }
        }
    }
    int ans = 0;
    for(int i = b;i<n;i++){
        ans = (ans + dp[n][i][0])%mod;
    }
    cout << ans <<endl;
}
```

## F - Rook Score

### **链接:** 

https://atcoder.jp/contests/abc298/tasks/abc298_f

### **简要题意:**

- #### 问题陈述
    我们有一个行数为 $10^9$ 列数为 $10^9$ 的网格。让 $(i,j)$ 表示从上往下数第 $i$ 行，从左往上数第 $j$ 列的正方形。
    对于 $i=1,2,\ldots,N$ ，正整数 $x_ i$ 写在 $(r_ i,c_ i)$ 上。其他 $10^{18}-N$ 个方格上写着 $0$ 。
    你选择一个方格 $(R,C)$ ，计算写在与 $(R,C)$ 共用一行或一列的 $2 \times 10^9 - 1$ 方格上的整数之和 $S$ 。
    求 $S$ 的最大可能值。
### **思路:**
- 首先我们约定$val(r/c/x)$ 表示 这个行或者列的数值累加和,或者单点的值
- 考虑贪心,我们最后可能会选一个在给定点集里面的点,也可能选择不在点集里面的点
- 我们先对行累加和值和列累加和值最大分别排序
- 那么 我们贪心考虑$max(val(r)) + max(val(c))$ 即行累加和最大和列累加和最大 r和c交点的那个位置
- 设这个位置为x,如果 $val(x) = 0$,那么直接选择此点就是答案
- 如果该位置$val(x) \neq 0$,因为容斥原理,我们必须要减掉$val(x)$
- 那么此时的值不一定是最大,还需要继续遍历,直到找到一个不在点集中的点,即$val(x)=0$退出遍历内循环(注意不是直接输出答案)
- 为什么碰到$val(x)=0$可以直接退出 因为我们循环是二重暴力枚举r与c,因为排过序,我们第一维度固定了r, 设当前位置为 $(r_i,c_i)$,后面位置是$(r_i,c_i)$ 那么 $val(r_i) + val(c_i) - 0 >= val(r_i) + val(c_j)-val(x)$
如此,后面肯定小于等于前面,所以后面没有意义,此操作也大大保证了时间复杂度,控制在$O(nlogn)$
因为只有点集中的点是遍历的,非点集会反复break,两重循环看似 $O(n^2)$,因为有了这个break操作,时间大幅减少到$O(n)$,另外的log是map的操作时间
- 为什么碰到0不直接输出答案?
- 因为设当前碰到0的位置为$(r_i,c_i)$,后面位置为$(r_j,c_j)$,我们虽然可以保证$val(r_i) >=val(r_j)$,但是保证不了$val(c_i) >=val(c_j)$ 所以两个val值无法比较谁大谁小,还是需要遍历的,证毕

### 代码:

```c++
const int N = 200005;
map<int,int> C;
map<int,int> R;
map<pair<int,int>,int> sq;
void solve(){
    int q;
    cin >> q;
    while(q--){
        int r,c,x;
        cin >> r >> c >> x;
        sq[{r,c}] = x;
        C[c]+=x;
        R[r]+=x;
    }
    int ma = 0;
    vector<pair<int,int>> r1;
    vector<pair<int,int>> c1;
    for(auto [k,v]:R){
        r1.push_back({v,k});
    }
    for(auto [k,v]:C){
        c1.push_back({v,k});
    }
    sort(r1.rbegin(),r1.rend());
    sort(c1.rbegin(),c1.rend());
    int ans = 0;
    //遍历点集,找点集最大值
    for(auto p:sq){
        int r = p.first.first,c = p.first.second;
        int val = p.second;
        ans=max(R[r]+C[c]-val,ans);
    }
    //遍历非点集
    for(auto [k1,v1]:r1){
        for(auto [k2,v2]:c1){
            if(sq.find({v1,v2}) == sq.end()){
                ans = max(ans,k1+k2);
                break;
            }
        }
    }
    cout <<ans <<endl;
}
```


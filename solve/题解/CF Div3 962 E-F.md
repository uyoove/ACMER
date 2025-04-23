# CF Div3 962补题 E-F

## E. Decode

### **链接:** 

[Problem - E - Codeforces](https://codeforces.com/contest/1996/problem/E)

### **简要题意:**

给你一个长度为 $n$ 的二进制字符串$s$ 。对于每一对整数$(l, r)$ $(1 \leq l \leq r \leq n)$ 中，数出 $(x, y)$ $(l \leq x \leq y \leq r)$ 这样的整数对的个数。 $(l \leq x \leq y \leq r)$ 中的 $\mathtt{0}$ 的数量等于子串  $s_xs_{x+1}...s_y$.中的 $\mathtt{1}$ 的数量。

输出所有可能的 $(l, r)$ modulo $10^9+7$ 的计数之和。

### **思路:**

- 很明显这样的题目算区间贡献和前缀和有关
- 我们定义子串左边位置为x  子串右边位置设为y
- 我们发现一个01数量相同的子串 对于整个数组的贡献是 $x * (n-y+1)$
- 算01相同数量我们可以用前缀和 + map实现
- 每次将x + 1的贡献累加到map中
- 计算答案 ans = mp[pre[i]] * (n-i+1)

### 代码:

```c++
void solve(){
    string s;
    cin >> s;
    int n = s.size();
    s = " " +s;
    map<int,int> h;
    int pre = 0;
    int ans = 0;
    h[0] = 1;
    for(int i = 1;i<=n;i++){
        if(s[i]=='0') pre--;
        else pre++;
        ans+=h[pre]*(n-i+1)%P;
        ans%=P;
        h[pre]+=i+1;
        h[pre]%P;
    }
    cout << ans <<endl;

}
```



## F. Bomb

### **链接:** 

[Problem - F - Codeforces](https://codeforces.com/contest/1996/problem/F)

### **简要题意:**

- 给你两个数组 $a[n]$ 和  $ b[n]$   $(1<= n <= 2e5)$
- 你可以执行最多k次下列操作 $(1<= k <= 1e9)$
- 选择 $a[i]$ 将 $a[i]$ 加入到你的分数中 然后使$a[i] = max(0,a[i] - b[i])$ 
- 求最大分数

### **思路:**

- 首先一个O(k)的思路是 将所有a[i]放入优先队列中,然后不断取k个最大的优先队列top即可,每次取出来都更新优先队列的值 $a[i] = max(0,a[i] - b[i])$ 再放入,因为可以取多次
- k有1e9,显然该思路不行
- 这么大的数据量 很自然的指向了二分,我们要二分什么?
- **二分一个x,此x为我每次取数字,至少要取大于等于x的数 (核心)**
- 我们得到取大于等于x的数会有一个操作次数,我们要使操作次数f(x) <= k, 并且取max(f(x));
- 然后我们就会得到一个x,我们把每个数取的的贡献不断加入答案中,这步可用等差数列求和
- 我们还有一部分是 (k - f(x)) 即剩余操作次数,我们发现 如果x更小,那么操作次数f(x) 会 > k,那么我们只要取(k - f(x))个 x加入答案即可完成最后一部分的补充**(这步很难理解,笔者建议多思考一下为什么这样补充)**

### 代码:

```c++
const int N = 200005;
int a[N],b[N],n,k;
bool check(int mid){
    int y = 0;
    for(int i = 1;i<= n;i++){
        if(a[i]>=mid){
            y += (a[i] - mid + b[i] - 1)/b[i];
        }
    }
    return y <= k;
}
void solve(){
    cin >> n >> k;
    for(int i = 1;i<=n;i++){
        cin >>a[i];
    }
    for(int i = 1;i<=n;i++){
        cin >>b[i]; 
    }
    int l=0,r=1e12,x=-1;
    while(l <= r){
        int mid = (l + r) >> 1;
        if(check(mid)){
            r = mid - 1;
            x = mid;
        }else{
            l = mid + 1;
        }
    }
    int us = 0;
    int ans = 0;
    for(int i = 1;i<=n;i++){
        if(a[i] >= x){
            int t = (a[i] - x + b[i] - 1)/b[i];
            //(a[i] + a[i] - b[i]*(t - 1))*t/2;
            ans += (a[i] + a[i] - b[i]*(t - 1))*t/2;
            us+=t;
        } 
    } 
    ans += (k - us)*x;
    cout << ans << endl;

}

signed main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    int times = 1;
    cin >> times;
    while(times--){
        solve();
    }
    return 0;
}
```


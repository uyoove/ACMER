# Atcoder ABC364 D-F

## **D - K-th Nearest**

### **链接:** 

[D - K-th Nearest (atcoder.jp)](https://atcoder.jp/contests/abc364/tasks/abc364_d)

### **简要题意:**

#### 问题陈述

在一条数线上有 $N+Q$ 个点 $A_1,\dots,A_N,B_1,\dots,B_Q$ ，其中点 $A_i$ 的坐标为 $a_i$ ，点 $B_j$ 的坐标为 $b_j$ 。

请就每个点 $j=1,2,\dots,Q$ 回答下面的问题：

- 设 $X$ 是 $A_1,A_2,\dots,A_N$ 中最靠近点 $B_j$ 的 $k_j$ 点。求点 $X$ 与 $B_j$ 之间的距离。更正式地说，设 $d_i$ 是点 $A_i$ 与 $B_j$ 之间的距离。将 $(d_1,d_2,\dots,d_N)$ 按升序排序，得到序列 $(d_1',d_2',\dots,d_N')$ 。求 $d_{k_j}'$ .

### **思路:**

- 找一个第k大的a中某个点与b的距离 d, 我们会发现一个性质:
- d越大,我们就会包含更多a中的数字 满足单调性
- 我们保证包含的数字>=k
- 然后最小化d
- 这即是二分

### 代码:

```c++
const int N = 200005;
int a[N];
void solve(){
    int n,q;
    cin >> n >> q;
    for(int i = 1; i <= n;i++){
        cin >> a[i];
    }
    sort(a+1,a+1+n);
    while(q--){
        int d,k;
        cin >> d>>k;
        int l = 0,r = 1e12,ans= 0;
        while(l<=r){
            int mid = (l + r) >> 1;
            int ls = d - mid,rs = d + mid;
            int qs = upper_bound(a+1,a+1+n,rs) - lower_bound(a+1,a+1+n,ls);
            if(qs >= k){
                r = mid - 1;
                ans = mid;
            }else{
                l = mid + 1;
            }
        }
        cout << ans << endl;
    }
}
```



## **E - Maximum Glutton**

### **链接:** 

[E - Maximum Glutton (atcoder.jp)](https://atcoder.jp/contests/abc364/tasks/abc364_e)

### **简要题意:**

 $N$ 道菜。这些菜肴的编号从 $1$ 到 $N$ ，菜肴 $i$ 的**甜度**为 $$A_i$$ ，**咸度**为 $B_i$ 。

你可以选择吃任意菜肴,吃过的菜肴的总甜度超过 $X$ 或总咸度超过 $Y$ ,他就不会再吃任何菜肴。

问**最多**吃多少道菜？

### **思路:**

- 很明显想到dp
- 怎么dp? 设$$dp[i][j][k]$$为前i个菜肴不超过x并且不超过y的能获得的最大奖牌数?? ,根据数据量,这样定义显然不行
- 我们可以把奖牌数开一个维度,然后x开一个维度,记录消耗的y
- 转移方程即: $$dp[i][j][k] = min(dp[i][j][k],dp[i - 1][j - 1][k - a[i]] +b[i])$$
- 表示前i个数获得j个菜肴并且用了k个甜值所消耗的最小咸值
- 明显是个背包,所以倒序枚举,优化一维;

### 代码:

```c++
const int N = 200005;
int a[N],b[N];
void solve(){
    int n,x,y;
    cin >> n >> x >>y;
    for(int i = 1;i<=n;i++){
        cin >> a[i] >>b[i];
    }

    int dp[n + 1][x + 2];
    for(int i = 0;i<=n;i++){
        for(int j = 0;j<=x;j++){
            dp[i][j] = inf;
        }
    }
    dp[0][0] = 0;
    for(int i = 1;i<=n;i++){
        for(int c = i;c>=1;c--){
            for(int k = x;k>=a[i];k--){
                dp[c][k] = min(dp[c][k],dp[c-1][k-a[i]]+b[i]);
            }
        }
    }
    int ans = 0;
    for(int i = 0;i<=n;i++){
        for(int j = 0;j<=x;j++){
            if(dp[i][j] <= y){
               ans = max(ans,i);
            }
        }
    }
    cout << min(ans+1,n) <<endl;

}
```

## F - Range Connect MST

### **链接:** 

[[F - Range Connect MST (atcoder.jp)](https://atcoder.jp/contests/abc364/tasks/abc364_f)](https://atcoder.jp/contests/abc364/tasks/abc364_e)

### **简要题意:**

有一个图，其顶点有 $N + Q$个 ，编号为 $1, 2, \ldots, N + Q$ 。最初，该图没有边。

对于这个图，请依次对 $i = 1, 2, \ldots, Q$ 执行以下操作：

- 对于每个满足  $L_i \leq j \leq R_i$ 的整数 $j$ ，在顶点 $N + i$ 和 $j$ 之间添加一条代价为 $C_i$,的无向边。

完成所有操作后，确定图形是否相连。如果相连，求该图的最小生成树的代价。

### **思路:**

- 首先数据量大,不能真正建边
- 集合分为两部分,第一部分是 $ 1, 2, \ldots, N$ 第二部分是 $N+1,N+2, \ldots, N+Q$ 
- 第二部分要想和第一部分连边 必定会用一次C的价值去连边 所以答案必定 有 $\sum c$
- 然后怎么让第一部分内部自己去连边呢,得靠第二部分去中转,我们可能会有多个l,r覆盖同一个区间,那么我们取最小值去连 l,l+1 等边,即是最小的生成树
- 此部分可用并查集实现
- 因为每个区间建完边后不会再访问
- 时间复杂度$O(NlogN + QlogQ)$

### 代码:

```c++
const int N = 2e5+5;
struct quarys{
    int l,r,c;
    bool operator<(const quarys &q)const{
        return c < q.c;
    }
}q1[N];
struct DSU {
    vector<int> f, siz;
    DSU() {}
    DSU(int n) {
        init(n);
    }
    void init(int n) {
        f.resize(n);
        iota(f.begin(), f.end(), 0);
        siz.assign(n, 1);
    }
    
    int find(int x) {
        while (x != f[x]) {
            x = f[x] = f[f[x]];
        }
        return x;
    }
    
    bool same(int x, int y) {
        return find(x) == find(y);
    }
    
    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return false;
        }
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }
    
    int size(int x) {
        return siz[find(x)];
    }
};
int n,q;
void solve(){
    cin >> n  >> q;
    ll ans = 0;
    DSU dsu(n + 1);
    for(int i = 0 ;i < q;i++){
        int l,r,c;
        cin >> l >> r >> c;
        q1[i].l=l;
        q1[i].r=r;
        q1[i].c=c;

    }
    sort(q1,q1+q);
    for(int i = 0;i < q;i++){
        int l = q1[i].l,r=q1[i].r,c=q1[i].c;
        ans+=c;
        for(int x = dsu.find(l);x<r;x=dsu.find(x)){
            ans+=c;
            dsu.merge(x + 1,x);

        }
    }
    if(dsu.find(1) != n){
        cout << -1;
        return;
    }
    cout << ans <<endl;
}
```


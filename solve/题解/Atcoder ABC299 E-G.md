# Atcoder ABC299 E-G

## **E - Nearest Black Vertex**

### **链接:** 

[E - Nearest Black Vertex (atcoder.jp)](https://atcoder.jp/contests/abc299/tasks/abc299_e)

### **简要题意:**

- #### 问题陈述

  给你一个简单连接的无向图，有 $N$ 个顶点和 $M$ 条边(简单图不包含自循环和多条边)。  
  在 $i = 1, 2, \ldots, M$ 中， $i$ -th 边双向连接顶点 $u_ i$ 和顶点 $v_ i$ 。
  
  请判断是否有办法将每个顶点涂成黑色或白色以同时满足以下两个条件，如果存在，请给出一个这样的办法。
  
  - 至少有一个顶点被涂成黑色。
  - 对于每个 $i = 1, 2, \ldots, K$ 都成立：
      - 顶点 $p_ i$ 与涂成黑色的顶点之间的最小距离正好是 $d_i$ 。
  
  这里，顶点 $u$ 和顶点 $v$ 之间的距离是连接 $u$ 和 $v$ 的路径中边的最小数量。

### **思路:**

- 先找到每个到$p_ i$距离为$d_i$的点,我们称之为可行点
- 那非可行点是什么呢,就是到$p_ i$短于$d_i$的点,这些点需要排除在外
- 然后对于每个$p_i$用可行点中挑出不可行点,即是答案

### 代码:

```c++
const int N = 200005;
int n,m;
vector<int> e[N];
int nin[N]; //排除在外的数字,白色数字
vector<int> can[N]; //可能的数字;
map<int,int> hd;// 每个数字对于黑色的最短距离
void solve(){
    cin >> n >> m;
    for(int i = 1; i <= m;i++){
        int u,v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    int q;
    cin >> q;
    for(int i = 1;i<=q;i++){
        int u,d;
        cin >> u >> d;
        hd[u] = d;
    }
    if(q==0){
        cout << "Yes" << endl;
        for(int i = 1;i<=n;i++){
            cout << 1;
        }
        return;
    }
    int vis[n + 1];
    for(int i = 1;i<=n;i++){
        if(!hd.count(i)){
            continue;
        }
        memset(vis,0,sizeof vis);
        int d = hd[i];
        if(d==0){
            can[i].push_back(i);
            continue;
        }
        queue<pair<int,int>> q;
        q.push({i,0});
        while(q.size()){
            auto p = q.front();q.pop();
            int u = p.first,val = p.second;
            if(vis[u]) continue;
            if(val<d){
                nin[u]=1;
            }
            if(val==d){
                can[i].push_back(u);
                continue;
            }
            if(val>d) continue;
            vis[u] = 1;
            for(auto v:e[u]){
                q.push({v,val+1});
            }
        }
    }
    int res[n + 1];
    memset(res,0,sizeof res);
    for(int i = 1;i<=n;i++){
        if(!hd.count(i)) continue;
        int cnt = 0;
        for(auto p:can[i]){
            if(!nin[p]){
                cnt++;
                res[p] = 1;
            }
        }
        if(!cnt){
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
    for(int i = 1;i<=n;i++){
        cout << res[i];
    }
}   
```

## G - Minimum Permutation

### **链接:** 

[G - Minimum Permutation (atcoder.jp)](https://atcoder.jp/contests/abc299/tasks/abc299_g)

### **简要题意:**

- #### 问题陈述

  长度为 $N$ 的序列 $A$ 由 $1$ 和 $M$ 之间的整数组成。其中，从 $1$ 到 $M$ 的每个整数都至少在 $A$ 中出现过一次。

  在 $A$ 的长度为 $M$ 的子序列中，每个 $1, \ldots, M$ 都出现过一次，请找出字典序最小的一个。

### **思路:**

- 很明显我们对于一个1至M的数有保留和删除两种操作
- 什么时候不能删除?,在后面数组中没有这个数字了就不能删除
- 这样我们可以建一个表记录每个数字最后出现的位置
- 然后用单调栈保持数组的最小即可
- 注意还要开一个表记录数字是否在栈中

### 代码:

```c++
const int N = 200005;
int last[N],a[N],instk[N];
void solve(){
	int n,k;
	cin >> n >> k;
	for(int i = 1;i<=n;i++){
		int t;
		cin >>t;
		a[i] = t;
		last[t] = i;
	}
	stack<int> st;
	for(int i = 1;i<=n;i++){
		if(instk[a[i]]) continue;
		while(!st.empty() && a[i] < st.top() && last[st.top()] > i){
			instk[st.top()]=0;
			st.pop();
		}
		st.push(a[i]);
		instk[a[i]]=1;
	}
	vector<int> res;
	while(st.size()){
		res.push_back(st.top());st.pop();
	}
	for(int i = res.size() - 1;i>=0;i--){
		cout << res[i] << " ";
	}
}

```


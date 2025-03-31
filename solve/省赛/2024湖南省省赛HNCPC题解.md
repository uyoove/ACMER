# 2024湖南省省赛HNCPC题解(E,K,J)

**这里只有铜/银牌题解哦** 

## E.拼接串

### **题意:**

**给出一个长度为 的正整数串 。现在可以把两个没有重叠的连续子串前后拼接起来，但是要求拼接之后的 数串中每个正整数不能出现超过1次。请问能拼接出来的符合要求的数字串的最大长度是多少**

### 思路:

**我们发现$a_i$最多只有18,这个数字很敏感,为什么不是50或者10呢,偏偏是18,很明显的指向了状压dp**

**这题的状压dp可能是状压 + dp吧感觉很那个传统的状压dp不一样**

**我们设$f[s]$为s这个集合下的最长连续符合条件的子串,这个我们可以(18*n)的时间复杂度算出来**

**然后枚举每个集合,对枚举集合的子集进行划分两部分,设当前集合是$i$,划分的一部分是$j$,那么另一部分自然是i^j了,因为不能都选也不能都不选(相对于当前集合情况下)**

### 代码:

```c++
const int N = 1e6+7;
int n;
int a[N];
int mask = 1 << 18;
int f[(1 << 20) + 1];
void solve(){
	cin >> n;
	int mx = 0;
	for(int i = 1;i <= n;i++) cin >> a[i];
	for(int i = 1;i <= n;i++){
		for(int j = i,s = 0;j <= n;j++){
			if((s >> (a[j] - 1)) & 1) break;
			s |= 1 << (a[j] - 1);
			f[s] = max(f[s],j - i + 1);
			mx = max(mx,f[s]);
		}
	}
	for(int i =0;i < mask;i++){
		for(int j = i;j>0;j=i&j-1){
			mx = max(f[j]+f[i ^ j],mx);
		}
	}
	cout << mx << endl;
}
```

## K. 渡劫

### **题意:**

太长了,不想写,直接看题吧;

[Attachments - 2024湖南省赛 - Codeforces](https://codeforces.com/gym/105423/attachments)

****

### 思路:

多源分层图dij

考虑有魔法和无魔法两种情况,最后找跑完dij后dis最大的值即是答案

很难去找一个单点出发,因为你找你可能会想找最小的修炼值岛屿出发然后不断更新其他岛屿,但此算法是假的

那就塞所有点,然后让堆来帮我们跑最优!!!

### 代码:

```c++
#include<bits/stdc++.h>
using namespace std;
#define int long long
//dp[n][2]
const int N = 1e5 + 1;
int n,m;

int a[N];
struct edges{
    int v,w,ne;
}e[N*10 + 1];
int h[N],idx = 1,vis[N][2],st[N];
void add(int u,int v,int w){
    e[++idx] = {v,w,h[u]};
    h[u] = idx;
}
struct id{
    int p,w,op;
    bool operator<(const id &t)const{
        if(w==t.w) return op > t.op;
        return w > t.w; 
    }
};
int dis[N][2];
int mi = 1e17,root = -1;
void solve(){
    cin >> n >> m;
    for(int i = 1;i<=m;i++){
        int u,v,w;
        cin >> u >> v >> w;
        add(u,v,w);
        add(v,u,w);
    }
    vector<int> vv;
    priority_queue<id> q;
    for(int i = 1;i<= n;i++){
        cin >> a[i];
        if(a[i] < mi) mi = a[i],vv.clear(),vv.push_back(i);
        else if(a[i]==mi) vv.push_back(i);
        dis[i][0] = a[i];
        dis[i][1] = a[i];
        q.push({i,a[i],0});
    }
    while(q.size()){
        auto p = q.top();q.pop();
        int u = p.p,w = p.w,op = p.op;
        bool f= true;
        if(vis[u][op] ) continue;
        vis[u][op] = 1;
        if(op==3) op = 0;
        for(int i = h[u];i;i=e[i].ne){
            int v = e[i].v;
            int w = e[i].w;
            if(op==0){
                if(dis[v][0] > dis[u][0] + w){
                    dis[v][0] = dis[u][0] + w;
                    q.push({v,dis[v][0],0});
                }
                if(dis[v][1] > dis[u][0]){
                    dis[v][1] = dis[u][0];
                    q.push({v,dis[v][1],1});
                }
                
            }else{
                if(dis[v][1] > dis[u][1] + w){
                    dis[v][1] = dis[u][1] + w;
                    q.push({v,dis[v][1],1});
                }
            }
        }
    }
    int mx = 0;
    for(int i = 1;i<= n;i++){
        mx = max(mx,min(dis[i][0],dis[i][1]));
    }
    cout << mx;
} 
signed main(){
    int t = 1;
    //cin >> t;
    while(t--) solve();
}
```

## J.Beautiful Sequence (Maxzz)

### **题意:**

太长了,不想写,直接看题吧;

[Attachments - 2024湖南省赛 - Codeforces](https://codeforces.com/gym/105423/attachments)

****

### 思路:

**发现所谓的beautiful seq就是长度为len的连续数字,比如说长度为5 那么 2 3 4 5 6**

**所以要解决找这个序列我们可以对值域双指针尺取法**

**因为满足连续,那么假设长度为5的序列满足,那么长度为4,3,2,1的该序列的子序列也是满足的,所以ans+=r-l+1**

**然后如何判这个两个数组是否都出现过呢,我们发现其实就是看这两个数组的绝对关系,那么树状数组维护即可,因为尺取法要增删查操作,很容易联想到树状数组**

****

### 代码:

```c++
const int N = 200005;
int n;
int tr1[N],tr2[N];
void add(int k,int val,int op){
	if(op==1){
		for(int i = k;i < N;i+=(i&-i)) tr1[i]+=val;
	}else{
		for(int i = k;i < N;i+=(i&-i)) tr2[i]+=val;
	}
}
int query(int k,int op){
	int res = 0;
	if(op==1){
		for(int i = k;i > 0;i-=(i&-i)) res+=tr1[i];
	}else{
		for(int i = k;i > 0;i-=(i&-i)) res+=tr2[i];
	}
	return res;
}
int pos1[N],pos2[N],a[N],b[N];
void solve(){
	cin >> n;
	for(int i = 1;i<=n;i++) cin >> a[i],pos1[a[i]] = i;
	for(int i = 1;i<=n;i++) cin >> b[i],pos2[b[i]] = i;
	int l = 1;
	int ans = 0;
	for(int r = 1;r <= n;r++){
		add(pos1[r],1,1);
		add(pos2[r],1,2);
		int q1 = query(pos1[r],1);
		int q2 = query(pos2[r],2);
		while(l<r && q1!=q2){
			add(pos1[l],-1,1);
			add(pos2[l],-1,2);
			q1 = query(pos1[r],1);
			q2 = query(pos2[r],2);
			l++;
		}
	
		ans += r-l+1;
		
	}
	cout << ans;
}
```


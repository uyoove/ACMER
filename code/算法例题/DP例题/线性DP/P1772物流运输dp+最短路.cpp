//和爸爸一起学编程真好,不过要小学四年级分流考试了,最近没时间写代码了,呜呜呜
#include<bits/stdc++.h>
using namespace std;
#define out(x) cout << #x << '=' << (x) << endl
#define out2(x, y) cout << #x << '=' << (x) << ',' << #y << '=' << (y) << endl 
#define int long long
#define lc u<<1
#define rc u<<1|1
#define pb push_back
#define vt vector
#define fi first
#define se second
#define PII pair<int,int>
#define endl "\n"
#define il inline
typedef unsigned long long ULL;
typedef long long ll;
il int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x*f;
}
const ll inf = 0x3f3f3f3f3f3f3f3fLL;
const int infi = 0x3f3f3f3f;
const int P = 13331;
const int N = 5005;
struct DSU {
    vector<int> f, sz;
    DSU(){}
    DSU(int n) {
        init(n);
    }
    void init(int n) {
        f.resize(n);
        iota(f.begin(), f.end(), 0);
        sz.assign(n, 1);
    }
    int fd(int x) {
        if(f[x]==x) return x;
        return f[x] = fd(f[x]);
    }
    bool same(int x, int y) {
        return fd(x) == fd(y);
    }
    bool mg(int x, int y) {
        x = fd(x);
        y = fd(y);
        if (x == y)return false;
        sz[x] += sz[y];
        f[y] = x;
        return true;
    }
    int size(int x) {
        return sz[fd(x)];
    }
};
int dp[N];//代表前i天最小花费
int n,m,k,t;
struct egdes{
	int v,w,ne;
}e[N << 1];
int h[N],idx = 1;
void add(int u,int v,int w){
	e[++idx] = {v,w,h[u]};
	h[u] = idx;
}
int now[N][N]; //代表i这个节点在j这天不行
int nt[N];//表示当前图不行
int vis[N],dis[N];
void spfa(){
	memset(dis,0x3f,sizeof dis);
	memset(vis,0,sizeof vis);
	dis[1] = 0;
	queue<int> q;
	q.push(1);
	vis[1] = 1;
	while(q.size()){
		int u = q.front();q.pop();
		vis[u] = 0;
		for(int i = h[u];i;i=e[i].ne){
			int v=e[i].v;
			if(nt[v]) continue;
			if(dis[v] > dis[u] + e[i].w){
				dis[v] = dis[u] + e[i].w;
				if(!vis[v]){
					vis[v] = 1;
					q.push(v);
				}
			}
		}
	}
}

void solve(){
	cin >> n >> m >> k >> t;
	for(int i = 1;i <= t;i++){
		int u,v,w;
		cin >> u >> v >> w;
		add(u,v,w);
		add(v,u,w);
	}
	int d;
	cin >> d;
	for(int i = 1;i <= d;i++){
		int u,a,b;
		cin >> u >> a >> b;
		for(int j = a;j <= b;j++){
			now[u][j] = 1;
		}
	}
	memset(dp,0x3f,sizeof dp);
	dp[0] = -k;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++) nt[j] = 0;
		for(int j = i;j >=1;j--){
			for(int k = 1;k<=m;k++) if(now[k][j]) nt[k] = 1;
			spfa();
			int p = dis[m];
			if(p > 0x3f3f3f3f) break;
			//cout << i << " " << j << endl;
			dp[i] = min(dp[i],dp[j-1] + p*(i-j+1) + k);
		}
	}
	cout << dp[n] << endl;
}

signed main(){
	std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
	int times = 1;
	//cin >> times;
	while(times--){
		solve();
	}
	return 0;
}
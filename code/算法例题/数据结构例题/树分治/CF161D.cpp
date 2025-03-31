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
#define all(x) x.begin(), x.end()
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
mt19937_64 rnd(time(0));
const ll inf = 0x3f3f3f3f3f3f3f3fLL;
const int infi = 0x3f3f3f3f;
const int P = 13331;
const int N = 200005;
struct edges{
	int v,ne;
}e[N << 1];
int h[N],idx = 1;
void add(int u,int v){
	e[++idx] = {v,h[u]};
	h[u] = idx;
}
int n,k;
int curn,root;
int ans;
int mx[N],use[N],sz[N];
int dis[N];
int has[N],d[N];
void get_root(int u,int f){
	sz[u] = 1,mx[u] = 0;
	for(int i = h[u];i;i=e[i].ne){
		int v = e[i].v;
		if(v==f || use[v]) continue;
		get_root(v,u);
		mx[u] = max(sz[v],mx[u]);
		sz[u]+=sz[v];
	} 
	mx[u]=max(mx[u],curn - sz[u]);
	if(mx[u] < mx[root]) root = u;
}
void get_dis(int u,int f){
	d[dis[u]]++;
	for(int i = h[u];i;i=e[i].ne){
		int v = e[i].v;
		if(use[v] || v == f) continue;
		dis[v] = dis[u] + 1;
		get_dis(v,u);
	}
}
void calc(int u){
	has[0] = 1;
	for(int i = h[u];i;i=e[i].ne){
		int v = e[i].v;
		if(use[v]) continue;
		dis[v] = 1;
		get_dis(v,u);
		for(int j = 1;j <= k;j++){
			ans+=d[j]*has[k - j];
		}
		for(int j = 1;j <= k;j++) has[j]+=d[j],d[j] = 0;
	}
	for(int j = 0;j <= k;j++) has[j] = 0;
}
void dfz(int u){
	calc(u);
	use[u] = 1;
	for(int i = h[u];i;i=e[i].ne){
		int v = e[i].v;
		if(use[v]) continue;
		root = 0;
		curn = mx[0] = sz[v];
		get_root(v,0),get_root(root,0);
		dfz(root);
	}
}
void solve(){
	cin >> n >> k;
	for(int i = 1;i < n;i++){
		int u,v;
		cin >> u >> v;
		add(u,v);
		add(v,u);
	}
	curn=mx[0]=n;
	get_root(1,0),get_root(root,0);
	dfz(root);
	cout << ans << endl;
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
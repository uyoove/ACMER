//最后一
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define out(x) cout << #x << '=' << (x) << endl
#define out2(x, y) cout << #x << '=' << (x) << ',' << #y << '=' << (y) << endl 
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
const int N = 100010;
struct edges{
	int v,ne,w;
}e[N << 1];
int h[N],idx = 1;
void add(int u,int v,int w){
	e[++idx] = {v,h[u],w};
	h[u] = idx;
}
int dis[N][20];
int vis[N];
array<int,3> times[20];
int a1[N];
int n,m,k,t;
void dij(int st,int op){
	
	memset(vis,0,sizeof vis);
	dis[st][op] = 0;
	priority_queue<PII,vt<PII>,greater<PII>> p;
	p.push({0,st});
	while(p.size()){
		auto [val,u] = p.top();p.pop();
		if(vis[u]) continue;
		vis[u] = 1;
		for(int i = h[u];i;i=e[i].ne){
			int v = e[i].v, w = e[i].w;
			if(val + w < dis[v][op]){
				dis[v][op] = val + w;
				p.push({dis[v][op],v});
			}
		}
	}
}
int vis2[N];
vt<int> it[N],ot[N];
void solve(){
	cin >> n >> m >> k >> t;
	for(int i = 1;i <= n;i++) cin >> a1[i];
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= k;j++) dis[i][j] = inf;
		}
	for(int i = 1;i <= k;i++){
		int a,b,c;
		cin >> a>> b >> c;
		times[i] = {a,b,c};
		it[b].pb(i);
		ot[c+1].pb(i);
	}
	for(int i = 1;i <= m;i++){
		int u,v,w;
		cin >> u >> v >> w;
		add(u,v,w);
		add(v,u,w);
	}
	int ans = 0;
	set<int> se;
	for(int i = 1;i <= t;i++){
		bool f = 1;
		if(it[i].size()){
			f = 0;
			for(auto &p:it[i]){
				se.insert(p);
				auto &[a,l,r] = times[p];
				dij(a,p);
			}
		}
		if(ot[i].size()){
			f = 0;
			for(auto &p:ot[i]) se.erase(p);
		}
		if(!f){
			ans = 0;
			for(int j = 1;j <= n;j++){
				int mi = inf;
				for(auto &p:se){
					mi = min(mi,dis[j][p]);
				}
			
				ans += mi*a1[j];
				
			}
		}
		if(se.size()) cout << ans << endl;
		else cout << -1 << endl;
		
	}
	

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
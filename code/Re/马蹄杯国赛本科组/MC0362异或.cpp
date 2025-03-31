//最后一舞
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
const int N = 500005;
const int mod = 1e9+7;
int n,q,k;
int a[N];
struct edges{
	int v,ne;
}e[N << 1];
int h[N],idx;
void add(int u,int v){
	e[++idx]={v,h[u]};
	h[u] = idx;
}
int d[N][32];
int d0[N][32];
int dis[N],fa[N];
map<int,stack<int>> mp;
void dfs(int u,int f){
	fa[u] = f;
	dis[u] = dis[f] + 1;
	if(mp[dis[u] - k].size()){
		int v = mp[dis[u] - k].top();
		for(int i = 0;i <= 30;i++){
			if(a[u]&(1<<i)){
				d[u][i]++;
				d[fa[v]][i]--;
			}else{
				d0[u][i]++;
				d0[fa[v]][i]--;
			}
		}
		//cout << u << " " << v << endl;
	}else{
		for(int i = 0;i <= 30;i++){
			if(a[u]&(1<<i)){
				d[u][i]++;
			}else{
				d0[u][i]++;
			}
		}
	}
	mp[dis[u]].push(u);
	for(int i = h[u];i;i=e[i].ne){
		int v = e[i].v;
		if(v==f) continue;
		dfs(v,u);
	}
	mp[dis[u]].pop();
}
int ans[N];
void dfs2(int u){
	for(int i = h[u];i;i=e[i].ne){
		int v= e[i].v;
		if(v==fa[u]) continue;
		dfs2(v);
		for(int j = 0;j <= 30;j++){
			d[u][j]+=d[v][j];
			d0[u][j]+=d0[v][j];
		}
	}
	int cnt = 0;
	for(int i = 0;i <= 30;i++){
		cnt += (d[u][i] * d0[u][i]%mod)*(1ll << i)%mod;
		cnt%=mod;
	}
	//cout << u << " " << cnt << endl;
	ans[u] = cnt;
}
void solve(){
	cin >> n >> q >> k;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	for(int i = 1;i < n;i++){
		int u,v;
		cin >> u >> v;
		add(u,v);
		add(v,u);
	}
	dfs(1,0);
	dfs2(1);
	while(q--){
		int v;
		cin >> v;
		cout << ans[v] << endl;
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
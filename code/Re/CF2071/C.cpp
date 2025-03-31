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
const int N = 200005;
int n,st,en;
struct edges{
	int v,ne;
}e[N << 1];
int h[N],idx = 1;
void add(int u,int v){
	e[++idx] = {v,h[u]};
	h[u] = idx;
}
int vis[N],cost[N],dep[N],cnt = 0;
bool f;
vt<int> t[N];
void dfs(int u,int fa){
	dep[u] = dep[fa] + 1;
	t[dep[u]].pb(u);
	for(int i = h[u];i;i=e[i].ne){
		int v = e[i].v;
		if(v==fa) continue;
		dfs(v,u);
	}	

}
void solve(){
	cin >> n >> st >> en;
	idx = 1;
	cnt=0;
	for(int i = 1;i <= n;i++){
		t[i].clear();
		vis[i] = 0;
		dep[i] = 0;
		cost[i] = 0;
		h[i] = 0;
	}
	f = false;
	for(int i = 1;i < n;i++){
		int u,v;
		cin >> u >> v;
		add(u,v);
		add(v,u);
	}
	dfs(en,0);
	for(int i = n; i >= 1;i--){
		for(auto p:t[i]){
			cout << p << " ";
		}	
	}
	cout << endl;
	
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
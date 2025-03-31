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
int n;
int vis[N];
struct edges{
	int v,ne;
}e[N << 1];
int h[N],idx = 1;
void add(int u,int v){
	e[++idx] = {v,h[u]};
	h[u] = idx;
}
int fa[N],sz[N],val[N];
int rt;
void dfs1(int u,int f){
	fa[u] = f;
	sz[u] = 1;
	val[u] = 0;
	for(int i = h[u];i;i=e[i].ne){
		int v = e[i].v;
		if(v==f) continue;
		dfs1(v,u);
		sz[u] += sz[v];
		val[u] += val[v];
	}
	val[u]+=sz[u];
}

int g[N];
void dfs2(int u){
	//1.子树贡献,头上树贡献,初始化连通块大小即是n
	if(u!=rt)g[u] = (val[u]-sz[u]) + (g[fa[u]] - val[u] - sz[u]) + n;
	else g[u] = val[u];
	for(int i = h[u];i;i=e[i].ne){
		if(e[i].v==fa[u]) continue;
		dfs2(e[i].v);
	}
}

//g[u] = (val[u]-sz[u]) + (g[fa] - val[u] - sz[u]) + n
void solve(){
	int res = 0;
	cin >> n;
	for(int i = 1;i< n;i++){
		int u,v;
		cin >>u >> v;
		add(u,v);
		add(v,u);
		vis[u]++,vis[v]++;
	}
	rt = 1;
	dfs1(rt,0);
	g[rt] = val[rt];
	dfs2(rt);
	for(int i = 1;i <= n;i++){
		res=max(res,g[i]);
	}
	cout << res << endl;
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
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
int n,m;
struct nodes{
	int u,v,w;
	bool operator<(const nodes& t1)const{
		return w < t1.w;
	}
};
struct edges{
	int v,w,ne;
}e[N << 1];
int h[N],idx = 1;
void add(int u,int v,int w){
	e[++idx] = {v,w,h[u]};
	h[u] = idx;
}
//克鲁斯卡尔重构树部分
vt<nodes> a;
int f[N << 1],val[N << 1];
int fd(int x){
	if(f[x]!=x) f[x] = fd(f[x]);
	return f[x];
}
void ex(){
	int cnt = n;
	for(int i = 1;i <= 2 * n;i++) f[i] = i;
	sort(all(a));
	for(int i = 0;i < m;i++){
		int u = fd(a[i].u),v = fd(a[i].v);
		if(u == v) continue;
		cnt++;
		f[u] = cnt,f[v] = cnt; //两个连通块生成一个新的节点,权值为w
		val[cnt] = a[i].w;
		add(cnt,u,0);
		add(cnt,v,0);
		add(u,cnt,0);
		add(v,cnt,0);
		if(cnt == 2 * n - 1) break;
	}
}
//树链剖分求lca部分
int son[N],dep[N],sz[N],fa[N],top[N];
void dfs(int u,int f){
	fa[u] = f;
	sz[u] = 1;
	dep[u] = dep[f] + 1;
	for(int i = h[u];i;i=e[i].ne){
		int v = e[i].v;
		if(v == f) continue;
		dfs(v,u);
		sz[u] += sz[v];
		if(sz[v] > sz[son[u]]) son[u] = v;
	}
}
void dfs2(int u,int t){
	top[u] = t;
	if(!son[u]) return;
	dfs2(son[u],t);
	for(int i = h[u];i;i=e[i].ne){
		int v = e[i].v;
		if(v==fa[u] || v == son[u]) continue;
		dfs2(v,v);
	}
}
int lca(int x,int y){
	while(top[x]!=top[y]){
		if(dep[top[x]] < dep[top[y]]) swap(y,x); //深度更深的进行操作,默认x深度更深
		x = fa[top[x]];
	}
	return dep[x] < dep[y] ? x : y;
}
void solve(){
	cin >> n >> m;

	for(int i = 1;i <= m;i++){
		int u,v,w;
		cin >> u >> v >> w;
		a.pb({u,v,w});
	}
	ex();
	for(int i = 1;i <= 2 * n - 1;i++){
		if(dep[fd(i)] == 0){
			dfs(fd(i),0);
			dfs2(fd(i),fd(i));
		}
	}
	int q;
	cin >> q;
	while(q--){
		int u,v;
		cin >> u >> v;
		if(fd(u)==fd(v)){
			cout << val[lca(u,v)] << endl;
		}else{
			cout << "impossible" << endl;
		}

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
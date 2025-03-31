//和爸爸一起学编程真好,不过要小学四年级分流考试了,最近没时间写代码了,呜呜呜
#include<bits/stdc++.h>
using namespace std;
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
const int N = 1000005;
int n,m,q;
struct edges{
	int v,ne;
}e[N];
int h[N],idx = 1;
void add(int u,int v){
	e[++idx] = {v,h[u]};
	h[u] = idx;
}
int height[N];
PII ls1[N];
struct nodes{
	int u,v,w;
	bool operator<(const nodes&t1)const{
		return w < t1.w;
	}
}es[N];
int f[N],val[N];
int fd(int x){
	if(x!=f[x]) f[x] = fd(f[x]);
	return f[x];
}
int cnt1;
void kruskal(){
	cnt1 = n;
	sort(es + 1,es + 1 + m);
	for(int i = 1;i <= 2*n;i++) f[i] = i;
	for(int i = 1;i <= m;i++){
		int u = es[i].u,v = es[i].v,w = es[i].w;
		u = fd(u),v = fd(v);
		if(u==v) continue;
		++cnt1;
		f[u] = f[v] = cnt1;
		val[cnt1] = w;
		add(cnt1,u);
		add(cnt1,v);
		if(cnt1 == 2*n - 1) return;
	}
}
//树上倍增,每个子树管理的的最左叶子的前一个和最右叶子节点;
//d为dfs序的叶子
int fa[N][30],L[N],R[N],d[N],pop;
void dfs(int u,int f){
	fa[u][0] = f;
	for(int i = 1;i <= 20;i++){
		fa[u][i] = fa[fa[u][i - 1]][i - 1];
	}
	//如果是叶子
	L[u] = pop; 
	if(!h[u]){
		d[++pop] = u;
		R[u] = pop;
		return;
	}
	for(int i = h[u];i;i=e[i].ne){
		int v= e[i].v;
		if(v == f) continue;
		dfs(v,u);
	}
	R[u] = pop;
}
//找到一个叶子上层 <= k的最近节点
int fd_t(int x,int k){
	int now = x;
	for(int i = 20;i >= 0;i--){
		if(val[fa[now][i]] <= k) now = fa[now][i]; 
	}
	return now;
}
const int M = 2e5 + 1;
int root[M * 20],ls[M * 20],rs[M * 20],cnt,tr[M * 20];
void build(int &u,int l,int r){
	u = ++cnt;
	if(l==r) return;
	int mid = l + r >> 1;
	build(ls[u],l,mid);
	build(rs[u],mid+1,r);
}
void modify(int &u,int v,int l,int r,int x){
	u = ++cnt;
	ls[u] = ls[v],rs[u] = rs[v],tr[u] = tr[v] + 1;
	if(l==r) return;
	int mid = l + r >> 1;
	if(x <= mid){
		modify(ls[u],ls[v],l,mid,x);
	}else{
		modify(rs[u],rs[v],mid + 1,r,x);
	}
}
int query(int u,int v,int l,int r,int k){
	if(l==r){
		if(tr[u] - tr[v] == k) return l;
		return 0;
	}
	int mid = l + r >> 1;
	int val = tr[rs[u]] - tr[rs[v]];
	if(val >= k){
		return query(rs[u],rs[v],mid + 1,r,k);
	}
	return query(ls[u],ls[v],l,mid,k - val);
}
void solve(){
	cin >> n >> m >> q;
	val[0] = inf;
	for(int i = 1;i <= n;i++) cin >> height[i],ls1[i].fi = height[i],ls1[i].se = i;
	sort(ls1 + 1,ls1 + 1 + n);
	for(int i = 1;i <= n;i++) height[ls1[i].se] = i;//离散化
	for(int i = 1;i <= m;i++){
		cin >> es[i].u >> es[i].v >> es[i].w;
	}	

	kruskal();
	dfs(cnt1,cnt1);
	build(root[0],1,n);
	for(int i = 1;i <= pop;i++){
		modify(root[i],root[i - 1],1,n,height[d[i]]);
	}
	ls1[0].fi = 0;
	int lastans = 0;
	for(int i = 1;i <= q;i++){
		int v,x,k;
		cin >> v >> x >> k;
		v = (v ^ lastans) %(n) + 1;
		k = (k ^ lastans) %(n) + 1;
		x = x ^ lastans;
		int tp = fd_t(v,x);
		int ans = query(root[R[tp]],root[L[tp]],1,n,k);
		lastans = ls1[ans].fi;
		cout << (lastans == 0 ? -1 : lastans)<< endl;
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
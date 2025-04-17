#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5+10;
#define endl '\n'
#define lc u<<1
#define rc u<<1|1
int n,q;
struct edges{
	int v,ne;
}e[N << 1];
int h[N],idx = 1;
void add(int u,int v){
	e[++idx] = {v,h[u]};
	h[u] = idx;
}
int fa[N],dep[N],top[N],dfn[N],sz[N],son[N],tot;
void dfs(int u,int f){
	dep[u]=dep[f]+1;
	fa[u]=f;
	sz[u]=1;
	for(int i = h[u];i;i=e[i].ne){
		int v = e[i].v;
		if(v==f) continue;
		dfs(v,u);
		sz[u]+=sz[v];
		if(sz[son[u]] < sz[v]) son[u] = v;
	}
}
void dfs2(int u,int t){
	top[u] = t;
	dfn[u]=++tot;
	if(son[u]) dfs2(son[u],t);
	for(int i = h[u];i;i=e[i].ne){
		int v = e[i].v;
		if(v==son[u]||v==fa[u]) continue;
		dfs2(v,v);
	}
}
int c[N],mp[N];
struct Tree{
	int l,r,c[21];
}tr[N << 2];
void push_up(int u){
	for(int i = 1;i <= 20;i++){
		tr[u].c[i]=tr[lc].c[i]+tr[rc].c[i];
	}
}
void build(int u,int l,int r){
	tr[u]={l,r};
	if(l==r){
		tr[u].c[c[mp[l]]]++;
		return;
	}
	int mid =l+r>>1;
	build(lc,l,mid);
	build(rc,mid+1,r);
	push_up(u);
}
Tree query(int u,int l,int r){
	if(tr[u].l > r || tr[u].r < l) return {};
	if(tr[u].l>=l&&tr[u].r<=r){
		return tr[u];
	}
	Tree t1=query(lc,l,r),t2=query(rc,l,r);
	for(int i = 1;i <= 20;i++) t1.c[i]+=t2.c[i];
	return t1;
}
int d[21];
void work(int x,int y){
	while(top[x]!=top[y]){
		if(dep[top[x]]<dep[top[y]]) swap(x,y);
		Tree t2 = query(1,dfn[top[x]],dfn[x]);
		for(int i = 1;i <= 20;i++) d[i]+=t2.c[i];
		x = fa[top[x]];
	}
	if(dep[x] < dep[y]) swap(x,y);
	Tree t2 = query(1,dfn[y],dfn[x]);
	for(int i = 1;i <= 20;i++) d[i]+=t2.c[i];
}
void solve(){
	cin >> n >> q;
	for(int i = 1;i <= n;i++) cin >> c[i];
	for(int i = 1;i < n;i++){
		int u,v;
		cin >> u >> v;
		add(u,v);
		add(v,u);
	}
	dfs(1,0);
	dfs2(1,1);
	for(int i = 1;i <= n;i++) mp[dfn[i]] = i;
	build(1,1,n);
	for(int i = 1;i <= q;i++){
		memset(d,0,sizeof d);
		int x,y;
		cin>>x>>y;
		work(x,y);
		int cnt = 0;
		for(int j = 1;j <= 20;j++) cnt+=(d[j]>=1); 
		cout << cnt << endl;
	}
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	solve();
	return 0;
}
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
int n,q;
struct edges{
	int v,ne;
}e[N << 1];
int h[N],idx = 1;
void add(int u,int v){
	e[++idx] = {v,h[u]};
	h[u] = idx;
}
int dfn[N],sz[N],dep[N],top[N],son[N],fa[N],tot;
PII b[N];
void dfs1(int u,int f){
	sz[u] = 1,dep[u] = dep[f] + 1;
	fa[u] = f;
	for(int i = h[u];i;i=e[i].ne){
		int v = e[i].v;
		if(v==f) continue;
		dfs1(v,u);
		sz[u]+=sz[v];
		if(sz[son[u]] < sz[v]) son[u] = v;
	}
}
void dfs2(int u,int t){
	top[u] = t;
	dfn[u] = ++tot;
	if(!son[u]) return;
	dfs2(son[u],t);
	int a = son[u],b = u;
	for(int i = h[u];i;i=e[i].ne){
		int v = e[i].v;
		if(v==son[u] || v == fa[u]) continue;
		dfs2(v,v);
	}
}
struct Tree{
	int l,r,h,b; 
}tr[N << 2];
void push_up(int u){
	tr[u].h = tr[lc].h + tr[rc].h;
	tr[u].b = tr[lc].b + tr[rc].b; 
}
void build(int u,int l,int r){
	tr[u] = {l,r,1,0};
	if(l==r) return;
	int mid = l + r >> 1;
	build(lc,l,mid);
	build(rc,mid+1,r);
	push_up(u);
}
void change(int u,int x,int ys){
	if(tr[u].l > x || tr[u].r < x) return;
	if(tr[u].l==x && tr[u].r==x){
		if(ys==2){
			if(tr[u].h==1){
				tr[u].h = 0;
				tr[u].b++;
			}
		}else{
			if(tr[u].b==1){
				tr[u].b = 0;
				tr[u].h++;
			}
		}
		return;
	}
	change(lc,x,ys);
	change(rc,x,ys);
	push_up(u);
}
PII query(int u,int l,int r){
	if(tr[u].l > r || tr[u].r < l) return {0,0};
	if(tr[u].l >= l && tr[u].r <= r){
		return {tr[u].h,tr[u].b};
	}
	PII p1 = query(lc,l,r),p2 = query(rc,l,r);
	return {p1.fi + p2.fi,p1.se + p2.se};
}
PII query_su(int x,int y){
	PII res = {0,0};
	while(top[x] != top[y]){
		if(dep[top[x]] < dep[top[y]]) swap(x,y);
		PII tp = query(1,dfn[top[x]],dfn[x]);
		res.fi+=tp.fi;
		res.se+=tp.se;
		x = fa[top[x]];
	}
	if(dep[x] < dep[y]) swap(x,y);
	PII tp = query(1,dfn[y] + 1,dfn[x]);
	res.fi+=tp.fi;
	res.se+=tp.se;
	return res;
}
void solve(){
	cin >> n;
	for(int i = 1;i <= n - 1;i++){
		int u,v;
		cin >> u >> v;
		if(u > v) swap(u,v);
		b[i] = {u,v};
		add(u,v);
		add(v,u);
	}
	cin >> q;
	dfs1(1,0);
	dfs2(1,1);
	build(1,1,n);
	//cout << query_su(3,4).fi << endl;
	while(q--){
		int op,l,r;
		cin >> op >> l;
		if(op<=2){
			PII p = b[l];
			int a= p.fi,b = p.se;
			if(dep[a] < dep[b]) swap(a,b);
			change(1,dfn[a],op);
		}else{
			cin >> r;
			auto p = query_su(l,r);
			if(p.se>=1){
				cout << -1 << endl;
			}else{
				cout << p.fi << endl;
			}
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
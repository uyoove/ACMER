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
const int N = 400005;
//线段树维护连续区间lca
int n,m,q;
struct edges{
	int v,ne;
}e[N << 1];
int h[N],idx = 1;
void add(int u,int v){
	e[++idx] = {v,h[u]};
	h[u] = idx;
}
struct nodes{
	int u,v,w;
	bool operator<(const nodes &t1)const{
		return w < t1.w;
	}
};
vector<nodes> a;
int fa[N],top[N],dep[N],sz[N],son[N];
void dfs(int u,int f){
	sz[u] = 1,dep[u] = dep[f] + 1,fa[u] = f;
	for(int i = h[u];i;i=e[i].ne){
		int v = e[i].v;
		if(v == f) continue;
		dfs(v,u);
		sz[u] += sz[v];
		if(sz[son[u]] < sz[v]) son[u] = v;
	}
}
void dfs2(int u,int t){
	top[u] = t;
	if(!son[u]) return;
	dfs2(son[u],t);
	for(int i = h[u];i;i=e[i].ne){
		int v = e[i].v;
		if(v == fa[u] || v == son[u]) continue;
		dfs2(v,v);
	}
}
int lca(int x,int y){
	while(top[x] != top[y]){
		if(dep[top[x]] < dep[top[y]]) swap(x,y);
		x = fa[top[x]];
	}
	return dep[x] < dep[y] ? x : y; 
}
int f[N << 1],val[N << 1];
int fd(int x){
	if(x!=f[x]) f[x] = fd(f[x]);
	return f[x];
}
void ex(){
	sort(all(a));
	int cnt = n;
	for(int i = 1;i <= 2*n;i++) dep[i]=0,f[i] = i,sz[i] = 0,val[i] = 0,son[i] = 0,fa[i] = 0,top[i] = 0;
	for(int i = 0;i < m;i++){
		int u = a[i].u,v = a[i].v,w = a[i].w;
		u = fd(u),v = fd(v);
		if(u==v) continue;
		++cnt;
		f[u] = cnt,f[v] = cnt;
		val[cnt] = w;
		add(cnt,u);
		add(cnt,v);
		add(u,cnt);
		add(v,cnt);
		if(cnt == 2*n - 1)break;
	}
}
struct Tree{
	int l,r,val,pos; //值,lc是谁
}tr[N << 2];
void push_up(int u){
	tr[u].pos = lca(tr[lc].pos,tr[rc].pos);
	tr[u].val = val[tr[u].pos];
}
void build(int u,int l,int r){
	tr[u] = {l,r,val[l],l};
	if(l==r) return;
	int mid = l + r >> 1;
	build(lc,l,mid);
	build(rc,mid + 1,r);
	push_up(u);
}
Tree query(int u,int l,int r){
	if(tr[u].l >= l && tr[u].r <= r){
		return tr[u];
	}
	int mid = tr[u].l + tr[u].r >> 1;
	if(r <= mid){
		return query(lc,l,r);
	}
	if(l > mid){
		return query(rc,l,r);
	}
	Tree t1 = query(lc,l,r);
	Tree t2 = query(rc,l,r);
	int lc1 = lca(t1.pos,t2.pos);
	Tree ans;
	ans.pos = lc1;
	ans.val = val[lc1];
	return ans;
}
void solve(){
	idx = 1;
	a.clear();
	cin >> n >> m >> q;
	for(int i = 1;i <= n*2;i++) h[i] = 0;
	for(int i = 1;i <= m;i++){
		int u,v;
		cin >> u >> v;
		a.pb({u,v,i});
	}
	ex();
	for(int i = 1;i <= 2*n - 1;i++){
		if(f[i]==i){
			dfs(i,0),dfs2(i,i);
			break;
		}
	}
	build(1,1,n);
	while(q--){
		int l,r;
		cin >>l >> r;
		if(l==r) {
			cout << 0 << " ";
		}else{
			cout << val[query(1,l,r).pos] << " ";
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
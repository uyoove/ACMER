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
struct edgse{
	int v,w,ne;
}e[N << 1];
int h[N],idx=1;
PII bq[N];
void add(int u,int v,int w){
	e[++idx] = {v,w,h[u]};
	h[u] = idx;
}
//树链剖分,统计路径上每一条重链的sum然后加起来
int w[N],dfn[N],tot,val[N];
int dis[N],sz[N],son[N],top[N],fa[N];
void dfs1(int u,int f){
	fa[u] = f,sz[u] = 1,dis[u] = dis[f] + 1;
	for(int i = h[u];i;i=e[i].ne){
		int v = e[i].v;
		if(v == f) continue;
		dfs1(v,u);
		sz[u] += sz[v];
		val[v] = e[i].w;
		if(sz[son[u]] < sz[v]) son[u] = v; 
	}
}
void dfs2(int u,int t){
	dfn[u] = ++tot;
	top[u] = t;
	w[tot] = val[u];
	if(!son[u]) return; //叶子才没有重儿子
	dfs2(son[u],t);
	for(int i = h[u];i;i=e[i].ne){
		int v = e[i].v;
		if(v==fa[u] || v==son[u]) continue;
		dfs2(v,v); //轻链做头
	}
}
int n,q;
struct Tree{
	int l,r,w;
}tr[N << 2];
void push_up(int u){
	tr[u].w = tr[lc].w + tr[rc].w;
}
void build(int u,int l,int r){
	tr[u] = {l,r,w[l]};
	if(l==r){
		return;
	}
	int mid=l+r>>1;
	build(lc,l,mid);
	build(rc,mid+1,r);
	push_up(u);
}
void modify(int u,int x,int v){
	if(tr[u].l > x || tr[u].r < x) return;
	if(tr[u].l==x&&tr[u].r==x){
		tr[u].w = v;
		return;
	}
	modify(lc,x,v);
	modify(rc,x,v);
	push_up(u);
}
int query(int u,int l,int r){
	if(tr[u].l > r || tr[u].r < l) return 0;
	if(tr[u].l >= l && tr[u].r <= r){
		return tr[u].w;
	}
	return query(lc,l,r) + query(rc,l,r);
}
int asksum(int x,int y){
	int res = 0;
	//不在一个重链上
	while(top[x] != top[y]){
		if(dis[top[x]] < dis[top[y]]){
			swap(x,y); //每次操作深度深的那个链
		}
		res += query(1,dfn[top[x]],dfn[x]); //因为下放,所以多跳到上一个链是对的
		x = fa[top[x]]; //多跳到上一个链
	}
	if(dis[x] > dis[y]){
		swap(x,y);//上面的是x,下面的是y;
	}
	res += query(1,dfn[x] + 1,dfn[y]); //因为下放所以+1
	return res;
}

void solve(){
	cin >> n;
	for(int i = 1;i <= n - 1;i++){
		int u,v,w;
		cin >> u >> v >> w;
		bq[i] = {u,v};
		add(u,v,w);
		add(v,u,w);
	}
	cin >> q;
	dfs1(1,0);
	dfs2(1,1);
	build(1,1,n);
	while(q--){
		int op;
		int u,v;
		cin >> op >> u >> v;
		if(op==1){
			int x = bq[u].fi,y = bq[u].se;
			if(dis[x] < dis[y]) swap(x,y);
			modify(1,dfn[x],v);
		}else{
			cout << asksum(u,v) << endl;
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
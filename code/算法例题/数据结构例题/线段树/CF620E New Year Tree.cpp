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
int n,m;
int c[N];
int in[N],out[N];
int d[N];//代表每个节点的值
struct egdes{
	int v,ne;
}e[N << 1];
int h[N],idx = 1;
void add(int u,int v){
	e[++idx] = {v,h[u]},h[u] = idx;
}
int cnt;
void dfs(int u,int f){
	in[u] = ++cnt;
	d[cnt] = c[u];
	for(int i = h[u];i;i=e[i].ne){
		if(e[i].v==f) continue;
		dfs(e[i].v,u);
	}
	out[u] = cnt;
}
struct Tree{
	int l,r,len,val,tag;
}tr[N << 2];
void push_up(int u){
	tr[u].val = tr[lc].val | tr[rc].val;
}
void push_down(int u){
	if(tr[u].tag){
		tr[lc].tag = tr[rc].tag = tr[u].tag;
		tr[lc].val = tr[rc].val = tr[u].tag;
		tr[u].tag = 0;
	}
}
void build(int u,int l,int r){
	tr[u] = {l,r,r-l+1,0,0};
	if(l==r){
		tr[u].val = (1ll << d[l]);
		return;
	}
	int mid = l + r >> 1;
	build(lc,l,mid);
	build(rc,mid+1,r);
	push_up(u);
}
void modify(int u,int l,int r,int x){
	if(tr[u].l > r || tr[u].r < l) return;
	if(tr[u].l >= l && tr[u].r <= r){
		tr[u].val = (1ll << x);
		tr[u].tag = (1ll << x);
		return;
	}
	push_down(u);
	modify(lc,l,r,x);
	modify(rc,l,r,x);
	push_up(u);
}
int query(int u,int l,int r){
	if(tr[u].l > r || tr[u].r < l) return 0;
	if(tr[u].l>=l&&tr[u].r<=r){
		return tr[u].val;
	}
	push_down(u);
	return query(lc,l,r) | query(rc,l,r);
}
void solve(){
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> c[i];
	for(int i = 1;i <= n - 1;i++){
		int u,v;
		cin >> u >> v;
		add(u,v);
		add(v,u);
	}
	dfs(1,0);
	build(1,1,n);
	while(m--){
		int op;
		cin >> op;
		if(op==1){
			int u,x;
			cin >> u >> x;
			modify(1,in[u],out[u],x);
		}else{
			int x;
			cin >> x;
			int p = query(1,in[x],out[x]);
			int d = __builtin_popcountll(p);
			cout << d << endl;
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
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
const int N = 500005;
//倒着操作,操作2直接加,操作一就是直接记录那个节点的答案;
struct edges{
	int v,ne;
}e[N << 1];
int h[N],idx = 1;
int q;
int ans[N];
void add(int u,int v){
	e[++idx] = {v,h[u]};
	h[u] = idx;
}
int in[N],out[N],t;
int d[N];//dfn序
struct Tree{
	int l,r,su,tag;
}tr[N << 1];
void build(int u,int l,int r){
	tr[u] = {l,r,0,0};
	if(l==r){
		return;
	}
	int mid = l + r >> 1;
	build(lc,l,mid);
	build(rc,mid+1,r);
}
void push_down(int u){
	if(tr[u].tag){	
		tr[lc].su+=tr[u].tag;
		tr[rc].su+=tr[u].tag;
		tr[lc].tag+=tr[u].tag;
		tr[rc].tag+=tr[u].tag;
		tr[u].tag = 0;
	}
}
void update(int u,int l,int r,int x){
	if(tr[u].l > r || tr[u].r < l) return;
	if(tr[u].l >= l && tr[u].r <= r){
		tr[u].su+=x;
		tr[u].tag+=x;
		return;
	}
	push_down(u);
	update(lc,l,r,x);
	update(rc,l,r,x);
}
int query(int u,int x){
	if(tr[u].l > x || tr[u].r < x) return -1;
	if(tr[u].l==tr[u].r&&x==tr[u].l){
		return tr[u].su;
	}
	push_down(u);
	int p = query(lc,x);
	if(p==-1) return query(rc,x);
	return p;
}
void dfs(int u){
	in[u] = ++t;
	d[t] = u;
	for(int i=h[u];i;i=e[i].ne){
		int v = e[i].v;
		dfs(v);
	}
	out[u] = t;
}
struct qs{
	int op,x,v;
};
void solve(){
	cin >> q;
	vt<qs> v;
	t = 0;
	idx = 1;
	int node = 1;
	for(int i =1;i<=q;i++) ans[i] = 0,h[i] = 0,in[i]=out[i]=d[i]=0;
	for(int i = 1;i<=q;i++){
		int op;
		cin >> op;
		if(op==1){
			int x;
			cin >> x;
			add(x,++node);
			v.pb({op,node});
		}else{
			int x,val;
			cin >> x >> val;
			v.pb({op,x,val});
		}
	}
	dfs(1);
	build(1,1,node);
	for(int i = q - 1;i >= 0;i--){
		int op = v[i].op;
		if(op==2){
			int x = v[i].x;
			int val = v[i].v;
			update(1,in[x],out[x],val);
		}else{
			int x = v[i].x;
			ans[x] = query(1,in[x]);
		}
	}
	ans[1] = query(1,1);
	for(int i = 1;i <= node;i++){
		cout << ans[i] << " ";
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
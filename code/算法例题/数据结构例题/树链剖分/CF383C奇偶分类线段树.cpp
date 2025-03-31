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
struct Tree{
	int l,r,o,j,po,pj;
}tr[N << 2];
int a[N];
int dep[N],st[N],ed[N],tot,gt[N];
struct edges{
	int v,ne;
}e[N << 1];
int h[N],idx = 1;
void add(int u,int v){
	e[++idx] = {v,h[u]};
	h[u] = idx;
}
void dfs1(int u,int f){
	dep[u] = dep[f] + 1;
	st[u] = ++tot;
	gt[tot] = u;
	for(int i = h[u];i;i=e[i].ne){
		int v = e[i].v;
		if(v== f) continue;
		dfs1(v,u);
	}
	ed[u] = tot;
 }
void build(int u,int l,int r){
	tr[u] = {l,r,0,0,0,0};
	if(l==r) return;
	int mid = l + r >> 1;
	build(lc,l,mid);
	build(rc,mid+1,r);
}
void push_down(int u){
	tr[lc].o += tr[u].po;
	tr[lc].j += tr[u].pj;
	tr[rc].o += tr[u].po;
	tr[rc].j += tr[u].pj;
	tr[rc].po += tr[u].po;
	tr[rc].pj += tr[u].pj;
	tr[lc].po += tr[u].po;
	tr[lc].pj += tr[u].pj;
	tr[u].po = tr[u].pj = 0;
}
void modify(int u,int l,int r,int op,int fuck){
	if(tr[u].l > r || tr[u].r < l) return;
	if(tr[u].l >= l && tr[u].r <= r){
		if(op==1){
			tr[u].j += fuck;
			tr[u].pj += fuck;
			tr[u].o -= fuck;
			tr[u].po -= fuck;
		}else{
			tr[u].j -= fuck;
			tr[u].o += fuck;
			tr[u].po += fuck;
			tr[u].pj -= fuck;
		}
		return;
	}
	push_down(u);
	modify(lc,l,r,op,fuck);
	modify(rc,l,r,op,fuck);
}
int quert(int u,int x){
	if(tr[u].l > x || tr[u].r < x) return -1;
	if(tr[u].l==tr[u].r && tr[u].l==x){
		if(dep[gt[x]]%2){
			return tr[u].j;
		}else{
			return tr[u].o;
		}
	}
	push_down(u);
	int res = quert(lc,x);
	if(res==-1) return quert(rc,x);
	return res;
}

void solve(){
	int n,m;
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	build(1,1,n + 1);
	for(int i = 1;i < n;i++){
		int u,v;
		cin >> u >> v;
		add(u,v);
		add(v,u);
	}	
	dfs1(1,0);
	while(m--){
		int op,x,y;
		cin >> op;
		if(op==1){
			cin >> x >> y;
			if(dep[x]%2){
				modify(1,st[x],ed[x],1,y);
			}else{
				modify(1,st[x],ed[x],2,y);
			}
		}else{
			int x;
			cin >> x;
			cout << quert(1,st[x]) +a[x] << endl;
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
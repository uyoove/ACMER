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
mt19937 rnd(time(0));
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
struct FHQ{
	int ls,rs,key,val,tag,id,sz,tval;
}fhq[N];
int root,tot,T1,T2,T3;
int ad(int v,int id){
	fhq[++tot] = {0,0,rnd(),(1ll << v),0,id,1,(1ll << v)};
	return tot;
}
void push_up(int u){
	fhq[u].val = fhq[fhq[u].ls].val | fhq[fhq[u].rs].val | fhq[u].tval;
	fhq[u].sz = fhq[fhq[u].ls].sz + fhq[fhq[u].rs].sz+1;
}
void push_down(int u){
	if(fhq[u].tag){
		if(fhq[u].ls) fhq[fhq[u].ls].tag = fhq[u].tag,fhq[fhq[u].ls].val = fhq[fhq[u].ls].tval = fhq[u].tag;
		if(fhq[u].rs) fhq[fhq[u].rs].tag = fhq[u].tag,fhq[fhq[u].rs].val = fhq[fhq[u].rs].tval = fhq[u].tag;
		fhq[u].tag = 0;
	}
}
void split(int u,int val,int &x,int &y){
	if(!u){
		x = y = 0;
		return;
	}
	push_down(u);
	int tp = fhq[fhq[u].ls].sz + 1;
	if(tp==val){
		x = u,y = fhq[u].rs;
		fhq[u].rs = 0;
	}
	else if(tp > val){
		y = u;
		split(fhq[u].ls,val,x,fhq[u].ls);
	}else{
		x = u;
		split(fhq[u].rs,val-tp,fhq[u].rs,y);
	}
	push_up(u);
}
int merge(int x,int y){
	if(x)push_down(x);
	if(y)push_down(y);
	if(x==0||y==0) return x+y;
	if(fhq[x].key <= fhq[y].key){
		fhq[y].ls = merge(x,fhq[y].ls);
		push_up(y);
		return y;
	}
	else{
		fhq[x].rs = merge(fhq[x].rs,y);
		push_up(x);
		return x;
	}
}
void insert(int id,int v){
	root = merge(root,ad(v,id));
}
void upd(int l,int r,int v){
	split(root,l - 1,T1,T2);
	split(T2,r - l + 1,T2,T3);
	fhq[T2].val = fhq[T2].tval = fhq[T2].tag = (1ll << v);
	root = merge(T1,merge(T2,T3));
}
int query(int l,int r){
	split(root,l - 1,T1,T2);
	split(T2,r - l + 1,T2,T3);
	int p = fhq[T2].val;
	root = merge(merge(T1,T2),T3);
	
	return p;
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
	for(int i = 1;i <= n;i++) insert(i,d[i]);
	while(m--){
		int op;
		cin >> op;
		if(op==1){
			int u,x;
			cin >> u >> x;
			upd(in[u],out[u],x);
		}else{
			int x;
			cin >> x;
			int p = query(in[x],out[x]);
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
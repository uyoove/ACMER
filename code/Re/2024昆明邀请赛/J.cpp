//最后一舞
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
struct edges{
	int v,ne,op,w;
}e[N << 1];
int dis[N],sy1[N],vis[N];
int h[N],idx = 1;
void add(int u,int v,int op,int w){
	e[++idx] = {v,h[u],op,w};
	h[u] = idx;
}
int n,m,k;
PII p[N];
vt<int> ls[N],v1[N];
struct Ts{
	struct Tree{
		int l,r,val;
	};
	vt<Tree> tr;
	Ts(){}
	Ts(int n){
		tr.resize(n*4 + n);
	}
	void build(int u,int l,int r){
		tr[u]={l,r,0};
		if(l==r) return;
		int mid =l+r>>1;
		build(lc,l,mid);
		build(rc,mid+1,r);
	}
	void insert(int u,int x,int val){
		if(tr[u].l > x || tr[u].r < x) return;
		if(tr[u].l==x && tr[u].r==x){
			tr[u].val = val;
			return;
		}
		insert(lc,x,val),insert(rc,x,val);
		tr[u].val = max(tr[lc].val,tr[rc].val);
	}
	int query(int u,int l,int r){
		if(tr[u].l > r || tr[u].r < l) return 0;
		if(tr[u].l>=l&&tr[u].r<=r){
			return tr[u].val;
		}
		return max(query(lc,l,r),query(rc,l,r));
	}
};

struct nodes{
	int val,v,sy,lx;
	bool operator<(const nodes &n1)const{
		if(val==n1.val) return sy < n1.sy;
		return val > n1.val;
	}
};

void solve(){
	cin >> n >> m >> k;
	idx = 1;
	for(int i = 1;i <= n;i++){
		dis[i]=inf;
		h[i] = 0;
		sy1[i]=0;
		vis[i] = 0;
	}
	for(int i = 1;i <= m;i++){
		ls[i].clear();
		ls[i].pb(0);
		v1[i].clear();
		v1[i].pb(0);
	}
	for(int i =1;i <= m;i++){
		int u,v,op,w;
		cin >> u >> v >> op >> w;
		add(u,v,op,w);
		add(v,u,op,w);
	}
	for(int i = 1;i <= k;i++){
		cin >> p[i].fi >> p[i].se;
		ls[p[i].fi].pb(i);
		v1[p[i].fi].pb(p[i].se);
	}
	vt<Ts> fuck(m + 1);
	for(int i = 1;i <= m;i++){
		if(ls[i].size()){
			fuck[i] = Ts(ls[i].size());
			fuck[i].build(1,1,ls[i].size());
			for(int j = 1;j < v1[i].size();j++){
				fuck[i].insert(1,j,v1[i][j]);
			}
		}
	}
	priority_queue<nodes> pq;
	dis[1] = 1;
	pq.push({0,1,0,0});
	while(pq.size()){
		auto p = pq.top();pq.pop();

		int u = p.v,val = p.val,sy = p.sy,lx=p.lx;
		if(vis[u]) continue;
		vis[u] = 1;
		for(int i = h[u];i;i=e[i].ne){
			int v = e[i].v;
			int op = e[i].op;
			int w = e[i].w;

			if(lx==op&&sy>=w){
				if(vis[v]==0){
					dis[v] = val;
					sy1[v] = sy - w;
					pq.push({dis[v],v,sy-w,lx});
				}
				continue;
			}
			auto it = upper_bound(all(ls[op]),val) - ls[op].begin();
			if(it==ls[op].size()) continue;
			int l = it,r = ls[op].size() - 1,ans = -1,pd = 0;
			if(fuck[op].query(1,l,r) < w) continue;
			while(l<=r){
				int mid=l+r>>1;
				int tp = fuck[op].query(1,l,mid);
				if(tp>=w){
					r = mid - 1;
					ans = mid;
					pd = tp;
				}else{
					l = mid + 1;
				} 
			}
			if(ans==-1) continue;
			
				dis[v] = ls[op][ans];
				sy1[v] = pd-w;
				pq.push({dis[v],v,pd - w,op});
			
		}
	}
	for(int i = 1;i <= n;i++){
		if(vis[i]==1){
			cout <<1;
		}else{
			cout<<0;
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
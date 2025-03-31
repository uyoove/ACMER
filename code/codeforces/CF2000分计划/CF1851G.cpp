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
struct DSU {
    vector<int> f, sz;
    DSU(){}
    DSU(int n) {
        init(n);
    }
    void init(int n) {
        f.resize(n);
        iota(f.begin(), f.end(), 0);
        sz.assign(n, 1);
    }
    int fd(int x) {
        if(f[x]==x) return x;
        return f[x] = fd(f[x]);
    }
    bool same(int x, int y) {
        return fd(x) == fd(y);
    }
    bool mg(int x, int y) {
        x = fd(x);
        y = fd(y);
        if (x == y)return false;
        sz[x] += sz[y];
        f[y] = x;
        return true;
    }
    int size(int x) {
        return sz[fd(x)];
    }
};
int n,m,q;
struct querys{
	int id,u,v,w1;
	bool operator<(const querys &t1)const{
		return w1 < t1.w1;
	}
};
int h[N],idx = 1;
struct edges{
	int v,ne;
}e[N << 1];
void add(int u,int v){
	e[++idx]={v,h[u]},h[u] = idx; 
}
PII a[N];
int vis[N],ans[N];
void solve(){
	cin >> n >> m;
	idx = 1;
	for(int i = 1;i <= n;i++){
		vis[i] = 0,h[i] = 0;
		cin >> a[i].fi;a[i].se = i;
	}
	for(int i = 1;i <= m;i++){
		int u,v;cin>>u>>v;
		add(u,v),add(v,u);
	}
	DSU dsu(n + 1);
	vt<querys> qs;
	cin >> q;
	for(int i = 1;i <= q;i++){
		int u,v,w;
		cin >> u >> v >> w;
		qs.pb({i,u,v,w + a[u].fi});
	}
	sort(all(qs));
	sort(a + 1,a + 1 + n);
	int l = 1;
	for(int i = 0;i < q;i++){
		while(l <= n && a[l].fi <= qs[i].w1){
			vis[a[l].se] = 1;
			int u = a[l].se;
			for(int j = h[u];j;j=e[j].ne){
				int v = e[j].v;
				if(!vis[v])continue;
				dsu.mg(v,u);
			}
			l++;
		} 
		if(dsu.fd(qs[i].u) == dsu.fd(qs[i].v)){
			ans[qs[i].id] = 1;
		}else{
			ans[qs[i].id] = 0;
		}
	}
	for(int i = 1;i <= q;i++){
		if(ans[i]){
			cout << "Yes" << endl;
		}else{
			cout << "No" << endl;
		}
	}
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
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
const int N = 1005;
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
int n,a[N];
int d[N][N];
struct nodes{
	int u,v,val;
	bool operator<(const nodes& t1)const{
		return val < t1.val;
	}
};
int vis[N];
void solve(){
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		vis[i] = inf;
	}
	vt<nodes> v;
	vt<PII> cuc;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			cin >> d[i][j];
			if(i!=j) v.pb({i,j,d[i][j]});
			cuc.pb({i,j});
		}
	}
	if(n==1){
		cout << (a[1]-1)*d[1][1] << endl;
		return;
	}
	DSU dsu(n + 1);
	sort(all(v));

	int res = 0;
	for(auto [u,v,w]:v){
		if(dsu.fd(u)==dsu.fd(v)) continue;
		dsu.mg(u,v);
		
		res+=w;
	}
	for(auto [u,v]:cuc){
		int d1 = (a[u] - 1)*d[u][v],d2 = (a[u]-1)*d[u][u];
		vis[u] = min(d1,min(vis[u],d2));
		d1 = (a[v] - 1)*d[u][v],d2 = (a[v]-1)*d[v][v];
		vis[v] = min(d1,min(vis[v],d2));
	}
	for(int i = 1;i <= n;i++) res+=vis[i];
	cout << res << endl;
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
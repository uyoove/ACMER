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
const int N = 200005;
int n,m,q;
int vis[N];
PII e[N];
int a[N];
struct DSU {
    vector<int> f, sz;
    vt<map<int,int>> hb;
    DSU(){}
    DSU(int n) {
        init(n);
    }
    void init(int n) {
        f.resize(n);
        hb.resize(n);
        iota(f.begin(), f.end(), 0);
        sz.assign(n, 1);
        for(int i = 1;i < n;i++){
        	hb[i][a[i]] = 1;
        }
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
        if(sz[x] > sz[y]){
        	sz[x] += sz[y];
        	f[y] = x;
        	for(auto &[k,v]:hb[y]){
        		hb[x][k]+=v;
        	}
        }else{
        	sz[y] += sz[x];
        	f[x] = y;
        	for(auto &[k,v]:hb[x]){
        		hb[y][k]+=v;
        	}
        }
        return true;
    }
    int size(int x) {
        return sz[fd(x)];
    }
};
struct query{
	int op,l,r;
}q1[N];
void solve(){
	cin >> n >> m >> q;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	DSU dsu(n + 1);
	for(int i = 1;i <= m;i++) cin >> e[i].fi >> e[i].se;
	for(int i = 1;i <= q;i++){
		cin >> q1[i].op >> q1[i].l;
		if(q1[i].op==2) cin >> q1[i].r;
		else vis[q1[i].l] = 1;
	}
	for(int i = 1;i<=m;i++){
		if(!vis[i]){
			dsu.mg(e[i].fi,e[i].se);
		}
	}
	vt<int> ans;
	for(int i = q;i>=1;i--){
		if(q1[i].op==1){
			vis[q1[i].l] = 0;
			dsu.mg(e[q1[i].l].fi,e[q1[i].l].se);
		}else{
			int d = q1[i].r - a[q1[i].l];
			int t = dsu.hb[dsu.fd(q1[i].l)][d];
			if(d == a[q1[i].l]) t--;
			ans.pb(t);
		}
	}
	reverse(all(ans));
	for(auto p:ans){
		cout << p << endl;
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
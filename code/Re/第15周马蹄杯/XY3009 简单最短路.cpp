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
struct edges{
	int u,v,w;
}e[N];
int n,m,q;
struct DSU {
    vector<int> f, sz;
    vector<multiset<int>> se;
    DSU(){}
    DSU(int n) {
        init(n);
    }
    void init(int n) {
        f.resize(n);
        se.resize(n);
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
        if(se[x].size() > se[y].size()){
        	sz[x] += sz[y];
        	f[y] = x;
        	for(auto &p:se[y]) se[x].insert(p);
        }else{
        	sz[y] += sz[x];
        	f[x] = y;
        	for(auto &p:se[x]) se[y].insert(p);
        }
        
        return true;
    }
    int size(int x) {
        return sz[fd(x)];
    }
};
void solve(){
	cin >> n >> m;
	DSU dsu(n + 1);
	for(int i = 1;i <= m;i++){
		int u,v,w;
		cin >> u >> v >> w;
		dsu.se[dsu.fd(u)].insert(w);
		if(dsu.fd(u)!=dsu.fd(v)){
			dsu.mg(u,v);
		}
	}
	cin >> q;
	while(q--){
		int u,v;
		cin >> u >> v;
		if(dsu.fd(u)!=dsu.fd(v) || dsu.se[dsu.fd(u)].size() < 3){
			cout << -1 << endl;
		}else{
			int a[3];
			int p = 0;
			for(auto &val:dsu.se[dsu.fd(u)]){
				a[p] = val;
				p++;
				if(p==3) break;
			}
			int ans = a[0]*a[1] + a[1]*a[2] +a[2]*a[0];
			cout << ans << endl;
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
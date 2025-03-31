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
int n,m;
int mod = 998244353;
int ksm(int x,int n){
	int res = 1;
	while(n){
		if(n&1) res = res*x%mod;
		x=x*x%mod;
		n >>= 1;
	}
	return res;
}
struct nodes{
	int u,v,w;
	bool operator<(const nodes &t1)const{
		return w < t1.w;
	}
};
void solve(){
	cin >> n >> m;
	DSU dsu(n + 1);
	int ans = 1;
	vt<nodes> v1;
	for(int i = 1;i <= n - 1;i++){
		int u,v,w;
		cin >> u >> v >> w;
		v1.pb({u,v,w});
	}
	sort(all(v1));
	for(int i = 1;i <= n-1;i++){
		auto &[u,v,w] = v1[i - 1];
		if(dsu.fd(u)==dsu.fd(v)) continue;
		int sz1 = dsu.size(u),sz2 = dsu.size(v);
		dsu.mg(u,v);
		ans*=ksm(m - w + 1,sz2 * sz1 - 1); //+1是因为可以不选
		ans%=mod;
	}
	cout << ans <<endl;
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
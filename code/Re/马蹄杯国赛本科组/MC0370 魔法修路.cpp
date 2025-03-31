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
struct nodes{
	int id;
	vt<int> v;
	bool operator<(const nodes& t1)const{
		return id < t1.id;
	}
};
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
}d[600],t,t2;
struct edges{
	int u,v,w;
	bool operator<(const edges& t1)const{
		return w < t1.w;
	} 
};
vt<edges> v,v2;
int n,m,q;
bool check(DSU dt,vt<int>& tb){
	for(int i = 0;i < tb.size() - 1;i++){
		if(dt.fd(tb[i]) != dt.fd(tb[i+1])){
			return 0;
		}
	}
	return 1; 
}
int df(int len,vt<int>& tb){
	int l = 1,r = len,ans = len;
	while(l<=r){
		int mid = l + r >> 1;
		if(check(d[mid],tb)){
			ans = mid;
			r = mid - 1;
		}else{
			l = mid + 1;
		}
	}
	return ans;
}
void solve(){
	cin >> n >> m >> q;
	for(int i = 0;i < 600;i++) d[i].init(n + 1);
	t.init(n + 1);
	t2.init(n + 1);
	for(int i = 1;i <= m;i++){
		edges ep;
		cin >> ep.u >> ep.v >> ep.w;
		v.pb(ep);
	}
	sort(all(v));
	for(int i = 0;i < m;i++){
		if(t2.mg(v[i].u,v[i].v)){
			v2.pb(v[i]);
		}
	}
	// for(auto [u,v,w]:v2){
	// 	cout << u << " " << v << " " << w << endl;
	// }
	m = v2.size();
	int sz = sqrt(m);
	int len = m/sz + (m%sz==0 ? 0 : 1);
	for(int i = 1;i <= m;i++){
		t.mg(v2[i-1].u,v2[i-1].v);
		if(i%sz==0){
			d[i/sz] = t;
		}
	}
	if(m%sz!=0) d[len] = t;
	while(q--){
		int l,r,p,c;
		cin >> l >> r >> p >> c;
		vt<int> tb;
		int i = (l/p)*p + c;
		if(i < l) i+=p;
		for(;i<=r;i+=p){
			tb.pb(i);
		}
		int x = df(len,tb) - 1;
		DSU tp = d[x];
		for(int i = x*(sz) + 1;i <= m;i++){
			int w = v2[i - 1].w;
			tp.mg(v2[i-1].u,v2[i-1].v);
			if(check(tp,tb)){
				cout << w << endl;
				break;
			}
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
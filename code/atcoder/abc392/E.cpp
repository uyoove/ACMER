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
    vt<vt<int>> v;
    DSU(){}
    DSU(int n) {
        init(n);
    }
    void init(int n) {
        f.resize(n);
        iota(f.begin(), f.end(), 0);
        sz.assign(n, 1);
        v.resize(n + 1);
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
        if(v[x].size() < v[y].size()){
        	 sz[y] += sz[x];
        	 f[x] = y;
        	 for(auto &p:v[x]) v[y].pb(p);
        }else{
        	sz[x] += sz[y];
        	 f[y] = x;
        	 for(auto &p:v[y]) v[x].pb(p);
        }
       
        return true;
    }
    int size(int x) {
        return sz[fd(x)];
    }
};
int n,m;
PII x[N];
struct nodes{
	int id,val;
	bool operator<(const nodes &t1)const{
		return val < t1.val; 
	}
};
struct re{
	int id,u,v;
};
void solve(){
	cin >> n >> m;
	DSU dsu(N);
	for(int i = 1;i <= m;i++){
		int u,v;
		cin >> u >> v;
		if(dsu.fd(u) == dsu.fd(v)){
			dsu.v[dsu.fd(u)].pb(i);
		}else{
			dsu.mg(u,v);
		}
		x[i] = {u,v};
	}
	vt<int> v;
	for(int i = 1;i <= n;i++){
		v.pb(dsu.fd(i));
	}
	sort(v.begin(),v.end());
	v.erase(unique(all(v)),v.end());
	multiset<nodes> mul;
	for(auto p:v){
		mul.insert({p,dsu.v[p].size()});
	}
	vt<re> res;
	while(mul.size()){
		auto it = mul.end();
		it--;
		int u = it->id;
		int d = it->val; 
		mul.erase(it);
		while(mul.size() && d > 1){
			auto it = mul.begin();
			int p = it->id;
			mul.erase(it);
			int u1 = x[dsu.v[u][d - 1]].fi;
			res.pb({dsu.v[u][d - 1],u1,p});
			d--;
		}
		if(d >= 1 && mul.size()){
			it = mul.end();
			it--;
			int u1 = it->id;
			int d1 = it->val;
			int u2 = x[dsu.v[u][d - 1]].fi;
			res.pb({dsu.v[u][d - 1],u2,u1});
		}
		
	}
	cout << res.size() <<endl;
	for(auto p:res){
		cout << p.id << " " << p.u << " " << p.v << endl;
	}

}

signed main(){
	int times = 1;
	std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
	//cin >> times;
	while(times--){
		solve();
	}
	return 0;
}
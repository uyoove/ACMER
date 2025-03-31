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
#define eps 1e-10
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
const int N = 300005;
int n,m;
int u[N],v[N],b[N],c[N];
struct egdes{
	int v,ne;
	double b,c;
}e[N << 1];
int h[N];
int idx = 1;
void add(int u,int v,double b,double c){
	e[++idx] = {v,h[u],b,c};
	h[u] = idx;
}
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
double f[N]; //表示到某个点的最大权值
bool check(double x){
	idx = 0;
	for(int i = 1;i <= n;i++) f[i] = -infi,h[i] = 0;
	for(int i = 1;i <= m;i++){
		add(u[i],v[i],(b[i]*1.0 - c[i]*x),0);
	}
	f[1] = 0;
	for(int i = 1;i <= n;i++){
		for(int j = h[i];j;j=e[j].ne){
			int v = e[j].v;
			f[v] = max(f[v],f[i] + e[j].b);
		}
	}
	return f[n] >= 0;
}
void solve(){
	cin >> n >> m;
	for(int i = 1;i <= m;i++){
		
		cin >> u[i] >> v[i] >> b[i] >> c[i];
	
	}
	double l = 0,r = 1e6,ans = -1;
	double res = 0;
	while(r - l > eps){
		double mid =( l + r )/2;
		if(check(mid)){
			l = mid;
			ans = mid;
		}else{
			r = mid;
			
		}
	}
	printf("%.11lf\n",ans);
}

signed main(){
	int times = 1;
	//cin >> times;
	while(times--){
		solve();
	}
	return 0;
}
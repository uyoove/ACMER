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
const int N = 300005;
const int mod = 1e9 + 7;
int fac[N];

int pw(int x,int n){
	int res = 1;
	while(n){
		if(n&1) res = res * x % mod;
		x = x * x %mod;
		n >>= 1;
	}
	return res;
}
vt<int> e[N];
int n,r;
int cnt1 = 0,cnt2 = 0; // 父节点比当前大的数量, 小于等于的数量
int fk[N];
void add(int k,int op){
	for(int i = k;i < N;i+=(i&-i)) fk[i]+=op;
}
int query(int u){
	int res = 0;
	for(int i = u;i > 0;i-=(i&-i)) res+=fk[i];
	return res;
}
int f[N]; //dfs序方案树
void dfs(int u,int fa){
	f[u] = 1;
	add(u,1);
	for(int v:e[u]){
		if(v==fa) continue;
		cnt1 = (cnt1 + query(n) - query(v) + mod) % mod;
		cnt2 = (cnt2 + query(v))% mod;
		dfs(v,u);
		f[u] = f[u] * f[v]%mod;
	}
	add(u,-1);
	int tmp = (u==r ? e[u].size() : e[u].size() - 1);
	f[u] = f[u] * fac[tmp]%mod;
}
void solve(){
	cin >> n >> r;
	fac[0] = 1;
	for(int i = 1;i < n;i++){
		int u,v;
		cin >> u >> v;
		e[u].pb(v);
		e[v].pb(u);
		fac[i] = fac[i - 1] * i%mod;
	}
	fac[n] = fac[n - 1] * n % mod;
	dfs(r,0);
	int t1 = (((n * (n-1))%mod*pw(2,mod-2)%mod-cnt1-cnt2)%mod+mod)%mod;
	int ans = f[r] *(cnt1 + t1 * pw(2,mod-2)%mod)%mod;
	cout << ans << endl;
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
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
const int mod = 1e9 + 7;
int n,m;
struct edges{
	int u,v;
}e[N];
vt<int> tb[N];
int d[N],pre[N]; //入度,上一个被指向的点
int ans = 0;
ll powerMod(ll x, ll n, ll mod){ //快速幂
    ll ans = 1;
    while (n > 0){
        if  (n & 1)
            ans = (ans * x) % mod;
        x = (x * x) % mod;
        n >>= 1;
    }
    return ans;
}
void solve(){
	cin >> n >> m;
	for(int i = 1;i <= m;i++){
		cin >> e[i].u >> e[i].v;
		d[e[i].u]++;
		d[e[i].v]++;
	}
	//三芒星个数
	for(int i = 1;i <= n;i++) if(d[i]>=3) ans += (d[i] * (d[i]-1)%mod * (d[i] - 2))%mod * powerMod(6,mod-2,mod)%mod,ans%=mod;
	for(int i = 1;i <= m;i++){
		ans += (d[e[i].u]-1) * (d[e[i].v]-1); //折线 + 三角形个数
		if(d[e[i].u] > d[e[i].v] || (d[e[i].u] == d[e[i].v] && e[i].u > e[i].v)) swap(e[i].u,e[i].v);
		tb[e[i].u].pb(e[i].v);
	}	
	for(int i = 1;i <= n;i++){
		for(auto p:tb[i]) pre[p] = i; //从i出发,上一个节点一定是i
		for(int u:tb[i]){
			for(int v:tb[u]){
				ans = (ans - 2*(pre[v]==i))%mod;
			}
		}
	}
	cout << (ans + mod)%mod << endl;
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
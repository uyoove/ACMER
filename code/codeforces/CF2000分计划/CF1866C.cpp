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
int mod = 998244353;
vector<PII> e[N];
int n;
int cnt[N][2];
int vis[N];
int dp[N];
void dfs(int u){
	vis[u] = 1;
	for(auto &[v,w]:e[u]){
		if(w==0) dp[u] = (dp[u] + cnt[u][1])%mod;
		//还没算过贡献的算一下
		cnt[u][w]++;
		if(!vis[v]) dfs(v);
		dp[u] = ((dp[u] + dp[v])%mod + cnt[v][0] * cnt[u][1]%mod)%mod;
		for(int i = 0;i<=1;i++){
			cnt[u][i] += cnt[v][i];
			cnt[u][i]%=mod;
		}
	}
}
void solve(){
	cin >> n;
	for(int i = 1;i <= n;i++){
		int k;
		cin >> k;
		while(k--){
			int t,val;
			cin >> t >> val;
			e[i].pb({t,val});
		}
	}
	dfs(1);
	cout << dp[1] <<endl;
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
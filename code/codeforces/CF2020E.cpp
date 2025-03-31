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
const ll inf = 0x3f3f3f3f3f3f3f3fLL;
const int infi = 0x3f3f3f3f;
const int P = 13331;
const int N = 200005;
const int MOD = 1e9 +7;
int ksm(int x,int n,int mod){
	int res = 1;
	while(n){
		if(n & 1) res = res * x%mod;
		x = x*x%mod;
		n>>=1;
	}
	return res;
}
void solve(){
	int n;
	cin >> n;
	int a[n + 1];
	int dp[2][1026];
	memset(dp,0,sizeof dp);
	for(int i = 1;i<=n;i++) cin >> a[i];
	dp[0][0] = 1;
	int id = 1;
	for(int i = 1;i <= n;i++){
		int p;
		cin >> p;
		int inv = ksm(10000,MOD-2,MOD);
		for(int j = 0; j < 1024;j++) {
			dp[id][j] = 0;
		}
		for(int j = 0;j <= 1023;j++){
			dp[id][j] = (dp[id][j] + (10000 - p) * dp[id ^ 1][j]%MOD)%MOD;
			dp[id][j] = (dp[id][j] +  p * dp[id ^ 1][j ^ a[i]]%MOD)%MOD;
		}
		for(int j = 0; j < 1024;j++) {
			dp[id][j] = dp[id][j] * inv % MOD;
		}
		id^=1;
	}
	int res = 0;
	for(int i = 0;i < 1024;i++){
		int p = i * i% MOD;
		res = (res + p * dp[id^1][i]%MOD)%MOD;
	}
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
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
const int N = 300005;
int n,a[N];
int dp[N][2];
void solve(){
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> a[i];
	int mi = 1e18;
	int ans1 = a[n];
	for(int i = 1;i <= n - 1;i++){
		dp[i][1] = min(dp[i-1][1],dp[i-1][0]) + a[i];
		dp[i][0] = dp[i - 1][1]; 
	}
	ans1+=min(dp[n-1][1],dp[n-1][0]);
	int ans2 = 0;
	memset(dp,0,sizeof dp);
	dp[1][1] = a[1];
	dp[1][0] = inf;
	for(int i = 2;i <= n;i++){
		dp[i][1] = min(dp[i-1][1],dp[i-1][0]) + a[i];
		dp[i][0] = dp[i - 1][1]; 
	}
	ans2=min(dp[n][1],dp[n][0]);
	cout << min(ans1,ans2) << endl;

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
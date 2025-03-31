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
const ll inf = 0x3f3f3f3f3f3f3f3fLL;
const int infi = 0x3f3f3f3f;
const int P = 13331;
const int N = 200005;
int n;
int d[200];
int dp[101][1001]; //表示前i个部分我用了k个tp1类型,最少需要多少个tp2
void solve(){
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> d[i];
	int l1,c1,k1,l2,c2,k2;
	cin >> l1 >> c1 >> k1 >> l2 >> c2 >> k2;
	memset(dp,0x3f,sizeof dp);
	dp[0][0] = 0;
	for(int i = 1;i <= n;i++){
		for(int j = 0;j <= k1;j++){
			for(int k = 0;k <= j;k++){
				dp[i][j] = min(dp[i][j],dp[i - 1][j - k] + (max(d[i] - l1 * k,0ll) + l2 - 1)/ l2);
			}
			
		}
	}
	int ans = 1e18;
	for(int j = 0;j <= k1;j++){
		if(dp[n][j] <= k2){
			ans = min(dp[n][j] * c2 + j * c1,ans);
		}
	}
	if(ans==1e18){
		cout << -1 << endl;
		return;
	}
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
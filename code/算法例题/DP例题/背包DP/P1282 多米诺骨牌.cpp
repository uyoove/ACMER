//和爸爸一起学编程真好,不过要小学四年级分流考试了,最近没时间写代码了,呜呜呜
#include<bits/stdc++.h>
using namespace std;
#define out(x) cout << #x << '=' << (x) << endl
#define out2(x, y) cout << #x << '=' << (x) << ',' << #y << '=' << (y) << endl 
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
int n;
int dp[1010][6010]; //前i个物品凑出j的数值的最小交换
int x[1001],y[1001];
void solve(){
	cin >> n;
	int su = 0;
	for(int i = 1;i <= n;i++){
		cin >> x[i] >> y[i];
		su+=x[i]+y[i];
	}
	for(int i = 0;i <= n;i++){
		for(int j = 0;j <= 6000;j++) dp[i][j] = infi;
	}
	dp[0][0] = 0;
	for(int i = 1;i <= n;i++){
		for(int j = 0;j <= 6*n;j++){
			//默认选第一组,选第二组就得+一次交换
			if(j-x[i]>=0)dp[i][j] = min(dp[i][j],dp[i - 1][j - x[i]]);
			if(j-y[i]>=0)dp[i][j] = min(dp[i][j],dp[i - 1][j - y[i]] + 1);
		}
	}
	int mi = 0x3f3f3f3f;
	int ans = 0x3f3f3f3f;
	for(int j = 0;j<=su;j++){
		if(dp[n][j] == infi) continue;
		if(abs(j - (su - j)) <= mi){
			if(abs(j - (su - j)) == mi) ans = min(dp[n][j],ans);
			else ans = dp[n][j];
			mi = abs(j - (su - j));
			//cout << j  << " " << dp[n][j] << " " <<mi<< endlans
		}
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
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 300;
// dp[i][j] 前i个元素在j这个位置为1的个数
void solve(){
	int n,m;
	cin >> n >> m;
	int dp[n + 1][m + 1];
	memset(dp,0,sizeof dp);
	for(int i = 1;i <= n;i++){
		string s;
		cin >> s;
		s = " " + s;
		for(int j = 1;j<=m;j++){
			dp[i][j]=dp[i-1][j]; 
			if(s[j]=='1'){
				if(!dp[i][j]) dp[i][j] = 1;
				else dp[i][j] += dp[i-1][j]; 
			}
			if(s[m - j + 1]=='1'){
				if(!dp[i-1][j]){
					if(!dp[i][j])dp[i][j] = 1;
					else dp[i][j] = 1;
				}
				else dp[i][j] += dp[i-1][j]; 
			}

		}
		// for(int j = 1;j <= m;j++){
		// 	cout << dp[i][j] << " ";
		// }
		// cout << endl;

	}
	int p = pow(2,n);
	int t = 1;
	for(int j = 1;j <= m;j++){
		//cout << dp[n][j] << endl;
		t*=dp[n][j];
	}
	cout << p- t << endl;
}
signed main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}
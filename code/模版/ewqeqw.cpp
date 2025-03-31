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
//int dp[4][2];表示该位置向上,向下转换到指定位置的最小
int ans;
string s, t;
int dp[5][11][11];//表示我这个位置向上j位向下k位的最小数
//
int pb1(int x,int y){
	int xyxs = 0;

	if(x >= y){
		xyxs = x - y; 
	}else{
		xyxs = 10 - (y) + (x);
	}
	int xyxx = 0;
	if(x <= y){
		xyxx = y - x; 
	}else{
		xyxx = 10 - (x) + (y);
	}
	return min(xyxx,xyxs);
}
void solve(){
	
	cin >> s >> t;
	s = " " + s,t = " " + t;
	ans = 0x3f3f3f3f;
	memset(dp,0x3f,sizeof dp);
	for(int k = 0; k <= 4;k++){
		for(int i = 0;i <= 10;i++){
		for(int j = 0;j <= 10;j++){
			dp[k][i][j] = inf;
		}
	}
	}
	
	dp[0][0][0] = 0;

	for(int i = 1;i <= 4;i++){
		int xyxs = 0;
		if(t[i] >= s[i]){
			xyxs = t[i] - s[i]; 
		}else{
			xyxs = 10 - (s[i] - '0') + (t[i] - '0');
		}
		int xyxx = 0;
		if(t[i] <= s[i]){
			xyxx = s[i] - t[i]; 
		}else{
			xyxx = 10 - (t[i] - '0') + (s[i] - '0');
		}
		//cout << xs << endl;
		for(int j = 0;j <= 10;j++){
			for(int k = 0;k <= 10;k++){
				if(j-k == xyxs || j-k == xyxx) {
					for(int t1 = 0;t1 <= 10;t1++){
						for(int t2 = 0;t2 <= 10;t2++){
							//if(t1==t2) continue;
							dp[i][j][k] = min(dp[i][j][k],dp[i - 1][t1][t2] + pb1(j,k));
							dp[i][j][k] = min(dp[i][j][k],dp[i - 1][t1][t2] + pb1(j,k));
						}
					}
				}
			}
		}
	}
	for(int i = 0;i <= 10;i++){
	 	for(int j = 0;j <= 10;j++){
	 		//cout << dp[4][i][j] << " ";
	 		ans=min(ans,dp[4][i][j]);
	 	}
	 	//cout << endl;
	}
	cout << ans << endl;
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
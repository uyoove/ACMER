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

void solve(){
	int x,y,z;
	cin >> x >> y >> z;
	string s;
	cin >> s;
	int n = s.size();
	s = " " + s;
	int dp[n + 1][2];
	memset(dp,0x3f,sizeof dp);
	dp[0][0] = 0;
	for(int i = 1;i <= n;i++){
		if(s[i]=='a'){
			dp[i][0] = min(dp[i - 1][0] + x,min(dp[i - 1][1]+z+x,dp[i-1][1]+y+z));
			dp[i][1] = min(min(dp[i - 1][0] + x + z,dp[i-1][0] + z + y),dp[i - 1][1]+ y);
		}else{
			dp[i][1] = min(dp[i - 1][1] + x,min(dp[i - 1][0]+z+x,dp[i-1][0]+y+z));
			dp[i][0] = min(min(dp[i - 1][1] + x + z,dp[i-1][1] + z + y),dp[i - 1][0]+ y);
		}
	}
	cout << min(dp[n][0],dp[n][1]) << endl;
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
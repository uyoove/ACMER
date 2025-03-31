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
int n;
int a[N];
int dp[N][40]; //表示每一位的最长符合条件长度
void solve(){
	cin >> n;
	memset(dp,0,sizeof dp);
	for(int i = 1;i <= n;i++) cin >> a[i];
	int ans = 0;
	for(int i = 1;i <= n;i++){
		int mx = 1;
		for(int j = 0;j < 31;j++){
			if(a[i] & (1ll << j)){
				mx = max(dp[i - 1][j] + 1,mx); 
			}
		}
		for(int j = 0;j < 31;j++){
			if(a[i] & (1ll << j)){
				dp[i][j] = max(mx,dp[i][j]);	//通过a[i]将多个状态增大成dp[i-1]位置位置的最多的长度的那个位		
			}else{
				dp[i][j] = dp[i - 1][j];
			}
		}
		ans=max(ans,mx);
	}
	cout << ans;
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
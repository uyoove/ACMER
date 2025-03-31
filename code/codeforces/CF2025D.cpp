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
const int N = 2000005;
int n,m;
int a[N];
//因为我们每次的0的个数是单调不减的 所以,我们上一次选择的最佳情况可以推广到后面
//为什么呢,考虑越前面的0越有用(自行体会证明)
//那么前面保证最优现在的选择是不会影响前面已经被选的数,(无后效性)
//转移思考如下:
//我可以智力此次比上次多1 dp[i][j] = max(dp[i][j],dp[i][j - 1] + cnt[i][j] + cnt[i - j]);  上一次 dp[i-1][j - 1]: 智力j - 1,力量 i - 1 - (j - 1) = i - j 这次cnt[j]就是加了一次智力,力量不变
//我可以力量比上次多1 dp[i][j] = max(dp[i][j],dp[i][j] + cnt[i][j] + cnt[i - j]); 上一次 i-j比i-1-j大1 dp[i-1][j] : 智力j,力量i-1-j; 这次cnt[j]就是智力不变,力量增加

void solve(){
	cin >> n >> m;
	vector<vector<int>> cnt1(m + 2,vector<int> (m+2)); //当前i个0选j个0可对后面多少check产生智力贡献
	vector<vector<int>> cnt2(m + 2,vector<int> (m+2)); //当前i个0选j个0可对后面多少check产生力量贡献
	for(int i = 1;i<=n;i++) cin >> a[i];
	int len = 0;
	for(int i = 1;i <= n;i++){
		if(!a[i]) ++len;
		if(a[i] > 0 && a[i] <= len){
			cnt1[len][a[i]]++;
		}else if(a[i] < 0 && abs(a[i]) <= len){
			cnt2[len][abs(a[i])]++;
		}
	}
	//做个前缀和 表示第i次 j个0最多能选多少个check
	for(int i = 1;i <= len;i++){
		for(int j = 1;j <= i;j++){
			cnt1[i][j] += cnt1[i][j - 1]; 
			cnt2[i][j] += cnt2[i][j - 1];
		}
	}
	int mx = 0;
	vector<vector<int>> dp(m + 2,vector<int> (m + 2)); // 代表我第i个0选择增加j个智力,i-j个力量获取的最大收益
	
	for(int i = 1;i <= len;i++){
		for(int j = 0;j <= i;j++){
			dp[i][j] = max(dp[i][j],dp[i - 1][j] + cnt1[i][j] + cnt2[i][i-j]);
			if(j > 0){
				dp[i][j] = max(dp[i][j],dp[i - 1][j - 1] + cnt1[i][j] + cnt2[i][i-j]);
			}
			mx = max(mx,dp[i][j]);
		}
	}
	cout << mx;
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
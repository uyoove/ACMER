//最后一舞
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
//二分答案 表示至少有k个元素大于等于mid值
//然后check 里面最优解k个元素的最小花费 dfs(pos,last,k); 表示 第i个位置作为第k个位置上一个位置是last时候的最小花费
//dp[n][k] //表示第i个位置作为k时候的最小花费,last - i之间的前缀必须大于mid,并且last有k-1的值;
//如果没有那么前面的也就没有
int n,m,k;
int pre[N];
int dp[N][6];
int mi[N][6];
string s;
bool check(int x){
	for(int i = 0;i <= n;i++){
		dp[i][0] = 0;
		mi[i][0] = 0;
		for(int j = 1;j <= k;j++){
			dp[i][j] = inf;
			mi[i][j] = inf;
		}
	}
	int res = inf;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= k;j++){
			//保证i-k的位置一定是0
			if(i - j * x < 0) continue;
			if(s[i-x]=='1') continue;
			int d = x - (pre[i] - pre[i - x]);
			dp[i][j] = min(mi[max(i-x-1,0ll)][j - 1] + d,dp[i][j]);
			mi[i][j] = min(mi[i][j],dp[i][j]);
			if(j==k) res=min(res,dp[i][j]);
			//cout << x << " " << i << " " << j << " " << dp[i][j] << endl;
		}
		for(int j = 1;j<=k;j++) mi[i][j]= min(mi[i - 1][j],mi[i][j]);

	}
	
	return res <= m;
}
//12 3 3
//100100010011
void solve(){
	cin >> n >> m >> k;
	
	cin >> s;
	s = " " + s;
	for(int i = 1;i <= n;i++){
		pre[i] = pre[i - 1] + (s[i]=='1');
	}
	int l = 1,r = n,ans = -1;
	while(l <= r){
		int mid = (l + r) >> 1;
		if(check(mid)){
			l = mid + 1;
			ans = mid;
		}else{
			r=  mid - 1;
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
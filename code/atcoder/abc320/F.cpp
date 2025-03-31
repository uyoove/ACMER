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
const int N = 200005;
int x[N],p[N],f[N],dp[320][320][320];//表示,从i出发到n再到i的最小消耗
void solve(){
	int n,h;
	cin >> n >> h;
	memset(dp,0x3f,sizeof dp);
	for(int i = 1;i <= n;i++) cin >> x[i];
	for(int i = 1;i < n;i++) cin >> p[i] >> f[i];
	for(int i = 0;i<= h;i++) dp[n][i][i] = 0;
	for(int i = n - 1;~i;i--){
		for(int j = 0;j <= h;j++){
			for(int k = 0;k <= h;k++){
				int dis = x[i + 1] - x[i];
				if(j + dis > h) continue; //j + dis,表示转移到当前j需要j + dis的油量
				if(k < dis) continue;
				int tp = dp[i + 1][j][k]; //后面一个坐标
				//都不加油
				dp[i][j + dis][k - dis] = min(dp[i][j + dis][k - dis],tp);
				//来时油
				dp[i][max(j + dis - f[i],0ll)][k - dis] = min(dp[i][max(j + dis - f[i],0ll)][k - dis],tp + p[i]);
				//去时油;
				dp[i][j + dis][min(k - dis + f[i],h)] = min(dp[i][j + dis][min(k - dis + f[i],h)],tp + p[i]);
			}
		}
		//舍去一些油
		for(int j = 1;j <= h;j++){
			for(int k = h;k;k--){
				dp[i][j][k] = min(min(dp[i][j][k],dp[i][j][k + 1]),min(dp[i][j - 1][k + 1],dp[i][j - 1][k]));
			}
		}
	} 
	int ans = inf;
	for(int i = 0;i <= h;i++) ans = min(ans,dp[0][h][i]);
	if(ans==inf) cout << -1 <<endl;
	else{
		cout << ans << endl;
	}
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
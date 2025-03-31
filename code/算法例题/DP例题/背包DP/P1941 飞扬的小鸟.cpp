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
const int M = 1010;
const int N = 10005;
//考虑条件: 高度,时间,点击次数
//要求最少点击次数 最多通过数
//dp[i][j] 表示在i这个位置,到j这个高度,至少需要多少点击次数
//每个位置赋予上下限
int hight[N],low[N];
struct edges{
	int x,y;
}e[N];
int n,m,k;
int ps[N];
int dp[N][2005];
void solve(){
	cin >> n >> m >> k;
	
	memset(dp,0x3f,sizeof dp);
	for(int i = 1;i<=n;i++){
		hight[i] =0x3f3f3f3f;
	}
	for(int i = 1;i <= n;i++){
		cin >> e[i].x >> e[i].y;
	}
	for(int i = 1;i <= k;i++){
		int p,x,y;
		cin >>p >> x >> y;
		low[p] = x;
		hight[p] = y;
		ps[p] = 1;
	}
	for(int j = 1;j <= m;j++) dp[0][j] = 0;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m + e[i].x;j++){
			if(j-e[i].x>0){
				dp[i][j] = min(dp[i - 1][j - e[i].x] + 1,dp[i][j - e[i].x] + 1);
			}
			
			//cout << i << " " << j << " " << dp[i][j] <<endl;
		}
		//不能和上面写一个循环内,因为上面的会从本层转移
		for(int j = 1;j <= m + e[i].x;j++){
		
			if(j + e[i].y <= m){
				dp[i][j] = min(dp[i - 1][min(j + e[i].y,m)],dp[i][j]);
			}
			//cout << i << " " << j << " " << dp[i][j] <<endl;
		}
		for(int j = m + 1;j <= e[i].x+m;j++){
			dp[i][m] = min(dp[i][m],dp[i][j]);
		}
		for(int j = 1;j <= low[i];j++){
			dp[i][j] = infi;
		}
		for(int j = hight[i];j <= m;j++){
			dp[i][j] = infi;
		}
		//cout << endl;
	}
	
	int mi = 0x3f3f3f3f;
	for(int i = 1;i<=m;i++){
		mi = min(mi,dp[n][i]);
	}
	if(mi>=0x3f3f3f3f){
		int i,j;
		for (i=n;i>=1;i--){
			for (j=1;j<=m;j++)
				if (dp[i][j]<0x3f3f3f) break;
			if (j<=m) break;
		}
		int ans=0;
		for (j=1;j<=i;j++)
		if (ps[j]) ans++;
		cout << 0 << endl;
		cout << ans << endl;
		return;
	}
	
	cout << 1 << endl;
	cout << mi << endl;
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
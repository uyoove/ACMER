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
const int N = 1005;
map<PII,int> mp;
int n,m;
int grid[N][N],dp[N][N],vis[N][N],ps[N][N];
int mx = grid[1][1];
struct Nodes
{
	int r,c,val,op;
};
int res = 0;
void solve(){
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			cin>>grid[i][j];
		}
	}
	int q1;
	cin >> q1;
	while(q1--){
		int u,v,t;
		cin >> u >> v >> t;
		vis[u][v] = t;
	}
	for(int i = 1;i <= m;i++) ps[0][i] = 1;
	for(int i = 1;i <= n;i++) ps[i][0] = 1;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			if(i==1&&j==1){
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]) + grid[i][j];
				res = max(res,dp[i][j]);
				continue;
			}
			if(i + j - 2 >= vis[i][j] && vis[i][j]){
				ps[i][j] = 1;
				continue;
			}
			if(ps[i-1][j]==1&&ps[i][j-1]==1){
				ps[i][j] = 1;
				continue;
			}
			dp[i][j] = max(dp[i-1][j],dp[i][j-1]) + grid[i][j];
			res = max(res,dp[i][j]);
		}
	}
	cout << res << endl;
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
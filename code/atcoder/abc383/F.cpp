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
//dp[i][j] 表示前i个颜色使用j的钱的最大收益
int dp[510][50010];
vt<PII> a[N];
int n,x,k;
void solve(){
	cin >> n >> x >> k;
	for(int i = 0;i < n;i++){
		int p,u,c;
		cin >> p >> u >> c;
		a[c].pb({p,u});
	} 
	int mx = 0;
	for(int i = 1;i <= n;i++){
		for(int j = 0;j <= x;j++) dp[i][j] = dp[i - 1][j];
		for(auto p:a[i]){
			int c = p.fi,w = p.se;
			for(int j = x;j >= c;j--){
				dp[i][j] = max(dp[i - 1][j - c] + w + k,max(dp[i][j],dp[i][j-c] + w));
				mx=max(mx,dp[i][j]);
			}
		}	
	}
	cout << mx << endl;
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
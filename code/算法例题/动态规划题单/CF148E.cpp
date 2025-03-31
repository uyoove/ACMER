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
const int N = 205;
int n,m;
int f[N][N],dp[N][N * N];
vector<int> v[N];
int pre[N][N],suf[N][N];
void solve(){
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		int k;
		cin >> k;
		for(int j = 0;j < k;j++){
			int t;
			cin >> t;
			v[i].pb(t);
			pre[i][j + 1] = pre[i][j] + t;
		}
		for(int j = k - 1;j >= 0;j--){
			suf[i][j + 1] = suf[i][j + 2] + v[i][j];
		}
		for(int j = 1;j <= min(k,m);j++){
			for(int t = 0;t <= j;t++){
				f[i][j] = max(f[i][j],pre[i][t] + suf[i][k - (j - t) + 1]);
			}
		}
	}
	for(int i = 1;i <= n;i++){
		int sz = v[i].size();
		for(int j = min(sz,m);j >= 0;j--){
			for(int p = m;p >= j;p--){
				dp[i][p] = max(dp[i][p],dp[i - 1][p]);
				dp[i][p] = max(dp[i][p],dp[i - 1][p - j] + f[i][j]);
			}
			
		}
	}
	cout << dp[n][m] << endl;

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
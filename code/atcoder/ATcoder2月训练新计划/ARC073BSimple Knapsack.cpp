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
const int N = 105;
int n,w1;
int dp[N][N][N * 3];
int w[N],v[N];
void solve(){
	cin >> n >> w1;
	int h;
	cin >> h >> v[1];
	for(int i = 2;i <= n;i++){
		cin >> w[i] >> v[i];
		w[i] -= h;
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= i;j++){
			for(int k = 0;k <= i*3;k++){
				dp[i][j][k] = max(dp[i - 1][j][k],dp[i][j][k]);
				if(k < w[i]){
				}else{
					dp[i][j][k] = max(dp[i][j][k],dp[i - 1][j - 1][k - w[i]] + v[i]);
				}
			}
		}
	}
	int res = 0;
	for(int i = 0;i <= 3*n;i++){
		for(int j = 1;j <= n;j++){
			if(j*h + i <= w1){
				res = max(res,dp[n][j][i]);
			}
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
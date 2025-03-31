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
//dp[n][100][100] 表示 前n项
int dp[102][102];
int k,m,n;
struct node{
	int a,b,c;
};
vt<node> v;
void solve(){
	cin >> k >> m >> n;
	for(int i = 1;i <= n;i++){
		int a,b,c;
		cin >> a >> b >> c;
		v.pb({a,b,c});
	}
	int res = 0;
	for(int i = 0;i < n;i++){
		for(int j = k;j >= 0;j--){
			for(int t = m;t >= 0;t--){
				if(j >= v[i].a){
					dp[j][t] = max(dp[j - v[i].a][t] + v[i].b,dp[j][t]);
				}
				if(t >= v[i].a){
					dp[j][t] = max(dp[j ][t- v[i].a] + v[i].c,dp[j][t]);
				}
				res=max(res,dp[j][t]);
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
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
int n;
int h[N];
vector<int> v[N];
int dp[3100],vis[3100];
void solve(){
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> h[i];
		v[h[i]].pb(i);
	}
	int ans = 0;

	for(int i = 1;i <= 3000;i++){
		memset(dp,0,sizeof dp);
		memset(vis,0,sizeof vis);
		vt<int> v1 = v[i]; 
		for(int p = 1;p <= 3000;p++){
			int cnt = 1;
			dp[p] = 0;
			vis[0] = p;
			for(int j =0;j<v1.size();j++){
				if(v1[j] - p < 0){
					dp[v1[j]] = 1;
					vis[v1[j]] = p;
					continue;
				}
				if(vis[v1[j] - p] == p){
					dp[v1[j]] = dp[v1[j] - p] +1;
				}else{
					dp[v1[j]] = 1;
				}
				vis[v1[j]] = p;
				cnt = max(cnt,dp[v1[j]]);
				
			}
			ans=max(ans,cnt);
		}
		
	}
	cout << ans <<endl;


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
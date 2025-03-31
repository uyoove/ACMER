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
const int N = 10005;
int n,m;
string s;
int dp[110][N];
int mod = 998244353;
int tmp[N],ans[N];
void solve(){
	cin >> n >> m;
	cin >> s;
	s = " " + s;
	dp[0][0] = 1;
	for(int i = 0;i <= m;i++){
		for(int j = 0;j < (1 << n);j ++){
			if(!dp[i][j]) continue;
			for(char k = 'a';k <= 'z';k++){
				for(int l = 1;l <= n;l++){
					int t = __builtin_popcount(j & ((1 << l) - 1));
					int pret = __builtin_popcount(j & ((1 << l - 1) - 1));
					if(l==1) pret = 0;
					if(s[l] == k){
						tmp[l] = pret + 1;
					}else{
						tmp[l] = max(t,tmp[l - 1]);
					}	
				}
				int newmask = 0;
				for(int l = 1;l <= n;l++){
					if(tmp[l] > tmp[l - 1]) newmask |= (1 << l - 1);
				}
				dp[i + 1][newmask] = (dp[i + 1][newmask] + dp[i][j])%mod;
			}
		}
	}
	for(int i = 0;i <(1 << n);i++){
		int p = __builtin_popcount(i);
		ans[p] += dp[m][i];
		ans[p]%=mod;
	}
	for(int i = 0;i <= n;i++){
		cout << ans[i] << " ";
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
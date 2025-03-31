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
const ll inf = 0x3f3f3f3f3f3f3f3fLL;
const int infi = 0x3f3f3f3f;
const int P = 13331;
const int N = 200005;
int fac[N],inv[N];
int mod = 1e9+7;

int n;
int a[N];
int ans[N];
int C[3001][3001];

void solve(){
	cin >> n;
	C[0][0] = 1;
	for(int i = 1;i <= 3000;i++){
	    C[0][i] = 1;
	    for(int j = 1;j <= 3000;j++){
	        C[j][i] = (C[j - 1][i - 1] + C[j][i - 1]) % mod;
	    }
	}

	for(int i = 1;i <= n;i++) cin >> a[i];
	int pfh = 0;
	int su = 0;
	for(int i = 1;i <= n;i++){
		pfh += a[i] * a[i] %mod;
		pfh%=mod;
		for(int j = 1;j < i;j++){
			su+=a[j]*a[i]%mod*2%mod;
			su%=mod;
		}
	}
	for(int i = 1;i <= n;i++){
		int res = pfh * C[n - i][n - 1]%mod;
		int p = C[min(n-2,i-2)][n-2]*su;
		if(i < 2) p = 0;
		int g = p+res;
		g%=mod;
		cout << g << " ";
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
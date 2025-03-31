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
int mod = 998244353;
int ksm(int x,int n,int mod)
{
	int res = 1;
    while(n){
        if(n&1) res = res * x % mod;
        x = x * x%mod;
        n >>= 1;
    }
    return res;
}
int iv(int x){
    return ksm(x,mod - 2,mod);
}

int n,x;
int a[N];
int dp[N];
void solve(){
	cin >> n >> x;
	int p = iv(n);
	for(int i = 1;i <= n;i++) cin >> a[i];
	dp[0] = 1;
	
		for(int j = 1;j <= x;j++){
			for(int i = 1;i <= n;i++){
				if(j >= a[i]) dp[j] = (dp[j] + (dp[j - a[i]] * p)%mod)%mod;
			} 
		}
	
	int res = 0;
	for(int i = max(x - a[1] + 1,0ll);i <= x;i++){
		res = (res + (dp[i] * p)% mod)%mod;
	}
	cout << res;

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
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
const int N = 5e5 + 10;
const int mod = 998244353;
int fac[N],inv[N];
int ksm(int x,int n,int mod){
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
void getfac(){
    fac[0] = inv[0] = 1;
    for(int i = 1; i<N;i++){
        fac[i]=fac[i-1]*i%mod;
         inv[i] = iv(i) * inv[i-1] %mod;
    }
}
int C(int n,int m){
    return fac[n]*inv[n-m]%mod*inv[m]%mod;
}
int d[30];
int f[30][N]; //前i个位置有 N个奇数位置
int pre[30];
void solve(){
	int n = 26;
	for(int i = 1;i <= 26;i++) cin >> d[i],pre[i] = pre[i - 1] + d[i];
	int sj = pre[n]/2 + pre[n]%2,o = pre[n] - sj;
	for(int i = 1;i <= n;i++){
		for(int j = 0;j <= pre[n];j++){
			f[i][j] = 0;
		}
	}
	f[0][0] = 1;
	for(int i = 1;i <= n;i++){
		if(!d[i]){
			for(int j = 0;j <= min(pre[i],sj);j++){
				f[i][j] = f[i - 1][j];
			}
			continue;
		}
		for(int j = 0;j <= min(pre[i],sj);j++){
			if(pre[i] - j <= o && pre[i - 1] >= j){
				f[i][j] += f[i - 1][j] * C((o - (pre[i - 1] - j)),d[i]);
				f[i][j]%=mod;
			}
			if(j >= d[i]){
				f[i][j] += f[i - 1][j - d[i]] * C((sj - (j - d[i])),d[i]);
				f[i][j]%=mod;
			}
		}
	}
	cout << f[n][sj] << endl;

}

signed main(){
	std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    getfac();
	int times = 1;
	cin >> times;
	while(times--){
		solve();
	}
	return 0;
}
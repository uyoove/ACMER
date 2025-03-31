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
int n,m;
string grid[2010];
int mod = 998244353;
int f[N],g[N],h[N]; //dp数组,dp前缀和数组,高度数组, f[i] = g[i + 1];// 当前高度为i那么之前的 0 - i + 1高度都可转移
void solve(){
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> grid[i];
		grid[i] = " " + grid[i];
	}
	for(int j = 1;j <= m;j++){
		for(int i = 1;i <= n;i++){
			if(grid[i][j] == '#') {
				h[j] = n - i + 1;
				break;
			}
		}
	}
	f[0] = 1;
	g[0] = 1;
	for(int i = 1;i <= n;i++) g[i] = 1;
	for(int j = 1;j <= m;j++){
		for(int i = h[j];i <= n;i++){
			f[i] = g[min(i + 1,n)];
		}
		if(h[j] == 0) g[0] = f[0];
		else g[0] = 0;
		for(int i = 1;i <= n;i++) g[i] = (g[i - 1] + (i >= h[j] ? f[i] : 0))%mod;
	}
	int ans = 0;
	cout << ((g[n] - g[h[m] - 1])%mod + mod)%mod << endl;	

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
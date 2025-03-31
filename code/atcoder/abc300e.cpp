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
int mod = 998244353;
int iv;
int n;
int ksm(int x,int n,int mod){
	int res = 1;
	while(n){
		if(n&1) res = res * x % mod;
		x = x * x%mod;
		n >>= 1;
	}
	return res;
}
map<int,int> h;
int dfs(int x){
	if(x==1) return 1;
	if(h.count(x)) return h[x];
	int res = 0;
	if(x%2==0) res = (res + dfs(x/2))%mod;
	if(x%3==0) res = (res + dfs(x/3))%mod;
	if(x%4==0) res = (res + dfs(x/4))%mod;
	if(x%5==0) res = (res + dfs(x/5))%mod;
	if(x%6==0) res = (res + dfs(x/6))%mod;
	return h[x] = (res*iv)%mod;
}
void solve(){
	cin >> n;
	iv = ksm(5,mod-2,mod);
	dfs(n);
	cout << h[n] << endl;
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
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
int n;
int a[N];
int vis[N];
int mod = 998244353;
vt<PII> v;
//忘记sqrt的另一个倍数了,难绷
ll powerMod(ll x, ll n, ll mod){ //快速幂
    ll ans = 1;
    while (n > 0){
        if  (n & 1)
            ans = (ans * x) % mod;
        x = (x * x) % mod;
        n >>= 1;
    }
    return ans;
}
void solve(){
	cin >> n;
	int ma = 0;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		v.pb({a[i],i});
	}
	sort(v.rbegin(),v.rend());
	int res = 0;
	int gg = n - 1;
	for(auto &[val,idx]:v){
		int p = sqrt(idx);
		for(int i = 1;i <= sqrt(idx);i++){
			if(idx%i) continue;
			if(!vis[i]){
				vis[i] = 1;
				res = (res + powerMod(2,gg,mod)*val%mod)%mod;
				gg--;
			
			}
			int d = idx/i;
			if(vis[d]||d==i) continue;
			vis[d] = 1;
			res = (res + powerMod(2,gg,mod)*val%mod)%mod;
			gg--;
		}
	}
	//cout << gg << endl;
	cout <<res <<endl;
	
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
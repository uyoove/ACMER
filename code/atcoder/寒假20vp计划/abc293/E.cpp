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
int a,x,m;
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
//a的次方从1开始,s从0开始
//等差数列求和
//公式sn = a1 + a2 + an/2 + an/2+1 + an/2+2
//sn = sn/2 + an/2*sn/2; 偶数个的情况
//奇数个的情况
//a1 + a2 + an-1/2 + an-1/2 + 1 ... an-1,an
//sn = sn-1/2 + an-1/2*sn-1/2 + an
int s(int n){
	if(n==0) return 1;
	if(n==1) return (1 + a)%m;
	if(n%2==0){
		return ((1 + powerMod(a,n/2,m))*s(n/2 - 1)%m + powerMod(a,n,m))%m;
	}else{
		return (1 + powerMod(a,(n)/2 + 1,m))*s((n)/2)%m;
	}
}
void solve(){
	cin >> a >> x >> m;
	cout << s(x-1)%m << endl;
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
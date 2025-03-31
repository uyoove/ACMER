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
int n,k;
vt<array<int,3>> v;

inline void print(__int128 x)
{
    if(x<0)
	{
        putchar('-');
        x=-x;
    }
    if(x>9) print(x/10);
    putchar(x%10 +'0');
}
bool check(__int128 x){
	__int128 res = 0;
	for(int i = 0;i < n;i++){
		auto &[t,l1,w] = v[i];
		__int128 l = 0, r = 2e18,ans = -1;
		while(l<=r){
			__int128 mid = (l + r)/2;
			__int128 cst = mid * t + ((mid-1)/l1)*w;
			if(cst <= x){
				l = mid + 1;
				ans = mid;
			}else{
				r = mid - 1;
			}
		}
		ans=(ans==-1 ? 0:ans);
		res+=ans;
	}
	return res >= k;
}
void solve(){
	cin >> n >> k;
	v.clear();
	for(int i = 1;i<=n;i++){
		int a,b,c;
		cin >> a >> b >> c;
		v.pb({a,b,c});
	}
	__int128 l = 0,r = 2e18,ans = -1;
	while(l <= r){
		__int128 mid = (l + r)/2;
		if(check(mid)){
			r = mid - 1;
			ans = mid;
		}else{
			l = mid +1;
		}
	}
	print(ans);
	cout << endl;
}

signed main(){
	int times = 1;
	cin >> times;
	while(times--){
		solve();
	}
	return 0;
}
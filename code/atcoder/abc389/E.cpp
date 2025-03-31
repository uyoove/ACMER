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
const __int128 inf = 1e18;
const int infi = 0x3f3f3f3f;
const int P = 13331;
const int N = 200005;
int n,m;
int p[N];
bool check(int x){
	__int128 cnt = 0;
	for(int i = 1;i <= n;i++){
		if(p[i] > x) continue;
		__int128 g = (x/p[i]);
		g = (g + 1)/2;
		cnt += g * g * p[i]; 
		if(cnt > m) return false;
	}
	return cnt <= m;
}
void solve(){
	cin >> n>> m;
	for(int i = 1;i <= n;i++) cin >> p[i];
	__int128 l = 0,r = inf,ans = 0;
	while(l <= r){
		__int128 mid = l + (r - l)/(__int128)2;
		if(check(mid)){
			ans = mid;
			l = mid + 1;
		}else{
			r = mid - 1;
		}
	} 
	int res = 0;
	__int128 su = 0;
	for(int i = 1;i<=n;i++){
		if(p[i] > ans) continue;
		int d = (ans/p[i]);
		d = (d+1)/2;
		res+=d;
		su+=d*d*p[i];
	}
	m -= su;
	vector<int> v;
	for(int i = 1;i<=n;i++){
		int d = (ans/p[i]);
		d = (d+1)/2;
		int t = (2*d + 1)*p[i];
		v.pb(t);
	}
	sort(all(v));
	//也可以直接写 res=m/(ans + 1)
	//为什么ans+1一定存在 因为二分的性质,如果ans+1不存在,那我肯定ans+1一定是更优的
	//所以一定存在
	for(auto p:v){
		if(m<p) break;
		m-=p;
		res++;
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
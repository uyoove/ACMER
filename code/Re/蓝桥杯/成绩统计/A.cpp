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
int n,k,t;
int a[N],b[N];
int pre[N],su[N];
bool check(int x){
	for(int i = 1;i <= x;i++) b[i] = a[i];
	sort(b + 1,b + 1 + x);
	for(int i = 1;i <= x;i++){
		pre[i] = pre[i - 1] + b[i] * b[i];
		su[i] = su[i-1] + b[i];
	}
	for(int i = k;i <= x;i++){
		double tmp = (pre[i] - pre[i - k])*1.0/k;
		double pf = (su[i] - su[i - k])*1.0/k;
		double dd = tmp - pf * pf;
		if(dd < t) return true;
	}
	return false;
}
void solve(){
	cin >> n >> k >> t;
	for(int i = 1;i <= n; i++){
		cin >> a[i];
	}
	int l = k,r = n,ans = -1;
	while(l <= r){
		int mid = l + r >> 1;
		if(check(mid)){
			r = mid - 1;
			ans = mid;
		}else{
			l = mid + 1;
		}
	}
	cout << ans << endl;
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
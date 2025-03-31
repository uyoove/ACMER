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
const int N = 1000005;
int n,p,t,k;
int pre[N];
int work(vt<int>& a){
	for(int i = 1;i <= n;i++){
		pre[i] = pre[i - 1] + a[i - 1];
	}
	int res = 0;
	for(int l = 0;l <= p;l++){
		if(p - l >= t) continue;
		int r = min(n,l + t - (p - l));
		int tp = pre[r] - pre[l] + (r-l)*t*k - (r-l)*(r-l-1)/2*k;
		res=max(res,tp);
	}
	return res;
}
void solve(){
	vt<int> a;
	cin >> n >> p;
	p--;
	for(int i = 1;i <= n;i++){
		int t;
		cin >> t;
		a.pb(t);
	}
	cin >> k >> t;
	int res = work(a);
	reverse(all(a));
	p = n - p - 1;
	res=max(res,work(a));
	cout << res << endl;
}

signed main(){
	std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
	int times = 1;
	cin >> times;
	while(times--){
		solve();
	}
	return 0;
}
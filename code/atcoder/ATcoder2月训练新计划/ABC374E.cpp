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
int n,x1;
int a[N],p[N],b[N],q[N];
bool check(int x){
	int cost = 0;
	for(int i = 1;i <= n;i++){
		int mi = inf;
		for(int j = 0;j <= b[i];j++){
			if(j*a[i] > x) break;
			int tp = x - j*a[i];
			mi = min(mi,j*p[i] + (tp + b[i] - 1)/b[i] * q[i]);
		}
		for(int j = 0;j <= a[i];j++){
			if(j*b[i] > x) break;
			int tp = x - j*b[i];
			mi = min(mi,j*q[i] +(tp + a[i] - 1)/a[i] * p[i]);
		}
		cost += mi;
	}
	return cost <= x1;
}
void solve(){
	cin >> n >> x1;
	for(int i = 1;i <= n;i++){
		cin >> a[i] >> p[i] >>  b[i] >> q[i];
	}
	int l = 0,r = 1e10,ans= 0;
	while(l<=r){
		int mid = (l + r) >> 1;
		if(check(mid)){
			l = mid + 1;
			ans = mid;
		}else{
			r = mid - 1;
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
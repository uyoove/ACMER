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
const int esp = 1e-14;
double n,m,k;
PII a[N],b[N];
//当前糖x在y的水含量下变成cc浓度额外至少需要多少糖 (可能是负的)
//x/x+y = cc
//x = ccx + ccy
//x - ccx = ccy
//x(1 - cc) = ccy
//x = ccy/(1-cc)
//x = cc/(1-cc) *y
bool check(double cc){
	double d = cc/(1-cc);
	int cnt = 0;
	vt<double> v;
	for(int i = 1;i<=m;i++){
		v.pb(b[i].fi - d * 1.0 * b[i].se);
	}
	sort(all(v));
	for(int j = 1;j <= n;j++){
		double xy = a[j].fi - d * 1.0 * a[j].se;
		int l = 0,r = v.size() - 1,res = -1;
		xy = -xy;
		while(l <= r){
			int mid = l + r >> 1;
			if(v[mid] >= xy){
				r = mid - 1;
				res = mid;
			}else{
				l = mid +1;
			}
		}
		if(res==-1) continue;
		cnt += v.size() - res;
	}
	return cnt >= k;
}
void solve(){
	cin >> n >> m >> k;
	for(int i = 1;i <= n;i++) cin >> a[i].fi >> a[i].se;
	for(int i = 1;i <= m;i++) cin >> b[i].fi >> b[i].se;	
	double l = 0,r = 1,res = 0;
	while(r - l >  1e-14){
		double mid = (l + r)/2;
		if(check(mid)){
			l = mid;
			res = mid;
		}else{
			r = mid;
		}
	}
	printf("%.10lf",res*100);
}

signed main(){
	int times = 1;
	//cin >> times;
	while(times--){
		solve();
	}
	return 0;
}
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
int n;
PII a[N];
void solve(){
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> a[i].fi >> a[i].se;
	vt<PII> v;
	for(int i = 1;i <= n;i++){
		for(int j = i+ 1;j <= n;j++){
			PII p;
			if((a[i].se >= a[j].se && a[i].fi <= a[j].se) || (a[j].se >= a[i].se && a[j].fi <= a[i].se)){
				p.fi = min(a[i].fi,a[j].fi);
				p.se = max(a[i].se,a[j].se);
				v.pb(p);
			}
		}
	}
	sort(all(v),[](PII x,PII y){
		if(x.se==y.se) return x.fi < y.fi;
		return x.se < y.se;
	});
	//cout << v.size() << endl;
	int ans = 0;
	int last = -1;
	for(auto p : v){
		if(p.fi > last) ans++,last = p.se;
	}
	cout << n - ans * 2 << endl;

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
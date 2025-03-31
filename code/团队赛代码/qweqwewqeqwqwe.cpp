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
int a[N],p[N];
int xs[N],vis[N];

void solve(){
	cin >> n;
	vt<PII> v;
multiset<PII> mul;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		v.pb({a[i],i});
	}
	sort(v.rbegin(),v.rend());
	for(int i = 1;i <= n;i++){
		cin >> p[i];
		vis[i] = xs[i] = 0;
	}
	mul.insert(v[0]);
	vis[v[0].se]=1;
	int zz = 1;
	int ma = v[0].fi;
	int res = 1;
	for(int i = 1;i <= n - 1;i++){
		xs[p[i]] = 1;
		if(vis[p[i]]){
			mul.erase({a[p[i]],p[i]});

			while(zz < n && xs[v[zz].se]){
				zz++;
			}
			if(zz < n) mul.insert({a[v[zz].se],v[zz].se}),vis[v[zz].se] = 1,zz++;
		}
		while(zz < n && xs[v[zz].se]){
			zz++;
		}
		if(zz < n) mul.insert({a[v[zz].se],v[zz].se}),vis[v[zz].se] = 1,zz++;
		if(mul.size() == i + 1){
			auto it = mul.begin();
			int p = it->fi;
			//cout << p << " "<< i + 1 <<endl;
			
			if((p) * (i + 1) > ma){
				ma=max((p) * (i + 1),ma);
				res = i + 1;
			}else{
				continue;
			}
		}
	}
	cout << ma << " " << res << endl;

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
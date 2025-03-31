//最后一舞
#include<bits/stdc++.h>
using namespace std;
#define out(x) cout << #x << '=' << (x) << endl
#define out2(x, y) cout << #x << '=' << (x) << ',' << #y << '=' << (y) << endl 
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
int n;
int a[N],vis[N];
vt<PII> v[N];

int idx = 0;
const int mod = 998244353;
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
int gt(int x,vt<int> &v){
	return lower_bound(all(v),x) - v.begin() + 1;
}
void solve(){
	cin >> n;
	vt<int> ls;
	idx = 0;
	int t = 1;
	for(int i = 1;i <= n;i++) {
		cin >> a[i];

		for(auto &p:v[a[i]]){
			ls.pb(p.fi);
		}
	}
	sort(ls.begin(),ls.end());
	ls.erase(unique(all(ls)),ls.end());
	int sz = ls.size();
	vt<vt<int>> vp(sz + 1);
	for(int i = 1;i <= n;i++){
		for(auto &p:v[a[i]]){
			vp[gt(p.fi,ls)].pb(p.se);
		}
	}
	for(int i = sz;i >= 1;i--){
		sort(all(vp[i]));
	}
	int cnt = 0;
	
	int res = 0;
	while(true){
		int t = 1;
		cnt++;
		bool f = 0;
		for(int i = sz;i >= 1;i--){
			if(vp[i].size()){
				t = t*powerMod(ls[i - 1],vp[i][vp[i].size() - 1],mod)%mod;
				vp[i].pop_back();
			}
			if(vp[i].size()) f=1;
		}
		res += t;
		res%=mod;
		if(!f){
			break;
		}
	}
	
	res += (n - cnt);
	res%=mod;
	cout << res << endl;

}

signed main(){
	std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
	int times = 1;
	cin >> times;
	for(int i = 2;i < N;i++){
		if(v[i].size()){
			continue;
		}
		for(int j = i;j < N;j+=i){
			int z = j;
			int cnt = 0;
			while(z%i==0){
				z/=i;
				cnt++;
			}
			if(cnt){
				v[j].pb({i,cnt});
			}
		}
	}
	while(times--){
		solve();
	}
	return 0;
}
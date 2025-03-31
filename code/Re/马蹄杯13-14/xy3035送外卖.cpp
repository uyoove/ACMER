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
PII a[N]; 
bool cmp(PII a,PII b){
	if(a.fi==b.fi) return a.se < b.se;
	return a.fi < b.fi;
}
struct Fenwick{
	vector<int> tr;
	int sz;
	void init(int n){
		tr.resize(n + 1);
		sz = n;
	}
	Fenwick(){}
	Fenwick(int n){
		init(n);
	}
	void add(int k,int val){
		for(int i = k;i <= sz;i+=(i&-i)){
			tr[i]+=val;
		}
	}
	int query(int k){
		int res = 0;
		for(int i = k;i > 0;i-=(i&-i)){
			res+=tr[i];
		}
		return res;
	}
	int ask_sum(int l,int r){
		return query(r) - query(l - 1);
	}
};
bool check(int d){
	Fenwick fk(N);
	int l = 1;
	int cnt = 0;
	for(int r = 1;r <= n;r++){
		while(a[r].fi - a[l].fi > d) fk.add(a[l++].se,-1);
		cnt += fk.ask_sum(max(1ll,a[r].se - d),min(N,a[r].se+d));
		fk.add(a[r].se,1);
	}
	return cnt >= k;
}
void solve(){
	cin >> n >> k;
	for(int i = 1;i <= n;i++) cin >> a[i].fi >> a[i].se;
	sort(a + 1,a + 1 + n,cmp);
	int l = 0,r = N,ans = -1;
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
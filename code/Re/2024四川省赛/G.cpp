//最后一舞
#include<bits/stdc++.h>
using namespace std;
#define int long long
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
const int N = 300005;
int n,q;
int x[N];
int tr[N *30][2],f[N * 30],idx = 0;
void add(int x,int id){
	int p = 0;
	for(int i = 30;i >= 0;i--){
		int d = (x >> i) & 1;
		if(!tr[p][d]) tr[p][d] = ++idx;
		p = tr[p][d];
	}
	f[p] = id;
	//cout << p << " " << id <<endl;
}
int query_max(int x){
	int p = 0;
	for(int i = 30;i >= 0;i--){
		int d = (x >> i) & 1;
		if(tr[p][d^1]) p = tr[p][d^1];
		else p = tr[p][d];
	}
	return f[p];
}
int query_mi(int x){
	int p = 0;
	for(int i = 30;i >= 0;i--){
		int d = (x >> i) & 1;
		if(tr[p][d]) p = tr[p][d];
		else p = tr[p][d^1];
	}

	return f[p];
}
void solve(){
	cin >> n >> q;
	for(int i = 1;i <= n;i++) cin >> x[i],add(x[i],i); 
		//cout << query_max(0) << " " << query_mi(0) << endl;
	while(q--){
		int a,b;
		cin >> a >> b;
		int mx = query_max(a),mi = query_mi(a);
		int d = ((x[mx]^a)-b) * ((x[mi]^a)-b);
		//cout << mi<< " " << mx << endl;
		if(d > 0){
			cout << -1 << endl;
			continue;
		}
		int llx = min(mi,mx),rrx = max(mi,mx);
		int l = min(mi,mx),r = max(mi,mx),ans = llx;
		while(l <= r){
			int mid = (l + r) >> 1;
			int d = ((x[rrx]^a)-b) * ((x[mid]^a)-b);
			if(d <= 0){
				l = mid + 1;
				ans = mid;
			}else{
				r = mid - 1;
			}
		}
		if(ans==rrx) ans -= 1;
		cout << ans << endl;
	}

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
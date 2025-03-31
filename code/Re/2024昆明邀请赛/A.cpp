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

int n,m,k;
int ok[N];
void solve(){
	vt<PII> v;
	cin >> n >> m >> k;
	map<int,int> mp;
	vt<vt<int>> a(n + 2,vt<int>());
	for(int i = 1;i <= n;i++){
		int t;
		cin>>t;
		v.pb({t,i});
		for(int j = 1;j <= m;j++){
			cin >> t;
			a[i].pb(t);
		}
        ok[i] = 0;
	}
	sort(all(v));
	int mx = 0;
	for(int i = 0;i < n;i++){
		auto [_,id] = v[i];
		int t = 0,val = 0;
		for(int j = 0;j < m;j++){
			if(a[id][j]==-1){
				val++;
			}else{
				t+=a[id][j];
			}
		}
		if(i>=1&&v[i - 1].fi==v[i].fi){
			if(t + val*k < mp[v[i].fi]){
				cout << "No" << endl;
				return;
			}
			mx = max(t+1,mx);
			ok[v[i].se] = mp[v[i].fi]- t;
		}else{
			mp[v[i].fi] = mx;
			if(t + val*k < mx && i!=0){
				cout << "No" << endl;
				return;
			}
			mx=max(mx,t);
			ok[v[i].se] = mx-t;
			mx+=1;
		}
	}
	cout << "Yes" << endl;
	for(int i = 1;i <= n;i++){
		for(int j = 0;j < m;j++){
			if(a[i][j]==-1){
				a[i][j] = 0;
				if(ok[i]>0){
					a[i][j] += min(ok[i],k);
					ok[i]-=min(ok[i],k);
				}
			}
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
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
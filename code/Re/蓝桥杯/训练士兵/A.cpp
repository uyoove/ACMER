#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6+7;
const int inf = 1e18;
int n,s;
struct nodes
{
	int p,c;
	bool operator<(const nodes t1)const{
		return c < t1.c;
	}
}a[N];
int pre[N],cs[N];
void solve(){
	cin >> n >> s;
	int mx = 0;
	for(int i = 1;i <= n;i++){
		cin >> a[i].p >> a[i].c;
		mx = max(mx,a[i].c);
	}
	sort(a + 1,a + 1 + n);
	for(int i = 1;i <= n;i++) pre[i]=pre[i-1]+a[i].p;
	for(int i = 1;i <= n;i++) cs[i]=cs[i-1]+a[i].p*a[i].c;
	int ans1 = inf;
	for(int i = 0;i <= mx;i++){
		int l = 1,r = n,ans = n + 1;
		while(l<=r){
			int mid =l+r>>1;
			if(a[mid].c>i){
				r = mid - 1;
				ans = mid;
			}else{
				l = mid + 1;
			}
		}
		int d = i * s + cs[n] - cs[ans - 1] - (pre[n] - pre[ans - 1]) *i;
		ans1 = min(ans1,d); 
	}
	cout << ans1 << endl;
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	solve();
}
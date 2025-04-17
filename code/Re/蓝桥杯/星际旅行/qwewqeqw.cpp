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
string s[2];
vt<PII> v;
void solve(){
	cin >> s[0] >> s[1];
	int n = s[1].size();
	for(int i = 0;i < n;i++){
		if(s[0][i]=='#'&& s[1][i]=='#'){
			v.pb({3,i});
			continue;
		}
		if(s[0][i]=='#'){
			v.pb({1,i});
			continue;
		}
		if(s[1][i]=='#'){
			v.pb({2,i});
			continue;
		}
	}
	int ans = 0;
	for(int i = 0;i < v.size() - 1;i++){
		if(v[i].fi==3){
			ans+=v[i+1].se-v[i].se-1;
		}else{
			if(v[i].fi==v[i+1].fi || v[i+1].fi== 3){
				ans+=v[i+1].se-v[i].se-1;
			}else{
				ans+=v[i+1].se-v[i].se;
				v[i+1].fi=3;
			}
		}
	}
	cout << ans;

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
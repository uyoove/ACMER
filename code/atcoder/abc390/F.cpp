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
int n,m;
vt<PII> a[4];
int dp[5010][4];//代表j类维生素消耗i的卡路里的最大维生素
bool check(int x){
	int res = 0;
	for(int _ = 1;_<=3;_++){
		int mi1 = 1e10;
		for(int i = 0;i <= m;i++){
			if(dp[i][_] >= x){
				mi1 = i;
				break;
			}
		}
		res += mi1;
	}
	//cout << x << " " << res <<endl;
	return res <= m;
}
void solve(){
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		int op,v,c;
		cin >> op >> v >> c;
		a[op].pb({v,c});
	}
	for(int _ = 1;_<=3;_++){
		for(int i = 0;i < a[_].size();i++){
			for(int j = m;j >= a[_][i].se;j--){
				dp[j][_] = max(dp[j - a[_][i].se][_] + a[_][i].fi,dp[j][_]);
			}
		}
	}
	int l = 0,r = 1e10,ans = 0;
	while(l <= r){
		int mid = l + r >> 1;
		if(check(mid)){
			l = mid + 1;
			ans = mid;
		}else{
			r = mid - 1;
		}
	}
	cout << ans <<endl;
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
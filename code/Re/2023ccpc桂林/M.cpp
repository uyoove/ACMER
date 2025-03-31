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
const int N = 300005;
int a[N],b[N];
int n;
int dp[N];
bool check(int x){
	memset(dp,0,sizeof dp);
	int cnt = 0;
	for(int i = 1;i <= n;i++){
		if(a[i]<x && b[i]>=x) dp[i] = 1;
		if(a[i]>=x && b[i]<x) dp[i] = -1;
		if(a[i]>=x) cnt++;
	}
	int l = 1;
	int tp = 0;
	int mx = 0;
	int ans = 0;
	for(int r = 1;r <= n;r++){
		tp+=dp[r];
		ans = max(tp-mx,ans);
		mx=min(mx,tp);
	}
	cnt+=ans;
	return cnt >= (n/2) + 1;
}
void solve(){
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i] >> b[i];
	}
	int l = 1,r = 1e9+7,ans = 0;
	while(l<=r){
		int mid = l + r >> 1;
		if(check(mid)){
			ans = mid;
			l= mid + 1;
		}else{
			r = mid - 1;
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
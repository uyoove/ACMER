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
int b[N],a[N],pre[N],suf[N];
int n,k;
void solve(){
	cin >> n >> k;
	suf[n + 1] = 0; 
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		pre[i]=__gcd(pre[i-1],a[i]);
		
	}
	for(int i = n;i>=1;i--){
		suf[i]=__gcd(suf[i+1],a[i]); 
	}
	int g = 0;
	int res = pre[n];
	for(int i = 1;i <= n;i++){
		if(pre[i]==pre[i-1]) continue;
		int g = pre[i - 1];
		for(int r = i;r<=n;r++){
			g = __gcd(g,a[r] + k);
			res=max(res,__gcd(g,suf[r + 1]));
		}
	}
	
	cout << res << endl;
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
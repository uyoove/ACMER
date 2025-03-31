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
int dp[30][30];
int g[30][30];
int n;
int a[N];
int pre[N];
vt<PII> res;
int mex(int l,int r){
	for(int i = 0;i<=18;i++){
		bool f = true;
		for(int j = l;j <= r;j++){
			if(a[j]==i){
				f=false;
				break;
			}
		}
		if(f) return i;
	}
	return 19;
}
void add(int l,int r){
	res.pb({l,r});
	fill(a + l,a+r+1,mex(l,r));
}
void gt(int l,int r){
	if(l > r) return;
	if(l==r){
		while(a[l]!=1) add(l,r);
		return;
	}
	//逐渐 0 0 0 -> 1 0 0 -> 2 2 0 - > 0 2 0 -> 1 2 0
	//从0变全部是len然后保留len个,将前len-1个重构   
	gt(l,r-1),add(l,r),add(l,r-1),gt(l,r-1);
}
void ptr(int l,int r){
	if(g[l][r] == 0){
		if(pre[r]-pre[l - 1] < (r-l+1)*(r-l+1)){
			while(accumulate(a + l,a+r + 1,0ll)!=0) add(l,r);
			gt(l,r-1),add(l,r);
		}
		return;
	}
	ptr(l,g[l][r]),ptr(g[l][r]+1,r);
}
void solve(){
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> a[i],pre[i] = pre[i - 1] + a[i];
	for(int len = 1;len <= n;len++){
		for(int l = 1;l + len - 1 <= n;l++){
			int r = l + len - 1;
			dp[l][r] = max(pre[r] - pre[l - 1],len*len);
			for(int k = l;k<r;k++){
				if(dp[l][k] + dp[k+1][r] > dp[l][r]){
					dp[l][r] = dp[l][k] + dp[k+1][r];
					g[l][r] = k;
				}
			}
		}
	}
	ptr(1,n);
	cout << dp[1][n] << " " << res.size() << endl;

	for(auto [k,v]:res){
		cout << k << " " << v <<endl;
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
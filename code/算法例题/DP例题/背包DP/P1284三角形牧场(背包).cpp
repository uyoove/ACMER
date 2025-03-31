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
const ll inf = 0x3f3f3f3f3f3f3f3fLL;
const int infi = 0x3f3f3f3f;
const int P = 13331;
const int N = 200005;
bool ok(int x,int y,int z){
	return x+y>z&&x+z>y&&z+y>x;
}
int dp[2000][2000];
void solve(){
	int su = 0;
	int n;
	cin >> n;
	int a[n];
	for(int i = 1;i <= n;i++) cin >> a[i],su+=a[i];
	memset(dp,0,sizeof dp);
	dp[0][0] = 1;
	for(int i = 1;i <= n;i++){
		for(int j = su/2;j>=0;j--){
			for(int k = su/2;k>=0;k--){
				if(j-a[i]>=0) dp[j][k] |= dp[j-a[i]][k];
				if(k-a[i]>=0) dp[j][k] |= dp[j][k-a[i]];
				//逐条加边
			}
		}
	}
	double ans = -1;
	for(int j = su/2;j>0;j--){
		for(int k = su/2;k>0;k--){
			//验证可行性
			if(!dp[j][k] || !ok(j,k,su-j-k)) continue;
			double tp = (j+k + su-j-k)*1.0/2;
			double tt = sqrt(tp*(tp - j)*(tp - k)*(tp-su+j+k));
			ans=max(ans,tt);
		}
	}
	if(ans==-1){
		cout << -1 << endl;
		return;
	}else{
		int d = ans*100;
		cout << d << endl;
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
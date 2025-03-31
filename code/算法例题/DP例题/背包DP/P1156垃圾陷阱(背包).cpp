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
const int N = 205;
int d,n;
struct node{
	int t,f,h; //时间,生命,高度
	bool operator<(const node& t1)const{
		return t < t1.t;
	}
}a[N];
int dp[105][2005]; //第i件物品,我有j这个高度的最大生命
void solve(){
	cin >> d >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i].t >> a[i].f >> a[i].h;
	}
	memset(dp,0,sizeof dp);
	sort(a + 1,a + 1 + n);
	dp[0][0] = 10;
	for(int i = 1;i <= n;i++){
		for(int j = 200;j>=0;j--){
			//转移生命增加
			if(dp[i-1][j] >= a[i].t){
				dp[i][j]=max(dp[i][j],dp[i-1][j] + a[i].f);
			}
			//转移高度增加
			if(j>=a[i].h && dp[i - 1][j - a[i].h]>=a[i].t){
				dp[i][j] = max(dp[i][j],dp[i-1][j-a[i].h]);
			}
		}
	}
	int mxh = 0;
	int maxt = 10;
	for(int i = 1;i<=n;i++){
		//cout << dp[i][d] << " " << a[i].t << endl;
		maxt = max(maxt,dp[i][0]);
		for(int p = d;p <= 200;p++) //可能超出d
		if(dp[i][p] >= a[i].t){
			cout << a[i].t << endl;
			return;
		}
	}
	cout << maxt << endl;
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
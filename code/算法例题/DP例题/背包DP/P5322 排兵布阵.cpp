//和爸爸一起学编程真好,不过要小学四年级分流考试了,最近没时间写代码了,呜呜呜
#include<bits/stdc++.h>
using namespace std;
#define out(x) cout << #x << '=' << (x) << endl
#define out2(x, y) cout << #x << '=' << (x) << ',' << #y << '=' << (y) << endl 
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
int s,n,m;
int b[N];
int a[110][110];
//考虑限制:兵数,关卡数
//考虑结果,最大得分
//dp[i][j] 前i个数字消耗j个军队所能换取的最大分数
//预处理cnt[i][j]表示第i列小于j的数字的个数;
int cnt[110][21000];
vector<int> xz[101];//优化,我们发现选择的数一定是0或者每列的2*a[j]+1
void solve(){
	cin >> s >> n >> m;
	int dp[n + 1][m + 1];
	memset(dp,0,sizeof dp);
	for(int i = 1;i <= s;i++){
		for(int j = 1;j <= n;j++){
			cin >> a[i][j];
			if(a[i][j] * 2 + 1 > m) continue;
			cnt[j][a[i][j] * 2 + 1]++;
			xz[j].push_back(a[i][j] * 2 + 1);
		}
	}
	for(int j = 1;j <= n;j++){
		for(int p = 1;p<=m;p++){
			cnt[j][p] += cnt[j][p-1];
		}
	}
	int ma = 0;
	for(int i = 1;i <= n;i++){
		xz[i].push_back(0);
		for(int j = 0;j <= m;j++){
			for(int k1 = 0;k1 < xz[i].size();k1++){
				int k = xz[i][k1];
				if(j-k<0)continue;
				dp[i][j] = max(dp[i][j],dp[i - 1][j -k] + i*cnt[i][k]);
				ma=max(ma,dp[i][j]);
			}
			
		}
		
	}
	cout << ma << endl;
	

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
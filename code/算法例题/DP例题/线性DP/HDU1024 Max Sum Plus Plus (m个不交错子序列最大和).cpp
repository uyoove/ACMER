//和爸爸一起学编程真好,不过要小学四年级分流考试了,最近没时间写代码了,呜呜呜
#include<cstdio>
#include<iostream>
#include<cstring>
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
const int N = 1000005;
int a[N],m,n;
int dp[N],last[N];
//考虑dp[m][n],dp[i][j]表示第i个组以j结尾的最大值
//转移: max(dp[i][j - 1] + a[j],dp[i - 1][k] + a[j]) 满足都是j结尾,并且第一个连续,第二个断开分组
//考虑优化 dp[i - 1][k]就是上一部分的最大值 设为f[j]
int max(int a,int b){
	return a > b ? a : b;
}
void solve(){
	for(int i = 1;i <= n;i++) scanf("%d",&a[i]);
	memset(dp,0,sizeof(dp));
     memset(last,0,sizeof(last));
     int tp = -infi;
	for(int i = 1;i <= m;i++){
		tp = -infi;
		for(int j = i;j <= n;j++){
			dp[j] = max(dp[j - 1] + a[j],last[j - 1] + a[j]); //j-1(含本身)以前最大值
			last[j - 1]=tp;
			tp=max(tp,dp[j]);
		}
	}
	
	printf("%d\n",tp);

}

signed main(){

	int times = 2;
	//cin >> times;
	while(scanf("%d%d", &m, &n) == 2){
		
		solve();
	}
	return 0;
}
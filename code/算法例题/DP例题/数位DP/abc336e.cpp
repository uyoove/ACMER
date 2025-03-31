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
const ll inf = 0x3f3f3f3f3f3f3f3fLL;
const int infi = 0x3f3f3f3f;
const int P = 13331;
const int N = 200005;
int n;
int ans[30];
int idx = 0;
int now;
int memo[50][200][200]; //第2维表示mod数位和,最后一位表示数位和
int dfs(int pos,bool limit,int md,int su){
	if(pos==0){
		return (md==0 && su==now);//得su==now,如果su>now&&md==0代表是su是now倍数,那么下一次枚举会枚举到,这次不能记录更新
	}
	if(~memo[pos][md][su] && !limit){
		return memo[pos][md][su];
	}
	int res = 0;
	int up = limit ? ans[pos] : 9;
	for(int i = 0;i <= up;i++){
		//前面那段数字拼接的模,比如11430 的114的数位mod枚举的这个数
		res+=dfs(pos - 1,limit&&(i==ans[pos]),(md*10 + i)%now,su+i); 
	}
	if(!limit) memo[pos][md][su] = res;
	return res;
}
void solve(){
	cin >> n;
	while(n){
		ans[++idx] = n%10;
		n/=10;
	}
	int cnt = 0;
	for(int i = 1;i <= idx*9;i++){
		now = i;
		memset(memo,-1,sizeof memo);
		cnt+=dfs(idx,1,0,0);
	}
	cout << cnt <<endl;

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
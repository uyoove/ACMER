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
const int mod = 1e9 + 7;
struct edges{
	int v,ne;
}e[N << 1];
int h[N],idx = 1;
void add(int u,int v){
	e[++idx] = {v,h[u]};
	h[u] = idx;
}
int n,m,k,x;
int sz[N];
int dp[N][11][3]; // 第二维表示用了几个,0比k小的,1等于k的,2大于k的
int tp[11][3]; //同层不能影响所以先要对上层进行值的转移通过tp去转移
void init(int u,int f){
	sz[u] = 1;
	for(int i = h[u];i;i=e[i].ne){
		int v = e[i].v;
		if(v == f) continue;
		init(v,u);
		sz[u]+=sz[v];
	}
}
void dfs(int u,int f){
	dp[u][0][0] = k - 1; //小于k的有k-1个
	dp[u][1][1] = 1;	//等于k的有一个
	dp[u][0][2] = m - k;  //大于k的有m - k个
	for(int i = h[u];i;i=e[i].ne){
		int v = e[i].v;
		if(v == f) continue;
		dfs(v,u);
		for(int j = 0;j <= x;j++){
			for(int k = 0;k <= 2;k++){
				tp[j][k] = dp[u][j][k];
				dp[u][j][k] = 0;
			}
		}
		//树上背包 外层倒序容量,内层正序物品代表考虑排列 
		for(int j = min(sz[u],x);j >= 0;j--){ //容量
			for(int k = 0;k <= min(sz[v],j);k++){ //物品
				dp[u][j][0] = (dp[u][j][0] + tp[j - k][0] * (dp[v][k][0] + dp[v][k][1] + dp[v][k][2])%mod)%mod;
				dp[u][j][1] = (dp[u][j][1] + tp[j - k][1] * (dp[v][k][0])%mod)%mod; 
				dp[u][j][2] = (dp[u][j][2] + tp[j - k][2] * (dp[v][k][0] + dp[v][k][2])%mod)%mod; 
			}
		}
	}
}
void solve(){
	cin >> n >> m;
	for(int i = 1;i < n;i++){
		int u,v;
		cin >> u >> v;
		add(u,v);
		add(v,u);
	}
	cin >> k >> x;
	init(1,0);
	dfs(1,0);
	int res = 0;
	for(int i = 0;i <= x;i++){
		for(int j = 0;j < 3;j++){
			res = (res + dp[1][i][j])%mod;
		}
	}
	cout << res << endl;
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
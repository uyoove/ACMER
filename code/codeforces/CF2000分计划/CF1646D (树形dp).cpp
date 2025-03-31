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
bool cmp(PII p1, PII p2){
	if(p1.fi != p2.fi) return p1.fi > p2.fi;
	return p1.se < p2.se;
}
vt<int> e[N];
PII dp[N][2]; //1代表该节点是好节点,0代表不是好节点,fi表示节点个数,se表示节点累加权值
void dfs(int u,int f){
	dp[u][0] = {0,1}; //不是好节点就默认1
	dp[u][1] = {1,e[u].size()}; //是好节点就是邻居节点数量
	for(auto v:e[u]){
		if(v==f) continue;
		dfs(v,u);
		dp[u][1].fi += dp[v][0].fi;
		dp[u][1].se += dp[v][0].se;
		//第一优先级节点数量,在保证数量最多时再去取最小权值
		if(cmp(dp[v][0],dp[v][1])){
			dp[u][0].fi += dp[v][0].fi;
			dp[u][0].se += dp[v][0].se;
		}else{
			dp[u][0].fi += dp[v][1].fi;
			dp[u][0].se += dp[v][1].se;
		}
	}
}
int ans[N];
void dfs2(int u,int f){
	for(auto v:e[u]){
		if(v==f) continue;
		if(ans[u]){
			dfs2(v,u);
		}else{
			if(cmp(dp[v][0],dp[v][1])){
				dfs2(v,u);
			}else{
				ans[v] = 1;
				dfs2(v,u);
			}
		}
	}
}
int n;
void solve(){
	cin >> n;
	for(int i = 1;i <= n - 1;i++){
		int x,y;
		cin >> x >> y;
		e[x].pb(y);
		e[y].pb(x);
	}
	dfs(1,0);
	if(n==2){
		cout << 2 << " " << 2 <<endl;
		for(int i = 1;i <= n;i++){
			if(ans[i]){
				cout << e[i].size() << " ";
			}else{
				cout << 1 << " ";
			}
		}
		return;

	}
	if(cmp(dp[1][0],dp[1][1])){
		cout << dp[1][0].fi << " " << dp[1][0].se << endl;
	}else{
		cout << dp[1][1].fi << " " << dp[1][1].se << endl;
		ans[1] = 1;
	}
	dfs2(1,0);
	for(int i = 1;i <= n;i++){
		if(ans[i]){
			cout << e[i].size() << " ";
		}else{
			cout << 1 << " ";
		}
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
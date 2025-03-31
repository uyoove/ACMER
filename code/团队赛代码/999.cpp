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
const int P = 1e9+7;
const int N = 1005;
int n,m;
int memo[N][N];
int f[N][N];
int mi = inf;
queue<PII> q;
int vis[N][N];
struct node{
	int val,r,c;
	bool operator<(const node& t1)const{
		return val < t1.val;
	}
};
int mx[4] = {0,0,1,-1};
int my[4] = {1,-1,0,0};
vector<node> e;
int dfs(int r,int c,int dep){
	if(memo[r][c] != -1 && dep >= 4) return memo[r][c];
	int res = 0;
	bool f1 = false;
	for(int i = 0;i < 4;i++){
		int nx = r + mx[i],ny = c + my[i];
		if(nx <= 0 || ny <= 0 || nx >n || ny > m || f[nx][ny] != f[r][c] + 1) continue;
		f1 = true;
		vis[nx][ny] = 1;
		res+=dfs(nx,ny,dep+1);
		res%=P;
	}
	if(f1) return memo[r][c] = res;
	if(dep < 4) return 0;
	return 1;
}
void solve(){
	cin >> n >> m;
	memset(memo,-1,sizeof memo);
	for(int i = 1;i<=n;i++){
		for(int j = 1;j <= m;j++){
			cin >> f[i][j];
			e.pb({f[i][j],i,j});
		}
	}
	sort(e.begin(),e.end());
	int ans = 0;
	for(int i = 0; i <e.size();i++){
		int val = e[i].val;
		int r = e[i].r , c = e[i].c;
		if(vis[r][c]) continue;
		ans+=dfs(r,c,1);
		ans%=P;
	}
	cout << ans << endl;

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
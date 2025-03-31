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
const int N = 306;
int mx[4] = {1,-1,0,0};
int my[4] = {0,0,-1,1};
int h,w,t;
int sx,sy,ex,ey;
struct node
{
	int r,c;
};
char grid[N][N];
int dis[N][N];
int dp[(1ll << 20) + 3][25];
int vis[N][N];
vector<node> v;
int bfs(int a,int b){
	int sx = v[a].r, sy = v[a].c;
	int ex = v[b].r, ey = v[b].c;
	memset(vis,0,sizeof vis);
	vis[sx][sy] = 1;
	queue<node> q;
	q.push({sx,sy});
	while(!q.empty()){
		auto p = q.front();q.pop();
		int x = p.r, y = p.c;
		for(int i = 0; i < 4;i++){
			int nx = x + mx[i];
			int ny = y + my[i];
			if(nx <= 0 || nx > h || ny <= 0 || ny > w || vis[nx][ny] || grid[nx][ny]=='#'){
				continue;
			}
			if(nx==ex && ny == ey){
				return vis[x][y];
			}
			vis[nx][ny] = vis[x][y] + 1;
			q.push({nx,ny});
		}
	}
	return inf;
}
void solve(){
	cin >> h >> w >> t;
	for(int i = 1; i <= h;i++){
		for(int j = 1;j <= w;j++){
			cin >> grid[i][j];
			if(grid[i][j]=='S') sx = i,sy = j;
			else if(grid[i][j]=='G') ex = i,ey = j;
			else if(grid[i][j]=='o') v.pb({i,j});
		}
	}
	v.pb({sx,sy});
	v.pb({ex,ey});
	int sz = v.size();
	//memset(dis,0x3f,sizeof dis);
	for(int i = 0; i < sz;i++){
		for(int j = i + 1;j < sz;j++){
			dis[i][j] = dis[j][i] = bfs(i,j);
			//cout << "i: " << i << "j: " << j << "dis[i][j]: " << dis[i][j] << endl;
		}
	}
	if(dis[sz-2][sz-1] > t){
		cout << -1 << endl;
		return;
	}
	memset(dp,0x3f,sizeof dp);
	//到达一个集合i且包含j的最小步数花费,通过j为桥梁联通其他的点,我们选最优的j,因为子集可以多个j点都可以到达k,
	dp[1 << (sz - 2)][sz - 2] = 0; 
	for(int i = (1 << (sz - 2)); i < (1 << (sz));i++){
		//包含起点
		if(!((i >> (sz-2))&1)){
			continue;
		}
		for(int j = 0;j < sz;j++) if((i >> j) & 1){
			for(int k = 0; k < sz;k++){
				if((i >> k)&1) continue;
				dp[i|(1<<k)][k] = min(dp[i|(1<<k)][k],dp[i][j] + dis[j][k]);
			}
		}
	}
	int ans = 0;
	for(int i = (1 << (sz - 2)); i < (1 << (sz));i++){
		if(!((i >> (sz-2))&1) || !((i >> (sz-1))&1) || dp[i][sz - 1] > t) continue;
		int su = __builtin_popcount(i);
		ans=max(su-2,ans);
	}
	cout << ans <<endl;
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
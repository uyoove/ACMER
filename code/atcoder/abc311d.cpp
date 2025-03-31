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
const int N = 205;
string grid[N];
int n,m;
int mx[4] = {1,-1,0,0};
int my[4] = {0,0,1,-1};
int ans = 0;
int vis[205][205][4];
void dfs(int r,int c,int fx){
	if(vis[r][c][fx]) return;
	vis[r][c][fx] = 1;
	//ans++;
	int nr = r + mx[fx],nc = c + my[fx];
	if(grid[nr][nc] == '#'){
		for(int i = 0;i < 4;i++){
			int nr = r + mx[i],nc = c + my[i];
			if(grid[nr][nc] == '#') continue;
			dfs(nr,nc,i);
		}
	}else{
		dfs(nr,nc,fx);
	}
}
void solve(){
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> grid[i],grid[i] = " " + grid[i]; 
	dfs(2,2,2);
	dfs(2,2,0);
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			if(vis[i][j][0] || vis[i][j][1] || vis[i][j][2] || vis[i][j][3]) ans++;
		}
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
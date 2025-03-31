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
int n,m;
char grid[1010][1010];
int vis[1010][1010];
int rs[1010][1010]; 
bool dfs(int r,int c){
	if(r > n || c >m || r <= 0 || c <= 0 || rs[r][c] == 1) return true;
	if(vis[r][c] || grid[r][c] =='?') {
		return false;
	}
	vis[r][c] = 1;
	if(grid[r][c] == 'U') rs[r][c] = dfs(r-1,c);
	if(grid[r][c] == 'D') rs[r][c] =dfs(r+1,c);
	if(grid[r][c] == 'R') rs[r][c] =dfs(r,c + 1);
	if(grid[r][c] == 'L') rs[r][c] = dfs(r,c - 1);
	return rs[r][c];
}
int mx[4]= {0,0,-1,1};
int my[4] = {1,-1,0,0};
void solve(){
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			cin >> grid[i][j];
			vis[i][j] = 0;
			rs[i][j] = 0;
		}
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			if(vis[i][j]) continue;
			dfs(i,j);

		}
	}
	int res = n*m;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			if(rs[i][j]) res--;
			else if(grid[i][j] == '?'){
				int p = 1;
				for(int k = 0;k < 4;k++){
					int nx = i + mx[k],ny = j+my[k];
					if(nx > n || ny > m || nx <= 0 || ny <= 0) continue;
					p&=rs[nx][ny];
				}
				if(p) res--;
			}
		}
		
	}
	cout << res <<endl;
}

signed main(){
	std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
	int times = 1;
	cin >> times;
	while(times--){
		solve();
	}
	return 0;
}
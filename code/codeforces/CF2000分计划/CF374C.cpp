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
const int N = 1000005;
int n,m;
string g[N];
map<char,char> mp;
int mx[4] = {1,0,0,-1};
int my[4] = {0,1,-1,0};
int gt(int x,int y){
	return (x - 1) * (m) + y;
}
struct edges{
	int v,ne;
}e[N << 1];
int h[N],idx = 1;
void add(int u,int v){
	e[++idx] = {v,h[u]};
	h[u] = idx;
}
int cur = 1;
int vis[N],dp[N];
char p[N];
int f = 0;
void dfs(int u){
	if(vis[u]==cur){
		f = 1;
		return;
	} 
	if(dp[u]) return;
	vis[u] = cur;
	int res = 0;
	for(int i = h[u];i;i=e[i].ne){
		int v = e[i].v;
		dfs(v);
		if(f) return;
		dp[u] = max(dp[u],dp[v]);
	}
	vis[u] = 0;
	if(p[u]=='A') dp[u]++;

}
void solve(){
	mp['D'] = 'I';
	mp['I'] = 'M';
	mp['M'] = 'A';
	mp['A'] = 'D';
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> g[i];
		g[i] = " " + g[i];
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			p[gt(i,j)] = g[i][j];
			//cout << gt(i,j) << ' ';
			for(int k = 0;k < 4;k++){
				int nx = i + mx[k],ny = j + my[k];
				if(nx<=0||ny<=0||nx>n||ny>m) continue;
				if(mp[g[i][j]] == g[nx][ny]) {
					add(gt(i,j),gt(nx,ny));
					//cout << i << " " << j << " -- " << nx << " " << ny <<endl;
				}
			}

		}
		//cout << endl;
	}
	int res = 0;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			if(g[i][j] == 'D'){
				cur++;
				dfs(gt(i,j));
				if(f){
					cout << "Poor Inna!" <<endl;
					return;
				}
				res = max(res,dp[gt(i,j)]);
			}
		}
	}
	if(res)cout << res << endl;
	else cout << "Poor Dima!" << endl;
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
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
const int N = 200005;
struct DSU {
    vector<int> f, sz;
    vector<set<int>> se;
    DSU(){}
    DSU(int n) {
        init(n);
    }
    void init(int n) {
        f.resize(n);
        se.resize(n);
        iota(f.begin(), f.end(), 0);
        sz.assign(n, 1);
        for(int i = 1;i < n;i++){
        	se[i].insert(i);
        }
    }
    int fd(int x) {
        if(f[x]==x) return x;
        return f[x] = fd(f[x]);
    }
    bool same(int x, int y) {
        return fd(x) == fd(y);
    }
    bool mg(int x, int y) {
        x = fd(x);
        y = fd(y);
        if (x == y)return false;
        if(se[x].size() > se[y].size()){
        	sz[x] += sz[y];
        	f[y] = x;
        	for(auto &p:se[y]) se[x].insert(p);
        }else{
        	sz[y] += sz[x];
        	f[x] = y;
        	for(auto &p:se[x]) se[y].insert(p);
        }
        
        return true;
    }
    int size(int x) {
        return se[fd(x)].size();
    }

};
int n,m;
int grid[1010][1010];
int vis[1010][1010];
DSU dsu;
int gt(int r,int c){
	return (r - 1)*m + c;
}
void dfs(int r,int c,int pr,int pc){
	if(r <= 0 || c <= 0 || r > n || c > m || grid[r][c] == 1 || vis[r][c]) return;
	
	if(grid[r + 1][c] == 1 || grid[r][c - 1] == 1 || grid[r - 1][c] == 1 ||grid[r][c + 1] == 1){
		dsu.se[dsu.fd(gt(pr,pc))].insert(gt(r,c));
		return;
	}
	vis[r][c] = 1;
	dsu.mg(gt(r,c),gt(pr,pc));
	dfs(r+1,c,r,c);
	dfs(r-1,c,r,c);
	dfs(r,c+1,r,c);
	dfs(r,c-1,r,c);
}

void solve(){
	cin >> n >> m;
	dsu.init(n*m +2);
	for(int i=1;i<=n;i++){
		string s;
		cin >> s;
		for(int j = 1;j <= m;j++){
			if(s[j - 1]== '#'){
				grid[i][j] = 1;
			}
		}
	}
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=m;j++){
			if(vis[i][j]) continue;
			if(grid[i + 1][j] == 1 || grid[i][j - 1] == 1 || grid[i - 1][j] == 1 ||grid[i][j + 1] == 1) continue;
			dfs(i,j,i,j);
		}
	}
	int mx = 0;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			mx=max(mx,dsu.size(gt(i,j)));
		}
	}
	cout << mx << endl;
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
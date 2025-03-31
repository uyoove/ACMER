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
int n,m,s,t;
const int N = 2100;
int h[N*N],idx = 1;
struct edges{
	int v,c,ne;
}e[N*N * 4];
void ad(int u,int v,int c){
	e[++idx] = {v,c,h[u]};
	h[u] = idx;
}
void add(int u,int v,int c){
	ad(u,v,c);
	ad(v,u,0);
}
int d[N*N],cur[N*N];
bool bfs(){
	memset(d,0,sizeof d);
	queue<int> q;
	d[s] = 1;
	q.push(s);
	cur[s] = h[s];
	while(q.size()){
		int u = q.front();q.pop();
		for(int i = h[u];i;i=e[i].ne){
			int v = e[i].v;
			if(!d[v] && e[i].c){
				cur[v] = h[v];
				d[v] = d[u] + 1;
				if(v == t) return true;
				q.push(v);
			}
		}
	}
	return false;
}
int dfs(int u,int mf){
	if(u==t) return mf;
	int su = 0;
	for(int i = cur[u];i;i=e[i].ne){
		int v = e[i].v;
		cur[u] = i;
		if(d[v] == d[u] + 1 && e[i].c){
			int f = dfs(v,min(e[i].c,mf));
			mf -= f;
			su+=f;
			e[i].c-=f;
			e[i^1].c+=f;
			if(mf == 0) break;
		}
	}
	if(su==0) d[u] = -1;
	return su;
}
int dinic(){
	int mxflow = 0;
	while(bfs()){
		mxflow += dfs(s,1e10);
	}
	return mxflow;
}
int id(int r,int c){return (r-1)*n+c;}
int a[N][N];
int mx[8] = {-2,-2,-1,1,2,2,1,-1};
int my[8] = {-1,1,2,2,1,-1,-2,-2};
void solve(){
	cin >> n >> m;
	int su = n*n - m;
	s = 0, t = n*n + 3; 
	for(int i = 1;i <= m;i++){
		int r,c;
		cin >> r >> c;
		a[r][c] = 1;
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			if(a[i][j]==1) continue;
			if((i + j)%2){
				add(s,id(i,j),1);
				for(int k = 0;k < 8;k++){
					int nx = mx[k] + i,ny = my[k] + j;
					if(nx <= 0 || ny <= 0 || nx > n || ny > n || a[nx][ny]) continue;
					add(id(i,j),id(nx,ny),1e9);
				}	
			}else{
				add(id(i,j),t,1);
			}
		}
	}
	cout << su - dinic();
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
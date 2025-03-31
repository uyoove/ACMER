//和爸爸一起学编程真好,不过要小学四年级分流考试了,最近没时间写代码了,呜呜呜
#include<bits/stdc++.h>
using namespace std;
#define out(x) cout << #x << '=' << (x) << endl
#define out2(x, y) cout << #x << '=' << (x) << ',' << #y << '=' << (y) << endl 
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
const int N = 3e3+100;
int n,m,s,t,k;
struct edges{
	int v,c,w,ne;
}e[1000006];
int h[N],idx = 1;
void ad(int u,int v,int c,int w){
	e[++idx] = {v,c,w,h[u]};
	h[u] = idx;
}
void add(int u,int v,int c,int w){
	ad(u,v,c,w);
	ad(v,u,0,-w);
}
int mf[N],vis[N],d[N],pre[N];
bool SPFA(){
	memset(d,-0x3f,sizeof d);
	memset(mf,0,sizeof mf);
	d[s] = 0,vis[s] = 1,mf[s] = 1e9;
	queue<int> q;
	q.push(s);
	while(q.size()){
		int u =q.front();q.pop();
		vis[u] = 0;
		for(int i =h[u];i;i=e[i].ne){
			int v = e[i].v;
			int w = e[i].w;
			if(d[v] < d[u] + w && e[i].c){
				pre[v] = i;
				d[v] = d[u] + w;
				mf[v] = min(mf[u],e[i].c);
				if(!vis[v]){
					vis[v] = 1;
					q.push(v);
				}
			}
		}
	}
	return mf[t] > 0;
}
int EK(){
	int cost = 0;
	while(SPFA()){
		int v = t;
		while(v!=s){
			int i = pre[v];
			e[i].c -= mf[t];
			e[i ^ 1].c += mf[t];
			v = e[i^1].v;
		}
		cost += mf[t]*d[t];
	}
	return cost;
}
int grid[51][51];
int gt(int i,int j,int k){
	return (i - 1)*m + j +  k*n*m;
}
void print(int id){
	int x = 1,y = 1;
	while(true){
		if(x==n&&y==m) return;

		for(int i = h[gt(x,y,1)];i;i=e[i].ne){
			int v = e[i].v;
			int p = gt(x,y+1,0);
			int p1 = gt(x + 1,y,0);
			//cout << x << " " <<y << " " << v << " "<< gt(x,y+1,0) <<" "<<  e[i^1].c << endl;
			if(e[i ^ 1].c == 0) continue; //反边有流量说明可以走
			if(v==p){
				e[i^1].c--;
				cout << id << " " << 1 << endl;
				y++;
				break; 
			}
			else if(v==p1){
				e[i^1].c--;
				cout << id << " " << 0 << endl;
				x++;
				break; 
			}
		}
	}
}
void solve(){
	cin >> k;
	cin >> m >> n;
	s = N - 1;
	t = s - 1;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			cin >> grid[i][j];
		}
	}
	 add(s,gt(1,1,0),k,0);
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			if(grid[i][j] == 2){
				add(gt(i,j,0),gt(i,j,1),1,1);
				add(gt(i,j,0),gt(i,j,1),k,0);
			}else if(grid[i][j] == 0){
				add(gt(i,j,0),gt(i,j,1),k,0);
			}
		}
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			if(grid[i][j] == 1) continue;
			if(i+1 <= n && grid[i+1][j] != 1){
				add(gt(i,j,1),gt(i+1,j,0),k,0);
			}
			if(j+1 <= m && grid[i][j + 1] != 1){
				add(gt(i,j,1),gt(i,j + 1,0),k,0);
			}
		}
	}
	add(gt(n,m,1),t,k,0);
	EK();
	for(int i = 1;i <= k;i++){
		print(i);
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
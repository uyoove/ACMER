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


const ll inf = 0x3f3f3f3f3f3f3f3fLL;
const int infi = 0x3f3f3f3f;
const int P = 13331;
const int N = 200005;
int n,m,s,t;
struct egdes
{
	int w,v,ne;
}e[N << 1];
int h[N],idx = 1;
void add(int u,int v,int w){
	egdes pp = {w,v,h[u]};
	e[++idx] = pp;
	h[u]=idx;
}
int dis[N][2],vis[N];
void spfa(){
	queue<int> q;
	memset(dis,0x3f,sizeof dis);
	dis[s][0] = 0;
	vis[s] = 1;
	q.push(s);
	while(q.size()){
		int u = q.front();q.pop();
		vis[u] = 0;
		for(int i = h[u];i;i=e[i].ne){
			int v = e[i].v;
			if(dis[u][0] + e[i].w < dis[v][0]){
				dis[v][1] = dis[v][0];
				dis[v][0] = dis[u][0] + e[i].w;
				if(!vis[v]) q.push(v),vis[v] = 1;
			}
			if(dis[u][0] + e[i].w > dis[v][0] && dis[u][0] + e[i].w < dis[v][1]){
				dis[v][1] = dis[u][0] + e[i].w;
				if(!vis[v]) q.push(v),vis[v] = 1;
			}
			if(dis[u][1] + e[i].w < dis[v][1]){
				dis[v][1] = dis[u][1] + e[i].w;
				if(!vis[v]) q.push(v),vis[v] = 1;
			}
		}
	}
}
void solve(){
	cin >> n >> m;
	s = n, t = 1;
	for(int i = 1;i <= m;i++){
		int u,v,w;
		cin >> u >> v >> w;
		add(u,v,w);
		add(v,u,w);
	}
	spfa();
	cout << dis[t][1] << endl;
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
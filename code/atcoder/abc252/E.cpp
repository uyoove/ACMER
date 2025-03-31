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
struct Edges
{
	int v,ne,nodes,w;
}e[N << 1];
int h[N],idx = 1;
int n,m;
void add(int u,int v,int nodes,int w){
	e[++idx] = {v,h[u],nodes,w};
	h[u] = idx;
}
int dis[N],vis[N],ans[N],tp[N];
void solve(){
	cin >> n >> m;
	for(int i = 1;i <= m;i++){
		int u,v,w;
		cin >> u >> v >>w;
		add(u,v,i,w);
		add(v,u,i,w);
	}
	memset(dis,0x3f,sizeof dis);
	priority_queue<PII,vt<PII>,greater<PII>> pq;
	pq.push({0,1});
	dis[1] = 0;
	while(pq.size()){
		auto p = pq.top();pq.pop();
		int u = p.se,val = p.fi;
		if(vis[u]) continue;
		vis[u] = 1;
		for(int i = h[u];i;i=e[i].ne){
			int v = e[i].v;
			if(dis[v] > dis[u] + e[i].w){
				int ns = e[i].nodes;
				ans[ns] = 1;
				ans[tp[v]] = 0;
				tp[v] = ns;
				dis[v] = e[i].w + dis[u];
				pq.push({dis[v],v});
			}
		}
	}
	for(int i = 1;i<=m;i++){
		if(ans[i]) cout << i << " ";
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
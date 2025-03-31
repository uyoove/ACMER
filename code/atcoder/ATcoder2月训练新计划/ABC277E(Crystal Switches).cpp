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
int n,m,k;
int vis[N][2],dis[N][2],c[N];
struct edges{
	int v,ne,a;
}e[N << 1];
int h[N],idx = 1;
void add(int u,int v,int x){
	e[++idx] = {v,h[u],x};
	h[u] = idx;
}
struct nodes{
	int u,val,op;
	bool operator<(const nodes t1)const{
		return val > t1.val;
	}
};
void dij(){
	priority_queue<nodes> pq;
	for(int i = 0;i < N;i++){
		for(int j = 0;j<=1;j++){
			dis[i][j] = infi;
		}
	}
	dis[1][0] = 0;
	pq.push({1,0,0});
	while(pq.size()){
		auto p = pq.top();pq.pop();
		int u = p.u,val = p.val,op = p.op;
		if(vis[u][op]) continue;
		vis[u][op] = 1;
		

		for(int i = h[u];i;i=e[i].ne){
			int v = e[i].v;

			if(c[u]){
				if((e[i].a ^ op) && dis[u][op] + 1 < dis[v][op]){
					dis[v][op] = dis[u][op] + 1;
					pq.push({v,dis[v][op],op});
				}
				if((e[i].a ^ op ^ 1) && dis[u][op] + 1 < dis[v][op^1]){
					dis[v][op ^ 1] = dis[u][op] + 1;
					pq.push({v,dis[v][op ^ 1],op ^ 1});
				}
				
			}else{

				if(!(e[i].a^op))continue;
				if(dis[u][op] + 1 < dis[v][op]){
					dis[v][op] = dis[u][op] + 1;
					pq.push({v,dis[v][op],op});
				}
			}
		}
	}
}
void solve(){
	cin >> n >> m >> k;
	for(int i = 1;i <= m;i++){
		int u,v,w;
		cin >> u >> v >> w;
		add(u,v,w);
		add(v,u,w);
	}
	for(int i = 1;i <= k;i++){
		int t;
		cin >> t;
		c[t] = 1;
	}
	dij();
	if(min(dis[n][0],dis[n][1]) > 1000005){
		cout << -1 <<endl;
		return;
	}
	cout << min(dis[n][0],dis[n][1]) << endl;
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
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <iostream>
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
const int N = 2005;
int n,m;
struct nodes{
	int u,my,k; //节点,钱数,油;
	bool operator<(const nodes &t)const{
		return t.my < my;
	}
};
struct edges{
	int v,w,ne;
}e[N*20];
int h[N],idx = 1;
void add(int u,int v,int w){
	e[++idx] = {v,w,h[u]};
	h[u] = idx;
}
int a[N];
int vis[N][105];
int dis[N][105];
//多个状态或许 下一个节点与更新状态分开写速率会优秀许多
void solve(){
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	for(int i = 1;i <= m;i++){
		int u,v,w;
		cin >> u >> v >> w;
		u++,v++;
		add(u,v,w);
		add(v,u,w);
	}
	int _;
	cin >> _;
	while(_--){
		int c,s,t;
		cin >> c >> s >> t;
		s++,t++;
		memset(vis,0,sizeof vis);
		memset(dis,0x3f,sizeof dis);
		dis[s][0] = 0;
		priority_queue<nodes> q;
		nodes t1 = {s,0,0};
		q.push(t1);
		int ans = inf;
		bool f = true;
		while(q.size()){
			if(!f) break;
			nodes p = q.top();q.pop();
			int u = p.u,my = p.my,k = p.k;
			if(u==t){
				ans = my;
				f = false;
				break;
			}
			if(vis[u][k]) continue;
			vis[u][k] = 1;
			if(k < c){
				int pk = k + 1;
				int pmy = my + a[u];
				if(dis[u][pk] > pmy){
					dis[u][pk] = pmy;
					nodes t1 = (nodes){u,pmy,pk};
					q.push(t1);
				}
			}

			for(int i = h[u];i;i=e[i].ne){
				int v = e[i].v;
				int w = e[i].w;
				if(k < w) continue;
				int sy = k - w;
				if(dis[v][sy] > my){
					dis[v][sy] = my;
					nodes t1 = {v,my,sy};
					q.push(t1);	
				}
				
			}
		}
		
		if(ans==inf){
			cout << "impossible" << endl;
		}else{
			cout << ans << endl;
		}
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
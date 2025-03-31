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
const int N = 50010;
struct edges{
	int v,w,ne;
}e[N << 2];
int n,m;
int h[N],idx = 1;
ll dis[N];
int w[N],vis[N];
int s;
void add(int u,int v,int w){
	edges p = {v,w,h[u]};
	e[++idx] = p,h[u] = idx;
}
void spfa(){
	for(int i = 1;i <= n;i++) dis[i] = inf,vis[i] = 0;
	priority_queue<PII,vector<PII>,greater<PII>> q;
	q.push(make_pair(0,s));
	dis[s] = 0;
	while(q.size()){
		pair<int,int> p = q.top();q.pop();
		int u = p.se;
		if(vis[u]) continue;
		vis[u] = 1;
		for(int i = h[u];i;i=e[i].ne){
			int v = e[i].v;
			if(dis[v] > dis[u] + e[i].w){
				dis[v] = dis[u] + e[i].w;
				q.push(make_pair(dis[v],v));
			}
		}
	}
}
void solve(){
	idx = 1;
	n = read(),m = read();
	s = 1;
	for(int i = 1;i <= n;i++) w[i] = read(),h[i] = 0;
	for(int i = 1;i <= m;i++){
		int u=read(),v=read(),w=read();
		
		add(u,v,w);
		add(v,u,w);
	}
	spfa();
	ll ans = 0;
	for(int i = 1;i <= n;i++){
		if(dis[i]==inf){
			cout << "No Answer" <<endl;
			return;
		}
		ans+=w[i] * dis[i] * 1ll;
	}
	cout << ans << endl;
}

signed main(){
	int times = 1;
	times=read();
	while(times--){
		solve();
	}
	return 0;
}
//最后一舞
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define vt vector
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define PII pair<int,int>
#define endl "\n"
const int P = 13331;
const int N = 1010;
struct edges{
	int v,ne;
}e[N << 1];
int h[N],idx = 1;
void add(int u,int v){
	e[++idx] = {v,h[u]};
	h[u] = idx;
}
int n,m,q;
int dis[N],vis[N];
int val[N][N]; //到i这个点,距离为j的点的个数
void dij(int st){
	memset(dis,0x3f,sizeof dis);
	memset(vis,0,sizeof vis);
	dis[st] = 0;
	priority_queue<PII,vt<PII>,greater<PII>> pq;
	pq.push({0,st});
	while(pq.size()){
		auto p = pq.top();pq.pop();
		int u = p.se,val = p.fi;
		if(vis[u]) continue;
		vis[u] = 1;
		for(int i = h[u];i;i=e[i].ne){
			int v = e[i].v;
			if(dis[u] + 1 < dis[v]){
				dis[v] = dis[u] + 1;
				pq.push({dis[v],v});
			}
		}
	}
	for(int i = 1;i <= n;i++){
		if(dis[i] > 1000) continue;
		val[st][dis[i]]++;
	}
	for(int i = 1;i <= n;i++) val[st][i]+=val[st][i-1];
}
void solve(){
	cin >> n >> m >> q;
	for(int i = 1;i <= m;i++){
		int u,v;
		cin >> u >> v;
		add(u,v),add(v,u);
	}
	for(int i = 1;i <= m;i++ ) dij(i);
	int cnt = 0;
	for(int i = 1;i <= q;i++){
		int x,y;
		cin >> x >> y;
		cnt+=val[x][y];
	}
	double p = cnt*1.0/q;
	printf("%.2lf",p);
}

signed main(){
	int times = 1;
	//cin >> times;
	while(times--){
		solve();
	}
	return 0;
}
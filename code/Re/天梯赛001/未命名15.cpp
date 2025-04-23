#include<bits/stdc++.h>
using namespace std;
#define int long long
#define vt vector
#define fi first
#define se second 
const int N = 500 + 10;
struct edges{
	int v,ne,w,c;
}e[N << 1];
int h[N],idx = 1;
void add(int u,int v,int w,int c){
	e[++idx] = {v,h[u],w,c},h[u] = idx;
} 
pair<int,int> dis[N];
int vis[N];
int val,n,m,q;
struct nodes{
	int u,d,hp;
	bool operator<(const nodes&t1)const{
		if(d!=t1.d) return d > t1.d;
		return hp < t1.hp;
	}
};
void dij(int u){
	for(int i = 1;i <= n;i++){
		dis[i].fi = 0x3f3f3f3f3f;
	}
	memset(vis,0,sizeof vis);
	priority_queue<nodes> pq;
	dis[u].fi = 0;
	pq.push({u,0,0});
	while(pq.size()){
		auto p = pq.top();pq.pop();
		int u = p.u,d = p.d,hp = p.hp;
		if(vis[u]) continue;
		vis[u] = 1;
		for(int i = h[u];i;i=e[i].ne){
			int v = e[i].v;
			if(dis[v].fi > dis[u].fi + e[i].w){
				dis[v].fi = dis[u].fi + e[i].w;
				dis[v].se = dis[u].se + e[i].c;
				pq.push({v,dis[v].fi,dis[v].se});
			}else if(dis[v].fi == dis[u].fi + e[i].w){
				if(dis[v].se < dis[u].se + e[i].c){
					dis[v].se = dis[u].se + e[i].c;
					pq.push({v,dis[v].fi,dis[v].se});
				}
			}
		}
	}	
}
void solve(){
	cin >> val >> n >> m >> q;
	for(int i = 1;i <= m;i++){
		int u,v,w,c;
		cin >> u >> v >> w >> c;
		add(u,v,w,c);
		add(v,u,w,c);
	}
	while(q--){
		int u;
		cin >> u;
		dij(u);
		bool f=  1;
		bool ok = 1;
		int mx = 0;
		for(int i = 1;i <= n;i++){
			if(dis[i].fi<=val && i!=u){
				if(ok) cout << i,ok = 0;
				else cout << " " << i;
				f = 1;
				mx = max(mx,dis[i].se);
			}
		}
		if(!f){
			cout << "T_T" << endl;
			continue;
		}else{
			cout << endl;
			bool ok = 1;
			for(int i = 1;i <= n;i++){
				if(dis[i].fi<=val && i!=u && mx==dis[i].se){
					if(ok) cout << i,ok = 0;
					else cout << " " << i;
				}
			}
		}
	}
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	solve();
}

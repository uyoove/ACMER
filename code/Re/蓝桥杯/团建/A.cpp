#include <bits/stdc++.h>
using namespace std;
#define int long long
#define vt vector
#define endl "\n"
const int N = 2e5+10;

int c[N][2];
struct edges{
	struct edge{
		int v,ne;
	}e[N << 1];
	int h[N],idx = 0;
	void add(int u,int v){
		e[++idx] = {v,h[u]};
		h[u] = idx;
	}
}tr[2];
int n,m;
int dis[N][2];
int h[N];
int has[N][2];
map<int,int> ha;
set<int> mp[N][2];
mt19937_64 rnd(time(0)); 
void dfs(int u,int f,int op){
	dis[u][op] = dis[f][op] + 1;
	has[u][op] = h[dis[u][op]] * ha[c[u][op]] + has[c[f][op]][op];
	mp[dis[u][op]][op].insert(has[u][op]);
	for(int i = tr[op].h[u];i;i=tr[op].e[i].ne){
		int v = tr[op].e[i].v;
		dfs(v,u,op);
	}
}
void solve(){
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> c[i][0],h[i] = rnd(),ha[c[i][0]] = rnd();
	for(int i = 1;i <= m;i++) cin >> c[i][1],h[i] = rnd(),ha[c[i][1]] = rnd();
	for(int i = 1;i < n;i++){
		int u,v;
		cin >> u >> v;
		tr[0].add(u,v);
	}
	for(int i = 1;i < m;i++){
		int u,v;
		cin >> u >> v;
		tr[1].add(u,v);
	}
	dfs(1,0,0);
	dfs(1,0,1);
	int mx = 0;
	for(int i = 1;i <= N;i++){
		for(auto &p:mp[i][0]){
			if(mp[i][1].count(p)) mx = i;
		}
		if(mx!=i){
			cout << mx << endl;
			return;
		}
	}
}

signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	solve();
}
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
const int N = 200005;
struct DSU {
    vector<int> f, sz;
    DSU(){}
    DSU(int n) {
        init(n);
    }
    void init(int n) {
        f.resize(n);
        iota(f.begin(), f.end(), 0);
        sz.assign(n, 1);
    }
    int fd(int x) {
        if(f[x]==x) return x;
        return f[x] = fd(f[x]);
    }
    bool same(int x, int y) {
        return fd(x) == fd(y);
    }
    bool mg(int x, int y) {
        x = fd(x);
        y = fd(y);
        if (x == y)return false;
        sz[x] += sz[y];
        f[y] = x;
        return true;
    }
    int size(int x) {
        return sz[fd(x)];
    }
};
int n,m;
 //ok:该连通块拥有奇环,dis:该连通块从一个简单节点出发的距离,vis:dfs序,tot:dfs序递增,ru:找入度小的点当连通块的"根"节点
int ok[N],dis[N],vis[N],tot,ru[N];
struct edges{
	int v,ne;
}e[N << 1];
DSU dsu(N);
int h[N],idx;
void add(int u,int v){
	e[++idx] = {v,h[u]};
	h[u] = idx;
}
void dfs(int u,int f){
	dis[u] = dis[f] + 1; //距离
	vis[u] = ++tot; //dfs序
	//cout << u << " " << vis[u] << endl;
	for(int i = h[u];i;i=e[i].ne){
		int v = e[i].v;
		if(v==f) continue;
		if(vis[v]){
            if(vis[v]==-1) continue;
			if((tot - vis[v])%2==0){
				ok[dsu.fd(v)] = 1; //有奇环
			}
			continue;
		}
		dfs(v,u);

	}
	tot--;
	vis[u] = -1; //回溯
}
void solve(){
	cin >> n >> m;
	memset(ok,-1,sizeof ok);
	vt<PII> v1;
	for(int i = 1;i <= m;i++){
		int u,v;
		cin >> u >> v;
		add(u,v);
		add(v,u);
		ru[u]++,ru[v]++;
		dsu.mg(u,v);
	}
	for(int i = 1;i <= n;i++) v1.pb({ru[i],i}); //排序一下,入度小的优先
	sort(all(v1));
	for(int k = 1;k <= n;k++){
		int i = v1[k-1].se;
		if(ok[dsu.fd(i)]!=-1) continue; //连通块被访问过久不再访问
		ok[dsu.fd(i)] = 0; //访问到一个连通块,先赋予初值默认没有奇环
		dfs(i,0);
	}	
	int q;
	cin >> q;
	while(q--){
		int u,v,l,r;
		cin >> u >> v >> l >> r;
		if(dsu.fd(u)!=dsu.fd(v)){
			cout << "no" << endl; //先判断联通
		}else{
			int p = l + r;
			if(ok[dsu.fd(u)]==1){
				cout << "yes" << endl; //有奇环一定可以
			}else{
				int d = abs(dis[u] - dis[v]);
				if(d%2==p%2){ //判断日夜奇偶是否与距离奇偶相同
					cout << "yes" << endl;
				}else{
					cout << "no" << endl;
				}
			}
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
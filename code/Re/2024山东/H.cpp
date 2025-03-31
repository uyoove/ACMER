//最后一舞
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
bool dfs(int u,vt<vt<int>> &E,vt<int> &match,vt<int>& vis){
	for(auto &v:E[u]){
		if(vis[v]) continue;
		vis[v] = 1;
		if(match[v]==-1 || dfs(match[v],E,match,vis)){
			match[v] = u;
			return true;
		}
	}
	return false;
};
void solve(){
	map<int,vt<PII>> X,Y;
	int n;
	cin >> n;
	for(int i = 1;i <= n;i++){
		int x,y;
		cin >> x >> y;
		X[x].emplace_back(y,0);
		Y[y].emplace_back(x,0);
	}
	int m;
	cin >> m;
	for(int i = 1;i <= m;i++){
		int x,y;
		cin >> x >> y;
		X[x].emplace_back(y,1);
		Y[y].emplace_back(x,1);
	}
	vt<array<int,3>> bx,gy; //bx表示在x1的轴上有 y2,y3两个点, gy反之 
	for(auto &[x,v]: X){
		sort(all(v));
		for(int i = 1;i < v.size();i++){
			auto &[y1,op1] = v[i - 1];
			auto &[y2,op2] = v[i];
			if(op1 || op2) continue;
			if(y2 - y1 <= 1){
				cout << -1 << endl;
				return;
			}
			bx.pb({x,y1,y2});
		}
	}
	for(auto &[y,v]: Y){
		sort(all(v));
		for(int i = 1;i < v.size();i++){
			auto &[x1,op1] = v[i - 1];
			auto &[x2,op2] = v[i];
			if(op1 || op2) continue;
			if(x2 - x1 <= 1){
				cout << -1 << endl;
				return;
			}
			gy.pb({y,x1,x2});
		}
	}
	n = bx.size(),m = gy.size();
	vt<vt<int>> E(n + 1);   
	for(int i = 0;i < n;i++){
		auto &[x,y1,y2] = bx[i];
		for(int j = 0;j < m;j++){
			auto &[y,x1,x2] = gy[j];
			if(x1 < x && x < x2 && y1 < y && y < y2){
				E[i].pb(j); //找十字匹配
			}
		}
	}
	vt<int> match(m+1,-1);
	for(int u = 0;u < n;u++){
		vt<int> vis(m + 1,0);
		dfs(u,E,match,vis);
	}
	vt<PII> res;
	vt<int> has(n + 1,0);
	for(int v = 0;v < m;v++){
		if(match[v]!=-1){
			has[match[v]] = 1;
			res.pb({bx[match[v]][0],gy[v][0]});
		}else{
			res.pb({gy[v][1] + gy[v][2] >> 1,gy[v][0]});
		}
	}
	for(int v = 0;v < n;v++){
		if(has[v]!=1){
			res.pb({bx[v][0],bx[v][1] + bx[v][2] >> 1});
		}
	}
	cout << res.size() << endl;
	for(auto [k,v]:res) cout << k << " " << v << endl;
}	

signed main(){
	std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
	int times = 1;
	cin >> times;
	while(times--){
		solve();
	}
	return 0;
}
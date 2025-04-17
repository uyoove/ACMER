#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define vt vector
#define PII pair<int,int> 
const int N = 2e5 + 10; 
int n;
struct edges{
	int v,ne;
}e[N << 1];
int h[N],idx = 1;
void add(int u,int v){
	e[++idx] = {v,h[u]};
	h[u] = idx;
}
int c[N];
int sz[N],son[N];
void dfs(int u){
	sz[u] = 1;
	for(int i = h[u];i;i=e[i].ne){
		int v = e[i].v;
		dfs(v);
		sz[u] += sz[v];
		if(sz[v] > sz[son[u]]) son[u] = v;
	} 
}
map<int,int> mp;
int val[N];
int flag = 0,ans = 0;
void count(int u,int add){
	mp[val[c[u]]]--;
	if(mp[val[c[u]]]<=0) mp.erase(val[c[u]]);
	val[c[u]]+=add;
	mp[val[c[u]]]++;
	for(int i = h[u];i;i=e[i].ne){
		int v = e[i].v;
		if(v==flag) continue;
		count(v,add);
	}
}
void dfs2(int u,int keep){
	//先轻儿子自己去计算 
	for(int i = h[u];i;i=e[i].ne){
		int v = e[i].v;
		if(v==son[u]) continue;
		dfs2(v,0);
	} 
	//最后重儿子自己去计算 
	if(son[u]){
		dfs2(son[u],1);
		flag = son[u];
	}
	//再算一次轻儿子贡献+没删的重儿子贡献等于当前节点的贡献 
	count(u,1);
	flag = 0;
	if(mp.size()==1) ans++;
//	 cout << u << " " << mp.size() << endl;
//	 for(auto p : mp){
//	 	cout << p.first << " " << p.second << endl;
//	 }
//	 cout << "------------" << endl;
	if(!keep){
		count(u,-1);
	}
}
void solve(){
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> c[i];
		int f;
		cin >> f;
		if(f==0) continue;
		add(f,i);
	}
	dfs(1);
	dfs2(1,0);
	cout << ans << endl;
}

signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	solve();
}

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
struct egdes{
	int v,ne;
}e[N << 1];
int h[N],idx = 1;
void add(int u,int v){
	e[++idx] = {v,h[u]};
	h[u] = idx;
}
int n;
int dep[N],sz[N],top[N],fa[N],son[N];
void dfs(int u,int f){
	sz[u] = 1;
	dep[u] = dep[f] + 1;
	fa[u] = f;
	for(int i = h[u];i;i=e[i].ne){
		int v = e[i].v;
		if(v == f) continue;
		dfs(v,u);
		sz[u] += sz[v];
		if(sz[v] > sz[son[u]]){
			son[u] = v;
		}
	}
}
void dfs2(int u,int t){
	top[u] = t;
	if(!son[u]) return;
	dfs2(son[u],t);
	for(int i = h[u];i;i=e[i].ne){
		int v = e[i].v;
		if(v == son[u] || v== fa[u]) continue;
		dfs2(v,v);
	}
}
int lca(int x,int y){
	while(top[y] != top[x]){
		if(dep[top[x]] < dep[top[y]]){
			swap(x,y);
		}
		x = fa[top[x]];
	}
	return dep[x] < dep[y] ? x : y;
}
int dis(int x,int y){
	return dep[x] + dep[y] - dep[lca(x,y)]*2;
}
bool check(int x,int y){
	return (x <= y)&&(x%2==y%2);
}
void solve(){
	cin >> n;
	for(int i = 1;i < n;i++){
		int u,v;
		cin >> u >> v;
		add(u,v);
		add(v,u);
	}
	dfs(1,0);
	dfs2(1,1);
	int q;
	cin >> q;
	while(q--){
		int a,b,x,y,k;
		cin >> x >> y >> a >>b >> k;
		int ab = dis(a,b),ax = dis(a,x),yb = dis(y,b),ay = dis(a,y),xb = dis(x,b);
		if(check(ab,k)||check(ax + yb + 1,k)||check(ay + xb + 1,k)){
			cout << "Yes" << endl;
		}else{
			cout << "No" << endl;
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
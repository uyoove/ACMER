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
const ll inf = 0x3f3f3f3f3f3f3f3fLL;
const int infi = 0x3f3f3f3f;
const int P = 13331;
const int N = 200005;
int n;
struct edges{
	int v,ne;
}e[N << 1];
int h[N],idx = 1;
void add(int u,int v){
	e[++idx] = {v,h[u]};
	h[u] = idx;
}
int sz[N];
vector<int> son[N];
void dfs(int u,int f){
	sz[u] = 1;
	for(int i = h[u];i;i=e[i].ne){
		if(e[i].v==f) continue;
		dfs(e[i].v,u);
		son[u].pb(e[i].v);
		sz[u]+=sz[e[i].v];
	}
}
int ans = 0;
void solve(){
	cin >> n;
	for(int i = 0; i < n - 1;i++){
		int u,v;
		cin >> u >> v;
		add(u,v);
		add(v,u);
	}
	dfs(1,0);
	int res = n * (n - 1) * (n - 2) / 6;
	for(int i = 1;i <= n;i++){
		int ans = 0;
		for(auto v:son[i]){
			ans += sz[v] * (sz[i] - sz[v] - 1);
		}
		res -= ans/2 + (sz[i] - 1) * (n - sz[i]);
	}
	cout << res <<endl;
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
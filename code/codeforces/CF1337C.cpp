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
struct edges{
	int v,ne;
}e[N << 1];
int h[N],idx = 1;
void add(int u,int v){
	e[++idx] = {v,h[u]};
	h[u] = idx;
}
//深度越深的当工业越划算
int n,k;

struct nodes{
	int dep,id,sz;
	bool operator<(const nodes &t1)const{
		//因为遍历到某个位置,那么下面位置一定是工业,那么就得减sz的贡献,当前为工业的贡献
		//为dep-sz
		return t1.dep - t1.sz < dep - sz;
	}
};
int dep[N],sz[N],cnt[N],vis[N];
vector<nodes> v1;
void dfs(int u,int f){
	dep[u] = dep[f] + 1;
	sz[u] = 1;
	for(int i = h[u];i;i=e[i].ne){
		int v = e[i].v;
		if(v==f) continue;
		dfs(v,u);
		sz[u]+=sz[v];
	}
	v1.push_back({dep[u],u,sz[u]});
}
int ans = 0;
void dfs2(int u,int f){
	for(int i = h[u];i;i=e[i].ne){
		int v = e[i].v;
		if(v==f) continue;
		dfs2(v,u);
		cnt[u]+=cnt[v];
	}
	if(!vis[u]) ans+=cnt[u];
}
void solve(){
	cin >> n >> k;
	for(int i = 1;i <= n - 1;i++){
		int u,v;
		cin >> u >> v;
		add(u,v);
		add(v,u);
	}
	dfs(1,0);
	sort(v1.begin(),v1.end());
	for(int i = 0;i < k;i++){
		cnt[v1[i].id] = 1,vis[v1[i].id] = 1;
		//cout << v1[i].dep <<endl;
	} 
	dfs2(1,0);
	cout << ans << endl;
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
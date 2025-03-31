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
const int N = 500005;
int n;
struct edges{
    int v,ne;
}e[N << 1];
int h[N],idx = 0; //记得初始化-1;
void add(int u,int v){
    e[idx] = {v,h[u]};
    h[u] = idx++;
}
int fa[N],dep[N];
int madep[N],sz[N],leaf[N];
void dfs(int u,int f){
	dep[u] = dep[f]+1;
	madep[u] = dep[u];
	sz[u] = 1;
	fa[u] = f;
	for(int i = h[u];~i;i=e[i].ne){
		int v = e[i].v;
		if(v==f)continue;
		dfs(v,u);
		sz[u]+=sz[v];
		madep[u] = max(madep[u],madep[v]);
	}
	if(sz[u]==1) leaf[u] = 1;
}
vector<int> v[N];
int in[N];
void solve(){
	idx = 0;
	cin >> n;
	for(int i = 0;i <= n;i++) leaf[i] = 0,h[i] = -1,sz[i] = 0,fa[i] = 0,dep[i] = 0,madep[N] = 0,in[i] = 0,v[i].clear();
	for(int i = 0; i <n-1;i++){
		int u,v;
		cin >> u >> v;
		add(u,v);
		add(v,u);
		in[u]++;
		in[v]++;
	}
	dfs(1,0);
	set<int> se;
	vector<int> vis(n+1,0);
	
	for(int i=1;i<=n;i++) se.insert(dep[i]),v[dep[i]].pb(i);
	int su = 0;
	int res = 0x3f3f3f3f;
	for(int p = 1;p <= n;p++){
		queue<int> q;
		int tp = 0;
		for(auto t:v[p]){
			tp+=sz[t]-1;
		}
		//cout <<p << " " << tp <<endl;
		res = min(res,tp + su);
		
		for(auto t:v[p]){
			if(leaf[t]) q.push(t);
		}
		
		while(q.size()){
			int x= q.front();
			q.pop();
			if(vis[x]) continue;
			vis[x] = 1;
			su++;
			for(int i = h[x];~i;i=e[i].ne){
				int v = e[i].v;
				if(v==1) continue;
				if(--in[v] <= 1) q.push(v);
			}
		}
	}
	cout << res <<endl;

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
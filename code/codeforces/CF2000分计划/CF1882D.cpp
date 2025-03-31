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
//要保证f节点与son节点一致,那么son节点就先一步一致
//f 的值应该等于 f ^ son * son.size
int n;
int a[N];
struct edges{
	int v,ne;
}e[N << 1];
int h[N],idx = 1;
void add(int u,int v){
	e[++idx] = {v,h[u]};
	h[u] = idx;
}
int sz[N];
int ans[N],lj[N];
void dfs(int u,int f){
	sz[u] = 1;
	for(int i = h[u];i;i=e[i].ne){
		int v = e[i].v;
		if(v==f) continue;
		dfs(v,u);
		sz[u]+=sz[v];
		ans[u]+=(a[u]^a[v])*sz[v];
		lj[u]+=lj[v] + (a[u]^a[v])*sz[v];
	}
}
void dfs2(int u,int f){
	for(int i = h[u];i;i=e[i].ne){
		int v = e[i].v;
		if(v==f) continue;
		int s = sz[u] - sz[v];
		int as = lj[u] - (a[u]^a[v])*sz[v] - lj[v];
		//cout << u << " " << v << " " << as <<endl;
		lj[v] += s * (a[u]^a[v]) + as;
		sz[v] += s;
		dfs2(v,u);
	}
}
void solve(){
	cin >> n;
	idx = 1;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		h[i] = 0;
		ans[i] = 0,lj[i] = 0;
	}
	for(int i = 1;i < n;i++){
		int u,v;
		cin >>u >> v;
		add(u,v);
		add(v,u);
	}
	dfs(1,0);
	dfs2(1,0);
	for(int i = 1;i <= n;i++){
		cout << lj[i] << " ";
	}
	cout <<endl;
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
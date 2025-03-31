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
int n,m;
int has[20000001];
struct edges
{
	int v,w,ne;
}e[N << 1];
int h[N],idx = 1;
void add(int u,int v,int w){
	e[++idx] = {v,w,h[u]};
	h[u]=idx;
}
int root,nsz; //当前根,当前子树大小
int sz[N],use[N],mx[N];
int cnt,d[N]; //记录其他子树的长度
int dis[N];
void getroot(int u,int f){
	sz[u] = 1;
	mx[u] = 0;
	for(int i = h[u];i;i=e[i].ne){
		int v= e[i].v;
		if(v==f || use[v]) continue;
		getroot(v,u);
		mx[u]=max(mx[u],sz[v]);
		sz[u]+=sz[v];
	}
	mx[u]=max(mx[u],nsz - sz[u]);
	if(mx[u] < mx[root]) root = u;
}
void getdis(int u,int f){
	d[dis[u]%3]++;
	for(int i = h[u];i;i=e[i].ne){
		int v = e[i].v;
		if(v==f || use[v]) continue;
		dis[v] = dis[u] + e[i].w;
		getdis(v,u);
	}
}
int ans = 0;
void calc(int u){
	vector<int> del;
	for(int i = h[u];i;i=e[i].ne){
		int v = e[i].v;
		if(use[v]) continue;
		d[0] = 0,d[1] = 0,d[2] = 0;
		dis[v] = e[i].w;
		getdis(v,u);
		for(int j = 0;j <= 2;j++){
			ans+= has[(3 - j)%3]*d[j] * 2;
		}
		ans+=d[0]*2;
		for(int j = 0;j <= 2;j++) has[j] += d[j];
	}
	has[0] = 0,has[1] = 0,has[2] = 0;
}
void dfz(int u){
	calc(u);
	//删上层节点
	use[u] = 1;
	for(int i = h[u];i;i=e[i].ne){
		int v = e[i].v;
		if(!use[v]){
			root = 0;
			mx[0] = nsz = sz[v];

			getroot(v,0),getroot(root,0);
			dfz(root);
		}
	}
}
void solve(){
	cin >> n;
	for(int i = 1;i < n;i++){
		int u,v,w;
		cin >> u >> v >> w;
		add(u,v,w);
		add(v,u,w);
	}
	mx[0] = n;
	nsz = n;
	getroot(1,0),getroot(root,0);
	dfz(root);
	ans+=n;
	int d = n*n;
	int g = __gcd(d,ans);
	cout << ans/g << "/" << d/g << endl;
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
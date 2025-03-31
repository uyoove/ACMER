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
int sbtm = 0;
int n = 0;
int g[100];
int sz[N];
int hd[N],idx = 1;
struct edges{
	int v,ne;
}e[N<<1];
void add(int u,int v){
	e[++idx] ={v,hd[u]},hd[u] = idx;
}
map<int,int> h;
bool f = false;
void dfs(int u,int f){
	sz[u] = 1;
	for(int i=hd[u];i;i=e[i].ne){
		int v = e[i].v;
		if(v==f) continue;
		dfs(v,u);
		sz[u]+=sz[v];
	}
	if(h.count(sz[u] - 1) && h.count(n - sz[u] + 1)) f=true;
}
void solve(){
	cin >> n;
	if(n==1){
		cout << "Y" << endl;
		return;
	}
	if(!h.count(n) && n!=1){
		cout << "N" <<endl;
		return;
	}
	for(int i = 1;i < n;i++){
		int u,v;
		cin >> u >> v;
		add(u,v);
		add(v,u);
	}
	dfs(1,0);
	
	if(f) cout <<"Y";
	else cout << "N" <<endl;
}

signed main(){
	std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
	int times = 1;
	//cin >> times;
	g[1] = 1;
	g[2] = 1;
	for(int i = 3;i<=100;i++){
		g[i] = g[i - 1] + g[i - 2];
		h[g[i]]++;
		if(g[i] > 200000) break;
	}
	while(times--){
		solve();
	}
	return 0;
}
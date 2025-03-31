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
int n,m;
struct egdes
{
	int w,v,ne;
}e[N << 1];
int s,t,k;
int h[N],idx = 1;
void add(int u,int v,int w){
	egdes pp = {w,v,h[u]};
	e[++idx] = pp;
	h[u]=idx;
}
int g[N];
struct node{
	int val,id,d;
	bool operator<(const node& n1)const{
		return val > n1.val;
	}
};
int st[N];
void dij(){
	memset(g,0x3f,sizeof g);
	g[t] = 0;
	priority_queue<node> hp;
	node t1 = {0,t,0};
	hp.push(t1);
	while(hp.size()){
		node p = hp.top();hp.pop();
		int val = p.val,u = p.id;
		if(st[u]) continue;
		st[u] = 1;
		for(int i = h[u];i;i=e[i].ne){
			int v = e[i].v;
			if(g[u] + e[i].w < g[v]){
				g[v] = g[u] + e[i].w;
				node t1 = {g[v],v,0};
				hp.push(t1);
			}
		}
	}
}
int tb;
int Ammmmm(){
	memset(st,0,sizeof st);
	priority_queue<node> hp;
	node t1 = {g[s],s,0};
	hp.push(t1);
	while(hp.size()){
		node p = hp.top();hp.pop();
		int val = p.val,u = p.id,d = p.d;
		st[u]++;
		if(u==t){
			if(d > tb) return d;
		}
		for(int i = h[u];i;i = e[i].ne){
			int v = e[i].v;
			node t1 = {d + e[i].w + g[v],v,d + e[i].w};
			hp.push(t1);
		} 
	}
	return -1;
}
void solve(){
	cin >> n >> m;
	s = n, t = 1;
	for(int i = 1;i <= m;i++){
		int u,v,w;
		cin >> u >> v >> w;
		add(u,v,w);
		add(v,u,w);
	}
	dij();
	tb = g[s];
	cout << Ammmmm() << endl;
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
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
const int N = 300005;
int n1,n2,m;
struct edges{
	int v,ne;
}e[N<<1];
int h[N],idx = 1;
void add(int u,int v){
	e[++idx] = {v,h[u]};
	h[u] = idx;
}
int dis[N];
int vis[N];
void dij(int s){
	priority_queue<PII,vt<PII>,greater<PII>> pq;
	dis[s] = 0;
	pq.push({0,s});
	while(pq.size()){
		auto p = pq.top();pq.pop();
		int u = p.se,val = p.fi;
		if(vis[u]) continue;
		vis[u] = 1;
		for(int i = h[u];i;i = e[i].ne){
			int v = e[i].v;
			if(dis[v] > dis[u] + 1){
				dis[v] = dis[u] + 1;
				pq.push({dis[v],v});
			}
		}
	}
}
void solve(){
	cin >> n1 >> n2 >> m;
	for(int i = 1;i <= m;i++){
		int u,v;
		cin >> u >> v;
		add(u,v);
		add(v,u);
	}
	memset(dis,0x3f,sizeof dis);
	dij(1),dij(n1+n2);
	int mx = 0;
	for(int i = 1;i <= n1;i++) mx=max(mx,dis[i]);
	int res = 0;
	for(int i = n1 + 1;i <= n1 + n2;i++){
		res = max(mx + dis[i],res);
	}
	cout << res + 1;
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
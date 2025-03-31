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
int dis[N];
struct edges{
	int v,w,ne;
}e[N<<1];
int h[N],tot = 1;
void add(int u,int v,int w){
	e[++tot] = {v,w,h[u]};
	h[u] = tot;
}
int st[N];
int x[N],y[N],l[N];
void solve(){
	int n,m,s;
	cin >> n >> m >> s;
	memset(dis,0x3f,sizeof dis);
	dis[s] = 0;
	for(int i = 1;i<=m;i++){
		int u,v,w;
		cin >> u >> v >> w;
		add(u,v,w);
		add(v,u,w);
		x[i] = u,y[i] = v,l[i] = w;
	}
	int d;
	cin >> d;
	priority_queue<PII,vt<PII>,greater<PII>> pq;
	pq.push({0,s});
	int cnt = 0;
	while(pq.size()){
		auto p = pq.top();pq.pop();
		int u = p.second,val = p.first;
		if(st[u]) continue;
		st[u] = 1;
		for(int i = h[u];i;i=e[i].ne){
			int v = e[i].v;
			int w = e[i].w;
			if(w + dis[u] < dis[v]){
				dis[v] = w + dis[u];
				pq.push({dis[v],v});
			}
		}
	}
	
	
	for(int i = 1;i <= n;i++){
		if(d==dis[i]) cnt++;
	}
	for(int i = 1;i <= m;i++){
		int u = x[i],v = y[i],w = l[i];
		if(dis[x[i]] < d && dis[y[i]] < d && d - dis[x[i]] + d -dis[y[i]]== l[i]) cnt++;
		if(dis[x[i]] < d && dis[x[i]] + l[i] > d && d - dis[x[i]] + d - dis[y[i]] < l[i]) cnt++; 
		if(dis[y[i]] < d && dis[y[i]] + l[i] > d && d - dis[x[i]] + d - dis[y[i]] < l[i]) cnt++;  
	}
	cout << cnt <<endl;
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
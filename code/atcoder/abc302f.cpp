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
int n,m;
int h[N],tot;
struct edge{
	int v,ne,w;
}e[N<<1];
void add(int u,int v,int w){
	e[tot] = {v,h[u],w};
	h[u] = tot++;
}
int dis[N],st[N];
void dij(){
	dis[n + 1] = 0;
	memset(st,0,sizeof st);
	priority_queue<PII,vt<PII>,greater<PII> > pq;
	pq.push({0,n + 1});
	while(pq.size()){
		auto p = pq.top();pq.pop();
		int u = p.se,val = p.fi;
		if(st[u]) continue;
		st[u] = 1;
		for(int i = h[u];~i;i=e[i].ne){
			int v = e[i].v;
			int w =e[i].w;
			//out2(v,dis[v]);
			if(dis[v] > dis[u] + w){
				dis[v] = dis[u] + w;
				pq.push({dis[v],v});
			}
		}
	}
}
void solve(){
	cin >> n >> m;
	memset(h,-1,sizeof h);
	memset(dis,0x3f,sizeof dis);
	for(int i = 1;i <= n;i++){
		int k;
		cin >>k;
		for(int j = 1;j <= k;j++){
			int v;
			cin >>v;
			add(i,v + n,0);
			add(v + n,i,1);
		}
	}
	dij();
	//cout << dis[n + m] <<endl;
	if(dis[n + m] == dis[0]) cout << -1 <<endl;
	else cout << dis[n + m] - 1 << endl;
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
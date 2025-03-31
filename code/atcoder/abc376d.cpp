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
struct edges{
	int v,ne;
}e[N<<1];
int h[N],idx = 1;
void add(int u,int v){
	e[++idx] = {v,h[u]},h[u] = idx;
}
int in[N],dfn[N];
int mi = 0x3f3f3f3f;
ll dis[N];
int vis[N];
void spfa(){
	for(int i = 1;i <= n;i++) dis[i] = inf,vis[i] = 0;
	priority_queue<PII,vector<PII>,greater<PII>> q;
	q.push(make_pair(0,1));
	dis[1] = 0;
	while(q.size()){
		pair<int,int> p = q.top();q.pop();
		int u = p.se;
		if(vis[u]) continue;
		vis[u] = 1;
		for(int i = h[u];i;i=e[i].ne){
			int v = e[i].v;
			if(dis[v] > dis[u] + 1){
				dis[v] = dis[u] + 1;
				q.push(make_pair(dis[v],v));
			}
		}
	}
}
void solve(){
	cin >> n >> m;
	memset(dfn,0x3f,sizeof dfn);
	for(int i = 1;i <= m;i++){
		int u,v;
		cin >> u >> v;
		add(u,v);
		in[v]++;
	}
	int cnt = 0;
	queue<int> q;
	for(int i = 1;i <= n;i++){
		if(!in[i]) q.push(i);
	}
	while(q.size()){
		int u = q.front();q.pop();
		cnt++;
		for(int i = h[u];i;i=e[i].ne){
			int v = e[i].v;
			if(--in[v]==0){
				q.push(v);
			}
		}
	}
	//cout << in[1] <<endl;
	if(in[1] == 0){
		cout << -1 << endl;
		return;
	}
	spfa();
	for(int i = 2;i<=n;i++){
		for(auto j = h[i];j;j=e[j].ne){
			if(e[j].v==1){
				mi=min(mi,dis[i] + 1);
				break;
			}
		}
	}
	cout << mi << endl;

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
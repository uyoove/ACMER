//和爸爸一起学编程真好,不过要小学四年级分流考试了,最近没时间写代码了,呜呜呜
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <iostream>
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
const int N = 10000 + 7;
int n,m,s,t;
struct edges{
	int v,w,ne;
}e[N << 1];
int h[N],idx = 1;
void add(int u,int v,int w){
	edges p = {v,w,h[u]};
	e[++idx] = p;
	h[u] = idx;
}
struct nb{
	int val,u,id;
	bool operator<(const nb &t1)const{
		return t1.val < val;
	}
};
int dis[N],dis2[N],st[N][2],cnt[N][2];
void dij(){
	for(int i = 1;i <= n;i++) dis[i] = inf,dis2[i] = inf,st[i][1] = st[i][0] = 0,cnt[i][1] = 0,cnt[i][0] = 0;
	priority_queue<nb> q;
	dis[s] = 0;
	cnt[s][0] = 1;
	nb t = {0,s,0};
	q.push(t);
	while(q.size()){
		nb p = q.top();q.pop();
		int u = p.u,id = p.id,val;
		if(id==0){
			val = dis[u];
		}else{
			val = dis2[u];
		}
		if(st[u][id]) continue;
		st[u][id] = 1;
		for(int i = h[u];i;i=e[i].ne){
			int v = e[i].v;
			int w = e[i].w;
			if(!st[v][0] && dis[v] > val + w){
				dis2[v] = dis[v];
				cnt[v][1] = cnt[v][0];
				nb t = {dis2[v],v,1};
				q.push(t);

				dis[v] = val + w;
				cnt[v][0] = cnt[u][id];
				nb t2 = {dis[v],v,0};
				q.push(t2);
			}else if(dis[v] == val + w){
				cnt[v][0] += cnt[u][id];
			}else if(!st[v][1] && dis2[v] > val + w && dis[v] < val + w){
				dis2[v] = val + w;
				cnt[v][1] = cnt[u][id];
				nb t = {dis2[v],v,1};
				q.push(t);
			}else if(dis2[v] == val + w){
				cnt[v][1] += cnt[u][id];
			}
		}
	}
}
void solve(){
	idx = 1;
	memset(st,0,sizeof st);
	memset(h,0,sizeof h);
	memset(cnt,0,sizeof cnt);
	cin >> n >> m;
	for(int i = 1;i <= n;i++) h[i] = 0;
	for(int i = 1;i <= m;i++){
		int u,v,w;
		cin >> u >> v >> w;
		add(u,v,w);
	}
	cin >> s >> t;
	dij();
	//cout << dis[t] << " " << dis2[t] << endl;
	//cout << cnt[t][0] << " " << cnt[t][1] <<endl;
	if(dis[t] + 1 == dis2[t]){
		int su = cnt[t][0] + cnt[t][1];
		cout << su << endl;
	}else{
		cout << cnt[t][0] << endl;
	}
	
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
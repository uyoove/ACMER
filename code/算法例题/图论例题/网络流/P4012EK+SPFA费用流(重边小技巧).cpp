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
const int N = 405;
struct edges{
	int v,c,w,ne;
}e[N*N];
int h[N],tot = 1;
void ad(int u,int v,int c,int w){
	e[++tot] = {v,c,w,h[u]};
	h[u] = tot;
}
void add(int u,int v,int c,int w){
	ad(u,v,c,w);
	ad(v,u,0,-w);
}
int a,b;
int n,m,s,t;
int idx = 1;
int id[30][30];
int pre[N],dis[N],mf[N],vis[N];
bool SPFA(){
	memset(dis,-0x3f,sizeof dis);
	memset(mf,0,sizeof mf);
	mf[s] = 1e9;
	vis[s] = 1,dis[s] = 0;
	queue<int> q;
	q.push(s);
	while(q.size()){
		int u = q.front();q.pop();
		vis[u] = 0;
		for(int i = h[u];i;i=e[i].ne){
			int v = e[i].v;
			if(e[i].c && e[i].w + dis[u] > dis[v]){
				dis[v] = e[i].w + dis[u];
				pre[v] = i;
				mf[v] = min(mf[u],e[i].c);
				if(!vis[v]){
					vis[v] = 1;
					q.push(v);
				}
			}
		}
	}


	return mf[t] > 0;
}
int EK(){
	int cost = 0;
	while(SPFA()){
		int v = t;
		while(v!=s){
			int i = pre[v];
			e[i].c -= mf[t];
			e[i^1].c += mf[t];
			v = e[i^1].v;
		}
		cost += mf[t]*dis[t];
	}
	return cost;
}
void solve(){
	cin >> a >> b;
	cin >> n >> m;
	s = ++idx;
	t = ++idx;
	for(int i = 0;i <= n;i++){
		for(int j = 0;j <= m;j++){
			id[i][j] = ++idx;
		}
	}
	for(int i = 0;i <= n;i++){
		for(int j = 0;j < m;j++){
			int w;
			cin >> w;
			add(id[i][j],id[i][j + 1],1,w);
			add(id[i][j],id[i][j + 1],1e9,0); //精髓,这样建边可以保证该点取获得收益,不取也可以走
		}
	}
	for(int j = 0;j <= m;j++){
		for(int i = 0;i < n;i++){
			int w;
			cin >> w;
			add(id[i][j],id[i + 1][j],1,w);
			add(id[i][j],id[i + 1][j],1e9,0); //精髓,这样建边可以保证该点取获得收益,不取也可以走
		}
	}
	while(a--){
		int i,j,k;
		cin >> k >> i >> j; 
		add(s,id[i][j],k,0);
	}
	while(b--){
		int i,j,k;
		cin >> k >> i >> j; 
		add(id[i][j],t,k,0);
	}
	cout << EK() << endl;
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
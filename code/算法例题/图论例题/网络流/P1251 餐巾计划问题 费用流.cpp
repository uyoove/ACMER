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
const int M = 1e6+7;
const int N = 5005;
int n,s,t,p,m,f,n1,s1;
int a[N];
struct edges{
	int v,c,w,ne;
}e[M];
int h[N],idx = 1;
void ad(int u,int v,int c,int w){
	e[++idx] = {v,c,w,h[u]};
	h[u] = idx;
}
void add(int u,int v,int c,int w){
	ad(u,v,c,w);
	ad(v,u,0,-w);	
}
int pre[N],vis[N],dis[N],mf[N];
bool SPFA(){
	memset(mf,0,sizeof mf);
	memset(dis,0x3f,sizeof dis);
	dis[s] = 0,vis[s] = 1,mf[s] = 1e9;
	queue<int> q;
	q.push(s);
	while(q.size()){
		int u = q.front();q.pop();
		vis[u] = 0;
		for(int i = h[u];i;i=e[i].ne){
			int v = e[i].v,w=e[i].w,c=e[i].c;
			if(c&&dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				pre[v]=i;
				mf[v]=min(mf[u],c);
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
			e[i].c-=mf[t];
			e[i^1].c+=mf[t];
			v=e[i^1].v;
		}
		cost+=mf[t]*dis[t];
	}
	return cost;
}
void solve(){
	cin >> n;
	s = N - 1,t = s - 1;
	int su = 0;
	for(int i = 1;i <= n;i++) cin >> a[i],su+=a[i];
	cin >> p >> m >> f >> n1 >> s1;
	
	for(int i = 1;i<=n;i++){
		add(s,i,inf,p); //每天早上可以购买餐巾
		add(s,i+n,a[i],0); //每天晚上从起点获得x条脏餐巾 
		add(i,t,a[i],0);//每天白天,向汇点提供x条干净的餐巾,流满时表示第i天的餐巾够用
	}
	for(int i = 1;i <= n;i++){
		if(i+m<=n) add(i+n,i+m,1e9,f); //快洗
		if(i+n1<=n) add(i+n,i+n1,1e9,s1); //慢洗
	}
	//每天晚上可以将脏餐巾留到第二天晚上
	for(int i = 2;i<=n;i++){
		add(i-1+n,i+n,1e9,0);
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
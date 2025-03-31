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
const int N = 210;
int n,m,s,t;
struct edges{
	int v,c,w,ne,yc;
}e[N*N];
int h[N],idx = 1;
void ad(int u,int v,int c,int w){
	e[++idx] = {v,c,w,h[u],c};
	h[u] = idx;
}
void add(int u,int v,int c,int w){
	ad(u,v,c,w);
	ad(v,u,0,-w);
}
int d[N],pre[N],mf[N],vis[N];
bool spfa(){
	memset(d,0x3f,sizeof d);
	memset(mf,0,sizeof mf);
	queue<int> q;
	d[s] = 0,mf[s] = 1e9,vis[s] = 1;
	q.push(s);
	while(q.size()){
		int u = q.front();q.pop();
		vis[u] = 0;
		for(int i = h[u];i;i=e[i].ne){
			int v = e[i].v,c=e[i].c,w=e[i].w;
			if(c && d[v] > d[u] + w){
				d[v] = d[u] + w;
				pre[v] = i;
				mf[v] = min(mf[u],c);
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
	int mxflow = 0,cost = 0;
	while(spfa()){
		int v = t;
		while(v!=s){
			int i = pre[v];
			e[i].c -= mf[t];
			e[i^1].c += mf[t];
			v = e[i ^ 1].v;
		}
		cost += d[t]*mf[t];
		mxflow+=mf[t];
	}
	return cost;
}
bool spfa1(){
	memset(d,-0x3f,sizeof d);
	memset(mf,0,sizeof mf);
	queue<int> q;
	d[s] = 0,mf[s] = 1e9,vis[s] = 1;
	q.push(s);
	while(q.size()){
		int u = q.front();q.pop();
		vis[u] = 0;
		for(int i = h[u];i;i=e[i].ne){
			int v = e[i].v,c=e[i].c,w=e[i].w;
			if(c && d[v] < d[u] + w){
				d[v] = d[u] + w;
				pre[v] = i;
				mf[v] = min(mf[u],c);
				if(!vis[v]){
					vis[v] = 1;
					q.push(v);
				}
			}
		}
	}
	return mf[t] > 0;
}
int EK1(){
	int mxflow = 0,cost = 0;
	for(int j = 2;j <= idx;j++) e[j].c = e[j].yc;
	while(spfa1()){
		int v = t;
		while(v!=s){
			int i = pre[v];
			e[i].c -= mf[t];
			e[i^1].c += mf[t];
			v = e[i ^ 1].v;
		}
		cost += d[t]*mf[t];
		mxflow+=mf[t];
	}
	return cost;
}
void solve(){
	cin >> n;
	s = n + n + 1;
	t = n + n + 2;
	for(int i = 1;i <= n;i++){
		add(s,i,1,0);
		add(i + n,t,1,0);
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			int t;
			cin >> t;
			add(i,j+n,1,t);
		}
	}
	cout << EK() << endl << EK1() << endl;
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
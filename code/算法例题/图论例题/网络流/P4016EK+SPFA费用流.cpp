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
const int N = 305;
int m,n,s,t;
struct edges{
	int v,c,w,ne;
}e[N*N];
int h[N],idx = 1;
void ad(int u,int v,int c,int w){
	e[++idx] = {v,c,w,h[u]};
	h[u] = idx;
}
void add(int u,int v,int c,int w){
	ad(u,v,c,w);
	ad(v,u,0,-w);
}
int mf[N],vis[N],dis[N],pre[N];
bool SPFA(){
	memset(dis,0x3f,sizeof dis);
	memset(mf,0,sizeof mf);
	queue<int> q;
	q.push(s);
	vis[s] = 1,dis[s] = 0, mf[s] = 1e9;
	while(q.size()){
		int u = q.front();q.pop();
		vis[u] = 0;
		for(int i = h[u];i;i=e[i].ne){
			int v = e[i].v,w = e[i].w,c = e[i].c;
			if(c && w + dis[u] < dis[v]){
				dis[v] = dis[u] + w;
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
	while(SPFA()){
		int u = t;
		while(u!=s){
			int i = pre[u];
			e[i].c -= mf[t];
			e[i ^ 1].c += mf[t];
			u = e[i ^ 1].v;
		}
		cost += dis[t]*mf[t],mxflow+=mf[t];
	} 
	return cost;
}
int a[N];
int su = 0;
void solve(){
	cin >> n;
	s = 0,t = n + 3;
	for(int i = 1;i <= n;i++) cin >> a[i],su+=a[i];
	if(su%n){
		cout << -1 << endl;
		return;
	}
	int p = su/n;
	for(int i = 1;i <= n;i++){
		if(a[i] > p){
			add(s,i,a[i]-p,0);
		}else{
			add(i,t,-(a[i]-p),0);
		}
	}
	for(int i = 1;i <= n;i++){
		if(i!=1){
			add(i,i-1,1e9,1);
		}
		if(i!=n){
			add(i,i+1,1e9,1);
		}
	}
	add(1,n,1e9,1);
	add(n,1,1e9,1);
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
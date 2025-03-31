//和爸爸一起学编程真好,不过要小学四年级分流考试了,最近没时间写代码了,呜呜呜
#include<bits/stdc++.h>
using namespace std;
#define out(x) cout << #x << '=' << (x) << endl
#define out2(x, y) cout << #x << '=' << (x) << ',' << #y << '=' << (y) << endl 
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
const int N = 5005;
int m,n,s,t;
struct edges{
	int v,c,w,ne;
}e[N << 1];
int h[N << 2],idx = 1;
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
	memset(dis,-0x3f,sizeof dis);
	memset(mf,0,sizeof mf);
	queue<int> q;
	q.push(s);
	vis[s] = 1,dis[s] = 0, mf[s] = 1e9;
	while(q.size()){
		int u = q.front();q.pop();
		vis[u] = 0;
		for(int i = h[u];i;i=e[i].ne){
			int v = e[i].v,w = e[i].w,c = e[i].c;
			if(c && w + dis[u] > dis[v]){
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
int grid[50][400];
//第一种情况 收1流1;
//第二种情况 收m流1;
//第三种情况 收m流m;
int tot = 1;
int pp[50][400];
void work(int in,int ot){
	idx = 1;
	memset(h,0,sizeof h);
	int cs = 801;
	int dd = n + m;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m+i-1;j++){
			add(pp[i][j],pp[i][j] + tot,in,grid[i][j]);
			if(i==1){
				add(s,pp[i][j],1,0);
			}
			if(i==n){
				add(pp[i][j] + tot,t,m,0);
			}else{
				add(pp[i][j] + tot,pp[i+1][j+1],ot,0);
				add(pp[i][j] + tot,pp[i+1][j],ot,0);
			}
			//cout << (i-1)*dd + j << endl;
		}
	}
	cout << EK() << endl;
}
void solve(){
	cin >> m >> n;
	
	
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m+i-1;j++){
			cin >> grid[i][j];
			pp[i][j] = ++tot;
		}
	}
	s = tot*2+1,t=s+1;
	work(1,1);
	work(m,1);
	work(m,m);


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
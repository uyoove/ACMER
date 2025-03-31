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
const int N = 200001;
int n,s,t,a,b,c,k;
struct edge{
	int v,c,w,ne; //加入一维w为边权单位价值 
}e[5000005];
int h[5000005],idx = 1;
void ad(int u,int v,int c,int w){
	e[++idx] = {v,c,w,h[u]};
	h[u] = idx;
}
void add(int u,int v,int c,int w){
	ad(u,v,c,w);
	ad(v,u,0,-w); //退费,走错了没关系,我退你钱,售后服务贼好
}
int tot = 1;
int id[200][200],grid[200][200];
int pre[N],d[N],mf[N],vis[N];
bool SPFA(){
	memset(d,0x3f,sizeof d);
	memset(mf,0,sizeof mf);
	queue<int> q;
	q.push(s);
	d[s] = 0,mf[s] = 1e9,vis[s] = 1;
	while(q.size()){
		int u = q.front();q.pop();
		vis[u] = 0;
		for(int i = h[u];i;i=e[i].ne){
			int v = e[i].v;
			int w = e[i].w;
			if(d[v] > d[u] + w && e[i].c){
				d[v] = d[u] + w;
				mf[v] =min(mf[u],e[i].c);
				pre[v] = i;
				if(!vis[v]){
					q.push(v);vis[v] = 1;
				}
			}
		}
	}
	return mf[t] > 0;
}
int EK(){
	int MF = 0;
	int cost = 0;
	while(SPFA()){
		int v = t;
		while(v!=s){
			int i = pre[v];
			e[i].c -= mf[t];
			e[i^1].c += mf[t];
			v = e[i ^ 1].v;
		}
		MF += mf[t];
		cost += mf[t]*d[t]; //单位流量*总费用
	}
	return cost;
}
void solve(){
	cin >> n >> k >> a >> b >> c;
	s = ++tot;
	t = ++tot;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			cin >> grid[i][j];
			id[i][j] = ++tot;
		}
	}
	add(s,id[1][1],1,0);
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			if(grid[i][j]){
				for(int p = 1;p <= k;p++){
					add(id[i][j]+p*tot,id[i][j],1,a);
				}
			}
			for(int p = 0;p < k;p++){
				if(grid[i][j] && p!=0)break; //如果强行加油,那么分层图只能第0层流下一个节点
				if(i+1<=n)add(id[i][j]+p*tot,id[i+1][j]+(p+1)*tot,1,0);
				if(j+1<=n)add(id[i][j]+p*tot,id[i][j + 1]+(p+1)*tot,1,0);
				if(i-1>0)add(id[i][j]+p*tot,id[i-1][j]+(p+1)*tot,1,b);
				if(j-1>0)add(id[i][j]+p*tot,id[i][j-1]+(p+1)*tot,1,b);
			}
			add(id[i][j]+k*tot,id[i][j],1e9,a+c);;
		}
	}
	for(int i = 0;i<=k;i++) add(id[n][n]+i*tot,t,1,0);
	cout << EK() <<endl;

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
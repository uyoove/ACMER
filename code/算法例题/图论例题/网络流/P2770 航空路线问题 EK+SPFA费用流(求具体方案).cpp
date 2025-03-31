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
const int N = 100010;
const int M = 5e5 + 7;
int n,m,s,t;
struct edge{
	int v,c,w,ne; //加入一维w为边权单位价值 
}e[M];
int h[N << 1],idx = 1;
void ad(int u,int v,int c,int w){
	e[++idx] = {v,c,w,h[u]};
	h[u] = idx;
}
void add(int u,int v,int c,int w){
	ad(u,v,c,w);
	ad(v,u,0,-w); //退费,走错了没关系,我退你钱,售后服务贼好
}
int pre[N],d[N],mf[N],vis[N];
bool SPFA(){
	memset(d,-0x3f,sizeof d);
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
			if(d[v] < d[u] + w && e[i].c){
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
pair<int,int> EK(){
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
	return make_pair(MF,cost);
}

int tot = 0;
map<string,int> mp;
string name[N];
int gt(string s){
	if(mp.count(s)) return mp[s];
	mp[s] = ++tot;
	name[tot] = s;
	return mp[s];
}	
string st[N];
int now[N];
void dfs1(int u){
	//cout << u << " " << u-n << endl;
	cout << name[u - n] << endl;
	now[u] = 1;
	//两条路选一条
	for(int i = h[u];i;i=e[i].ne){
		if(e[i].v <= n &&!e[i].c){
			//cout << u << " " << e[i].v << endl;
			dfs1(e[i].v + n);
			break;
		}
	}
}
void dfs2(int u){
	//cout << u << " " << u-n << endl;
	
	now[u] = 1;
	//两条路选一条
	for(int i = h[u];i;i=e[i].ne){
		if(e[i].v <= n &&!e[i].c&&!now[e[i].v + n]){
			//cout << u << " " << e[i].v << endl;
			dfs2(e[i].v + n);
		}
	}
	cout << name[u - n] << endl;
}
void solve(){
	cin >> n >> m;
	s=N-1;t = s - 1;
	for(int i = 1;i <= n;i++){
		cin >> st[i];
		if(i==1||i==n){
			add(gt(st[i]),gt(st[i]) + n,2,1);
		}else{
			add(gt(st[i]),gt(st[i]) + n,1,1);
		}
	}
	bool check = false;
	for(int i = 1;i <= m;i++){
		string u,v;
		cin >> u >> v;

		if(gt(u) > gt(v)) swap(u,v);
		if(gt(u)==1&&gt(v)==n){
			check = true;
		}
		add(gt(u) + n,gt(v),1,0);
	}
	add(s,1,2,0);
	add(gt(st[n]) + n,t,2,0);
	PII pi = EK();
	if(pi.fi!=2){
		if(pi.fi==1&&check){ //坑点,只要能直接连终点和起点的路线就可以输出
			cout << 2 << endl << st[1] << endl << st[n] << endl << st[1] << endl;
			return;
		}
		cout << "No Solution!" << endl;
		return;
	}
	cout << pi.se - 2<< endl;
	dfs1(1 + n);
	dfs2(1 + n);
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
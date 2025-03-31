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
const int N = 10005;
int n,m,s,t;
int h[N],idx = 2;
struct edges{int v,c,ne;}e[N << 1];
void add(int u,int v,int c) {e[idx]={v,c,h[u]},h[u]=idx++;} //从2开始
int pre[N << 1],flow[N]; //前驱边,流量表
bool bfs(){
	memset(pre,0,sizeof pre);
	memset(flow,0,sizeof flow);
	queue<int> q;
	q.push(s);
	flow[s] = 1e9;
	while(q.size()){
		int u = q.front();q.pop();
		for(int i = h[u];i;i=e[i].ne){
			int v = e[i].v;
			if(!flow[v] && e[i].c){
				//如果没走过并且有容量可以走,取容量与流量最小
				flow[v] = min(e[i].c,flow[u]);
				pre[v] = i;//u -> v的边
				q.push(v);
				if(v==t) return true;
			}
		}
	}

	return false;
}
void update(int& mxflow){
	int u = t;
	while(u!=s){
		int i = pre[u];
		e[i].c -= flow[t];
		e[i^1].c += flow[t];
		u = e[i ^ 1].v;
	}
	mxflow += flow[t];
}
int EK(){
	int mxflow = 0;
	while(bfs()){
		update(mxflow);
	}
	return mxflow;
}
void solve(){
	cin >> n >> m >> s >> t;
	for(int i = 1;i <= m;i++){
		int u,v,c;
		cin >> u >> v >>c;
		add(u,v,c);
		add(v,u,0);
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
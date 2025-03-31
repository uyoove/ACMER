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
const int N = 205;
vt<PII> res;
struct edges{
	int v,c,ne;
}e[20005];
int h[N],idx = 1;
void add(int u,int v,int c){
	e[++idx] = {v,c,h[u]};
	h[u] = idx; 
}
int n,m,s,t;
int cur[N],d[N]; //当前弧,分层图
bool bfs(){
	for(int i = 1;i < N;i++) d[i] = 0;
	queue<int> q;
	d[s] = 1;
	q.push(s);
	cur[s] = h[s]; //当前弧优化初始化
	while(q.size()){
		int u = q.front();q.pop();
		for(int i = h[u];i;i=e[i].ne){
			int v = e[i].v;
			if(d[v]==0 && e[i].c){
				d[v] = d[u] + 1;
				cur[v] = h[v];
				q.push(v);
				if(v == t) return true; //优化1,找到一个即可
			}
		}
	}
	return false;
}
int dfs(int u,int mf){
	if(u==t) return mf;
	int sum = 0;//累计流量
	for(int i = cur[u];i;i=e[i].ne){
		cur[u] = i; //当前弧优化,当走过或不能走,现在该点直接从该边出发
		int v = e[i].v;
		if(d[v] == d[u] + 1 && e[i].c){
			int f = dfs(v,min(mf,e[i].c));
			e[i].c -= f;
			e[i^1].c += f;
			sum += f; //累加流出
			mf-=f;
			if(mf==0) break;//余量优化
		}
	}
	if(sum == 0) d[u] = -1; //当前流量为0那么断开连接,防止后面进入
	return sum;
}
int dinic(){
	int mxflow = 0;
	while(bfs()){
		mxflow += dfs(s,1e9);
	}
	return mxflow;
}
void solve(){
	cin >> m >> n;
	s = n + 1;
	t = n + 2;
	for(int i = 1;i <= m;i++){
		add(s,i,1);
		add(i,s,0);
	}
	for(int i = m + 1;i <= n;i++){
		add(i,t,1);
		add(t,i,0);
	}
	int u,v;
	while(true){
		cin >> u >> v;
		if(u==-1&&v==-1) break;
		add(u,v,1);
		add(v,u,0);
	}	
	int c = dinic();
	//为什么不是最大流,因为最大流路径是通过反悔增广出来的并不是实际路径,只有在最后的残留网络中有边>1才是匹配项
	cout << c << endl;
	 for(int u=1;u<=m;++u) {
        for(int i=h[u];i;i=e[i].ne) {
            int v=e[i].v;
            if(v!=s&&e[i].c==0&&e[i^1].c==1) cout << u << " " << v << endl;
        }
    }
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
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
const int N = 200005;
int n,m,s,t;
int d1,f;
struct edges{
	int v,c,ne;
}e[N<<1];
int h[N],idx = 1;
void add(int u,int v,int c){
	e[++idx] = {v,c,h[u]};
	h[u] = idx; 
}
int cur[N],d[N]; //当前弧,分层图
bool bfs(){
	memset(d,0,sizeof d);
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
	if(sum == 0) d[u] = 0; //当前流量为0那么断开连接,防止后面进入
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
	cin >> n >> f >> d1;
	//食物 1- f;
	//喝的是 f+ 1 - f+1+d;
	//牛是 f+d + 1- f+d+n*2;
	int tot = 1ll;
	
	for(int i = 1;i <= n;i++){
		int a,b;
		cin >> a >> b;
		add(f+d1+tot,f+d1+tot+1,1);
		add(f+d1+tot+1,f+d1+tot,0);
		
		for(int j = 1;j<=a;j++){
			int p;
			cin >> p;
			add(p,f+d1+tot,1);
			add(f+d1+tot,p,0);
		}
		for(int j = 1;j<=b;j++){
			int p;
			cin >> p;
			add(p + f,f+d1+tot+1,0);
			add(f+d1+tot+1,p + f,1);
		}
		tot= tot+2;
	}
	s = f+ d1 + tot+ 1;
	t = f+ d1 + tot + 2;
	for(int i =1;i <= f;i++){
		add(s,i,1);
		add(i,s,0);
	}
	for(int i =1;i <= d1;i++){
		add(t,i + f,0);
		add(i + f,t,1);
	}
	cout << dinic();
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
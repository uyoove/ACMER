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
struct edges{
	int v,c,ne;
}e[N*N];
int h[N << 2],idx = 1;
void add(int u,int v,int c){
	e[++idx] = {v,c,h[u]};
	h[u] = idx;
}
int n,m,s,t;
void ad(int u,int v,int c){
	add(u,v,c);
	add(v,u,0);
}
int d[N << 2],cur[N << 2];
int dfs(int u,int mf){
	if(u==t) return mf;
	int su = 0;
	for(int i = h[u];i;i=e[i].ne){
		int v = e[i].v;
		if(d[u]+1 == d[v] && e[i].c){
			int f = dfs(v,min(mf,e[i].c));
			e[i].c -= f;
			e[i^1].c += f;
			mf -= f;
			su+=f;
			if(mf==0) break;
		}
	}
	if(su==0) d[u] = 0;
	return su;
}
bool bfs(){
	memset(d,0,sizeof d);
	cur[s] = h[s];
	queue<int> q;
	q.push(s);
	d[s] = 1;
	while(q.size()){
		int u = q.front();q.pop();
		for(int i = h[u];i;i=e[i].ne){
			int v = e[i].v;
			if(!d[v] && e[i].c){
				d[v] = d[u] + 1;
				cur[v] = h[v];
				if(v == t) return true;
				q.push(v);
			}
		}
	}
	return false;
}
int dinic(){
	int mxflow = 0;
	while(bfs()){
		mxflow += dfs(s,1e9);
	}
	return mxflow;
}
int a[N],b[N];
int bj[N][N];
void solve(){
	cin >> n >> m;
	s = n + m + 3;
	t = n + m + 4;
	int cnt = 0;
	
	for(int i = 1;i <= n;i++) cin >> a[i],ad(s,i,a[i]),cnt+=a[i];
	for(int i = 1;i <= m;i++) cin >> b[i],ad(i + n,t,b[i]);
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			bj[i][j] = idx + 1;
			ad(i,j + n,1);
		}
	}
	int mx = dinic();
	if(mx < cnt){
		cout << 0 << endl;
		return;
	}
	cout << 1 << endl;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			if(e[bj[i][j] ^ 1].c) cout <<j << ' ';
		}
		cout << endl;
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
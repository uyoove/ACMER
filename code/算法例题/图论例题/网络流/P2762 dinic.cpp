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
bool flag = 0;
int read() {
	static char c;
	static int x;
	if(c == '\n') return c = 0, -1;
	while(!isdigit(c = getchar())); 
	x = c ^ 48;
	while(isdigit(c = getchar()))
		x = x * 10 + (c ^ 48);
	return x;
}
const ll inf = 0x3f3f3f3f3f3f3f3fLL;
const int infi = 0x3f3f3f3f;
const int P = 13331;
const int N = 2005;
int n,m,s,t;
int h[N],idx = 1;
struct edges{
	int v,c,ne;
}e[N * 2];
void ad(int u,int v,int c){
	e[++idx] = {v,c,h[u]};
	h[u] = idx;
}
void add(int u,int v,int c){
	ad(u,v,c);
	ad(v,u,0);
}
int d[N],cur[N];
bool bfs(){
	memset(d,0,sizeof d);
	queue<int> q;
	d[s] = 1;
	q.push(s);
	cur[s] = h[s];
	while(q.size()){
		int u = q.front();q.pop();
		for(int i = h[u];i;i=e[i].ne){
			int v = e[i].v;
			if(!d[v] && e[i].c){
				cur[v] = h[v];
				d[v] = d[u] + 1;
                if(v == t) return true;
				q.push(v);
			}
		}
	}
	return false;
}
int dfs(int u,int mf){
	if(u==t) return mf;
	int su = 0;
	for(int i = cur[u];i;i=e[i].ne){
		int v = e[i].v;
		cur[u] = i;
		if(d[v] == d[u] + 1 && e[i].c){
			int f = dfs(v,min(e[i].c,mf));
			mf -= f;
			su+=f;
			e[i].c-=f;
			e[i^1].c+=f;
			if(mf == 0) break;
		}
	}
	if(su==0) d[u] = 0;
	return su;
}
int dinic(){
	int mxflow = 0;
	while(bfs()){
		mxflow += dfs(s,1e9);
	}
	return mxflow;
}
vector<int> yq[N];
int c[N];
void solve(){
	cin >> n >> m;
	s = n + m + 3;
	t = n + m + 4;
	int su = 0;
	for(int i = 1;i <= n;i++){
		int val;
		cin >> val;
		//cout << val << endl;
		add(s,i,val);
		su+=val;
		int p;
		while(~(p = read())){
			add(i,p + n,1e9);
		}
	}
	for(int i = 1;i <= m;i++) cin>>c[i],add(i + n,t,c[i]);
	int fl = dinic();
	for(int i = 1;i<=n;i++){
		if(d[i]) cout << i << " ";
	}
	cout <<endl;
	for(int i = 1;i <= m;i++){
		if(d[i + n]) cout << i << " ";
	}
	cout << endl;
	cout << su - fl<<endl;

}

signed main(){
	// std::ios::sync_with_stdio(0);
    // std::cin.tie(0);
    // std::cout.tie(0);
	int times = 1;
	//cin >> times;
	while(times--){
		solve();
	}
	return 0;
}
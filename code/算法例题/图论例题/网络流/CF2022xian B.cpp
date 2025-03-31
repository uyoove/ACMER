//和爸爸一起学编程真好,不过要小学四年级分流考试了,最近没时间写代码了,呜呜呜
#include<bits/stdc++.h>
#define int long long
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
const int N = 252*2;
int n,m,s,t;
int h[N],idx = 1;
struct edges{
	int v;
	ll c;
	int ne;
}e[N*N];
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
ll dfs(int u,ll mf){
	if(u==t) return mf;
	ll su = 0;
	for(int i = cur[u];i;i=e[i].ne){
		int v = e[i].v;
		cur[u] = i;
		if(d[v] == d[u] + 1 && e[i].c){
			ll f = dfs(v,min(e[i].c,mf));
			mf -= f;
			su+=f;
			e[i].c-=f;
			e[i^1].c+=f;
			if(mf == 0) break;
		}
	}
	if(su==0) d[u] = -1;
	return su;
}
ll dinic(){
	ll mxflow = 0;
	while(bfs()){
		mxflow += dfs(s,1e9+1);
	}
	return mxflow;
}
//思路二分图最大匹配 (网格颜色覆盖问题);
//因为我们k颜色种类枚举,那么答案贡献于填色的格子无关,因为k*c已经固定
//所以尽量让z(0颜色的数量)尽量少 所以最大匹配可以染色的格子即可
void solve(){
	cin >> n >> m;
	ll c,d;
	cin >> c >> d;
	s = n + m;
	t = n + m + 1; 
	vector<int> si,ei;
	for(int i = 0;i < n;i++){
		si.pb(idx + 1);
		add(s,i,0);
	}
	for(int i = 0;i < m;i++){
		ei.pb(idx + 1);
		add(i + n,t,0);
	}
	int su = 0;
	for(int i = 0;i <n;i++){
		string s;
		cin >> s;
		for(int j = 0;j < m;j++){
			if(s[j] == '.'){
				add(i,j + n,1);
				su++;
			}
		}
	}
	ll ans = su * d*1ll;
	int cnt = 0;
	for(int i = 1;i <= max(n,m);i++){
		for(auto &p:si){
			e[p].c++;
		}
		for(auto &p:ei){
			e[p].c++;
		}
		int f = dinic();
		cnt += f;
		ans = min(ans,c*i*1ll + (su - cnt)* 1ll * d);
	}
	cout << ans <<endl;

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
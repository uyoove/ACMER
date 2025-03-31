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
#define all(x) x.begin(), x.end()
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
const int N = 5000005;
int prm[N];
int n;
void getprm(){
	for(int i = 2;i<N;i++){
		if(prm[i]==0) prm[++prm[0]] = i;

		for(int j = 1;j <= prm[0] && prm[j]*i < N;j++){
			prm[i*prm[j]] = -1;
			if(i%prm[j]==0) break;
		}
	}
}
set<int> se;
struct edges{
	int v,ne;
}e[N << 1];
int h[N],idx = 1;
void add(int u,int v){
	e[++idx] = {v,h[u]},h[u] = idx;
}
int hs[N],sz[N];
void dfs(int u,int f){
	sz[u] = hs[u] = 1;
	for(int i = h[u];i;i=e[i].ne){
		int v = e[i].v;
		if(v==f) continue;
		dfs(v,u);
		sz[u] += sz[v];
		hs[u] += hs[v] * prm[sz[v]];
	}
}
//换根
void dfs2(int u,int f){

	for(int i = h[u];i;i=e[i].ne){
		int v = e[i].v;
		if(v==f) continue;
		int vx = hs[u] - hs[v] * prm[sz[v]];
		hs[v] += vx * prm[n - sz[v]];
		dfs2(v,u);
	}
}
int du[N];
void solve(){
	cin >> n;
	getprm();
	for(int i = 1;i < n;i++){
		int u,v;
		cin >> u >> v;
		add(u,v);
		add(v,u);
	}
	dfs(1,0),dfs2(1,0);//算出第一棵树每个点为根的hash值
	set<int> se;
	for(int i = 1;i <= n;i++) se.insert(hs[i]); //保存下来
	memset(h,0,sizeof h);
	idx = 1;
	memset(hs,0,sizeof hs);
	memset(sz,0,sizeof sz);
	n++;
	for(int i = 1;i < n;i++){
		int u,v;
		cin >> u >> v;
		add(u,v);
		add(v,u);
		du[u]++,du[v]++;
	}
	dfs(1,0),dfs2(1,0);//算出第二棵树每个点为根的hash值
	for(int i = 1;i <= n;i++){
		//找叶子,度数为1
		if(du[i]==1){
			int j = e[h[i]].v;
			//以父节点当根,不能是别的当根,因为别的会被prm影响,只有父亲中该节点hash值为2
			if(se.count(hs[j] - 2)){
			 	cout << i << endl;
			 	return;
			}

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
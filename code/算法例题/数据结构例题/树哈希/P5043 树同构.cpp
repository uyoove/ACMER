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
const int N = 100;
int prm[10000007]; //5e5的数据得开2e7才行

void getprm(){
	for(int i = 2;i<1e7;i++){
		if(prm[i]==0) prm[++prm[0]] = i;
		for(int j = 1;j <= prm[0] && prm[j]*i < 1e7;j++){
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
int n,m;
void add(int u,int v){
	e[++idx] = {v,h[u]},h[u] = idx;
}
ULL hs[N],sz[N];
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
		hs[v] += vx * prm[m - sz[v]];
		dfs2(v,u);
	}
}
void solve(){
	
	cin >> n;
	getprm();
	set<int> se[N];
	map<int,int> mp;
	for(int i = 1;i <= n;i++){
		
		cin >> m;
		memset(h,0,sizeof h),idx=1;
		memset(hs,0,sizeof hs);
		memset(sz,0,sizeof sz);
		int root = -1;
		for(int j = 1;j <= m;j++){
			int f;
			cin >> f;
			if(f==0){
				root = j;
				continue;
			}
			add(f,j);
			add(j,f);

		}
		dfs(root,-1);
		dfs2(root,-1);
		for(int j = 1;j <= m;j++) {
			se[i].insert(hs[j]);
		}
	}
	for(int i = 1;i <= n;i++){
		int mi = 1e9;
		for(auto p:se[i]){
			for(int j = 1;j <= n;j++){
				if(se[j].count(p)){
					mi=min(mi,j);
					break;
				}
			}
		}
		cout << mi << endl;
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
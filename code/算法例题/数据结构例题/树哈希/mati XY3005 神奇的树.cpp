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
const int N = 500005;
int prm[20000007];
int n;
void getprm(){
	for(int i = 2;i<2e7;i++){
		if(prm[i]==0) prm[++prm[0]] = i;
		for(int j = 1;j <= prm[0] && prm[j]*i < 2e7;j++){
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
void solve(){
	getprm();
	cin >> n;
	for(int i = 1,u,v;i < n&&cin>>u>>v;i++){
		add(u,v);
		add(v,u);
	}
	dfs(1,0),dfs2(1,0);
	map<int,int> mp;
	for(int i = 1;i <= n;i++){
		mp[hs[i]]++;
	}
	for(int i = 1;i<=n;i++){
		cout << mp[hs[i]] << endl;
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
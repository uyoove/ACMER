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
const int N = 200005;
vector<int> e[N];
int n;
int f1[N],f2[N];
int ans = 0;
void dfs(int u,int f){
	int t = e[u].size() - 2;
	f1[u] = 0;
	f2[u] = 0;
	ans = max(t + 2,ans);
	for(auto v:e[u]){
		if(v==f) continue;
		dfs(v,u);
		int p = f1[v];
		if(p > f1[u]) f2[u] = f1[u],f1[u] = p;
		else if(p > f2[u]) f2[u] = p; 
	}
	f1[u]+=t;
	ans = max(f1[u] + max(f2[u],0ll) + 2,ans);
	
	
	
}
void solve(){
	ans = 0;
	cin >> n;
	for(int i = 1;i <= n;i++) e[i].clear(),f1[i] = 0,f2[i] = 0;
	for(int i = 1;i < n;i++){
		int u,v;
		cin >> u >> v;
		e[u].pb(v);
		e[v].pb(u);
	}
	dfs(1,-1);
	// for(int i = 1;i <= n;i++){
	// 	cout << f1[i] << " " << f2[i] << endl;
	// }
	 
	cout << ans << endl;

}

signed main(){
	std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
	int times = 1;
	cin >> times;
	while(times--){
		solve();
	}
	return 0;
}
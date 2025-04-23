//最后一舞
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
mt19937_64 rnd(time(0));
const ll inf = 0x3f3f3f3f3f3f3f3fLL;
const int infi = 0x3f3f3f3f;
const int P = 13331;
const int N = 200005;
int n,m;
struct edges{
	int v,ne;
}e[N];
int h[N],idx = 1;
int in[N],out[N];
void add(int u,int v){
	e[++idx] = {v,h[u]};
	h[u] = idx;
}
int memo[N];
int st,ed;
bool f = 1;
int dfs(int u){
	if(u==ed){
		return 1;
	}
	if(memo[u]) return memo[u];
	bool f1 = 0;
	int res = 0;
	for(int i = h[u];i;i=e[i].ne){
		int v = e[i].v;
		res+=dfs(v);
		f1 = 1;
	}
	if(!f1) f = false;
	return memo[u] = res;
}
void solve(){
	cin >> n >> m;
	for(int i = 1;i <= m;i++){
		int u,v;
		cin >> u >> v;
		add(u,v);
		in[v]++;
		out[u]++;
	}
	cin >> st >> ed;
	dfs(st);
	cout << memo[st] << " ";
	if(f){
		cout << "Yes" << endl;
	}else{
		cout << "No" << endl;
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
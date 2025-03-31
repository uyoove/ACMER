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
mt19937_64 rnd(time(0));
const ll inf = 0x3f3f3f3f3f3f3f3fLL;
const int infi = 0x3f3f3f3f;
const int P = 13331;
const int N = 200005;
int n,k;
struct edges{
	int v,ne;
}e[N << 1];
int h[N],idx;
void add(int u,int v){
	e[++idx] = {v,h[u]};
	h[u] = idx;
}
bool f = false;
int dp[N];
int mod = 1e9 + 7;
//当前节点,父节点,曾祖父节点,兄弟节点
void dfs(int u,int fa,int grand,int id){
	if(f) return;
	int num = 0;
	if(fa) num++;
	if(grand) num++;
	num+=id;
	int g = k - num;
	if(g<=0) {
		f=1;
		return;
	}	
	dp[u] = g;
	int ip = 0;
	for(int i = h[u];i;i=e[i].ne){
		int v = e[i].v;
		if(v==fa) continue;
		dfs(v,u,fa,ip++);
		dp[u] = dp[v] * dp[u] % mod;
	}
}
void solve(){
	cin >> n >> k;
	for(int i = 0;i < n - 1;i++){
		int u,v;
		cin >> u >> v;
		add(u,v),add(v,u);
	}
	dfs(1,0,0,0);
	if(f){
		cout <<0 <<endl;
		return;
	}
	cout << dp[1] << endl;

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
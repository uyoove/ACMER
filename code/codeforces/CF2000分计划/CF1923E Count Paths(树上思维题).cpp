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
int cnt[N],ans = 0;
struct edges{
	int v,ne;
}e[N << 1];
int h[N],idx = 1;
void add(int u,int v){
	e[++idx] = {v,h[u]};
	h[u] = idx;
}
//可以看出是有相同颜色就遮住部分的关系
int n;
int c[N];
void dfs(int u,int f){
	int jr = cnt[c[u]];//进来有多少个
	for(int i = h[u];i;i=e[i].ne){
		int v = e[i].v;
		if(v==f) continue;
		cnt[c[u]] = 1; //将上面的颜色全部覆盖掉,结束了再还原+1
		dfs(v,u);
	}
	ans+=jr,cnt[c[u]] = jr + 1;//加入进来的节点数量,还原上层来的,并且 + 1
}
void solve(){
	cin >> n;
	idx = 1;
	ans = 0;
	for(int i = 1;i <= n;i++) cin >> c[i],h[i] = 0,cnt[c[i]] = 0;
	for(int i = 1;i<n;i++){
		int u,v;
		cin >> u >> v;
		add(u,v);
		add(v,u);
	} 
	dfs(1,0);
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
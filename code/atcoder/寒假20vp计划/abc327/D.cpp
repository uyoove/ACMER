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
int n,m;
struct edges{
	int v,ne;
}e[N << 1];
int h[N],idx = 1;
void add(int u,int v){
	e[++idx] = {v,h[u]};
	h[u] = idx;
}
int a[N],b[N];
int bh = 0;
int gt[N];
int vis[N];
int sz[N];
int p = 0;
bool ans = true;
int tot = 1;
int dfn[N];
void dfs(int u,int f){
	dfn[u] = ++tot;
	for(int i = h[u];i;i=e[i].ne){
		int v = e[i].v;
		if(e[i].v==f) continue;
		if(vis[v]){
			int p = dfn[u] - dfn[v];
			if(p%2==0){
				ans = false;
			}
			gt[bh] = 1;
			continue;
		} 
		vis[v] = bh;
		dfs(v,u);
		tot = dfn[u];
	}
}
void solve(){
	cin >> n >> m;
	for(int i = 1;i <= m;i++){
		cin >> a[i];
	}
	set<PII> p;
	for(int i = 1;i<=m;i++){
		cin >> b[i];
		if(a[i]==b[i]){
			cout << "No" << endl;
			return;
		}
		if(p.count({a[i],b[i]})) continue;
		add(a[i],b[i]);
		add(b[i],a[i]);
		p.insert({a[i],b[i]});
		p.insert({b[i],a[i]});
	}
	for(int i = 1;i<=n;i++){
		if(!vis[i]){
			bh++;
			vis[i] = bh;
			dfs(i,0);
		}
	}
	if(!ans){
		cout << "No" << endl;
	}else{
		cout << "Yes" << endl;
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
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
int n;
int a[N];
int h[N],idx = 1;
struct edges{int v,w,ne;}e[N];
void add(int u,int v,int w){
	e[++idx] = {v,w,h[u]};h[u] = idx;
}
int cnt[N];
map<int,int> ha;
int su = 0;
void dfs(int u,int fa){
	if(ha.size()){
		int mi = 0x3f3f3f3f;
		for(auto [k,v]:ha){
			mi = k;
			break;
		}
		if(su - mi > a[u]){
			cnt[u] = 1;
			return;
		}
	}
	if(su > a[u]){
		cnt[u] = 1;
		return;
	}
	for(int i = h[u];i;i=e[i].ne){
		int v = e[i].v,w = e[i].w;
		if(v==fa) continue;
		su += w;
		ha[su]++;
		dfs(v,u);
		ha[su]--;
		if(ha[su]==0)ha.erase(su);
		su-=w;
	}
}
int res = 0;
void dfs2(int u,int f){
	if(cnt[u]) return;
	res++;
	for(int i = h[u];i;i=e[i].ne){
		int v= e[i].v;
		if(v==f) continue;
		dfs2(v,u);
	}
}
void solve(){
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> a[i];
	for(int i = 1;i < n;i++){
		int p,w;
		cin >> p >> w;
		add(i + 1,p,w);
		add(p,i + 1,w);
	}
	dfs(1,0);
	dfs2(1,0);
	cout << n - res <<endl;
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
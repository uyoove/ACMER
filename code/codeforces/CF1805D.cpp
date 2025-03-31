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
int h[N],idx = 1;
struct edges{int v,ne;}e[N << 1];
void add(int u,int v){
	e[++idx] = {v,h[u]};
	h[u] = idx; 
}
int dep[N],dep1[N],cnt[N],ds[N];
int root,root2;
void dfs1(int u,int fa){
	dep[u] = dep[fa] + 1;
	for(int i = h[u];i;i=e[i].ne){
		int v = e[i].v;
		if(v==fa) continue;
		dfs1(v,u); 
	}
}
void solve(){
	cin >> n;
	for(int i = 1;i < n;i++){
		int u,v;
		cin >> u >> v;
		add(u,v);
		add(v,u);
		cnt[u]++;
		cnt[v]++;
	}
	dfs1(1,0);
	int mx = 0;
	for(int i = 1;i<= n;i++){
		if(cnt[i] == 1){
			if(dep[i] > mx){
				mx = dep[i];
				root = i;
			}
		}
	}
	dfs1(root,0);
	mx = 0;
	for(int i = 1;i<= n;i++) if(dep[i] > mx){mx = dep[i],root2 = i;}
	for(int i = 1;i<= n;i++){
		dep1[i] = dep[i];
	}
	dfs1(root2,0);
	for(int i = 1;i<=n;i++){
		int p = max(dep[i],dep1[i]);
		ds[p]++;
	}
	int res = n + 1;
	vector<int> v;
	for(int i = n;i>=1;i--){
		if(i >= mx) v.pb(n);
		else{
			res -= ds[i + 1];
			v.pb(res);
		}
		
	}	
	for(int i = n;i >= 1;i--){
		cout << v[i - 1] << " ";
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
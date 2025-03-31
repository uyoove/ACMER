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
vt<int> e[N];
int n;
map<int,int> mp;
map<int,int> sj;
int a[N];
int stk[N],top,ans[N];
map<int,stack<int>> sk;
int dfn[N],tp = 1;
void dfs(int u){
	stk[++top] = a[u];
	dfn[u] = ++tp;
	auto it = sj.lower_bound(a[u]);
	int pre = 0,suf = 0;
	if(it!=sj.begin()) --it,pre = it->second;
	
	  it = sj.lower_bound(a[u]);
	  if(it!=sj.end()) suf = it->second; 

	if(abs(a[pre] - a[u]) < abs(a[suf]- a[u])){
		ans[u] = pre;
	}else if(abs(a[pre] - a[u]) > abs(a[suf]- a[u])){
		ans[u] = suf;
	}else{
		if(dfn[pre] > dfn[suf]){
			ans[u] = pre;
		}else{
			ans[u] = suf;
		}
	}
	mp[a[u]]++;
	if(sj.count(a[u])) sk[a[u]].push(sj[a[u]]);
	sj[a[u]] = u;

	for(auto v:e[u]){
		dfs(v);
	}
	mp[a[u]]--;
	if(mp[a[u]]==0) mp.erase(a[u]),sj.erase(a[u]);
	else sj[a[u]] = sk[a[u]].top(),sk[a[u]].pop();
	--top;
}
void solve(){
	cin >> n;
	a[0] = inf;
	for(int i = 1;i < n;i++){
		int f;
		cin >> f;
		e[f].pb(i);
	}
	for(int i = 1;i <= n;i++) cin >> a[i];
	for(int i = 1;i <= n;i++) if(!dfn[i]) dfs(n);
	for(int i = 1;i < n;i++){
		cout << ans[i] << " ";
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
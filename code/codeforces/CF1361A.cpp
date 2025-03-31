//和爸爸一起学编程真好,不过要小学四年级分流考试了,最近没时间写代码了,呜呜呜
#include<bits/stdc++.h>
using namespace std;
#define out(x) cout << #x << '=' << (x) << endl
#define out2(x, y) cout << #x << '=' << (x) << ',' << #y << '=' << (y) << endl 
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
const int N = 500005;
//一个图,查看该位置是否连着连续与当前数字的节点,如果1,1相邻则无图
//首先对主题从小到大排序,然后对每个数字开个桶,如果遍历到当前数字,桶中有n-1个那么一定可以,如果没有-1
//我们只对数字编号比当前数字大的建单向边
int n,m;
int v[N];
struct edges{
	int v,ne;
}e[N << 1];
int h[N],idx = 1;
void add(int u,int v){
	e[++idx] = {v,h[u]};
	h[u] = idx;
}
PII p[N];
set<int> cnt[N];
void solve(){
	cin >> n >> m;
	for(int i = 1;i <= m;i++){
		cin >> p[i].fi >> p[i].se;
	}
	vt<PII> a;
	for(int i = 1;i<=n;i++) cin >> v[i],a.pb({v[i],i});
	for(int i = 1;i<=m;i++){
		if(v[p[i].fi] > v[p[i].se]) swap(p[i].se,p[i].fi);
		if(v[p[i].fi] == v[p[i].se]){
			if(v[p[i].fi]==1){
				cout << -1 <<endl;
				return;
			}
			continue;
		}
		add(p[i].fi,p[i].se);
	}
	sort(a.begin(),a.end());
	for(int i = 0;i<n;i++){
		int u = a[i].se;
		if(cnt[u].size()==a[i].fi - 1){
			for(int j = h[u];j;j=e[j].ne){
				int v = e[j].v;
				cnt[v].insert(a[i].fi);
			}
		}else{
			cout << -1 <<endl;
			return;
		}
	}
	for(auto [k,v]:a){
		cout << v << " ";
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
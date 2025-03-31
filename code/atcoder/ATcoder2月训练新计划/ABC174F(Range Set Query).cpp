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
const int N = 500005;
struct node{
	int l,r,id;
	bool operator<(const node & n1) const{
		return r  < n1.r;
	}
};
struct tree{
	int l,r,su;
}tr[N << 2];
void push_up(int u){
	tr[u].su = tr[lc].su+tr[rc].su;
}
void build(int u,int l,int r){
	tr[u] = {l,r,0};
	if(l==r) return;
	int mid = l + r >> 1;
	build(lc,l,mid);
	build(rc,mid + 1,r);
}
void update(int u,int x,int v){
	if(tr[u].l > x || tr[u].r < x) return;
	if(tr[u].l == x && tr[u].r == x){
		tr[u].su += v;
		return;
	}
	update(lc,x,v);
	update(rc,x,v);
	push_up(u);
}
int quary(int u,int l,int r){
	if(tr[u].l > r || tr[u].r < l) return 0;
	if(tr[u].l >= l && tr[u].r <= r){
		return tr[u].su;
	}
	return quary(lc,l,r) + quary(rc,l,r);
}
int n,m;
int a[N],last[N],ans[N];
vector<node> v[N];
vector<node> qs;
void solve(){
	cin >> n;
	cin >> m;
	build(1,1,n);
	for(int i = 1;i<=n;i++){
		cin >> a[i];
	}
	
	for(int i = 1; i <= m;i++){
		int l,r;
		cin >> l >> r;
		v[r].push_back({l,r,i});
		sort(v[r].begin(),v[r].end());
	}
	for(int i = 1;i<=n;i++){
		if(last[a[i]]){
			update(1,last[a[i]],-1);
		}
		last[a[i]] = i;
		update(1,i,1);
		for(auto &p:v[i]){
			ans[p.id] = quary(1,p.l,p.r);
		}
	}
	for(int i =1;i<=m;i++){
		cout << ans[i] << endl;
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
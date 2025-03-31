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
struct qs{
	int l,r,id;
	bool operator<(const qs& t1)const{
		return r < t1.r;
	}
}querys[N];
int n,q;
int a[N],last[N],ans[N];
map<int,int> mp;
struct Tree{
	int l,r,val;
}tr[N << 2];
void push_up(int u){
	tr[u].val = min(tr[lc].val,tr[rc].val);
}
void build(int u,int l,int r){
	tr[u] = {l,r,inf};
	if(l==r) return;
	int mid = l + r >> 1;
	build(lc,l,mid);
	build(rc,mid + 1,r);
	push_up(u);
}
void modify(int u,int x,int val){
	if(tr[u].r < x || tr[u].l > x)  return;
	if(tr[u].l==x && tr[u].r==x){
		tr[u].val = val;
		return;
	}
	modify(lc,x,val);
	modify(rc,x,val);
	push_up(u);
}
int query(int u,int l,int r){
	if(tr[u].l > r || tr[u].r < l) return inf;
	if(tr[u].l >= l && tr[u].r <= r){
		return tr[u].val;		
	}
	return min(query(lc,l,r),query(rc,l,r));
}
void solve(){
	cin >> n >> q;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		if(mp.count(a[i])){
			last[i] = mp[a[i]];
		}
		mp[a[i]] = i;
	}
	for(int i = 1;i <= q;i++){
		cin >> querys[i].l >> querys[i].r;
		querys[i].id = i;
	}
	sort(querys + 1, querys + q + 1);
	int d = 0;
	build(1,1,n);
	for(int i = 1;i <= q;i++){
		while(d < querys[i].r){
			++d;
			modify(1,last[d],d - last[d]);
		}
		ans[querys[i].id] = query(1,querys[i].l,querys[i].r);
		//cout << tr[1].val << endl;
	}
	for(int i = 1;i <= q;i++){
		if(ans[i] >= infi){
			cout << -1 << endl;
		}else{
			cout << ans[i] <<endl;
		}
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
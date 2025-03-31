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
//根据 ai = si-1可以从中找 ai >= si-1的节点
//又si >= 2si-1,成指数倍上升,所以节点数实际只有log个,暴力找这log个即可
//维护d[i] = a[i] - s[i - 1],大于的区间一定是>=0的
int s[N],a[N],d[N];
int n,q;
struct Tree{
	int l,r,mx,val,tag;
}tr[N << 2];
void push_up(int u){
	tr[u].mx = max(tr[lc].mx,tr[rc].mx);
}
void build(int u,int l,int r){
	tr[u].l = l,tr[u].r = r;
	if(l==r){
		tr[u].mx = d[l],tr[u].val = d[l];
		return;
	}
	int mid=l+r>>1;
	build(lc,l,mid);
	build(rc,mid+1,r);
	push_up(u);
}
int res = -1;
void push_down(int u){
	if(tr[u].tag){
		tr[lc].tag+=tr[u].tag;
		tr[rc].tag+=tr[u].tag;
		tr[lc].mx+=tr[u].tag;
		tr[rc].mx+=tr[u].tag;
		tr[lc].val+=tr[u].tag;
		tr[rc].val+=tr[u].tag;
		tr[u].tag = 0;
	}
}
void update(int u,int l,int r,int x){
	if(tr[u].l > r || tr[u].r < l) return;
	if(tr[u].l >= l && tr[u].r <= r){
		tr[u].mx+=x;
		tr[u].val+=x;
		tr[u].tag+=x;
		return;
	}
	push_down(u);
	update(lc,l,r,x);
	update(rc,l,r,x);
	push_up(u);
}
void query(int u){
	if(res!=-1) return;
	if(tr[u].l==tr[u].r){
		if(tr[u].val == 0){
			res = tr[u].l;
		}
		return;
	}
	push_down(u);
	if(tr[lc].mx >= 0) query(lc);
	if(tr[rc].mx >= 0) query(rc);
}
void solve(){
	cin >> n >> q;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		s[i] = s[i - 1] + a[i];
		d[i] = a[i] - s[i - 1];
	}
	build(1,1,n);
	while(q--){
		int x,v;
		cin >> x >> v;
		res = -1;
		int d = v - a[x];
		a[x] = v;
		update(1,x,x,d);
		if(x!=n)update(1,x + 1,n,-d);
		query(1);
		cout << res << endl;
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
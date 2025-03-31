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
const ll inf = 0x3f3f3f3f3f3f3f3fLL;
const int infi = 0x3f3f3f3f;
const int P = 13331;
const int N = 200005;
int h,w,n;
struct nodes{
	int r,c,l,id;
	bool operator<(const nodes&t1)const{
		return t1.r < r;
	}
}a[N];
struct tree{
	int l,r,val,tag,mx,pp;
}tr[N<<2];
void push_up(int u){
	tr[u].val = tr[lc].val + tr[rc].val;
	tr[u].mx = max(tr[lc].mx,tr[rc].mx);
}
void build(int u,int l,int r){
	tr[u] = {l,r,0,0,0,0};
	if(l==r) return;
	int mid = l+r>>1;
	build(lc,l,mid);
	build(rc,mid+1,r);
	push_up(u);
}
void push_down(int u){
	if(tr[u].tag){
		tr[lc].val += tr[u].tag * (tr[lc].r - tr[lc].l +1);
		tr[rc].val += tr[u].tag * (tr[rc].r - tr[rc].l +1);
		tr[lc].mx += tr[u].tag;
		tr[rc].mx += tr[u].tag;
		tr[lc].tag += tr[u].tag;
		tr[rc].tag += tr[u].tag;
		if(tr[lc].pp) tr[lc].pp+=tr[u].tag;
		if(tr[rc].pp) tr[rc].pp+=tr[u].tag;
		tr[u].tag = 0;
	}else if(tr[u].pp){
		tr[lc].mx = tr[u].pp;
		tr[rc].mx = tr[u].pp;
		tr[lc].pp = tr[u].pp;
		tr[rc].pp = tr[u].pp;
		tr[lc].tag = 0;
		tr[rc].tag = 0;
		tr[u].pp = 0;
	}
	
}
void update(int u,int l,int r,int val){
	if(tr[u].l > r || tr[u].r < l) return;
	if(tr[u].l >= l && tr[u].r <= r){
		tr[u].val+=(tr[u].r - tr[u].l +1) * val;
		tr[u].tag+=val;
		tr[u].mx += val;
		if(tr[u].pp) tr[u].pp += tr[u].tag;
		return;
	}
	push_down(u);
	update(lc,l,r,val);
	update(rc,l,r,val);
	push_up(u);
}
void update2(int u,int l,int r,int val){
	if(tr[u].l > r || tr[u].r < l) return;
	if(tr[u].l >= l && tr[u].r <= r){
		tr[u].pp=val;
		tr[u].mx=val;
		tr[u].tag = 0;
		return;
	}
	push_down(u);
	update2(lc,l,r,val);
	update2(rc,l,r,val);
	push_up(u);
}
int quary(int u,int l,int r){
	if(tr[u].l > r || tr[u].r < l) return 0;
	if(tr[u].l >= l && tr[u].r <= r){
		return tr[u].mx;
	}
	push_down(u);
	return max(quary(lc,l,r) ,quary(rc,l,r));
}
int ans[N];
void solve(){
	cin >> h >> w >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i].r >> a[i].c >> a[i].l;
		a[i].id = i;
	}
	build(1,1,200010);
	sort(a +1,a+1+n);
	int d = h;
	int mx = a[1].r;
	for(int i = 1;i<=n;i++){
		if(a[i].r == mx){
			ans[a[i].id] = h;
			update(1,a[i].c,a[i].c + a[i].l - 1,1);
		}else{
			int g = quary(1,a[i].c,a[i].c +a[i].l-1);

			ans[a[i].id] = h - g;
			update2(1,a[i].c,a[i].c + a[i].l - 1,1 + g);
		}	
	}
	for(int i = 1;i <= n;i++){
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
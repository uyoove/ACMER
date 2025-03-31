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
const int N = 400005;
int n,d,w;
//一个节点代表 [a[i],a[i] + w -1];
//如果一个节点被增加,那么 [a[i] - w + 1,a[i]] 这么多区间都会被修改,因为她们都会包含a[i]
struct Tree{
	int l,r,tag,mx;
}tr[N << 2];
PII a[N];
void push_up(int u){
	tr[u].mx = max(tr[lc].mx,tr[rc].mx);
}
void build(int u,int l,int r){
	tr[u] = {l,r,0,0};
	if(l==r) return;
	int mid =l+r>>1;
	build(lc,l,mid);
	build(rc,mid + 1,r);
	push_up(u);
}
void push_down(int u){
	if(tr[u].tag){
		int p = tr[u].tag;
		tr[lc].tag += p;
		tr[rc].tag += p;
		tr[lc].mx += p;
		tr[rc].mx += p;
		tr[u].tag = 0;
	}
}
void modify(int u,int l,int r,int val){
	if(tr[u].l > r || tr[u].r < l) return;
	if(tr[u].l >= l && tr[u].r <= r){
		tr[u].tag+=val;
		tr[u].mx+=val;
		return;
	}
	push_down(u);
	modify(lc,l,r,val);
	modify(rc,l,r,val);
	push_up(u);
}

bool cmp(PII p1,PII p2){
	if(p1.fi!=p2.fi) return p1.fi < p2.fi;
	return p1.se < p2.se;
}
void solve(){
	
	cin >> n >> d >> w;
	for(int i = 1;i <= n;i++){
		cin >> a[i].fi >> a[i].se;
	}
	sort(a + 1,a + 1 + n);
	build(1,1,N/2 -1);
	int su = 0;
	int l = 1;
	int mx = 0;
	for(int i = 1;i <= n;i++){
		modify(1,max(a[i].se - w + 1,1ll),a[i].se,1);
		while(l <= i && a[i].fi>a[l].fi + d - 1){
			modify(1,max(a[l].se - w + 1,1ll),a[l].se,-1);
			l++;
		}
		mx=max(mx,tr[1].mx);
	}
	cout << mx <<endl;
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
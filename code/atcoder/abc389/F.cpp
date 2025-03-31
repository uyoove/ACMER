//和爸爸一起学编程真好,不过要小学四年级分流考试了,最近没时间写代码了,呜呜呜
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define out(x) cout << #x << '=' << (x) << endl
#define out2(x, y) cout << #x << '=' << (x) << ',' << #y << '=' << (y) << endl 
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
const int N = 6e5 +1;
int n;
struct Tree{
	int l,r,cov,tag,al,ar;
}tr[N << 2];
void push_up(int u){
	tr[u].al = min(tr[lc].al,tr[rc].al);
	tr[u].ar = max(tr[lc].ar,tr[rc].ar);
}
void build(int u,int l,int r){
	tr[u] = {l,r,0ll,0ll,l,r};
	if(l==r){
		return;
	}
	int mid = l + r >> 1;
	build(lc,l,mid);
	build(rc,mid+1,r);
}
void push_down(int u){
	if(tr[u].tag){
		tr[lc].cov+=tr[u].tag;
		tr[rc].cov+=tr[u].tag;
		tr[lc].al+=tr[u].tag;
		tr[rc].al+=tr[u].tag;
		tr[lc].ar+=tr[u].tag;
		tr[rc].ar+=tr[u].tag;
		tr[lc].tag+=tr[u].tag;
		tr[rc].tag+=tr[u].tag;
		tr[u].tag = 0;
	}
}
void modify(int u,int l,int r,int val){

	if(tr[u].al> r || tr[u].ar< l){
		return;
	}
	
	if(tr[u].al >= l && tr[u].ar <=r){
		//cout << l << " " << r << " "<< tr[u].l + tr[u].cov  << " " << tr[u].r + tr[u].cov << endl; 
		tr[u].cov+=val;
		tr[u].tag+=val;
		tr[u].al+=val;
		tr[u].ar+=val;
		push_down(u);
		return;
	}
	push_down(u);
	modify(lc,l,r,val);
	modify(rc,l,r,val);
	push_up(u);
}
int query(int u,int x){
	if(tr[u].l > x || tr[u].r < x){
		return -1;
	}
	if(tr[u].l==tr[u].r&&tr[u].l==x){
		return tr[u].cov;
	}
	push_down(u);
	int p = query(lc,x);
	if(p==-1) return query(rc,x);
	return p;
}
void solve(){
	cin >> n;
	build(1,1,N - 1);
	for(int i = 1;i<=n;i++){
		int l,r;
		cin >> l >> r;
		modify(1,l,r,1);
		//cout << query(1,3) << endl;
	}
	int m;
	cin >> m;
	while(m--){
		int t;
		cin >> t;
		cout << query(1,t)+t << endl;
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
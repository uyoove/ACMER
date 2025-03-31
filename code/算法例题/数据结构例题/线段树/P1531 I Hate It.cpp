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
struct edges
{
	int l,r,len,mx;
}tr[N << 2];
int a[N];
void update(int u){
	tr[u].mx = max(tr[lc].mx,tr[rc].mx);
}
void build(int u,int l,int r){
	tr[u] = {l,r,r-l+1,a[l]};
	if(l==r) return;
	int mid = l + r >> 1;
	build(lc,l,mid);
	build(rc,mid+1,r);
	update(u);
}
void modify(int u,int x,int v){
	if(tr[u].r < x || tr[u].l > x) return;
	if(tr[u].r == x && tr[u].l == x){
		tr[u].mx=max(tr[u].mx,v);
		return;
	}
	modify(lc,x,v);
	modify(rc,x,v);
	update(u);
}
int query(int u,int l,int r){
	if(tr[u].l > r || tr[u].r < l) return 0;
	if(tr[u].l >= l && tr[u].r <= r){
		return tr[u].mx;
	}
	return max(query(lc,l,r),query(rc,l,r));
} 
int n,m;
void solve(){
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	build(1,1,n);
	while(m--){
		char ch;
		int l,r;
		cin >> ch >> l >> r;
		if(ch == 'Q'){
			cout << query(1,l,r) << endl;
		}else{
			modify(1,l,r);
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
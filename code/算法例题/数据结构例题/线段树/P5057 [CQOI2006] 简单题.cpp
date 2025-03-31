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
int n,m;
struct Tree{
	int l,r,val,tag;
}tr[N << 2];
void build(int u,int l,int r){
	tr[u] = {l,r,0,0};
	if(l==r) return;
	int mid = l + r >> 1;
	build(lc,l,mid);
	build(rc,mid + 1,r);
}
void push_down(int u){
	if(tr[u].tag==0) return;
	tr[lc].tag^=1;
	tr[rc].tag^=1;
	tr[lc].val^=1;
	tr[rc].val^=1;
	tr[u].tag = 0;
}
void update(int u,int l,int r,int v){
	if(tr[u].l > r || tr[u].r < l) return;
	if(tr[u].l >= l && tr[u].r <= r){
		tr[u].tag ^= v;
		tr[u].val ^= 1;
		return;
	}
	push_down(u);
	update(lc,l,r,v);
	update(rc,l,r,v);
}
int query(int u,int x){
	if(tr[u].l > x || tr[u].r < x) return -1;
	if(tr[u].l == x && tr[u].r == x){
		return tr[u].val;
	}
	push_down(u);
	int res = query(lc,x);
	if(res==-1){
		return query(rc,x);
	}
	return res;
}
void solve(){
	cin >> n >> m;
	build(1,1,n);
	while(m--){
		int op;
		cin >> op;
		if(op==1){
			int l,r;
			cin >> l >> r;
			update(1,l,r,1);
		}else{
			int x;
			cin >> x;
			cout << query(1,x) << endl;
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
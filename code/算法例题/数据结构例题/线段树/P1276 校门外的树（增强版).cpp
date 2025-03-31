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
//一颗线段树,统计区域内种树的个数,新种植的个数
struct Tree{
	int l,r,len,add,su1,su2,add2;
}tr[N << 2];
void push_up(int u){
	tr[u].su1 = tr[lc].su1 + tr[rc].su1;
	tr[u].su2 = tr[lc].su2 + tr[rc].su2;
}
void build(int u,int l,int r){
	tr[u] = {l,r,r - l + 1,-1,1,0,-1};
	if(l==r) return;
	int mid = l + r >> 1;
	build(lc,l,mid);
	build(rc,mid+1,r);
	push_up(u);
}
void push_down(int u){
	if(tr[u].add!=-1){
		tr[lc].add=tr[rc].add=tr[u].add;
		tr[lc].su1=tr[lc].su2=tr[u].add*tr[lc].len;
		tr[rc].su2=tr[rc].su1=tr[u].add*tr[rc].len;
		tr[u].add = -1;
	}
	if(tr[u].add2!=-1){
		tr[lc].add2=tr[rc].add2=tr[u].add2;
		tr[lc].su2=tr[lc].len*tr[u].add2 - tr[lc].su1;
		tr[rc].su2=tr[rc].len*tr[u].add2 - tr[rc].su1;
		tr[u].add2 = -1;
	}
}
int query(int u,int l,int r){
	if(tr[u].l > r || tr[u].r < l) return 0;
	if(tr[u].l >= l && tr[u].r <= r){
		return tr[u].su2;
	}
	push_down(u);
	return query(lc,l,r) + query(rc,l,r);
}
void update(int u,int l,int r,int v){
	if(tr[u].l > r || tr[u].r < l) return;
	if(tr[u].l >= l && tr[u].r <= r){
		if(v==0){
			tr[u].su1=tr[u].len*v;
			tr[u].add=v;
			tr[u].add2=v;
			tr[u].su2=tr[u].len*v;
		}else{
			tr[u].su2=tr[u].len*v - tr[u].su1; //空位 - 有大树的位置
			tr[u].add2=v;
		}
		
		return;
	}
	push_down(u);
	update(lc,l,r,v);
	update(rc,l,r,v);
	push_up(u);
}
int n,m;
void solve(){
	cin >> n >> m;
	build(1,1,n + 1);
	int cnt = 0;
	for(int i = 0;i <m ;i++){
		int op,l,r;
		cin >> op >> l >> r;
		l++,r++;
		if(op==0){
			cnt+=query(1,l,r);
			update(1,l,r,0);
		}else{
			update(1,l,r,1);
		}
	}
	cout << query(1,1,n + 1) << endl;
	cout << cnt << endl;

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
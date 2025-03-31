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
const int N = 300005;
vt<int> v;
int gt(int x){
	return lower_bound(all(v),x) - v.begin() + 1;
}
int T[N],L[N],R[N];
int n;
struct Tree{
	int l,r,rev,tag,sum; //tag-1无覆盖,1有增加覆盖,2是有删除覆盖
}tr[N << 2];
void push_up(int u){
	tr[u].sum = tr[lc].sum + tr[rc].sum;
}
void build(int u,int l,int r){
	tr[u] = {l,r,0,-1,0};
	if(l==r) return;
	int mid = l + r >> 1;
	build(lc,l,mid);
	build(rc,mid+1,r);
}
//标记如何覆盖:首先父节点有rev标记,那么子节点如果有tag那么子节点tag会翻转,
//不然,子节点的rev就可以直接翻转区间0/1
//区间赋值，之前的反转标记就会失效。区间反转，之前的赋值标记就会取反。
//它们之间没有先后的顺序，只是每次打新标记的时候直接重新赋值另一种标记就好。
void mark(int u,int k){
	if(k==1){
		tr[u].sum = tr[u].r - tr[u].l + 1;
		tr[u].tag=1;
		tr[u].rev = 0;
	}else if(k==2){
		tr[u].sum = 0;
		tr[u].tag=0;
		tr[u].rev = 0;
	}else{
		if(tr[u].tag!=-1){
			tr[u].tag^=1;
		}else{
			tr[u].rev^=1;
		}
		tr[u].sum = (tr[u].r-tr[u].l + 1) - tr[u].sum;
	}
}
void push_down(int u){
	if(tr[u].tag==1){
		mark(lc,1);
		mark(rc,1);
		tr[u].tag = -1;
	}else if(tr[u].tag==0){
		mark(lc,2);
		mark(rc,2);
		tr[u].tag = -1;
	}
	if(tr[u].rev){
		mark(lc,3);
		mark(rc,3);
		tr[u].rev = 0;
	}
}
void update(int u,int l,int r,int k){
	if(tr[u].l > r || tr[u].r < l) return;
	if(tr[u].l>=l&&tr[u].r<=r){
		mark(u,k);
		return;
	}
	push_down(u);
	update(lc,l,r,k);
	update(rc,l,r,k);
	push_up(u);
}
int query(int u){
	if(tr[u].sum == tr[u].r - tr[u].l + 1){
		return 0;
	}
	if(tr[u].l==tr[u].r) return tr[u].l;
	push_down(u);
	int p = query(lc);
	if(p!=0) return p;
	return query(rc);
}
void solve(){
	v.pb(1);
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> T[i] >> L[i] >> R[i];
		v.pb(L[i]);
		v.pb(R[i]);
		//为什么r[i] + 1要放上去,因为,可能整个区块被放满导致只放L,R不能找到MEX,所以放了R[i] + 1
		v.pb(R[i] + 1); 	
	}
	sort(all(v));
	v.erase(unique(all(v)),v.end());
	build(1,1,v.size() + 1);
	for(int i = 1;i <= n;i++){
		update(1,gt(L[i]),gt(R[i]),T[i]);
		cout << v[query(1) - 1] << endl;
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
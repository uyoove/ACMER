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
int n,a[N];
int q;
struct Tree{
	//lans以左端点开始的最长山峰
	//rans以右端点结束的最长山峰
	//down以左端点开始的最长递减子段
	//up以右端点结束的最长递增子段
	//ans 区间最长山峰
	//lval,rval,左端点值,右端点值
	int l,r,len,lans,rans,up,down,ans,tag,lval,rval;
}tr[N << 2];
void push_up(int u){
	tr[u].lval = tr[lc].lval,tr[u].rval = tr[rc].rval;
	tr[u].up = tr[rc].up;
	if(tr[rc].up == tr[rc].len && tr[lc].rval < tr[rc].lval){
		tr[u].up += tr[lc].up;
	}
	tr[u].down = tr[lc].down;
	if(tr[lc].down == tr[lc].len && tr[lc].rval > tr[rc].lval){
		tr[u].down += tr[rc].down;
	}
 
	tr[u].lans = tr[lc].lans;
	if(tr[lc].up == tr[lc].len){
		if(tr[lc].rval > tr[rc].lval){ //中峰
			tr[u].lans += tr[rc].down;
		}else if(tr[lc].rval < tr[rc].lval){ 
			tr[u].lans += tr[rc].lans; //右峰
		}
	}else if(tr[lc].len==tr[lc].lans && tr[lc].rval > tr[rc].lval){
		tr[u].lans += tr[rc].down; //左峰		
	}

	tr[u].rans = tr[rc].rans;
	if(tr[rc].down == tr[rc].len){
		if(tr[lc].rval < tr[rc].lval){ //中峰
			tr[u].rans += tr[lc].up;
		}else if(tr[lc].rval > tr[rc].lval){ 
			tr[u].rans += tr[lc].rans; //左峰
		}
	}else if(tr[rc].len==tr[rc].rans && tr[lc].rval < tr[rc].lval){
		tr[u].rans += tr[lc].up; //右峰		
	}

	tr[u].ans = max(tr[lc].ans,tr[rc].ans);
	if(tr[lc].rval < tr[rc].lval){ //中锋,右峰
		tr[u].ans = max(tr[u].ans,max(tr[lc].up + tr[rc].down,tr[lc].up + tr[rc].lans));
	}else if(tr[lc].rval > tr[rc].lval){ //中锋,左峰
		tr[u].ans = max(tr[u].ans,max(tr[rc].down + tr[lc].up,tr[lc].rans + tr[rc].down));
	}
}
void build(int u,int l,int r){
	tr[u] = {l,r,r - l + 1,1,1,1,1,1,0,a[l],a[r]};
	if(l==r) return;
	int mid=l+r>>1;
	build(lc,l,mid);
	build(rc,mid + 1,r);
	push_up(u);
}
void push_down(int u){
	int p = tr[u].tag;
	tr[lc].tag+=p,tr[rc].tag+=p;
	tr[lc].lval+=p,tr[lc].rval+=p,tr[rc].lval+=p,tr[rc].rval+=p;
	tr[u].tag=0;
}
void modify(int u,int l,int r,int x){
	if(tr[u].l > r || tr[u].r < l) return;
	if(tr[u].l >= l && tr[u].r <= r){
		tr[u].lval+=x;
		tr[u].rval+=x;
		tr[u].tag+=x;
		return;
	}
	push_down(u);
	modify(lc,l,r,x);
	modify(rc,l,r,x);
	push_up(u);
}
void solve(){
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	cin >> q;
	build(1,1,n);
	while(q--){
		int l,r,x;
		cin >> l >> r >> x;
		modify(1,l,r,x);
		cout << tr[1].ans << endl;
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
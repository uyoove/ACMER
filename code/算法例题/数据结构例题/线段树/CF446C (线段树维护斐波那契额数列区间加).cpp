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
int mod = 1e9 + 9;
int n,q;
int a[N],pre[N],f[N];
int add(int x,int y){
	int p = x + y;
	if(p < 0) return p + mod;
	return p%mod;
}
struct Tree{
	int l,r,len,T1,T2,val; //开头两个节点,可直接作为tag,无需再写tag,val为累加值
}tr[N << 2];
//根据第一项 和 第二项 计算广义斐波那契数列
int calc1(int x,int y,int len){
	if(len==1) return x;
	if(len==2) return y;
	int p = add(x * f[len - 2],y*f[len - 1]%mod);
	return p;
}
//计算总和 fn = sum(1 ~ (n - 2))fi + f2
//sum(1 ~ (n - 2))fi = fn - f2
//sum(1 ~ (n))fi = fn + 2 - f2;
int calc2(int x,int y,int len){
	if(len==1) return x;
	if(len==2) return add(x,y);
	return add(calc1(x,y,len + 2),-y);
}
void push_up(int u){
	tr[u].val = add(tr[lc].val,tr[rc].val);
}
void push_down(int u){
	if(tr[u].T1){
		tr[lc].T1 = add(tr[lc].T1,tr[u].T1);
		tr[lc].T2 = add(tr[lc].T2,tr[u].T2);
		tr[lc].val = add(tr[lc].val,calc2(tr[u].T1,tr[u].T2,tr[lc].len));
		int x = calc1(tr[u].T1,tr[u].T2,tr[lc].len + 1),y = calc1(tr[u].T1,tr[u].T2,tr[lc].len + 2);
		tr[rc].T1=add(tr[rc].T1,x);
		tr[rc].T2 = add(tr[rc].T2,y);
		tr[rc].val = add(tr[rc].val,calc2(x,y,tr[rc].len));
		tr[u].T1 = 0,tr[u].T2 = 0;
	}	
}
void update(int u,int l,int r){
	if(tr[u].l > r || tr[u].r < l) return;
	if(tr[u].l >= l && tr[u].r <= r){
		tr[u].T1 = add(tr[u].T1,f[tr[u].l - l + 1]);
		tr[u].T2 = add(tr[u].T2,f[tr[u].l - l + 2]);
		tr[u].val = add(tr[u].val,calc2(f[tr[u].l - l + 1],f[tr[u].l - l + 2],tr[u].len));
		return;
	}
	push_down(u);
	update(lc,l,r);
	update(rc,l,r);
	push_up(u);
}
int query(int u,int l,int r){
	if(tr[u].l > r || tr[u].r <l) return 0;
	if(l <= tr[u].l && tr[u].r <= r){
		return tr[u].val;
	}
	push_down(u);
	return query(lc,l,r) + query(rc,l,r);
}
void build(int u,int l,int r){
	tr[u] = {l,r,r-l+1,0,0,0};
	if(l==r) return;
	int mid = l + r >> 1;
	build(lc,l,mid);
	build(rc,mid+1,r);
}

void solve(){
	f[1] = 1,f[2] = 1;
	cin >> n >> q;
	for(int i = 3;i <= n + 2;i++) f[i] = add(f[i - 1],f[i - 2]);
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		pre[i] = pre[i - 1] + a[i];
		pre[i]%=mod;
	}
	build(1,1,n);
	for(int i = 1;i <= q;i++){
		int op,l,r;
		cin >> op >> l >> r;
		if(op==1){
			update(1,l,r);
		}else{
			cout << add(add(pre[r],-pre[l-1]),query(1,l,r)) << endl; 
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
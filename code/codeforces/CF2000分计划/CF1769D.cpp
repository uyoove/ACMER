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
//dp[n]
//枚举最小的二十个位置的l,这我可以用单调栈实现
//当前贡献是 pre[r] - pre[l - 1] + min(r - l + 1,k) * x
//分成距离 <= 20暴力, > 20的直接找区间最小即可
int n,k,x;
int a[N];
struct Tree
{
	int l,r,ls,rs,ms,su;
}tr[N << 2];
void push_up(Tree &T,Tree T2,Tree T3){
	T.ls = max(T2.ls,T2.su + T3.ls);
	T.rs = max(T3.rs,T3.su + T2.rs);
	T.su = T2.su+T3.su;
	T.ms = max(max(T3.ms,T2.ms),T2.rs + T3.ls); 
}
void build(int u,int l,int r){
	tr[u] = {l,r,0,0,0};
	if(l==r){
		tr[u].ls = a[l];
		tr[u].rs = a[l];
		tr[u].ms = a[l];
		tr[u].su = a[l];
		return;
	}
	int mid = l + r >> 1;
	build(lc,l,mid);
	build(rc,mid + 1,r);
	push_up(tr[u],tr[lc],tr[rc]);
}
void update(int u,int x,int val){
	if(tr[u].l > x || tr[u].r < x) return;
	if(tr[u].l==x&&tr[u].r==x){
		int p = tr[u].ms + val;
		tr[u].ls = tr[u].rs = tr[u].ms = p;
		tr[u].su = p;
		return;
	}
	update(lc,x,val);
	update(rc,x,val);
	push_up(tr[u],tr[lc],tr[rc]);
}
Tree query(int u,int l,int r){
	if(tr[u].l > r || tr[u].r < l) return {};
	if(tr[u].l >= l && tr[u].r <= r){
		return tr[u];
	} 
	Tree T;
	Tree t1 = query(lc,l,r);
	Tree t2 = query(rc,l,r);
	push_up(T,t1,t2);
	return T;
}
void solve(){
	n = read(),k=read(),x = read();
	if(x < 0) x=-x,k=n-k;
	for(int i = 1;i <= n;i++){
		a[i] = read();
		a[i]-=x;
	}
	build(1,1,n);
	int l = 1;
	int mx = 0;
	for(int i = 1;i <= n;i++){
		update(1,i,2*x);
		while(i-l + 1 > k){
			update(1,l,-2*x);
			l++;
		}
		mx = max(mx,query(1,1,n).ms);
	}
	cout << mx <<endl;
}

signed main(){
	int times = 1;
	cin >> times;
	while(times--){
		solve();
	}
	return 0;
}
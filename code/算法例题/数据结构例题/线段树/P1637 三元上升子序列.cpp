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
int n;
int a[N];
struct Tree{
	int l,r,val;
}tr[N << 1];
void build(int u,int l,int r){
	tr[u] = {l,r,0};
	if(l==r) return;
	int mid = l+r>>1;
	build(lc,l,mid);
	build(rc,mid+1,r);
}
void modify(int u,int x){
	if(tr[u].l > x || tr[u].r < x) return;
	if(tr[u].l==x&&tr[u].r==x){
		tr[u].val++;
		return;
	}
	modify(lc,x);
	modify(rc,x);
	tr[u].val = tr[lc].val + tr[rc].val;
}
int query(int u,int l,int r){
	if(tr[u].l > r || tr[u].r < l) return 0;
	if(tr[u].l>=l&&tr[u].r<=r){
		return tr[u].val;
	}
	return query(lc,l,r) + query(rc,l,r);
}
int pre[N];
void solve(){
	cin >> n;
	build(1,1,100000);
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		pre[i] = query(1,1,a[i] - 1);
		modify(1,a[i]);
	}
	build(1,1,100000);
	int cnt = 0;
	for(int i = n;i >= 1;i--){
		int t = query(1,a[i] + 1,100000);
		cnt+=t*pre[i];
		modify(1,a[i]);
	}
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
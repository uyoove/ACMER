//最后一舞
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
const int N = 500005;
int v[N];
int n,m;
int ans = 0;
struct Tree{
	int l,r,val;
	vt<int> v;
}tr[N << 2];
void build(int u,int l,int r){
	tr[u] = {l,r,1};
	if(l==r) return;
	int mid = l + r >> 1;
	build(lc,l,mid);
	build(rc,mid+1,r);
	tr[u].val = tr[lc].val + tr[rc].val;
}
void add(int u,int l,int r,int op){
	if(tr[u].l > r || tr[u].r < l) return;
	if(tr[u].l>=l&&tr[u].r<=r){
		tr[u].v.pb(op);
		return;
	}
	add(lc,l,r,op);
	add(rc,l,r,op);
}
void modify(int u,int x){
	if(tr[u].l > x || tr[u].r < x) return;
	if(tr[u].l==tr[u].r && tr[u].l==x){
		tr[u].val = 0;
		for(auto p:tr[u].v){
			v[p] -= 1; //把剩下的那个节点剪掉
			if(v[p]==1) ans += p*p;
			else if(v[p]==0) ans -= p*p;
		}
		return;
	}
	modify(lc,x),modify(rc,x);
	tr[u].val = tr[lc].val + tr[rc].val;
	if(tr[u].val == 1){
		for(auto p:tr[u].v){
			v[p] -= (tr[u].r - tr[u].l + 1) - 1; //整个区间-1个节点
			if(v[p]==1) ans += p*p;
			else if(v[p]==0) ans -= p*p;
		}
	}else if(tr[u].val == 0){
		for(auto p:tr[u].v){
			v[p] -= 1; //把剩下的那个节点剪掉
			if(v[p]==1) ans += p*p;
			else if(v[p]==0) ans -= p*p;
		}
	}
	
}
void solve(){
	cin >> n >> m;
	ans = 0;
	build(1,0,n-1);
	for(int i = 1;i <= m;i++){
		int l,r;
		cin >> l >> r;
		v[i] = r - l + 1;
		add(1,l,r,i);
		if(r - l + 1 == 1) ans+=i*i;
	}
	cout << ans << " ";
	for(int i = 1 ;i <= n;i++){
		int t;
		cin >> t;
		t = (t + ans)%n;
		modify(1,t);
		cout << ans << " ";
	}
	cout << endl;
}

signed main(){
	std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
	int times = 1;
	cin >> times;
	while(times--){
		solve();
	}
	return 0;
}
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
const int N = 500005;
struct Tree{
	int l,r,mx;
}tr[N << 2];
int a[N];
void build(int u,int l,int r){
	tr[u] = {l,r,a[l]};
	if(l==r) return;
	int mid= l + r >> 1;
	build(lc,l,mid);
	build(rc,mid + 1,r);
	tr[u].mx = max(tr[lc].mx,tr[rc].mx);
}
void modify(int u,int x,int val){
	if(tr[u].l > x || tr[u].r < x) return;
	if(tr[u].l==tr[u].r && tr[u].r == x){
		tr[u].mx = val;
		return;
	}
	modify(lc,x,val);
	modify(rc,x,val);
	tr[u].mx = max(tr[lc].mx,tr[rc].mx);
}
int query(int u,int l,int r){
	if(tr[u].l > r || tr[u].r < l) return 0;
	if(tr[u].l >= l && tr[u].r <= r) return tr[u].mx;
	return max(query(lc,l,r),query(rc,l,r));
}
int n,q;
int v[25000001];
int hs[N],p[25000001];
struct Fenwick{
	vector<int> tr;
	int sz;
	void init(int n){
		tr.resize(n + 1);
		sz = n;
	}
	Fenwick(){}
	Fenwick(int n){
		init(n);
	}
	void add(int k,int val){
		for(int i = k;i <= sz;i+=(i&-i)){
			tr[i]^=val;
		}
	}
	int query(int k){
		int res = 0;
		for(int i = k;i > 0;i-=(i&-i)){
			res^=tr[i];
		}
		return res;
	}
	int ask_sum(int l,int r){
		return query(r) ^ query(l - 1);
	}
};
void solve(){
	cin >> n >> q;
	
	Fenwick fk(n);
	int mx = 0;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		mx = max(a[i],mx);
	}
	for(int i = 0;i <= mx;i++){
		v[i] = rnd();
	}
	for(int i = 1;i <= mx;i++){
		p[i] = p[i - 1] ^ v[i];
	}
	for(int i = 1;i <= n;i++){
		hs[i] = v[a[i]];
		fk.add(i,hs[i]);
	}
	build(1,1,n);
	while(q--){
		int op;
		cin >> op;
		if(op==1){
			int x,val;
			cin >> x >> val;
			modify(1,x,val);
			fk.add(x,hs[x]);
			hs[x] = val;
			fk.add(x,hs[x]);
		}else{
			int l,r;
			cin >> l >> r;
			int mx = query(1,l,r);
			int len = r - l + 1;
			int mi = mx - len + 1;
			//cout << mx << " " << mi << endl;
			if(fk.ask_sum(l,r) == (p[mx] ^ p[mi - 1])){
				cout << "damushen" << endl;
			}else{
				cout << "yuanxing" << endl;
			}
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
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
const ll inf = 0x3f3f3f3f3f3f3f3fLL;
const int infi = 0x3f3f3f3f;
const int P = 13331;
const int N=200005;
int n,q;
ll a[N], b[N], c[N];
struct T {
	int l, r;
	ll ans;
	int mi,mx;
} t[N*4];
 
ll gcd(ll x, ll y) {
	return y ? gcd(y, x % y) : x;
}
 
void build(int p, int l, int r) {
	t[p].l = l;
	t[p].r = r;
	if (l == r) {
		t[p].ans = b[l];
		t[p].mi = a[l];
		t[p].mx = a[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(p << 1, l, mid);
	build(p << 1 | 1, mid + 1, r);
	t[p].ans = gcd(t[p<<1].ans, t[p<<1|1].ans);
	t[p].mi = min(t[p<<1].mi,t[p<<1|1].mi);
	t[p].mx = max(t[p<<1].mx,t[p<<1|1].mx);

}
 
void change_add(int p, int x, ll v) {
	if (t[p].l == t[p].r) {
		t[p].ans += v;
		return;
	}
	int mid = (t[p].l + t[p].r) >> 1;
	if (x <= mid) change_add(p << 1, x, v);
	else change_add(p << 1 | 1, x, v);
	t[p].ans = gcd(t[p<<1].ans, t[p<<1|1].ans);
}
 
ll ask_t(int p, int l, int r) {
	if (l <= t[p].l && r >= t[p].r) return t[p].ans;
	int mid = (t[p].l + t[p].r) >> 1;
	ll ans = 0;
	if (l <= mid) ans = gcd(ans, ask_t(p << 1, l, r));
	if (r > mid) ans = gcd(ans, ask_t(p << 1 | 1, l, r));
	return abs(ans);
}
ll ask_mi(int p, int l, int r) {
	if (l <= t[p].l && r >= t[p].r) return t[p].mi;
	int mid = (t[p].l + t[p].r) >> 1;
	ll ans = 1e12;
	if (l <= mid) ans = min(ans, ask_mi(p << 1, l, r));
	if (r > mid) ans = min(ans, ask_mi(p << 1 | 1, l, r));
	return ans;
} 
ll ask_mx(int p, int l, int r) {
	if (l <= t[p].l && r >= t[p].r) return t[p].mx;
	int mid = (t[p].l + t[p].r) >> 1;
	ll ans = 0;
	if (l <= mid) ans = max(ans, ask_mx(p << 1, l, r));
	if (r > mid) ans = max(ans, ask_mx(p << 1 | 1, l, r));
	return ans;
} 
void add(int x, ll y) {
	while (x <= n) {
		c[x] += y;
		x += x & -x;
	}
}
 
ll ask_c(int x) {
	ll ans = 0;
	while (x) {
		ans += c[x];
		x -= x & -x;
	}
	return ans;
}



void solve(){
	cin >> n >> q;
	b[0] = 0;
	c[n + 1] = 0;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		c[i] = 0;
		b[i] = a[i] - a[i - 1];
	}
	build(1,1,n); 

	while(q--){
		int l,r;
		cin >> l >> r;
		if(l==r || ask_mi(1,l,r) == ask_mx(1,l,r)){
			cout <<  0 << " ";
			continue;
		}
		int p = gcd(a[l] + ask_c(l), ask_t(1, l + 1, r));
		ll d = -ask_mi(1,l,r);
		change_add(1, l, d);
		add(l, d);
		if (r + 1 <= n) {
			change_add(1, r + 1, -d);
			add(r + 1, -d);
		}
		p = max(p,gcd(a[l] + ask_c(l), ask_t(1, l + 1, r)));
		cout << p << " ";
		d = -d;
		change_add(1, l, d);
		add(l, d);
		if (r + 1 <= n) {
			change_add(1, r + 1, -d);
			add(r + 1, -d);
		}
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
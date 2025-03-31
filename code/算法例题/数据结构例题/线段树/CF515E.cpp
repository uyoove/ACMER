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
int n,q;
int sumi[N],sumx[N];
int d[N],h[N];
struct Tree{
	int l,r,mx,mi; //都是最值的下标编号
}tr[N << 2];
int gtmx(int x,int y){
	return sumx[x] < sumx[y] ? y : x;
}
int gtmi(int x,int y){
	return sumi[x] > sumi[y] ? y : x;
}
void push_up(int u){
	tr[u].mx = gtmx(tr[lc].mx,tr[rc].mx);
	tr[u].mi = gtmi(tr[lc].mi,tr[rc].mi);
}
void build(int u,int l,int r){
	tr[u] = {l,r,l,l};
	if(l==r) return;
	int mid = l + r >> 1;
	build(lc,l,mid);
	build(rc,mid+1,r);
	push_up(u);
}
//最大最小
PII query(int u,int l,int r){
	if(tr[u].l > r || tr[u].r < l) return {0,0};
	if(tr[u].l >= l && tr[u].r <= r){
		return {tr[u].mx,tr[u].mi};
	}
	PII p1 = query(lc,l,r);
	PII p2 = query(rc,l,r);
	return {gtmx(p1.fi,p2.fi),gtmi(p1.se,p2.se)};
}
int work(int l,int r){
	PII p = query(1,l,r);
	int mi = p.se,mx = p.fi;
	if(mi!=mx) return sumx[mx] - sumi[mi];
	p = query(1,l,mi - 1);
	PII p2 = query(1,mi + 1,r);
	PII d = {gtmx(p.fi,p2.fi),gtmi(p.se,p2.se)};
	return max(sumx[mx] - sumi[d.se],sumx[d.fi] - sumi[mi]);
}
void solve(){
	cin >> n >> q;
	sumi[0] = inf;
	sumx[0] = -inf;
	for(int i = 1;i <= n;i++){
		cin >> d[i%n + 1];
		d[i%n + n + 1] = d[i%n + 1];
	}
	for(int i = 1;i <= n;i++){
		cin >> h[i];
		h[i + n] = h[i];
	}
	int su = 0;
	for(int i = 1;i <= n*2;i++){
		su += d[i];
		sumi[i] = su - 2*h[i];
		sumx[i] = su + 2*h[i];
	}
	build(1,1,n * 2);
	while(q--){
		int l,r;
		cin >> l >> r;
		if(l <= r){
			cout << work(r + 1,n + l - 1) << endl;
		}else{
			cout << work(r + 1,l - 1) << endl;
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
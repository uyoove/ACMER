//和爸爸一起学编程真好,不过要小学四年级分流考试了,最近没时间写代码了,呜呜呜
#include<bits/stdc++.h>
using namespace std;
#define out(x) cout << #x << '=' << (x) << endl
#define out2(x, y) cout << #x << '=' << (x) << ',' << #y << '=' << (y) << endl 
#define lc u<<1
#define rc u<<1|1
#define pb push_back
#define vt vector
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define PII pair<int,long long>
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
const int N = 300005;
int n,q;
struct nodes{
	int x[3];
}a[N];
long long calc(nodes n1,int op){
	long long res = 0;
	for(int j = 0;j < 3;j++){
		if(op & (1 << j)){
			res += n1.x[j];
		}else{
			res -= n1.x[j]; 
		}
	}
	return res;
}
struct Tree{
	int l,r;
	long long mxval[8],mival[8];
}tr[N << 2];
void push_up(int u){
	for(int i = 0;i < 8;i++){
		if(tr[lc].mxval[i] >= tr[rc].mxval[i]){
			tr[u].mxval[i] = tr[lc].mxval[i];
		}else{
			tr[u].mxval[i] = tr[rc].mxval[i];
		}
		if(tr[lc].mival[i] <= tr[rc].mival[i]){
			tr[u].mival[i] = tr[lc].mival[i];
		}else{
			tr[u].mival[i] = tr[rc].mival[i];
		}
	}
}
void build(int u,int l,int r){
	tr[u].l = l, tr[u].r = r;
	if(l==r){
		for(int i = 0;i < 8;i++){
			tr[u].mival[i] = calc(a[l],i);
			tr[u].mxval[i] = calc(a[l],i);
		}
		return;
	}
	int mid = l + r >> 1;
	build(lc,l,mid);
	build(rc,mid + 1,r);
	push_up(u);
}
void update(int u,int x,nodes n1){
	if(tr[u].l > x || tr[u].r < x){
		return;
	}
	if(tr[u].l == tr[u].r && tr[u].l == x){
		a[x] = n1;
		for(int i = 0;i < 8;i++){
			tr[u].mxval[i] = tr[u].mival[i] = calc(n1,i);
		}
		return;
	}
	update(lc,x,n1),update(rc,x,n1);
	push_up(u);
}
vector<long long> query_mi(int u,int l,int r){
	vector<long long> t(8);
	if(tr[u].l > r || tr[u].r < l){
		for(int i = 0;i < 8;i++){
			t[i] = 1e12;
		}
		return t;
	}
	if(tr[u].l >= l && tr[u].r <= r){
		for(int i = 0;i < 8;i++){
			t[i] = tr[u].mival[i];
		}
		return t;
	}
	vector<long long> t1 = query_mi(lc,l,r),t2 = query_mi(rc,l,r);
	for(int i = 0;i < 8;i++){
		if(t1[i] < t2[i]){
			t[i] = t1[i];
		}else{
			t[i] = t2[i];
		}
	}
	return t;
}
vector<long long> query_mx(int u,int l,int r){
	vector<long long> t(8);
	if(tr[u].l > r || tr[u].r < l){
		for(int i = 0;i < 8;i++){
			t[i] = -1e12;
		}
		return t;
	}
	if(tr[u].l >= l && tr[u].r <= r){
		for(int i = 0;i < 8;i++){
			t[i] = tr[u].mxval[i];
		}
		return t;
	}
	vector<long long> t1 = query_mx(lc,l,r),t2 = query_mx(rc,l,r);
	for(int i = 0;i < 8;i++){
		if(t1[i] > t2[i]){
			t[i] = t1[i];
		}else{
			t[i] = t2[i];
		}
	}
	return t;
}
void solve(){
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i].x[0] >> a[i].x[1] >> a[i].x[2];
	}
	cin >> q;
	build(1,1,n);
	while(q--){
		int op;
		cin >> op;
		if(op==2){
			int l,r;
			cin >> l >> r;
			vt<ll> v1 = query_mi(1,l,r);
			vt<ll> v2 = query_mx(1,l,r);
			long long ans = 0;
			for(int i = 0;i < 8;i++){
				ans = max(ans,abs(v2[i]- v1[i]));
			}
			cout << ans << endl;
		}else{
			int x,a,b,c;
			cin >> x >> a >> b >> c;
			nodes  t1 = {a,b,c};
			update(1,x,t1);
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
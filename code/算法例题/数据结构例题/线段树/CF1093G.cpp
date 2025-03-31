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
const ll inf = 0x3f3f3f3f;
const int infi = 0x3f3f3f3f;
const int P = 13331;
const int N = 200005;
struct Tree{
	int l,r,mxval[1 << 5 + 1],mival[1 << 5 +1];
}tr[N << 2];
vt<int> a[N];
int n,k;
int calc(vt<int> v,int i){
	int res = 0;
	for(int j = 0;j < k;j++){
		if((i >> j)&1){
			res += v[j];
		}else{
			res -= v[j];
		}
	}
	return res;
}
void push_up(int u){
	for(int i = 0;i < (1 << k);i++){
		tr[u].mxval[i] = max(tr[lc].mxval[i],tr[rc].mxval[i]);
		tr[u].mival[i] = min(tr[lc].mival[i],tr[rc].mival[i]);
	}
}
void build(int u,int l,int r){
	tr[u].l = l,tr[u].r = r;
	if(l==r){
		for(int i = 0;i < (1 << k);i++){
			tr[u].mxval[i] = tr[u].mival[i] = calc(a[l],i);
		}
		return;
	}
	int mid = l + r >> 1;
	build(lc,l,mid);
	build(rc,mid+1,r);
	push_up(u);
}
//默认已在a上面更改
void modify(int u,int x){
	if(tr[u].l > x || tr[u].r < x) return;
	if(tr[u].l == x && tr[u].r == x){
		for(int i = 0;i < (1 << k);i++){
			tr[u].mxval[i] = tr[u].mival[i] = calc(a[x],i);
		}
		return;
	}
	modify(lc,x);
	modify(rc,x);
	push_up(u);
}
PII query(int u,int l,int r,int op){
	if(tr[u].l > r || tr[u].r < l) return {inf,-inf};
	if(tr[u].l >= l && tr[u].r <= r){
		return {tr[u].mival[op],tr[u].mxval[op]};
	}
	PII T1 = query(lc,l,r,op);
	PII T2 = query(rc,l,r,op);
	return {min(T1.fi,T2.fi),max(T1.se,T2.se)};
}
void solve(){
	cin >> n >> k;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j<=k;j++){
			int t;
			cin >> t;
			a[i].pb(t);
		}
	}
	build(1,1,n);
	int q;
	cin >> q;
	for(int i = 1;i <= q;i++){
		int op,l,r;
		cin >> op;
		if(op==1){
			int id;
			cin >> id;
			for(int j = 1;j <= k;j++){
				cin >> a[id][j - 1];
			}
			modify(1,id);
		}else{
			int res = 0;
			cin >> l >> r;
			for(int i = 0;i < (1 << k);i++){
				res = max(query(1,l,r,i).se - query(1,l,r,i).fi,res);
				//cout << query(1,l,r,i).se << " " << query(1,l,r,i).fi << endl;
			}
			cout << res <<endl;
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
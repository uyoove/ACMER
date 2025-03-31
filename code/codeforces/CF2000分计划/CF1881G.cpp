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
int n,m;
string s;
struct Tree{
	int l,r,len,l1,l2,r2,r1,ans,tag;
}tr[N << 2];
void push_up(int u){
	if(tr[u].len == 2){
		tr[u].l1 = tr[lc].l1;
		tr[u].l2 = tr[rc].r1;
		tr[u].r1 = tr[rc].r1;
		tr[u].r2 = tr[lc].l1;
		tr[u].ans = (tr[lc].l1 == tr[rc].l1);
		return;
	}
	if(tr[u].len == 3){
		tr[u].l1 = tr[lc].l1;
		tr[u].l2 = tr[lc].r1;
		tr[u].r1 = tr[rc].l1;
		tr[u].r2 = tr[lc].r1;
		tr[u].ans = tr[lc].ans + (tr[u].l2 == tr[u].r1) + (tr[u].r1==tr[u].l1); 
		return;
	}
	tr[u].l1 = tr[lc].l1;
	tr[u].l2 = tr[lc].l2;
	tr[u].r1 = tr[rc].r1;
	tr[u].r2 = tr[rc].r2;
	tr[u].ans = tr[lc].ans + tr[rc].ans + (tr[lc].r1 == tr[rc].l1) + (tr[lc].r1 == tr[rc].l2) + (tr[lc].r2 == tr[rc].l1);
}
void build(int u,int l,int r){
	tr[u].l = l,tr[u].r = r,tr[u].len = r - l + 1;
	tr[u].ans = 0;
	tr[u].tag = 0;
	if(l == r){
		tr[u].l1 = tr[u].l2 = tr[u].r1 = tr[u].r2 = s[l] - 'a';
		tr[u].ans = 0;
		return;
	}
	int mid = l + r >> 1;
	build(lc,l,mid);
	build(rc,mid + 1,r);
	push_up(u);
}
void push_down(int u){
	int v = tr[u].tag;
	tr[lc].tag += v;
	tr[lc].tag%=26;
	tr[rc].tag += v;
	tr[rc].tag%=26;
	tr[lc].l1 += v;
	tr[lc].l1%=26;
	tr[lc].l2 += v;
	tr[lc].l2%=26;
	tr[lc].r1 += v;
	tr[lc].r1%=26;
	tr[lc].r2 += v;
	tr[lc].r2%=26;
	tr[rc].l1 += v;
	tr[rc].l1%=26;
	tr[rc].l2 += v;
	tr[rc].l2%=26;
	tr[rc].r1 += v;
	tr[rc].r1%=26;
	tr[rc].r2 += v;
	tr[rc].r2%=26;
	tr[u].tag = 0;
}
void modify(int u,int l,int r,int v){
	if(tr[u].l > r || tr[u].r < l) return;
	if(tr[u].l >= l && tr[u].r <= r){
		tr[u].l1 += v;
		tr[u].l1%=26;
		tr[u].l2 += v;
		tr[u].l2%=26;
		tr[u].r1 += v;
		tr[u].r1%=26;
		tr[u].r2 += v;
		tr[u].r2%=26;
		tr[u].tag += v;
		tr[u].tag%=26;
		return;
	}
	push_down(u);
	modify(lc,l,r,v),modify(rc,l,r,v);
	push_up(u);
}
//计算拼凑答案
int hb(int u,int l,int r){
	int mid = tr[u].l + tr[u].r >> 1;
	int ans = 0;
	int L = max(l,tr[u].l),R = min(r,tr[u].r);
	ans += (tr[lc].r1 == tr[rc].l1);
	if(L!=mid) ans += (tr[lc].r2 == tr[rc].l1);
	if(R!=mid + 1) ans += (tr[lc].r1 == tr[rc].l2);
	return ans;
}
int query(int u,int l,int r){
	if(tr[u].l >= l && tr[u].r <= r){
		return tr[u].ans;
	}
	push_down(u);
	int mid = tr[u].l + tr[u].r >> 1;
	//在左边完整区间就去左区间,右边完整就去右边,不然就得左右拼凑
	if(r <= mid) return query(lc,l,r);
	if(l > mid) return query(rc,l,r);
	return query(lc,l,r) + query(rc,l,r) + hb(u,l,r);
}
void solve(){
	cin >> n >> m;
	cin >> s;
	s = " " + s;
	build(1,1,n);
	while(m--){
		int op;
		cin >> op;
		if(op==1){
			int l,r,x;
			cin >>l  >> r >>x;
			x%=26;
			modify(1,l,r,x);
		}else{
			int l,r;
			cin >> l >> r;
			int p = query(1,l,r);
			if(p > 0){
				cout << "No" << endl;
			}else{
				cout << "Yes" << endl;
			}
		}
	}
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
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
const int N = 200005;
int n,q;
//l为0 r为1
struct Tree{
	int l,r,len,mxl,mxr,mxval,chl,chr; 
}tr[N << 2];
void push_up(int u){
	if(tr[rc].mxr == tr[rc].len){
		if(tr[lc].chr == tr[rc].chl){
			tr[u].mxr = tr[rc].len;
		}else{
			tr[u].mxr = tr[rc].len + tr[lc].mxr;
		}
	}else{
		tr[u].mxr = tr[rc].mxr;
	}
	if(tr[lc].mxl == tr[lc].len){
		if(tr[lc].chr == tr[rc].chl){
			tr[u].mxl = tr[lc].len;
		}else{
			tr[u].mxl = tr[lc].len + tr[rc].mxl;
		}
	}else{
		tr[u].mxl = tr[lc].mxl;
	}
	tr[u].mxval = max(tr[lc].mxval,tr[rc].mxval);
	if(tr[lc].chr != tr[rc].chl){
		tr[u].mxval = max(tr[u].mxval,tr[lc].mxr + tr[rc].mxl);
	}
	tr[u].chr = tr[rc].chr;
	tr[u].chl = tr[lc].chl;
}
void build(int u,int l,int r){
	tr[u] = {l,r,r-l+1,1,1,1,0,0};
	if(l==r) return;
	int mid = (l + r) >> 1;
	build(lc,l,mid);
	build(rc,mid + 1,r);
	push_up(u);
}
void modify(int u,int x){
	if(tr[u].l > x || tr[u].r < x) return;
	if(tr[u].l == x && tr[u].r == x){
		tr[u].chr^=1;
		tr[u].chl=tr[u].chr;
		return;
	}
	modify(lc,x);
	modify(rc,x);
	push_up(u);
}
void solve(){
	cin >> n >> q;
	build(1,1,n);
	while(q--){
		int x;
		cin >> x;
		modify(1,x);
		cout <<tr[1].mxval << endl;
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
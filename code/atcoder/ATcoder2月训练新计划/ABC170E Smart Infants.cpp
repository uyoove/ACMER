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
const int N = 2e5 + 10;
struct Tree{
	int l,r;
	multiset<int> mul;
}tr[N << 2];
void push_up(int u){
	tr[u].mul.clear();
	if(tr[lc].l==tr[lc].r){
		if(tr[lc].mul.size()){
			auto it = tr[lc].mul.end();
			it--;
			tr[u].mul.insert(*it);
		}
		
	}
	if(tr[rc].mul.size() && tr[rc].l==tr[rc].r){
		auto it = tr[rc].mul.end();
		it--;
		tr[u].mul.insert(*it);
	}
	if(tr[lc].mul.size()&& tr[lc].l!=tr[lc].r){
		auto it = tr[lc].mul.begin();
		tr[u].mul.insert(*it);
	}
	if(tr[rc].mul.size()&& tr[rc].l!=tr[rc].r){
		auto it = tr[rc].mul.begin();
		tr[u].mul.insert(*it);
	}
	
	
}
void build(int u,int l,int r){
	tr[u].l=l,tr[u].r=r;
	tr[u].mul.clear();
	if(l==r) return;
	int mid = l + r >> 1;
	build(lc,l,mid);
	build(rc,mid + 1,r);
}
void modify(int u,int x,int op,int val){
	if(tr[u].l > x || tr[u].r < x) return;
	if(tr[u].l==x&&tr[u].r==x){
		if(op==1){
			tr[u].mul.insert(val);
		}else{
			auto p = tr[u].mul.lower_bound(val);
			tr[u].mul.erase(p);
		}
		return; 
	}
	modify(lc,x,op,val);
	modify(rc,x,op,val);
	push_up(u);
}
int n,q;
int a[N],b[N];
const int B = 200005; 
void solve(){
	cin >> n >> q;
	build(1,1,B);
	for(int i = 1;i <= n;i++){
		cin >> a[i] >> b[i];
		modify(1,b[i],1,a[i]);
	}
	while(q--){
		int c,d;
		cin >> c >> d;
		modify(1,b[c],0,a[c]);
		b[c] = d;
		modify(1,b[c],1,a[c]);
		auto it = tr[1].mul.begin();
		cout << (*it) << endl;
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
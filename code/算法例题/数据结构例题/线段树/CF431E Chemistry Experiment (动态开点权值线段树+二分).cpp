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
const int N = 800005;
int n,q;
int h[N];
struct Tree{
	int ls,rs,val,sz;
}tr[N << 2];
int idx,root;
void push_up(int u){
	tr[u].val = tr[tr[u].ls].val + tr[tr[u].rs].val;
	tr[u].sz = tr[tr[u].ls].sz + tr[tr[u].rs].sz;
}
void add(int &u,int l,int r,int x,int val){
	if(u==0) u = ++idx; 
	if(l==x && r==x){
		tr[u].val += val * x;
		tr[u].sz += val;
		return;
	}
	int mid = l + r >> 1;
	if(x <= mid) add(tr[u].ls,l,mid,x,val);
	if(x > mid)  add(tr[u].rs,mid + 1,r,x,val);
	push_up(u);
}
PII query(int &u,int l,int r,int x,int y){
	if(!u) return {0,0};
	if(x <= l && r <= y){
		return {tr[u].sz,tr[u].val};
	}
	int mid = l + r >> 1;
	PII p1 = {0,0},p2 = {0,0};
	if(x <= mid) p1 = query(tr[u].ls,l,mid,x,y);
	if(y > mid) p2 = query(tr[u].rs,mid + 1,r,x,y);
	PII p3;
	p3.fi = p1.fi + p2.fi;
	p3.se = p1.se + p2.se;
	return p3;
}
void bsh(){
	int v;
	cin >> v;
	double c = 1e-5;
	double l = 0,r = 1e15,ans = 0;
	while(r-l>c){
		double mid = (l + r)/2.0;
		int d1 = ceil((ll)mid);
		PII p = query(root,0,inf,0,d1);
		int sz = p.fi,val = p.se;
		double d = sz * mid - val;
		if(d >= v){
			r = mid ;
			ans= mid;
		}else{
			l = mid;
		}
	}
	printf("%.5lf\n", ans);
}
void solve(){
	cin >> n >> q;
	for(int i = 1;i <= n;i++) cin >> h[i],add(root,0,inf,h[i],1);
	while(q--){
		int op;
		cin >> op;
		if(op==1){
			int x,val;
			cin >> x >> val;
			add(root,0,inf,h[x],-1);
			h[x] = val;
			add(root,0,inf,h[x],1);
		}else{
			bsh();
		}
	}

}

signed main(){
	// std::ios::sync_with_stdio(0);
    // std::cin.tie(0);
    // std::cout.tie(0);
	int times = 1;
	//cin >> times;
	while(times--){
		solve();
	}
	return 0;
}
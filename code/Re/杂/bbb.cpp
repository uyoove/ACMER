//最后一舞
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
const ll inf = 0x3f3f3f3f3f3f3f3fLL;
const int infi = 0x3f3f3f3f;
const int P = 13331;
const int N = 200005;
int n,m;
int a[N];
struct FHQ
{
	int ls,rs;
    ll key;
    int sz,val;	
}fhq[N*40];
int tot,T1,T2,T3;
il void fhqup(int u){
	fhq[u].sz = fhq[fhq[u].ls].sz + fhq[fhq[u].rs].sz + 1;
}
il void split(int u,int k,int& x,int& y){
	if(!u){
		x = y = 0;
		return;
	}
	if(k >= fhq[u].val){
		x = u;
		split(fhq[u].rs,k,fhq[u].rs,y);
	}else{
		y = u;
		split(fhq[u].ls,k,x,fhq[u].ls);
	}
	fhqup(u);
}
il int merge(int x,int y){
	if(!x||!y) return x+y;
	if(fhq[x].key > fhq[y].key){
		fhq[x].rs = merge(fhq[x].rs,y);
		fhqup(x);
		return x;
	}else{
		fhq[y].ls = merge(x,fhq[y].ls);
		fhqup(y);
		return y;
	}
}
il int NewFHQ(int val){
	fhq[++tot] = {0,0,(int)rnd(),1,val};
	return tot;
}
il void insert(int &root,int val){
	split(root,val,T1,T2);
	root = merge(merge(T1,NewFHQ(val)),T2);
}
void del(int &root,int data){
	split(root,data,T1,T2);
	split(T1,data-1,T1,T3);
	T3=merge(fhq[T3].ls,fhq[T3].rs);
	root=merge(T1,merge(T3,T2));
}
il int find_rank(int &root,int data){
	split(root,data - 1,T1,T2);
	int ans = fhq[T1].sz;
	root = merge(T1,T2);
	return ans;
}
struct Tree{
	int l,r,root;
}tr[N << 2];
il void build(int u,int l,int r){
	tr[u].l=l,tr[u].r=r;
	if(l==r){
		tr[u].root=NewFHQ(a[l]);
		return;
	}
	for(int i = l;i<=r;i++){
		insert(tr[u].root,a[i]); //merge会自动编号,把区间所有数插一下
	}
	int mid =(l+r)/2;
	build(lc,l,mid);
	build(rc,mid + 1,r);
}
il int Rank(int u,int l,int r,int d){
	if(tr[u].l > r || tr[u].r < l){
		return 0;
	}
	if(tr[u].l >= l && tr[u].r <= r){
		return find_rank(tr[u].root,d);
	}
	return Rank(lc,l,r,d) + Rank(rc,l,r,d);
}
il void change(int u,int x,int data){
	del(tr[u].root,a[x]);
	insert(tr[u].root,data);
	if(tr[u].l==tr[u].r){
		
		return;
	}
	int mid=(tr[u].l+tr[u].r)>>1;
	if(x<=mid){
		change(lc,x,data);
	}
	if(x>mid){
		change(rc,x,data);
	}
}
il void solve(){
	n = read(),m = read();
	for(int i = 1;i <= n;i++){
		a[i] = i;
	}
	build(1,1,n);
	ll ans = 0;
	while(m--){
		int l,r;
		cin >> l >> r;
		int mx = max(a[r],a[l]), mi = min(a[r],a[l]);
		int p = Rank(1,l,r,mx ) - Rank(1,l,r,mi+1); 
		if(a[l]<a[r]) ans = ans + 2*p+1;
		else ans = ans-2*p-1;
		int t = a[l];
		change(1,l,a[r]);
		change(1,r,t);
		swap(a[l],a[r]);
		printf("%lld\n", ans);
	}
}

signed main(){
	int times = 1;

	//cin >> times;
	while(times--){
		solve();
	}
	return 0;
}
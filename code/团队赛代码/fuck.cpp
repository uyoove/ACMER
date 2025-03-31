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
const int infi = 1e6;
const int P = 13331;
const int N = 2e5+7;
int n,p;
int a[N];

int pre[N];
struct tree{
	int l,r,len,lmi,rmx,lz1,lz2;
}tr[N << 2];
void push_up(int u){
	tr[u].lmi = min(min(tr[lc].lmi ,tr[rc].lmi),tr[u].lmi);
	tr[u].rmx = max(max(tr[lc].rmx ,tr[rc].rmx),tr[u].rmx );
}
void build(int u,int l,int r){
	tr[u] = {l,r,r-l+1,l,r,infi,-infi};
	if(l==r) return;
	int mid = l+r>>1;
	build(lc,l,mid);
	build(rc,mid+1,r);
	push_up(u);
}
void push_down(int u){
	if(tr[u].lz1!=infi){
		tr[rc].lmi = min(tr[rc].lmi,tr[u].lz1);
		tr[lc].lmi= min(tr[lc].lmi,tr[u].lz1);
		tr[rc].lz1 = min(tr[rc].lz1,tr[u].lz1);
		tr[lc].lz1 = min(tr[lc].lz1,tr[u].lz1);
		tr[u].lz1=infi;
	}
	if(tr[u].lz2!=-infi){
		tr[rc].rmx= max(tr[rc].rmx,tr[u].lz2);
		tr[lc].rmx= max(tr[lc].rmx,tr[u].lz2);
		tr[rc].lz2 = max(tr[rc].lz2,tr[u].lz2);
		tr[lc].lz2 = max(tr[lc].lz2,tr[u].lz2);
		tr[u].lz2=-infi;
	}
}
void update(int u,int l,int r,int ls,int rs){
	if(tr[u].l > r || tr[u].r < l) return;
	
	if(tr[u].l >= l && tr[u].r <= r){
		//cout << tr[u].l << " " << tr[u].r << " "<<l << " " <<r <<endl;
		tr[u].lmi = min(tr[u].lmi ,ls);
		tr[u].rmx = max(tr[u].rmx ,rs);
		tr[u].lz2 = max(tr[u].lz2,rs);
		tr[u].lz1 = min(tr[u].lz1,ls);
		return;
	}
	push_down(u);
	update(lc,l,r,ls,rs);
	update(rc,l,r,ls,rs);
	push_up(u);
}
int query(int u,int l,int r){
	if(tr[u].l > r || tr[u].r < l) return 0x3f3f3f3f;
	if(tr[u].l>=l&&tr[u].r<=r){
		return tr[u].lmi;
	}
	push_down(u);
	
	return min(query(lc,l,r),query(rc,l,r));
}
int query2(int u,int l,int r){
	if(tr[u].l > r || tr[u].r < l) return -0x3f3f3f3f;
	if(tr[u].l>=l&&tr[u].r<=r){
		return tr[u].rmx;
	}
	push_down(u);
	
	return max(query2(lc,l,r),query2(rc,l,r));
}
void solve(){
	int n,q;
	cin >> n >> q;
	
	memset(pre,0,sizeof pre);
	for(int i = 1;i <= n;i++) cin >> a[i],pre[i] = pre[i - 1] + a[i];
		build(1,1,n);
	//cout << 1 << " " <<query(1,3) << " " << query2(1,3) << endl;
	while(q--){
		int op;
		cin >>op;
		if(op==1){
			int l,r;
			cin >> l >> r;
			int ls = query(1,l,r),rs = query2(1,l,r);
			update(1,l,r,min(ls,query(1,l,l)),max(rs,query2(1,r,r)));
		}else{
			int v;
			cin >> v;
			int l = query(1,v,v);
			int r = query2(1,v,v);
			//cout << l << " " << r <<endl;
			double t = (pre[r] - pre[l-1] )*1.0/(r-l+1);
			printf("%.10lf\n",t);
		}
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
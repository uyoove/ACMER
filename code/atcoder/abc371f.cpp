//等差数列trick+线段树维护
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
const ll inf = 0x3f3f3f3f3fLL;
const int infi = 0x3f3f3f3f;
const int P = 13331;
const int N = 200005;
int n;
int x[N];
struct Tree{
	int l,r,len;
	int su,mx,tg; //区间总和,最大的坐标
}tr[N << 2];
void push_up(int u){
	tr[u].mx = max(tr[lc].mx,tr[rc].mx);
	tr[u].su = tr[lc].su + tr[rc].su;
}
void build(int u,int l,int r){
	tr[u] ={l,r,r-l+1,x[l],x[l],-inf};
	if(l==r) return;
	int mid = l+r>>1;
	build(lc,l,mid);
	build(rc,mid+1,r);
	push_up(u);
}
void push_down(int u){
	if(tr[u].tg==-inf) return;
	int tp = tr[u].tg;
	tr[u].tg = -inf;
	tr[lc].mx = tr[lc].tg = tp;
	tr[rc].mx = tr[rc].tg = tp;
	tr[lc].su = tp * tr[lc].len;
	tr[rc].su = tp * tr[rc].len;
}
void modify(int u,int l,int r,int v){
	if(tr[u].l > r || tr[u].r < l) return;
	if(tr[u].l >= l && tr[u].r <= r){
		tr[u].tg = tr[u].mx = v;
		tr[u].su = tr[u].len * v;
		return;
	}
	push_down(u);
	modify(lc,l,r,v);
	modify(rc,l,r,v);
	push_up(u);
}
int query(int u,int l,int r){
	if(tr[u].l > r || tr[u].r < l) return 0;
	if(tr[u].l >= l && tr[u].r <= r){
		return tr[u].su;
	}
	push_down(u);
	return query(lc,l,r) + query(rc,l,r);
}
int querymx(int u,int l,int r){
	if(tr[u].l > r || tr[u].r < l) return -inf;
	if(tr[u].l >= l && tr[u].r <= r){
		return tr[u].mx;
	}
	push_down(u);
	return max(querymx(lc,l,r),querymx(rc,l,r));
}
void solve(){
	cin >> n;
	for(int i = 1;i <= n; i++) cin >> x[i],x[i]-=i;
	build(1,1,n);
	int q;
	cin >> q;
	int res = 0;
	for(int _=0;_<q;_++){
		int t,g;
		cin >> t >> g;
		int curt = query(1,t,t);
		if(curt == g-t) continue;
		if(curt < g - t){ //right
			//binery search to find the last person
			int l = t+1,r = n,ans = t;
			while(l <= r){
				int mid = (l + r) >> 1;
				if(querymx(1,t,mid) <= g - t){
					l = mid + 1;
					ans = mid; 
				}else{
					r = mid - 1;
				}
			}
			res -= query(1,t,ans);
			res += (g - t) * (ans - t + 1); 
			modify(1,t,ans,g-t);
		}else{			 //left
			int l = 1,r = t-1,ans = t;
			while(l <= r){
				int mid = (l + r) >> 1;
				if(querymx(1,1,mid) >= g - t){
					r = mid - 1;
					ans = mid; 
				}else{
					l = mid + 1;
				}
			}
			res += query(1,ans,t);
			res -= (g - t) * (t -ans + 1); 
			modify(1,ans,t,g-t);
		}
	} 
	cout << res << endl;
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
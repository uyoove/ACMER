#include <bits/stdc++.h>
using namespace std;
#define int long long
#define lc u<<1
#define rc u<<1|1
const int N = 1e5 + 7;

int n,k;
int a[N];
struct Tree{
	int l,r,mx,mmx,mxid,mmxid;
}tr[N << 1];
bool cmp(pair<int,int> x,pair<int,int> y){
	if(x.first==y.first) return x.second < y.second;
	return x.first > y.first;
}
void push_up(Tree &u,Tree T1,Tree T2){
	int mx1 = T1.mx,mx2 = T2.mx;
	int mmx1 = T1.mmx,mmx2 = T2.mmx;
	vector<pair<int,int>> v;
	v.push_back({mx1,T1.mxid});
	v.push_back({mmx1,T1.mmxid});
	v.push_back({mx2,T2.mxid});
	v.push_back({mmx2,T2.mmxid});
	sort(v.begin(),v.end(),cmp);
	u.mx = v[0].first;
	u.mxid = v[0].second;
	u.mmx = -1;
	u.mmxid = -1;
	for(int i = 1;i < v.size();i++){
		if(v[i].first!=u.mx){
			u.mmx = v[i].first;
			u.mmxid = v[i].second;
			break;
		}
	}
}
void build(int u,int l,int r){
	tr[u] = {l,r,-1,-1,-1,-1};
	if(l==r){
		tr[u].mx = a[l];
		tr[u].mxid = l;
		return;
	}
	int mid =l+r>>1;
	build(lc,l,mid);
	build(rc,mid+1,r);
	push_up(tr[u],tr[lc],tr[rc]);
}
Tree query(int u,int l,int r){
	if(tr[u].l > r || tr[u].r < l) return {-1,-1,-1,-1,-1,-1};
	if(tr[u].l>=l&&tr[u].r<=r){
		return tr[u];
	}
	Tree res;
	push_up(res,query(lc,l,r),query(rc,l,r));
	return res;
}
void add(int u,int x){
	if(tr[u].l > x || tr[u].r < x) return;
	if(tr[u].l==x&&tr[u].r==x) {
		tr[u].mx = -1,tr[u].mxid = -1; 
		tr[u].mmx = -1,tr[u].mmxid = -1; 
		return;
	}
	add(lc,x),add(rc,x);
	push_up(tr[u],tr[lc],tr[rc]);
}
int wz[N];
void solve(){
	cin >> n >> k;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		wz[i] = -1;
	}
	build(1,1,n);
	for(int i = 1;i <= n;i++){
		int r = i + k;
		Tree t = query(1,i,r);
		if(t.mx != wz[i - 1]){
			wz[i]=t.mx;
			k-=(t.mxid-i);
			add(1,t.mxid);
		}else{
			wz[i]=t.mmx;
			k-=(t.mmxid-i);
			add(1,t.mmxid);
		}
	}
	for(int i = 1;i<=n;i++) cout << wz[i] << " ";
}

signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	solve();
	return 0;
}
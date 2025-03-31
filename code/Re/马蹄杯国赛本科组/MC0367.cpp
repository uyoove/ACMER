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
const int N = 100005;
const int mod = 1e9+7;
ll qw(ll x,ll n){
	ll res = 1;
	while(n){
		if(n&1) res = res*x%mod;
		x=x*x%mod;;
		n>>=1;
	}
	return res;
}
int n,m,a[N];
int prm[1000];
map<int,int> wz;
void getprm(){
	for(int i = 2;i<=200;i++){
		if(prm[i]==0) prm[++prm[0]] = i,wz[i] = prm[0];
		for(int j = 1;j <= prm[0] && prm[j]*i <= 200;j++){
			prm[i*prm[j]] = -1;
			if(i%prm[j]==0) break;
		}
	}
}
struct Tree{
	int l,r;
	int mp[16];
}tr[N << 2];
void push_up(int u){
	for(int i = 1;i<=15;i++){
		tr[u].mp[i] = tr[lc].mp[i] + tr[rc].mp[i];
	}
}
void build(int u,int l,int r){
	tr[u]={l,r};
	if(l==r){
		int t = a[l];
		for(int i = 1;i<=15;i++){
			while(t%prm[i]==0){
				tr[u].mp[i]++;
				t/=prm[i];
			}
		}
		if(t>1) tr[u].mp[wz[t]]++;
		return;
	}
	int mid = l + r>>1;
	build(lc,l,mid);
	build(rc,mid+1,r);
	push_up(u);
}
void modify(int u,int x,int val){
	if(tr[u].l>x||tr[u].r<x) return;
	if(tr[u].l==x&&tr[u].r==x){
		a[x] = val;
		int t = a[x];
		for(int i = 1;i<=15;i++){
			tr[u].mp[i]=0;
			while(t%prm[i]==0){
				tr[u].mp[i]++;
				t/=prm[i];
			}
		}
		if(t>1) tr[u].mp[wz[t]]++;
		return;
	}
	modify(lc,x,val);
	modify(rc,x,val);
	push_up(u);
}
Tree query(int u,int l,int r){
	if(tr[u].l>r||tr[u].r<l) return tr[0];
	if(tr[u].l>=l&&tr[u].r<=r){
		return tr[u];
	}
	Tree t1 = query(lc,l,r),t2 = query(rc,l,r);
	Tree ne;
	for(int i =1;i <= 15;i++){
		ne.mp[i] = t1.mp[i] + t2.mp[i];
	}
	return ne;
}
void solve(){
	getprm();
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> a[i];
	int m;
	cin >> m;
	build(1,1,n);
	while(m--){
		int op,x,y;
		cin >> op >> x >> y;
		if(op==1){
			Tree mp = query(1,x,y);
			ll res = 1;
			for(int i = 1;i <= 15;i++){
				int p = prm[i];
				int d = mp.mp[i];
				res = res * ((qw(p,d + 1) - 1) * qw(p - 1,mod - 2) % mod) % mod;
			}
			cout << res << endl;
		}else{
			modify(1,x,y);
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
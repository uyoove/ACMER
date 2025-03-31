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
const int infi = 0x3f3f3f3f;
const int P = 13331;
const int N = 200005;
int n,m;
int a[N],d[N];
struct tree{
	int l,r,val,mx;
}tr[N << 2];
void build(int u,int l,int r){
	tr[u] = {l,r,a[l],a[l]};
	if(l==r) return;
	int mid = l + r >> 1;
	build(lc,l,mid);
	build(rc,mid+1,r);
	tr[u].mx = max(tr[lc].mx,tr[rc].mx);
}
int query(int u,int l,int r){
	if(tr[u].l > r || tr[u].r < l) return 0;
	if(tr[u].l >=l && tr[u].r <= r){
		return tr[u].mx;
	}
	return max(query(lc,l,r),query(rc,l,r));
}
struct hero{
	int p,s;
	bool operator<(const hero &h1)const{
		return p > h1.p;
	}
}hr[N];
int tr1[N],dp[N];
void add(int k,int val){
	for(int i = k;i <= m;i+=(i&-i)) tr1[i] = max(tr1[i],val);
}
int query1(int k){
	int res = 0;
	for(int i = k;i > 0;i-=(i&-i)) res = max(tr1[i],res);
	return res;
}
bool check(int l,int r){
	int mx = query(1,l,r);
	int l1 = 1,r1 = m,ans = -1;
	while(l1 <= r1){
		int mid = l1+r1>>1;
		if(hr[mid].p >= mx){
			l1 = mid +1;
			ans = mid;
		}else{
			r1 = mid - 1;
		}
	}
	int big = query1(ans);
	//cout <<endl <<l << " " << r << " " << mx << endl;
	return big >= (r - l + 1);
}
void solve(){
	cin >> n;
	
	int mxval = 0;
	int mxhero = 0;
	for(int i = 1;i <= n;i++) cin >> a[i],mxval = max(mxval,a[i]),dp[i] = 0x3f3f3f3f;
	build(1,1,n);
	cin >> m;
	for(int i = 1;i <= m;i++) cin >> hr[i].p >> hr[i].s,mxhero = max(mxhero,hr[i].p),tr1[i] = 0;
	if(mxhero < mxval){
		cout << -1 <<endl;
		return;
	}
	sort(hr+1,hr+1+m);
	dp[0] = 0;
	for(int i = 1;i<=m;i++) add(i,hr[i].s);
	//从一个点到最远的点是 符合区间最大值,符合d
	int res = 0;
	dp[1] = 1;
	for(int i = 1;i<=n;i++){
		
		int l = i,r = n,ans = -1;
		
		while(l <= r){
			int mid = l+r>>1;
			if(check(i,mid)){
				l = mid + 1;
				ans = mid;
			}else{
				r = mid - 1;
			}
		}
		//out2(a[i],ans);
		i = ans;
		res++;
		
	}
	cout << res <<endl;
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
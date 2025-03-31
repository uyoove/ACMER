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
int ans1[N];
struct Tree{
	int l,r,mi;
}tr[N << 2];
void build(int u,int l,int r){
	tr[u] = {l,r,0};
	if(l==r) return;
	int mid = l + r>> 1;
	build(lc,l,mid);
	build(rc,mid +1,r);
	tr[u].mi = min(tr[lc].mi,tr[rc].mi); 
}
void modify(int u,int x,int val){
	if(tr[u].l > x || tr[u].r < x) return;
	if(tr[u].l==tr[u].r && tr[u].l==x){
		tr[u].mi = val;
		return;
	}
	modify(lc,x,val);
	modify(rc,x,val);
	tr[u].mi = min(tr[lc].mi,tr[rc].mi); 
}
int query(int u,int l,int r){
	if(tr[u].l > r || tr[u].r < l) return inf;
	if(tr[u].l >= l && tr[u].r <= r){
		return tr[u].mi;
	}
	return min(query(lc,l,r),query(rc,l,r));
}
void solve(){
	cin >> n >> m;
	build(1,1,n);	
	for(int i = 1;i <= m;i++){
		int t,v,c;
		cin >> t >> v >> c;
		int l = 1,r = n,ans = -1;
		while(l<=r){
			int mid = l + r >> 1;
			//cout << mid << " " << query(1,1,mid) << endl;
			if(query(1,1,mid) > t){
				l = mid + 1;
			}else{
				r = mid - 1;
				ans = mid;
			}
		}
		if(ans!=-1) ans1[ans]+=v,modify(1,ans,t + c);
	}
	for(int i = 1;i<=n;i++){
		cout << ans1[i] << endl;
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
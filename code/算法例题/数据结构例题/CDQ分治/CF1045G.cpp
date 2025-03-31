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
const int N = 300005;
int n,k;
struct node{
	int lpos,rpos,iq,r,x;
}a[N];
bool cmp(node n1,node n2){
	if(n1.r != n2.r) return n1.r > n2.r;
	if(n1.x!=n2.x) return n1.x < n2.x;
	return n1.iq < n2.iq;
}
bool cmp2(node n1,node n2){
	return n1.iq < n2.iq;
}
vector<int> ls;
int gt(int x){
	return lower_bound(ls.begin(),ls.end(),x) - ls.begin() + 1;
}
int ans = 0;
int tr[N];
void add(int k,int val){
	for(int i = k; i < N;i+=(i&-i)) tr[i]+=val;
}
int query(int k){
	int res = 0;
	for(int i = k;i>0;i-=(i&-i)) res+=tr[i];
	return res;
}
int sum(int l,int r){
	return query(r) - query(l - 1);
}
void cdq(int l,int r){
	if(l==r) return;
	int mid = l + r >> 1;
	cdq(l,mid),cdq(mid+1,r);
	sort(a + l,a + mid +1,cmp2);
	sort(a + mid + 1,a + r + 1,cmp2);
	int L = l, R = l - 1;
	for(int i = mid + 1;i <= r;i++){
		while(L <= mid && a[L].iq < a[i].iq - k){
			add(a[L].x,-1);
			L++;
		}
		while(R < mid && a[R + 1].iq <= a[i].iq + k){
			add(a[R + 1].x,1);
			R++;
		}
		ans += sum(a[i].lpos,a[i].rpos);
	}
	while(L <= R){
		add(a[L].x,-1);
		L++;
	} 
}
void solve(){
	cin >> n >> k;
	for(int i = 1;i<=n;i++){
		cin >> a[i].x >> a[i].r >> a[i].iq;
		ls.push_back(a[i].x);
		ls.push_back(a[i].x + a[i].r);
		ls.push_back(a[i].x - a[i].r);
	}
	sort(ls.begin(),ls.end());
	ls.erase(unique(ls.begin(),ls.end()),ls.end());
	for(int i = 1;i<=n;i++){
		a[i].lpos = gt(a[i].x - a[i].r);
		a[i].rpos = gt(a[i].x + a[i].r);
		a[i].x = gt(a[i].x);
	}
	sort(a+1,a+n+1,cmp);
	cdq(1,n);
	cout << ans << endl;
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
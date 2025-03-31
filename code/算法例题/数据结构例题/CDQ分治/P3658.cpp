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
struct node
{
	int x,y,val;
}a[N];
int tr[N];
void add(int k,int val){
	for(int i = k;i < N;i += (i&-i)) tr[i]+=val;
}
int query(int k){
	int res = 0;
	for(int i = k;i > 0;i -= (i&-i)) res+=tr[i];
	return res;
}
bool cmp(node a,node b){
	if(a.x!=b.x) return a.x < b.x;
	if(a.y!=b.y) return a.y < b.y;
	return a.val <b.val;
}
bool cmp2(node a,node b){
	if(a.y!=b.y) return a.y > b.y;
	return a.val <= b.val;
}
int n,k;
int ans = 0;
void cdq(int l,int r){
	if(l==r) return;
	int mid = l+r>>1;
	cdq(l,mid),cdq(mid + 1,r);
	sort(a + l,a + mid + 1,cmp2);
	sort(a+mid+1,a+r+1,cmp2);
	int i = l;
	for(int j = mid + 1;j <= r;j++){
		while(i <= mid && a[i].y >= a[j].y){
			add(a[i].val,1);
			i++;
		}
		ans += query(a[j].val - k - 1) + query(n) - query(k + a[j].val);
	}
	for(int j = l;j < i;j++) add(a[j].val,-1);
}
void solve(){
	cin >> n >> k;
	for(int i = 1;i <= n;i++){
		int val;
		cin >> val;
		a[val].val = val;
		a[val].x = i;
	}
	for(int i = 1;i <= n;i++){
		int val;
		cin >> val;
		a[val].y = i;
	}
	sort(a + 1,a + 1 + n,cmp);
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
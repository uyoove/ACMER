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
int tr[N];
void add(int k,int val){
	for(int i = k;i < N;i+=(i&-i)) tr[i]+=val;
}
int query(int k){
	int res = 0;
	for(int i = k;i > 0;i-=(i&-i)) res+=tr[i];
	return res;
}
struct node{
	int x,y,z,cnt,num;//cnt为相同个数,num为答案;
}a[N],b[N];
bool cmp(node a,node b){
	if(a.x!=b.x) return a.x < b.x;
	if(a.y!=b.y) return a.y < b.y;
	return a.z < b.z;
}
bool cmp2(node a,node b){
	if(a.y==b.y) return a.z < b.z;
	return a.y < b.y;
}
int n,k;
int m = 0;
void cdq(int l,int r){
	if(l==r) return;
	int mid = l+r>>1;
	cdq(l,mid),cdq(mid+1,r);
	sort(b + l,b + mid + 1,cmp2);
	sort(b + mid + 1,b + r + 1,cmp2);
	int i = l,j = mid + 1;
	for(;j<=r;j++){
		while(i <= mid && b[i].y <= b[j].y){
			add(b[i].z,b[i].cnt);
			i++;			
		}
		b[j].num += query(b[j].z);
	}
	for(int j = l;j < i;j++) add(b[j].z,-b[j].cnt); //还原
}
int ans[N];
void solve(){
	cin >> n >> k;
	for(int i = 1; i<=n;i++){
		cin >> a[i].x >> a[i].y >> a[i].z;
	}
	sort(a + 1, a + n + 1,cmp);
	int len = 0;//查重
	for(int i = 1;i <= n;i++){
		len++;
		if(a[i].x!=a[i + 1].x || a[i].y != a[i + 1].y || a[i].z!=a[i + 1].z){
			a[i].cnt = len;
			b[++m] = a[i];
			len=0;
		}
	}
	cdq(1,m);
	for(int i = 1;i <= m;i++){
		ans[b[i].num + b[i].cnt - 1] += b[i].cnt;
	}
	for(int i = 0; i < n;i++){
		cout << ans[i] << endl;
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
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
struct node{
	int x1,x2,y,val;
	bool operator<(const node& t1)const{
		return t1.y > y;
	}
}a[N << 1]; //两倍的线
int n;
vector<int> x;
int gt(int val){return lower_bound(x.begin(),x.end(),val) - x.begin() + 1;}
struct tree{
	int l,r;
	int cnt,len; //覆盖次数,长度
}tr[N << 4];
void push_up(int u){
	int l = tr[u].l, r = tr[u].r;
	if(tr[u].cnt) tr[u].len = x[r] - x[l-1];//被覆盖那么就是整个区间[l,r+1],但是x是从0开始下标的
	else tr[u].len = tr[lc].len + tr[rc].len;
}
void build(int u,int l,int r){
	tr[u] = {l,r,0,0};
	if(l==r) return;
	int mid = l + r>> 1;
	build(lc,l,mid);
	build(rc,mid+1,r);
}
void modify(int u,int l,int r,int cnt){
	if(tr[u].r < l || tr[u].l > r) return;
	if(tr[u].l >= l && tr[u].r <= r){
		tr[u].cnt+=cnt;
		push_up(u);   //根据cnt的值动态更新区间长度
		return;
	}
	modify(lc,l,r,cnt);
	modify(rc,l,r,cnt);
	push_up(u);
}
void solve(){
	cin >> n;
	for(int i = 1;i <= n;i++){
		int x1,y1,x2,y2;
		cin >> x1 >> y1 >> x2 >> y2;
		a[i] = {x1,x2,y1,1};
		a[i + n] = {x1,x2,y2,-1};
		x.push_back(x1);
		x.push_back(x2);
	}
	sort(x.begin(),x.end());
	n = n*2; //因为矩形两条边所以数组长度*2
	sort(a + 1,a + 1 + n);
	x.erase(unique(x.begin(),x.end()),x.end());
	int sz = x.size();
	build(1,1,sz - 1);
	int res = 0;
	for(int i = 1;i < n;i++){
		int l = gt(a[i].x1);
		int r = gt(a[i].x2) - 1;
		modify(1,l,r,a[i].val);//正或者负贡献
		res += (tr[1].len) * (a[i + 1].y - a[i].y);
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
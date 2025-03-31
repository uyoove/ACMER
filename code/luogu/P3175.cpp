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
int n,m;
void add(int k,int val){
	for(int i = k;i <= n;i += (i&(-i))){
		tr[i]+=val;
	}
}
int query(int k){
	int res = 0;
	for(int i = k;i > 0;i-=(i&(-i))){
		res += tr[i];
	}
	return res;
}

struct node{
	int pos,val,gx,id;
}a[N];
bool cmp1(node a1,node b1){
	return a1.pos < b1.pos;
}
bool cmp2(node a1,node b1){
	return a1.pos > b1.pos;
}
int tot = 0,idx = 0;
int pos[N],ans[N];
void cdq(int l,int r){
	if(l==r) return;
	int mid = l+r>>1;
	cdq(l,mid),cdq(mid+1,r);
	sort(a + l,a + mid + 1,cmp1);
	sort(a + mid + 1,a +r +1,cmp1);
	//位置在j前面且值大的数
	int i = l,j = mid + 1;
	for(;j<=r;j++){
		while(i <= mid && a[i].pos <= a[j].pos){
			add(a[i].val,a[i].gx);
			i++;
		}
		ans[a[j].id]+=a[j].gx * (query(n) - query(a[j].val));
	}
	for(int t = l; t < i;t++) add(a[t].val,-a[t].gx);
	sort(a + l,a + mid + 1,cmp2);
	sort(a + mid + 1,a +r +1,cmp2);
	i = l,j = mid + 1;
	for(;j<=r;j++){
		while(i <= mid && a[i].pos >= a[j].pos){
			add(a[i].val,a[i].gx);
			i++;
		}
		ans[a[j].id]+=a[j].gx * (query(a[j].val - 1));
	}
	for(int t = l; t < i;t++) add(a[t].val,-a[t].gx);
}
void solve(){
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i].val;
		a[i].pos = i;
		pos[a[i].val] = i;
		a[i].gx = 1;
		a[i].id = 0;
	}
	idx = n;
	for(int i = 1;i <= m;i++){
		int val;
		cin >> val;
		a[++idx] = {pos[val],val,-1,++tot};
	}
	cdq(1,idx);
	for(int i = 1;i <= m;i++) ans[i]+=ans[i-1];
	for(int i = 0; i < m;i++) cout << ans[i] << endl;
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
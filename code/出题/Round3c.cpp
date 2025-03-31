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
int n;
struct node{
	int w,val,op,id,ans;
}a[N];
bool cmp(node a,node b){
	return a.id < b.id;
}
bool cmp2(node a,node b){
	if(a.val!=b.val) return a.val <= b.val;
	return a.w > b.w;
}
int tr[N];
void add(int k,int val){
	for(int i = k;i < N;i+=(i&-i)){
		tr[i]+=val;
	}
}
int query(int k){
	int res = 0;
	for(int i = k;i > 0;i-=(i&-i)) res+=tr[i];
	return res;
}
void cdq(int l,int r){
	if(l==r) return;
	int mid = l+r>>1;
	cdq(l,mid),cdq(mid+1,r);
	sort(a + l,a + mid +1,cmp2),sort(a + mid + 1,a + r +1,cmp2);
	int i = l;
	for(int j = mid + 1;j <= r;j++){
		while(i <= mid && a[i].val <= a[j].val){
			if(a[i].op==1) add(a[i].w,1);
			i++;
		}
		if(a[j].op==2){
			a[j].ans += query(N - 1) - query(a[j].w);
		}
	}
	for(int j = l;j < i;j++){
		if(a[j].op==1) add(a[j].w,-1);
	}
}
void solve(){
	cin >> n;
	for(int i = 1;i <= n;i++){
		int op,w,val;
		cin >> op >> w >> val;
		a[i] = {w,val,op,i,0};
	}
	cdq(1,n);
	sort(a + 1,a +1 +n,cmp);
	for(int i = 1;i <= n;i++){
		if(a[i].op==2){
			cout << a[i].ans << endl;
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
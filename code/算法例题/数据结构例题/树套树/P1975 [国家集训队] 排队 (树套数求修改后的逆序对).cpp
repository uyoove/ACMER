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
int res = 0;
int a[N],b[N];
int n;
//根据交换区间可以划分为 A i B j C
//其中AC不受影响
//只需考虑B中影响,用Rank就能查出有多少比x小的数
struct FHQ
{
	int ls,rs,key,sz,val;	
}fhq[N*40];
int tot,T1,T2,T3;
il void fhqup(int u){
	fhq[u].sz = fhq[fhq[u].ls].sz + fhq[fhq[u].rs].sz + 1;
}
il void split(int u,int k,int& x,int& y){
	if(!u){
		x = y = 0;
		return;
	}
	if(k >= fhq[u].val){
		x = u;
		split(fhq[u].rs,k,fhq[u].rs,y);
	}else{
		y = u;
		split(fhq[u].ls,k,x,fhq[u].ls);
	}
	fhqup(u);
}
il int merge(int x,int y){
	if(!x||!y) return x+y;
	if(fhq[x].key > fhq[y].key){
		fhq[x].rs = merge(fhq[x].rs,y);
		fhqup(x);
		return x;
	}else{
		fhq[y].ls = merge(x,fhq[y].ls);
		fhqup(y);
		return y;
	}
}
il int NewFHQ(int val){
	fhq[++tot] = {0,0,rnd(),1,val};
	return tot;
}
il void insert(int &root,int val){
	split(root,val,T1,T2);
	root = merge(merge(T1,NewFHQ(val)),T2);
}
void del(int &root,int data){
	split(root,data,T1,T2);
	split(T1,data-1,T1,T3);
	T3=merge(fhq[T3].ls,fhq[T3].rs);
	root=merge(T1,merge(T3,T2));
}
il int find_rank(int &root,int data){
	split(root,data - 1,T1,T2);
	int ans = fhq[T1].sz;
	root = merge(T1,T2);
	return ans;
}
struct Tree{
	int l,r,root;
}tr[N << 2];
il void build(int u,int l,int r){
	tr[u].l=l,tr[u].r=r;
	if(l==r){
		tr[u].root=NewFHQ(a[l]);
		return;
	}
	for(int i = l;i<=r;i++){
		insert(tr[u].root,a[i]); //merge会自动编号,把区间所有数插一下
	}
	int mid = l + r>> 1;
	build(lc,l,mid);
	build(rc,mid + 1,r);
}
il int Rank(int u,int l,int r,int d){
	if(tr[u].l > r || tr[u].r < l){
		return 0;
	}
	if(tr[u].l >= l && tr[u].r <= r){
		return find_rank(tr[u].root,d);
	}
	return Rank(lc,l,r,d) + Rank(rc,l,r,d);
}
il int same(int u,int l,int r,int d){
	if(tr[u].l > r || tr[u].r < l){
		return 0;
	}
	if(tr[u].l >= l && tr[u].r <= r){
		split(tr[u].root,d,T1,T2);
		split(T1,d - 1,T1,T3);
		int res = fhq[T3].sz;
		tr[u].root = merge(merge(T1,T3),T2);
		return res; 
	}
	return same(lc,l,r,d) + same(rc,l,r,d);
}
il void change(int u,int x,int data){
	del(tr[u].root,a[x]);
	insert(tr[u].root,data);
	if(tr[u].l==tr[u].r){
		return;
	}
	int mid=(tr[u].l+tr[u].r)>>1;
	if(x<=mid){
		change(lc,x,data);
	}
	if(x>mid){
		change(rc,x,data);
	}
}
void merge_sort(int l,int r){
	if(l==r) return;
	int mid = l + r >>1;
	merge_sort(l,mid),merge_sort(mid+1,r);
	sort(b + l,b + mid +1),sort(b + mid + 1,b + r + 1);
	int i = l;
	for(int j = mid + 1;j <= r;j++){
		while(i <= mid && b[i] <= b[j]){
			i++;
		}
		res += (mid - i + 1);
	}
}
void sp(int i,int j){
	int small = Rank(1,i + 1,j - 1,a[i]);
	int big = (j - 1 - i) - small - same(1,i+1,j-1,a[i]);
	res+=big-small; 
	small = Rank(1,i + 1,j - 1,a[j]);
	big = (j - 1 - i) - small - same(1,i+1,j-1,a[j]);
	res+=small-big;
	int t = a[i];
	change(1,i,a[j]);
	change(1,j,a[i]);
}
void solve(){
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> a[i],b[i] = a[i];
	merge_sort(1,n);
	cout << res << endl; //开始的逆序对
	build(1,1,n);
	//cout << Rank(1,2,2,150) << endl;
	int q;
	cin >> q;
	while(q--){
		int i,j;
		cin >> i >> j;
		if(i > j) swap(i,j);
		if(a[i] < a[j]){
			res++;
		}else if(a[i] > a[j]){
			res--;
		}
		if(j - i <= 1){
			cout << res << endl;
			change(1,i,a[j]);
			change(1,j,a[i]);
		}else{
			sp(i,j);
			cout << res << endl;
		}
		swap(a[i],a[j]);
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
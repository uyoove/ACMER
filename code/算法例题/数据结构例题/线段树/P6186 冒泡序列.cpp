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
const ll inf = 0x3f3f3f3f3f3f3f3fLL;
const int infi = 0x3f3f3f3f;
const int P = 13331;
const int N = 200005;
struct Tree{
	int l,r,len,val,add;
}tr[N << 2];
void build(int u,int l,int r){
	tr[u] = {l,r,r-l+1,0,0};
	if(l==r) return;
	int mid = l + r >> 1;
	build(lc,l,mid);
	build(rc,mid+1,r);
}
void push_down(int u){
	if(tr[u].add==0) return;
	tr[lc].add+=tr[u].add;
	tr[rc].add+=tr[u].add;
	tr[lc].val += tr[u].add * tr[lc].len;
	tr[rc].val += tr[u].add * tr[rc].len;
	tr[u].add = 0;
}
void update(int u,int l,int r,int v){
	if(tr[u].l > r || tr[u].r < l) return;
	if(tr[u].r <= r && tr[u].l >= l){
		tr[u].val += tr[u].len * v;
		tr[u].add += v;
		return;
	}
	push_down(u);
	update(lc,l,r,v);
	update(rc,l,r,v);
	tr[u].val = tr[lc].val + tr[rc].val;
}
int query(int u,int l,int r){
	if(tr[u].l > r || tr[u].r < l) return 0;
	if(tr[u].r <= r && tr[u].l >= l){
		return tr[u].val;
	}
	push_down(u);
	return query(lc,l,r) + query(rc,l,r);
}
int n,m;
int a[N];
int before[N],record[N]; //前面有几个比a[i]大, 前面有i个数比当前大的数量
void solve(){
	cin >> n >> m;
	int tot = 0;
	build(1,1,n+1);
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		int q = i - 1 - query(1,1,a[i]);
		//cout << query(1,1,a[i]) << endl;
		tot += q;
		before[i] = q;
		record[q]++;
		update(1,a[i],a[i],1);
	}
	//cout << tot << endl;
	build(1,1,n+1);
	update(1,1,n,tot);
	tot = 0;
	for(int i = 1;i <= n;i++){
		tot += record[i - 1];
		//n-tot个数要被减逆序数贡献 5 3 2 6 1 这里3 2 1 都被影响,可以看成是一步步解锁过程
		//add(i + 1,-(n - tot));//下标偏移一位,即第一次操作完是2,第二次操作完是3,以此类推
		update(1,i + 1,n,-(n - tot));
	}
	while(m--){
		int op,x;
		cin >> op >> x;
		if(x >= n) x = n - 1;
		if(op==2){
			cout << query(1,x + 1,x+1) << endl; //偏移了一位
		}else{
			if(a[x] < a[x + 1]){
				//多一个逆序对
				swap(a[x],a[x + 1]);
				swap(before[x],before[x +1]);

				before[x + 1]++;
				update(1,1,before[x+1],1);
			}else{
				//少一个逆序对
				swap(a[x],a[x + 1]);
				swap(before[x],before[x +1]);

				update(1,1,before[x],-1);
				before[x]--;
			}
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
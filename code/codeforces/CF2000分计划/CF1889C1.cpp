//和爸爸一起学编程真好,不过要小学四年级分流考试了,最近没时间写代码了,呜呜呜
#include<bits/stdc++.h>
using namespace std;
#define out(x) cout << #x << '=' << (x) << endl
#define out2(x, y) cout << #x << '=' << (x) << ',' << #y << '=' << (y) << endl 
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
//分类讨论
//1.考虑单独分别删对线段覆盖一次节点影响最大的两条
//2.考虑删每个被覆盖2次的点的线段看全局空白有多少
struct qs{
	int l,r,id,val;
	bool operator<(const qs& t1)const{
		return val < t1.val;
	}
};
struct Tree{
	//左,右,被多少覆盖,有多少个干旱节点,标记
	int l,r,cov,val,tag;
	vector<qs> v;//每个区间被覆盖的线段的详细信息
}tr[N << 2];
void push_up(int u){
	tr[u].cov = min(tr[lc].cov,tr[rc].cov);
	//注意不能直接判0,因为区间修改的元素,没有push_up;
	//我们只能猜测哪些节点是被修改后能正常干涸的;
	//如果我当前变成了cov==0,那么最有可能干涸的就是cov小的
	if(tr[lc].cov == tr[rc].cov) tr[u].val = tr[rc].val+tr[lc].val;
	if(tr[lc].cov < tr[rc].cov) tr[u].val = tr[lc].val;
	if(tr[lc].cov > tr[rc].cov) tr[u].val = tr[rc].val;
	
}
void build(int u,int l,int r){
	tr[u].l=l,tr[u].r=r;
	tr[u].cov = tr[u].tag = 0;
	tr[u].v.clear();
	if(l==r){
		tr[u].val = 1;
		return;
	}
	int mid=l+r>>1;
	build(lc,l,mid);
	build(rc,mid+1,r);
	push_up(u);
}
void push_down(int u){
	if(tr[u].tag){
		tr[lc].tag += tr[u].tag;
		tr[rc].tag += tr[u].tag;
		tr[lc].cov += tr[u].tag;
		tr[rc].cov += tr[u].tag;
		tr[u].tag = 0;
	}
}
void modify(int u,int l,int r,int x){
	if(tr[u].l > r || tr[u].r < l) return;
	if(tr[u].l >= l && tr[u].r <= r){
		tr[u].cov+=x;
		tr[u].tag+=x;
		return;
	}
	push_down(u);
	modify(lc,l,r,x);
	modify(rc,l,r,x);
	push_up(u);
}
void insert(int u,int l,int r,qs q){
	if(tr[u].l > r || tr[u].r < l) return;
	if(tr[u].l >= l && tr[u].r <= r){
		tr[u].cov++;
		tr[u].tag++;
		tr[u].v.pb(q);
		return;
	}
	push_down(u);
	insert(lc,l,r,q);
	insert(rc,l,r,q);
	push_up(u);
}
qs stk[N << 2];
int top = 0;
int ans = 0;
void query(int u){
	int start = top;
	for(auto p:tr[u].v) stk[++top] = p;
	if(tr[u].l==tr[u].r){
		//cout << tr[u].l << " " << top << endl;
		if(top==2){
			//cout << tr[1].cov << endl;
			modify(1,stk[1].l,stk[1].r,-1);
			modify(1,stk[2].l,stk[2].r,-1);
			//如果所有区间没有被覆盖

			if(tr[1].cov==0){
				ans = max(ans,tr[1].val);
			}
			modify(1,stk[1].l,stk[1].r,1);
			modify(1,stk[2].l,stk[2].r,1);
		}
		while(start < top) --top;
		return;
	} 
	push_down(u);
	query(lc),query(rc);
	push_up(u);
	while(start < top) --top;
}
qs q[N];
void solve(){
	int n,m,k;
	ans = 0;
	//城市数,区间数,可修改大小
	cin >> n >> m >> k;
	build(1,1,n);
	for(int i = 1;i <= m;i++){
		cin >> q[i].l >> q[i].r;
		q[i].id = i;
		q[i].val = 0; 
		insert(1,q[i].l,q[i].r,q[i]);
	}
	//cout << tr[1].cov << endl;
	query(1); //查寻所有被2个线覆盖的点删除两条线后的全局空白
	for(int i = 1;i <= m;i++){
		modify(1,q[i].l,q[i].r,-1);
		if(!tr[1].cov) q[i].val = tr[1].val;
		modify(1,q[i].l,q[i].r,1);
	}
	sort(q + 1,q + 1 + m);
	modify(1,q[m].l,q[m].r,-1);
	modify(1,q[m-1].l,q[m-1].r,-1);
	if(tr[1].cov==0){
		ans = max(ans,tr[1].val);
	}
	cout << ans << endl;
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
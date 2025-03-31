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
//原串的生成串要最大,那么被越靠前的组别覆盖的点优先级越高
//所以那些优先级高的点都应该是1;
//所以做一个区间覆盖
struct Tree{
	int l,r,id,tag;
}tr[N << 2];
void build(int u,int l,int r){
	tr[u]={l,r,-1,-1};
	if(l==r) return;
	int mid = l + r >> 1;
	build(lc,l,mid);
	build(rc,mid + 1,r);
}
void calc(int u,int tg){
	tr[u].tag = tg;
	tr[u].id = tg;
}
void push_down(int u){
	if(tr[u].tag!=-1){
		calc(lc,tr[u].tag),calc(rc,tr[u].tag);
		tr[u].tag = -1;
	}
}
void modify(int u,int l,int r,int val){
	if(tr[u].l > r || tr[u].r < l) return;
	if(tr[u].l >= l && tr[u].r <= r){
		calc(u,val);
		return;
	}
	push_down(u);
	modify(lc,l,r,val);
	modify(rc,l,r,val);
}
int query(int u,int x){
	if(tr[u].l > x || tr[u].r < x) return -1;
	if(tr[u].l == x && tr[u].l==tr[u].r){
		return tr[u].id;
	}
	push_down(u);
	int ans = query(lc,x);
	return (ans == -1 ? query(rc,x) : ans);
} 
vt<PII> v;
int sum1 = 0,cnt1 = 0;
int n,m,q;
string s;
vt<PII> qj;
struct Fenwick{
	vector<int> tr;
	int sz;
	void init(int n){
		tr.resize(n + 1);
		sz = n;
	}
	Fenwick(){}
	Fenwick(int n){
		init(n);
	}
	void add(int k,int val){
		for(int i = k;i <= sz;i+=(i&-i)){
			tr[i]+=val;
		}
	}
	int query(int k){
		int res = 0;
		for(int i = k;i > 0;i-=(i&-i)){
			res+=tr[i];
		}
		return res;
	}
	int ask_sum(int l,int r){
		return query(r) - query(l - 1);
	}
};
bool cmp(PII p1,PII p2){
	if(p1.fi==p2.fi) return p1.se < p2.se;
	return p1.fi > p2.fi;
}
int cnt[N];
void solve(){
	cin >> n >> m >> q >> s;
	s = " " + s;
	for(int i = 1;i <= m;i++){
		int l,r;
		cin >> l >> r;
		qj.pb({l,r});
	}
	build(1,1,n);
	reverse(qj.begin(),qj.end());
	for(int i = 0;i < m;i++){
		modify(1,qj[i].fi,qj[i].se,i + 1);
	}
	map<int,int> h,h1;
	for(int i = 1;i <= n;i++){
		v.pb({query(1,i),i});
	}
	sort(v.begin(),v.end(),cmp);
	Fenwick fk(n + 1);
	int mx = n;
	for(int i = 0;i<n;i++){
		cnt[v[i].se] = i + 1;
	}
	int c1 = 0; //关键位置数量,如果1的数量大于关键位置数量显然不合法,就取min
	//一部分1去关键位置即可
	for(int i = 1;i<=n;i++){
		if(s[i]=='1') {
			if(query(1,i)!=-1) fk.add(cnt[i],1);
			sum1++;
		}
		if(query(1,i)!=-1) c1++;
	}
	//cout << sum1 << endl;
	for(int i = 0;i<q;i++){
		int x;
		cin >> x;
		if(s[x]=='1'){
			sum1--;
			if(query(1,x)!=-1) fk.add(cnt[x],-1);
			s[x] = '0';
		}else{
			sum1++;
			if(query(1,x)!=-1) fk.add(cnt[x],1);
			s[x] = '1';
		}
		//cout << cnt[x] <<endl;
		//关键位置与1的个数的最小值 - 关键位置上有多少个1
		//比如说我前两个位置是0,我有四个1,那么我只需要查关键位置前2个就行
		cout << min(sum1,c1) - fk.query(sum1) << endl;
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
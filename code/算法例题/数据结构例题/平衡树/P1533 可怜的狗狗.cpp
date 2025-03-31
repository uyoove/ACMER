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
const int N = 300005;
struct qs{
	int l,r,k,id;
	bool operator<(const qs &t1)const{
		return l < t1.l;
	}
};
vt<qs> v;
int ans[N];
int a[N];
int n,q;
struct FHQ{
	int ls,rs,key,sz,val;
}fhq[N];
int root,idx,T1,T2,T3;
void push_up(int u){
	fhq[u].sz = fhq[fhq[u].ls].sz + fhq[fhq[u].rs].sz + 1;
}
void split(int u,int v,int &x,int &y){
	if(u==0){
		x = y = 0;
		return;
	}
	if(v < fhq[u].val){
		y = u;
		split(fhq[u].ls,v,x,fhq[u].ls);
	}else{
		x = u;
		split(fhq[u].rs,v,fhq[u].rs,y);
	}
	push_up(u);
}
int merge(int x,int y){
	if(x==0||y==0) return x + y;
	if(fhq[x].key>=fhq[y].key){
		fhq[x].rs = merge(fhq[x].rs,y); 
		push_up(x);
		return x;
	}else{
		fhq[y].ls = merge(x,fhq[y].ls);
		push_up(y);
		return y;
	}
}
void insert(int val){
	fhq[++idx] = {0,0,rnd(),1,val};
	split(root,val,T1,T2);
	root = merge(merge(T1,idx),T2);
}
void erase(int val){
	split(root,val,T1,T2);
	split(T1,val - 1,T1,T3);
	T3 = merge(fhq[T3].ls,fhq[T3].rs);
	root = merge(merge(T1,T3),T2);
}
int topk(int k){
	int u = root;
	while(u){
		int sz = fhq[fhq[u].ls].sz + 1;
		if(sz==k){
			break;
		}
		if(k > sz){
			k-=sz;
			u = fhq[u].rs;
		}else{
			u = fhq[u].ls;
		}
	}
	return fhq[u].val;
}
void solve(){
	cin >> n >> q;
	for(int i = 1;i <= n;i++) cin >> a[i];
	for(int i = 1;i <= q;i++){
		int l,r,k;
		cin >> l >> r >> k;
		v.pb({l,r,k,i});
	}
	sort(all(v));
	int l,r;
	for(int i = 1;i <= q;i++){
		if(i==1){
			for(int j = v[i - 1].l;j <= v[i - 1].r;j++) insert(a[j]);
			ans[v[i - 1].id] = topk(v[i - 1].k);
			l = v[i - 1].l,r=v[i - 1].r;
		}else{
			while(l < v[i - 1].l) l++,erase(a[l - 1]);
			while(r < v[i - 1].r) r++,insert(a[r]);
			ans[v[i - 1].id] = topk(v[i - 1].k);
		}
	}
	for(int i = 1;i<=q;i++){
		cout <<ans[i]<<endl;
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
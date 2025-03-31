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
	int l,r,len,w,add;
}tr[N*40];
void push_up(int u){
	tr[u].w = tr[lc].w + tr[rc].w;
}
void build(int u,int l,int r){
	tr[u] = {l,r,r-l+1,0,inf};
	//cout << l << " " << r <<endl;
	if(l == r) return;
	int mid = l + r >> 1;
	build(lc,l,mid);
	build(rc,mid+1,r);
}
void push_down(int u){
	if(tr[u].add==inf) return;
	int tp = tr[u].add;
	tr[lc].add = tp; 
	tr[rc].add = tp;
	tr[lc].w = tp * tr[lc].len;
	tr[rc].w = tp * tr[rc].len;
	tr[u].add = inf;
}
void upd(int u,int l,int r,int w){
	if(tr[u].l > r || tr[u].r < l) return;
	if(tr[u].l >= l && tr[u].r <= r){
		//out2(l,r);out2(tr[u].l,tr[u].r);
		tr[u].w =w*tr[u].len;
		tr[u].add = w;
		return;
	}
	push_down(u);
	upd(lc,l,r,w);
	upd(rc,l,r,w);
	push_up(u);
}
struct qs{
	int l,r,w;
	bool operator<(const qs &t)const{
		return t.w < w;
	}; 
};
int n,m;
bool cmp(PII p1,PII p2){
	if(p1.second == p2.second) return p1.first < p1.first;
	return p1.second <p2.second;
}
void solve(){
	cin >> n >> m;
	build(1,1,n - 1);
	int su = 0;
	vt<qs> v;
	vt<PII> vv; 
	for(int j = 0;j < m;j++){
		int l,r,w;
		cin >> l >> r >> w;
		su += (r - l)*(r-l+1)/2*w;
		vv.pb({l,r});
		//cout << tr[1].w << endl;
		v.pb({l,r,w});
	}
	sort(vv.begin(),vv.end());
	int r = 1;
	for(int i=0;i<vv.size();i++){
		if(vv[i].first > r) {
			cout<<"Gotta prepare a lesson" <<endl;
			return;
		}
		r = max(vv[i].second,r);
	}
	if(r != n){
		
		cout<<"Gotta prepare a lesson" <<endl;
		return;
		
	}
	sort(v.begin(),v.end());
	for(int i = 0; i < v.size();i++){
		int l = v[i].l,r=v[i].r,w=v[i].w;
		upd(1,l,r - 1,w);
	}

	
	cout<<su - tr[1].w << endl;

}

signed main(){
	std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
	int times = 1;
	cin >> times;
	for(int i = 1;i<=times;i++){
		cout <<"Case #" << i << ": ";
		solve();
	}
	return 0;
}
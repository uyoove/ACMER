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
const int N = 1000005;
int n;
struct nodes{
	int l,r,id;
	bool operator<(const nodes& t1)const{
		if(r==t1.r) return l < t1.l;
		return r > t1.r; 
	}
};
int tr1[N]; //大于某个数的右边最大值
int tr2[N];
int pp;
void add1(int k,int val){
	for(int i = k; i <= pp;i += (i&-i)) tr1[i] = max(tr1[i],val);
}
void add2(int k,int val){
	for(int i = k; i <= pp;i += (i&-i)) tr2[i] = min(tr2[i],val);
}
int query1(int k){
	int res = 0;
	for(int i = k;i > 0;i -=(i&-i)){
		res=max(res,tr1[i]);
	}
	return res;
}
int query2(int k){
	int res = 1e9 + 7;
	for(int i = k;i > 0;i -=(i&-i)){
		res=min(res,tr2[i]);
	}
	return res;
}
int ans[N];
int gt(vt<int>& v,int x){
	return lower_bound(all(v),x) - v.begin() +1;
}
void solve(){
	cin >> n;
	vector<int> ls;
	vt<nodes> v;
	map<PII,int> h;
	for(int i = 1;i <= n;i++){
		int l,r;
		cin >> l >> r;
		v.pb({l,r,i});
		ls.pb(l);
		ls.pb(r);
		h[{l,r}]++;
	}
	sort(ls.begin(),ls.end());
	ls.erase(unique(all(ls)),ls.end());
	pp = ls.size();
	for(int i = 0;i <= ls.size();i++){
		tr1[i] = 0;
		tr2[i] = 1e9 + 7;
	}
	sort(v.begin(),v.end());
	for(int i = 0;i < n;i++){
		bool f = 1;
		if(h[{v[i].l,v[i].r}] >= 2){
			ans[v[i].id] = 0;
			f = false;
		}
		v[i].l = gt(ls,v[i].l),v[i].r = gt(ls,v[i].r);
		int l = query1(v[i].l),r = query2(v[i].l);
		add1(v[i].l,v[i].l);
		add2(v[i].l,v[i].r);

		//cout << v[i].l << " " << v[i].r << " " <<l << " " << r << endl;
		 if(l==0 || r == 1e9+7 || !f){
		 	ans[v[i].id] = 0;
			continue;
		 }

		int p = ls[v[i].l-1] - ls[l-1] + ls[r-1] - ls[v[i].r-1];
		ans[v[i].id] = p;
	}
	for(int i = 1;i <= n;i++){
		cout << ans[i] << endl;
	}
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
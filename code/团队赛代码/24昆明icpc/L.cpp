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
int n,m;
int h[N],t[N],h1[N],t1[N];
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
vt<int> ls;
int gt(int x){
	return lower_bound(all(ls),x) - ls.begin() + 1;
}
bool check(){
	ls.clear();
	int l = 1;
	sort(h + 1,h + 1 + n);
	sort(t + 1,t + 1 + m);
	priority_queue<int> q;
	for(int i = 1;i <= m;i++) q.push(t[i]);

	bool f =  true;
	for(int i = n;i >= 1;i--){
		int p = q.top();q.pop();
		p--;
		h[i]--;
		q.push(p);
		if(h[i]==0) f=false;
		if(!f) break;
	}
	if(f) return false;
	sort(h+1,h+1+n);
	vt<int> v;
	for(int i = 1;i <= n;i++){
		v.pb(h[i]);
		//cout << h[i] << " ";
	}
	//cout << q.size() << endl;
	int mx = q.top();
	while(q.size()) v.pb(q.top()),q.pop();
	sort(v.begin(),v.end());
	for(auto p:v){
		//cout << p << " ";
		ls.pb(p);
	}
	sort(all(ls));
	ls.erase(unique(all(ls)),ls.end());
	Fenwick fk(ls.size() + 2);
	for(auto p:v){
		int val = gt(p);
		int p1 = fk.query(val);
		//cout << p1 << " " << p << endl;
		if(fk.query(gt(mx)) >= mx) return true;
		if(p1 < p) {
			return false;
		}
		fk.add(val,1);
	}
	return true;
	
}
bool check2(){
	ls.clear();
	int l = 1;
	sort(h + 1,h + 1 + n);
	sort(t + 1,t + 1 + m);
	int id = n;
	for(int i = 1;i < n;i++){
		if(h[i]==1) continue;
		while(t[l]==1) l++;
		if(l <= m) t[l]-=1,h[i]-=1;
		else {
			id = i;
			break;
		}
	}
	h[id]--;
	t[1]--;	
	// for(int i = 1;i <= n;i++) cout << h[i] << " ";
	// 	cout << endl;
	// for(int i = 1;i <= m;i++) cout << t[i] << " ";
	if(t[1]>0){
		return false;
	}
	//cout << -1 <<endl;
	vt<int> v;
	for(int i = 1;i <= n;i++) v.push_back(h[i]);
	int mx = t[m];
	ls.pb(mx);
	for(int i = 1;i < m;i++) v.push_back(t[i]);
	sort(v.begin(),v.end());
	for(auto p:v){
		ls.pb(p);
	}
	sort(all(ls));
	ls.erase(unique(all(ls)),ls.end());
	Fenwick fk(ls.size() + 2);
	for(auto p:v){
		int val = gt(p);
		int p1 = fk.query(val);
		//cout << p1 << " " << p << endl;
		if(fk.query(gt(mx)) >= mx) return true;
		if(p1 < p) {
			return false;
		}
		fk.add(val,1);
	}
	if(fk.query(gt(mx)) < mx){
		return false;
	}else{
		return true;
	}
}
void solve(){
	cin >> n >> m;
	int su = 0;
	for(int i = 1;i <= n;i++) cin >> h[i],h1[i] = h[i];
	for(int i = 1;i <= m;i++) cin >> t[i],su+=t[i],t1[i] = t[i];
	// if(su <= n){
	//  	cout << "Yes" << endl;
	//  	return;
	//  }
	
	bool f = check2();
	
	for(int i = 1;i <= n;i++) h[i] = h1[i];
	for(int i = 1;i <= m;i++) t[i] = t1[i];
		f|=check();
	if(f){
		cout << "Yes" << endl;
	}else{
		cout << "No" << endl;
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
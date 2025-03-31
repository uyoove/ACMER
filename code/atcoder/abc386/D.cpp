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
int mx1,my1;
vt<PII> v,v1;
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
vector<int> ls;
int gt(int x){
	return lower_bound(all(ls),x) - ls.begin() + 1;
}
void solve(){
	cin >> n >> m;

	for(int i = 1;i <= m;i++){
		int x,y;
		cin >> x >> y;
		char ch;
		cin >> ch;
		if(ch=='W')v.pb({x,y});
		else v1.pb({x,y});
		ls.pb(x);
		ls.pb(y);
	}
	sort(ls.begin(),ls.end());
	ls.erase(unique(all(ls)),ls.end());
	sort(v.begin(),v.end());
	sort(v1.begin(),v1.end());
	int sz = ls.size();
	int l = 0;
	Fenwick fk(sz + 1);
	for(int i = 0;i < v1.size();i++){
		PII p = v1[i];
		int x = gt(p.fi),y = gt(p.se);
		while(l < v.size() && gt(v[l].fi) <= x){
			fk.add(gt(v[l].se),1);
			l++;
		}
		if(fk.query(y) > 0){
			cout << "No" << endl;
			return;
		}
	}
	cout << "Yes" << endl;

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
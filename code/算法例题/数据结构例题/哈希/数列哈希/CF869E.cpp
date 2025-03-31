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
int n,m,q;
struct Fenwick{
	vector<vector<int>> tr;
	int n,m;
	void init(int n1,int m1){
		tr.resize(n1 + 1);
		for(int i =0 ;i <= n1;i++){
			tr[i].resize(m1 + 1);
		}
		n = n1;
		m = m1;
	}
	Fenwick(){}
	Fenwick(int n,int m){
		init(n,m);
	}
	void add(int r,int c,int val){
		for(int i = r;i <= n;i+=(i&-i)){
			for(int j = c;j <= m;j += (j&-j)){
				tr[i][j] += val;
			}
		}
	}
	int query(int r,int c){
		int res = 0;
		for(int i = r;i > 0;i-=(i&-i)){
			for(int j = c;j > 0;j-=(j&-j)){
				res+=tr[i][j];
			}
		}
		return res;
	}
	void change(int r1,int c1,int r2,int c2,int val){
		add(r1,c1,val);
		add(r1,c2 + 1,-val);
		add(r2 + 1,c1,-val);
		add(r2 + 1,c2 + 1,val);
	}
};
struct nodes{
	int r1,c1,r2,c2;
	bool operator<(const nodes &t1)const{
		if(t1.r1!=r1) return t1.r1 < r1;
		if(t1.c1!=c1) return t1.c1 < c1;
		if(t1.r2!=r2) return t1.r2 < r2;
		return t1.c2 < c2;
	}
};
//用哈希使得 多次加法相同的概率降至很低
void solve(){
	cin >> n >> m >> q;
	Fenwick fk(n,m);
	map<nodes,int> mp;
	while(q--){
		int op,r1,c1,r2,c2;
		cin >> op >> r1 >> c1 >> r2 >> c2;
		if(op==1){
			if(!mp.count({r1,c1,r2,c2})){
				mp[{r1,c1,r2,c2}] = rnd();
			}
			fk.change(r1,c1,r2,c2,mp[{r1,c1,r2,c2}]);
		}else if(op==2){
			if(!mp.count({r1,c1,r2,c2})){
				mp[{r1,c1,r2,c2}] = rnd();
			}
			fk.change(r1,c1,r2,c2,-mp[{r1,c1,r2,c2}]);
		}else{
			if(fk.query(r1,c1) == fk.query(r2,c2)){
				cout << "Yes" << endl;
			}else{
				cout << "No" << endl;
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
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
const int N = 500005;
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
int n;
int a[N];
int pos[N];
void solve(){
	cin >> n;
	Fenwick fk(n + 1);
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	for(int i = n;i>= 1;i--){
		int p = a[i];
		int q = fk.query(a[i]);
		int l = p + q,r = n,ans = n;
		while(l<=r){
			int mid = l + r >> 1;
			if(fk.query(mid)  <= mid -  a[i] ){
				r = mid - 1;
				ans = mid;
			}else{
				l = mid + 1;
			}
		}
		pos[ans] = i;
		fk.add(ans,1);

	}
	for(int i = 1;i <= n;i++){
		cout << pos[i] << " ";
	}

}

signed main(){
	
	int times = 1;
	//cin >> times;
	while(times--){
		solve();
	}
	return 0;
}
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
int n;
int a[N];
multiset<int> mi,ma;
void add(int x){
	if(ma.size()){
		if(x > *ma.rbegin()){
			mi.insert(x);
		}else{
			ma.insert(x);
		}
	}else{
		ma.insert(x);
	}
	if(ma.size() > mi.size() + 1){
		int t = *ma.rbegin();
		auto t1 = ma.find(t);
		ma.erase(t1);
		mi.insert(t);
	}	
	if(mi.size() > ma.size() + 1){
		int t = *mi.begin();
		auto t1 = mi.find(t);
		mi.erase(t1);
		ma.insert(t);
	}
}
int query(){
	if(ma.size() > mi.size()) return *ma.rbegin();
	return *mi.begin();
}
void solve(){
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> a[i];
	for(int i = 1;i <= n;i++){
		add(a[i]);
		if(i%2) cout << query() << endl;
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
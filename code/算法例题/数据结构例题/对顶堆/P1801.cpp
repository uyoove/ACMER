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
int ans[N],a[N];
int n,m;
vector<int> res[N];
multiset<int> mi,mx;
int id = 1;
void add(int x){
	if(mx.size()){
		if(x >= *mx.rbegin()){
			mi.insert(x);
		}else{
			mx.insert(x);
		}
	}else{
		mx.insert(x);
	}

	if(mx.size() > id){
		int u = *mx.rbegin();
		auto it = mx.find(u);
		mx.erase(it);
		mi.insert(u);
	}
	if(mx.size() < id){
		int u = *mi.begin();
		auto it = mi.find(u);
		mi.erase(it);
		mx.insert(u);
	}
}
int query(int k){
	if(mx.size() > id){
		int u = *mx.rbegin();
		auto it = mx.find(u);
		mx.erase(it);
		mi.insert(u);
	}
	if(mx.size() < id){
		int u = *mi.begin();
		auto it = mi.find(u);
		mi.erase(it);
		mx.insert(u);
	}
	return *mx.rbegin();
}
void solve(){
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	for(int j = 1;j <= m;j++){
		int p;
		cin >> p;
		res[p].pb(j);
	}
	for(int i = 1;i <= n;i++){
		add(a[i]);
		for(auto p:res[i]){
			ans[p] = query(p);
			id++;
		}
	}
	for(int i = 1;i <= m;i++) cout << ans[i] << endl;

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
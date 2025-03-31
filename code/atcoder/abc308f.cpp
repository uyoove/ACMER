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
//如果没被占用,就直接占用最左边空闲点
//被占用,因为按价值排序,所以放弃
int n,m;
int p[N];
struct node{
	int d,l;
	bool operator<(const node& t1)const{
		return t1.d < d;
	}
}v[N];
int vis[N];
void solve(){
	cin >> n >> m;
	int res = 0;
	for(int i = 1;i <= n;i++) cin >> p[i],res+=p[i];
	for(int i = 1;i <= m;i++) cin >> v[i].l;
	for(int i = 1;i <= m;i++) cin >> v[i].d;
	sort(v+1,v+1+m);
	sort(p+1,p+1+n);
	set<int> se;
	for(int i = 1;i <= n;i++) se.insert(i);
	for(int i = 1;i <= m;i++){
		int l = lower_bound(p + 1,p + 1 + n,v[i].l) - p;
		if(se.lower_bound(l) == se.end()) continue;
		int p = *se.lower_bound(l);
		se.erase(p);
		res-=v[i].d;
	}
	cout << res <<endl;
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
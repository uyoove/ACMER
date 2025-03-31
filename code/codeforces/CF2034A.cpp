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

void solve(){
	cin >> n;
	vt<PII> res;
	set<int> se[3];
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		se[a[i]].insert(i);
	}
	while(se[2].size() && *se[1].rbegin() > *se[2].begin()){
		int p1 = *se[2].begin();
		int p3 = *se[1].rbegin();
		se[2].insert(p3);
		se[1].insert(p1);
		se[1].erase(p3);
		se[2].erase(p1);
		res.pb({p3,p1});
	}
	while(se[0].size() && se[2].size() && *se[0].rbegin() > *se[2].begin()){
		int p1 = *se[0].rbegin();
		int p2 = *se[2].begin();
		int p3 = *se[1].begin();
		se[2].insert(p1);
		se[1].insert(p2);
		se[0].insert(p3);
		se[0].erase(p1);
		se[1].erase(p3);
		se[2].erase(p2);
		res.pb({p3,p1});
		res.pb({p2,p1});
	}

	while(se[0].size() && *se[0].rbegin() > *se[1].begin()){
		int p1 = *se[0].rbegin();
		int p3 = *se[1].begin();
		se[0].insert(p3);
		se[1].insert(p1);
		se[1].erase(p3);
		se[0].erase(p1);
		res.pb({p3,p1});
	}
	cout << res.size() <<endl;
	for(auto p:res){
		cout << p.fi << " " << p.se << endl;
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
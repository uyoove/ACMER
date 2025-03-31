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
int n,m;
int x[N],a[N];
struct edge{
	int x,a;
	bool operator<(const edge& t1)const{
		return t1.x > x;
	}
}e[N];

void solve(){
	cin >> n >> m;
	x[0] = 1;
	for(int i = 1;i <= m;i++){
		cin >> e[i].x;
	}
	int su = 0,d = 0;
	int p = (n + 1)*(n)/2;

	for(int i = 1;i <= m;i++){
		cin >> e[i].a;
		su+=e[i].a;
		d+=e[i].a*e[i].x;
	}
	sort(e+1,e+1+m);
	if(su!=n || d > p){
		cout << -1 << endl;
		return;
	}
	int sp = 0;
	for(int i = 1;i <= m;i++){
		if (sp < e[i].x - 1)
		{
			cout << -1 << endl;
			return;
		}
		sp+=e[i].a;
	}

	cout << p - d << endl;
	
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
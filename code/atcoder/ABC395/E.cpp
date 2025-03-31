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
PII p[N];
int l[N],r[N];
bool check(int x){
	// ed + eu == x;
	// sd + su - ? == x
	// sd 能减 sd个, su 能减 su个
	// 但是e[u] - e[u + 1] <= m;
	//su 最小要减 (0,(x - sd)) 因为sd被减完了,
	//最大可以减 su个
	//上一次最大减su个,这次要控制在su + m,su - m
	for(int i = 1;i <= n;i++){
		l[i] = max(0ll,x - p[i].se),r[i] = p[i].fi;
		if(l[i] > r[i]) return false;
	}
	for(int i = 2;i <= n;i++){
		l[i] = max(l[i],l[i - 1] - m);
		r[i] = min(r[i],r[i - 1] + m);
		if(l[i] > r[i]) return false;
	}
	return true;
}
void solve(){
	cin >> n >> m;
	int r = 1e12;
	for(int i = 1;i <= n;i++){
		cin >> p[i].fi >> p[i].se;
		r = min(r,p[i].fi + p[i].se);
	}
	int l = 0,ans = 0;
	while(l <= r){
		int mid = l + r >> 1;
		if(check(mid)){
			ans = mid;
			l = mid + 1;
		}else{
			r = mid - 1;
		}
	}
	int res = 0;
	for(int i = 1;i <= n;i++){
		res+=p[i].fi+p[i].se - ans;
	}
	cout << res << endl;

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
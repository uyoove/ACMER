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
int n;
struct fuck{
	int a[5];
}f[N];
int mask = (1 << 5) - 1;
vt<int> vis[N];
set<int> se[N];
bool check(int x){
	vt<int> h(mask + 1,0);
	vt<int> v;
	for(int i = 1;i <= n;i++){
		int t = 0;
		for(int j = 0;j < 5;j++){
			if(f[i].a[j] >= x){
				t |= (1 << j);
			}
		}
		v.pb(t);
		h[t]=1;
	}
	h[0] = 1;
	for(int i = 0;i < n;i++){
		for(int j = 0;j < i;j++){
			int p = v[i] | v[j];
			int d = mask - p;
			if(h[d] == 1) return true;
			int g1 = d;
			while(g1 <= mask){
				if(h[d] ==1) return true;
				g1 = (g1 + 1) | mask;
			}
		}
	}
	return false;
}
void solve(){
	cin >> n;

	for(int i = 1;i <= n;i++){
		for(int j = 0;j < 5;j++){
			cin >> f[i].a[j];
		}
	}
	int l = 1,r = 1e9,ans = -1;
	//cout << check(1) << endl;
	while(l<=r){
		int mid = (l + r) >> 1;
		//cout << mid << endl;
		if(check(mid)){
			l = mid + 1;
			ans = mid;
		}else{
			r = mid - 1;
		}
	}	
	cout << ans << endl;
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
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
map<__int128,int> h;
__int128 v[N];
int a[N],cnt[N],cnt2[N];
int n;
__int128 has[N];
__int128 pre[N];
void solve(){
	cin >> n;
	for(int i = 1; i <= 5e5;i++) v[i] = rnd(); 
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		cnt[a[i]]++;
		has[i] = (cnt[a[i]] % 3 ? v[a[i]] : -2 * v[a[i]]);
		//cout << has[i] << endl;
		pre[i] = pre[i - 1] + has[i];
	}
	int ans = 0;
	int l = 1;
	h[0] = 1;
	for(int i = 1;i <= n;i++){
		cnt2[a[i]]++;
		while(cnt2[a[i]] > 3){
			--cnt2[a[l]];
			--h[pre[l - 1]];
			++l;
		}
		if(cnt2[a[i]] == 3) ans+= h[pre[i]];
		++h[pre[i]];
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
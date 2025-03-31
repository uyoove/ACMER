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
vt<int> v[30];
int f[(1 << 20) + 7];// 表示s集合符合条件的最小右端点下标
void solve(){
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> a[i],v[a[i] - 1].pb(i);
	memset(f,0x3f,sizeof f);
	f[0] = 0;
	for(int i = 0;i < (1 << 20);i++){
		for(int j = 0;j <= 19;j++){
			if(i & (1 << j)){
				continue;
			}
			int p = lower_bound(v[j].begin(),v[j].end(),f[i]) - v[j].begin();
			//cout << i << " " << j << " " << p << endl;
			if(p + 1 >= v[j].size()) continue;
			f[i | (1 << j)] = min(f[i | (1 << j)],v[j][p + 1]);
		}
	}
	int ans = 0;
	for(int i = 0;i < (1 << 20);i++){
		if(f[i] <= n){
			//cout << f[i] << endl;
			int t = __builtin_popcount(i);
			ans = max(ans,t*2);
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
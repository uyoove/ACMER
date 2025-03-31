//最后一舞
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
const int N = 1000005;
int n,x,y;
vt<int> nx[N];
void solve(){
	cin >> n >> x >> y;
	int res = 0;
	set<int> se;
	int tp = (1 + y)*y/2;
	res = tp*(x + 1);
	res += (y+1 + (y+1)*x)*x/2;
	for(int i = 1;i <= n;i++){
		int x,y;
		cin >> x >> y;
		x++,y++;
		nx[x].pb(y);
		se.insert(x);
	}
	res = (y + 1) * y / 2 * (x + 1) + (x + 1) * x / 2 * (y + 1);
	int cury = 0;
	for(auto i:se){
		sort(all(nx[i]));
		int l = 0,r = nx[i].size() - 1,ans = -1;
		while(l <= r){
			int mid = l + r >> 1;
			if(nx[i][mid] >= cury){
				r = mid - 1;
				ans = mid;
			}else{
				l = mid + 1;
			}
		}
		if(ans!=-1 && nx[i][ans] <= y){
			res -= (x - i + 1) * (y - nx[i][ans] + 1);
			cury = nx[i][ans] + 1;
		}
		nx[i].clear();
	}
	cout << res <<endl;


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
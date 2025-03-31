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
const int N = 300005;
int n;
int a[N],ans;
int v[N],hs[N],p[N]; //随机数,数组随机,排列随机
vector<int> pos1; //1的位置
void solve(){
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		v[i] = rnd();
		if(a[i] == 1) pos1.pb(i); 
	}
	for(int i = 1;i <= n;i++){
		p[i] = p[i - 1]^(v[i]);
		hs[i] = hs[i - 1] ^ (v[a[i]]);
	}
	int m = pos1.size();
	int ans = 0;
	for(int i = 0;i < m;i++){
		int l = (i == 0 ? 1 : pos1[i - 1] + 1);
		int r = (i == m - 1 ? n : pos1[i + 1] - 1);
		int mx = 1;
		ans++; //1的数组自然也是
		for(int j = pos1[i] - 1;j >= l;j--){
			mx = max(mx,a[j]);
			int pl = j,pr = j + mx - 1;
			if(pr >= pos1[i] && pr <= r && p[mx] == (hs[pr] ^ hs[pl - 1])){
				ans++;
			}
		}
		mx = 1;
		for(int j = pos1[i] + 1;j <= r;j++){
			mx = max(mx,a[j]);
			int pl = j - mx + 1,pr = j;
			if(pl >= l && pl <= pos1[i] && p[mx] == (hs[pr] ^ hs[pl - 1])){
				ans++;
			}
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
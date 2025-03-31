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
const int infi = 1e18;
const int P = 13331;
const int N = 200005;
int n;
int a[N],c[N];
PII p[N];
unordered_map<int,int> mp;
void solve(){
	cin >> n;
	int mx = 0;
	for(int i = 1;i <= n;i++){
		cin >> a[i] >> c[i];
		mp[a[i]] = c[i];
		mx = a[i];
		p[i] = {a[i],c[i]};
	}
	sort( p +1 ,p+1+n);
	int res = 0;
	for(int i = 1;i <= n;i++){
		int d = mp[p[i].fi];
		for(int j = 1;j <= 60;j++){
			if((a[i] << (j - 1)) >= infi) break;
			int hs = mp[a[i] << (j - 1)];
			mp[a[i] << j] += hs/2;
			mp[a[i] << (j - 1)] = hs%2;
			if(mp[a[i] << (j - 1)]==0) mp.erase(a[i] << (j - 1));
			//cout << (a[i] << (j - 1)) << " " << hs%2 << endl;
		}
		//cout << res << endl;
	}
	for(auto &p:mp){
		res+=p.se;
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
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
int a[N],val[N];
vt<int> v[N];
void solve(){
	cin >> n >> m;
	for(int i = 1;i <= m;i++){
		cin >> a[i];
	}
	for(int i = 1;i <= n;i++){
		string s;
		cin >> s;
		int t = 0;
		int id = 1;
		for(auto p:s){
			if(p=='o') t+=a[id];
			else v[i].pb(a[id]);
			id++;
		}
		val[i] = t + i; 
		sort(all(v[i]));
	}
	for(int i = 1;i <= n;i++){
		int mx = 0;
		for(int j = 1;j <= n;j++){
			if(i==j) continue;
			mx = max(mx,val[j]);
		}
		if(val[i] > mx){
			cout << 0 << endl;
			continue;
		}
		int cnt = 0;
		int d = mx - val[i];
		for(int j = v[i].size() - 1;j >= 0;j--){
			d-=v[i][j];
			cnt++;
			if(d < 0) break;
		}
		cout << cnt << endl;
	}
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
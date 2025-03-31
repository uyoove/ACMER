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
const int N = 1000005;
int d[N];
int n,c;
vt<int> v[N];
void solve(){
	cin >> n >> c;
	for(int i = 1;i <= n;i++){
		int t;
		cin >>t ;
		while(t--){
			int p;
			cin >> p;
			v[i].pb(p); 
		}
	}
	for(int i = 1;i <= n - 1;i ++){
		int sz = min(v[i].size(),v[i + 1].size());
		bool f = false;
		for(int j = 0;j < sz;j++){
			if(v[i][j]==v[i + 1][j]) continue;
			int a = v[i][j],b = v[i + 1][j];
			if(v[i][j] < v[i + 1][j]){
				d[c - b + 1]++;
				d[c - a + 1]--;
			}else{
				d[0]++;
				d[c - a + 1]--;
				d[c - b + 1]++;
				d[c]--;
			}
			f = true;
			break;
		}
		if(!f){ //如果都一样,且前面长
			if(v[i].size() > v[i + 1].size()){
				cout << -1 << endl;
				return;
			}
		}
	}
	int su = 0;
	for(int i = 0;i<=c - 1;i++){
		su+=d[i];
		if(su==0){
			cout << i << endl;
			return;
		}
	}
	cout << -1 << endl;
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
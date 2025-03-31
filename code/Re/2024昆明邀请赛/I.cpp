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
const int N = 200005;
string s;
void solve(){
	cin >> s;
	int n = s.size();
	map<char,int> mp;
	for(auto p:s) mp[p]++;
	if(mp.size()==1){
		cout << n/2 << endl;
	}else{
		vt<int> v;
		int id = 0;
		for(int i = n - 1;i >= 0;i--){
			if(s[i]==s[0]){
				id = i;
			}else{
				break;
			}
		}
		int t = 1;
		for(int i = id + 1;(i%n) != id;i++){
			int last = (i - 1 + n)%n;
			if(s[last]==s[i%n]){
				t++;
			}else{
				if(t > 1) v.pb(t);
				t = 1;
			}
		}
		if(t>1) v.pb(t);
		int res = 0;
		bool f = 0;
		for(auto p:v){
			if(p%2==0){
				f = 1;
			}
			res+=p/2;
		}
		cout << res - f << endl;
	}

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
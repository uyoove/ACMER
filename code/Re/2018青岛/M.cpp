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
int pb[10] = {1,0,0,0,1,0,1,0,2,1};
string s;
int k;
void solve(){
	cin >> s >> k;
	while(s.size() >= 2 && k){
		int d = 0;
		for(auto ch:s){
			d += pb[ch-'0'];
		}
		s = to_string(d);
		k--;
	}
	while(k && s!="0"){
		int d = 0;
		for(auto ch:s){
			d += pb[ch-'0'];
		}
		s = to_string(d);
		k--;
	}
	if(!k){
		cout << s << endl;
		return;
	}
	if(k%2==0){
		cout << 0 << endl;
	}else{
		cout << 1 << endl;
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
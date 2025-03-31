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
//a1
//a1 + a2
//a1 + a2 + a2 + a3
//a1 + a2 + a2 + a3 + a2 + a3 + a3 + a4
//a1 + a2 + a2 + a3 + |a2 + a3 + a3 + a4 + a2 + a3 + a3 + a4| + |a3 + a4 + a4 + a5|
ll powerMod(ll x, ll n, ll mod){ //快速幂
    ll ans = 1;
    while (n > 0){
        if  (n & 1)
            ans = (ans * x) % mod;
        x = (x * x) % mod;
        n >>= 1;
    }
    return ans;
}
int n,m;
string s;
string next(string s){
	for(auto &p :s){
		p = (p -'a' +1)%26 + 'a';
	}
	return s;
}
void solve(){
	int  d = powerMod(10,100,26);
	cin >> n >> m;
	cin >> s;
	s = s.substr(n/2);
	//直到我后半段的值大于等于m
	//然后后缀一定在s中产生
	//所以只要s演变16-cnt次就行
	int cnt = 0;
	while(s.size() < m){
		s = s + next(s);
		cnt++;
	}
	int p = (16 - cnt + 26)%26;
	while(p--){
		s = next(s);
	}
	int p1 = s.size();
	for(int j = p1-m;j < p1;j++){
		cout << s[j];
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
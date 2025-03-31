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
const int N = 1000005;
string s;
int dp[N]; //代表以i结尾的最长合法子串
void solve(){
	cin >> s;
	int n = s.size();
	map<char,char> mp;
	mp[')'] = '(';
	mp[']'] = '[';
	s = " " + s;
	int mx = 0,id = 0;
	for(int i = 1;i <= n;i++){
		if(!mp.count(s[i])) continue;
		if(mp[s[i]]==s[i - dp[i-1] - 1]){
			dp[i] = dp[i - 1] + 2 + dp[i - dp[i-1] - 2];//自己的贡献2,中间的贡献dp[i-1],还有前面并列的贡献
		}
		if(dp[i]>mx){
			mx = dp[i];
			id = i;
		}
	}
	for(int i = id-mx+1;i<=id;i++){
		cout << s[i];
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
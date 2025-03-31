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
const int N = 200005;
int dp[N][2];// 表示后面包括自身的2/3个字符存在是否符合要求
void solve(){
	string s;
	cin >> s;
	int n = s.size();
	s = " " + s;
	for(int i = n;i >= 6;i--){
		if(i + 2 == n + 1){
			dp[i][0] = 1;
		}else if(i + 3 == n + 1){
			dp[i][1] = 1;
		}else{
			if(dp[i + 2][1]){
				dp[i][0] = 1;
			}
			if(dp[i + 3][0]){
				dp[i][1] = 1;
			}
			if(dp[i+2][0] && (s[i] != s[i + 2] || s[i + 1] != s[i + 3])){
				dp[i][0] = 1;
			}
			if(dp[i+3][1] && (s[i] != s[i + 3] || s[i + 1] != s[i + 4] || s[i + 2] != s[i + 5])){
				dp[i][1] = 1;
			}
			
		}
	}
	set<string> se;
	for(int i = 6;i <= n;i++){
		if(dp[i][0]){
			//cout << i << endl;
			se.insert(s.substr(i,2));
		}
		if(dp[i][1]){
			se.insert(s.substr(i,3));
		}
	}
	cout << se.size() << endl;
	for(auto p:se){
		cout << p << endl;
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
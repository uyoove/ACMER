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
const int N = 20;
int n;
int len[N],s[N],e[N];
int dp[100005][30];
void solve(){
	cin >> n;
	int mx = 0;
	for(int i = 1;i <= n;i++){
		string s1;
		cin >> s1;
		s[i] = s1[0] - 'A';
		e[i] = s1[s1.size() - 1] - 'A';
		len[i] = s1.size();
	}

	for(int i = 0;i < (1 << n);i ++){
		for(int j = 1;j <= n;j++){
			if(i & (1 << (j-1))) continue;
			dp[i | (1 << (j - 1))][e[j]] = max(dp[i][s[j]] + len[j],dp[i | (1 << (j - 1))][e[j]]);
			mx=max(dp[i | (1 << (j - 1))][e[j]],mx);
		}
	}
	cout << mx <<  endl;
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
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
int MOD = 1e9+7;
string n;
int k;
int dp[1500];// 代表i位变成1要多少次
int memo[1500][1500];

int dfs(int pos,int limit,int cost,int base){
	if(base - cost < 0) return 0;
	if(pos == -1){
		//cout << s << endl;
		if(cost==base){
			return 1;
		}
		return 0;
	}
	if(memo[pos][base - cost]!=-1 && !limit) return memo[pos][base - cost];
	int res = 0;
	int up = limit ? n[pos] - '0' : 1; 
	for(int i = 0;i <= up;i++){
		res+=dfs(pos - 1,limit && (n[pos] - '0') == i,cost + (i==1),base);
		res%=MOD;
	}
	if(!limit) memo[pos][base - cost] = res;
	return res;

}
void solve(){
	
	dp[1] = 1;
	for(int i = 2;i <= 1001;i++){
		int p = __builtin_popcount(i);
		dp[i] = dp[p] + 1;
	}
	cin >> n >> k;
	memset(memo,-1,sizeof memo);
	if(k==1){
		cout << n.size() - 1 << endl;
		return;
	}
	if(k==0){
		cout << 1 <<endl;
		return;
	}
	reverse(n.begin(),n.end());
	int sz = n.size();
	int res = 0;
	for(int i = k;i <= sz;i++){
		if(dp[i] == k) res+=dfs(sz - 1,1,0,i);
		res%=MOD;
	}
	
	
	cout << res <<endl;
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
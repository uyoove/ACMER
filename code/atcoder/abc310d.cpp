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
const ll inf = 0x3f3f3f3f3f3f3f3fLL;
const int infi = 0x3f3f3f3f;
const int P = 13331;
const int N = 200005;
int dp[1 << 10 + 10][15];//代表集合s运动员已经选择,现在在第t组的方案数 
int n,t,m;
set<PII> se;
bool check(int k){
	for(int i = 0;i < n;i++){
		for(int j = 0;j < n;j++){
			if(i==j) continue;
			if((k >> i) & 1){
				if((k >> j)&1){
					if(se.count({i+1,j+1})) return false;
				}
			}
		}
	}
	return true;
}
int lb(int x){
	return x&-x;
}
void solve(){
	cin >> n >> t >> m;
	for(int i = 0;i < m;i++){
		int u,v;
		cin >> u >> v;
		se.insert({u,v});
		se.insert({v,u});
	}
	dp[0][0] = 1;
	for(int k = 1; k <= t;k++){
		for(int i = 0; i < (1 << n);i++){
			for(int j = i;;j=(j-1)&i){
				//要lb相同才行,不然会重合 11001 <- 10001 但不能  11001 <- 11000 
				if( lb(i)!=lb(i&j) && check(i ^ j)){
					dp[i][k] += dp[j][k - 1];
				}
				if(!j) break;
				
			}
		}
	}
	cout << dp[(1 << n) - 1][t] <<endl;
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
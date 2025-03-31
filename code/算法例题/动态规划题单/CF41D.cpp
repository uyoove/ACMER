//和爸爸一起学编程真好,不过要小学四年级分流考试了,最近没时间写代码了,呜呜呜
#include<bits/stdc++.h>
using namespace std;
#define out(x) cout << #x << '=' << (x) << endl
#define out2(x, y) cout << #x << '=' << (x) << ',' << #y << '=' << (y) << endl 
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
int n,m,k;
int dp[110][110][13];
PII last[110][110][13];
string s[N];
void solve(){
	cin >> n >> m >> k;
	k = k + 1;
	for(int i = 0;i <= n + 1;i++){
		for(int j = 0;j <= m + 1;j++){
			for(int p = 0;p < k + 1;p++){
				dp[i][j][p] = -1;
			}
		}
	}
	for(int i = 1;i <= n;i++){
		cin >> s[i];
		s[i] = " " + s[i];
		if(i==n){
			for(int j = 1;j <= m;j++){
				int val = s[i][j] - '0';
				dp[i][j][val%k] = val;
				//cout << val%k << endl;
			}
		}
	}
	for(int i = n - 1;i >= 1;i--){
		for(int j = 1;j <= m;j++){
			for(int p = 0;p < k;p++){
				if(j > 1 && dp[i + 1][j - 1][p]!=-1) {
					if(dp[i+1][j-1][p] + s[i][j] - '0' > dp[i][j][(p + s[i][j] - '0')%k]){
						dp[i][j][(p + s[i][j] - '0')%k] = dp[i+1][j-1][p] + s[i][j] - '0';
						last[i][j][(p + s[i][j] - '0')%k] = {j-1,p};
					}
					
				}
				if(j<m && dp[i + 1][j + 1][p]!=-1){
					if(dp[i+1][j+1][p] + s[i][j] - '0' > dp[i][j][(p + s[i][j] - '0')%k]){
						dp[i][j][(p + s[i][j] - '0')%k] = dp[i+1][j+1][p] + s[i][j] - '0';
						last[i][j][(p + s[i][j] - '0')%k] = {j+1,p};
					}
				}
			}
		}
	}
	int res = -1;
	int wz = 0,md = 0;
	for(int i = 1;i <= m;i++){
		if(dp[1][i][0]!=-1){
			if(dp[1][i][0] >= res){
				res = dp[1][i][0];
				wz = i;
			}
		}
	}
	cout << res <<endl;
	if(res==-1) return;
	vt<string> v;
	int id = 1;
	while(id < n){
		int p = last[id][wz][md].fi;
		md = last[id][wz][md].se;
		if(p == wz + 1){
			v.pb("L");
		}else{
			v.pb("R");
		}
		wz = p;
		id++;
	}
	cout << wz << endl;
	for(int i = id - 2;i >= 0;i--){
		cout << v[i];
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
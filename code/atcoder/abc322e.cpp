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
int n,m,k;
int c[N];
int g[110][10];
vector<string> res;
int vis[10];
vector<int> p;
void dfs(int pos,string s){
	if(pos==m){
		res.push_back(s);
		return;
	}
	for(int i = 0;i < p.size();i++){	
		dfs(pos+1,s+(char)(p[i] + '0'));
	}
}
void solve(){
	cin >> n >> m >> k;
	p.push_back(0);
	for(int i = 1;i <= k;i++) p.push_back(i);
	for(int i = 1;i <= n;i++){
		cin >> c[i];
		for(int j= 1;j <= m;j++){
			cin >> g[i][j];
		}
	}
	dfs(0,"");
	map<string,int> dp;
	for(auto &p:res) dp[p] = 1e18;
	int p1 = res.size();
	string s2,s3;
	for(int i = 0;i < m;i++) s2+='0',s3+=(char)(k + '0');
	dp[s2] = 0;
	//cout << s2 << " " << s3 << endl;
	for(int i = 1;i <= n;i++){
		for(int k = p1 - 1; k >= 0;k--){
			bool f = true;
			string s2;
			for(int j = 0;j < m;j++){
				if(g[i][j + 1] >= res[k][j] - '0'){
					s2+=(char)( '0');
					continue;
				}
				s2+=(char)(res[k][j] - g[i][j + 1]);
			}
			
			dp[res[k]] = min(dp[res[k]],dp[s2] + c[i]);
		}
	}
	if(dp[s3] == 1e18){
		cout << -1 << endl;
		return;
	}
	cout << dp[s3] <<endl;
}

signed main(){
	// std::ios::sync_with_stdio(0);
    // std::cin.tie(0);
    // std::cout.tie(0);
	int times = 1;
	//cin >> times;
	while(times--){
		solve();
	}
	return 0;
}
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

mt19937_64 rnd(time(0));
const ll inf = 0x3f3f3f3f3f3f3f3fLL;
const int infi = 0x3f3f3f3f;
const int P = 13331;
const int N = 200005;
int m;
string s[3];
vector<int> mp[10][3];
set<int> se[3];
void solve(){
	cin >> m >> s[0] >> s[1] >> s[2];
	s[0] = s[0] + s[0] + s[0];
	s[1] = s[1] + s[1] + s[1];
	s[2] = s[2] + s[2] + s[2];
	int ans = 1e9;
	for(int i = 0; i < 3*m;i++){
		for(int j = 0;j < 3*m;j++){
			for(int k = 0;k < 3*m;k++){
				if(i==j||j==k||i==k) continue;
				if(s[0][i] == s[1][j] && s[1][j] == s[2][k]){
					ans =  min(ans,max(i,max(j,k)));
				}
			}
		}
	}
	cout << (ans == 1e9 ? -1 : ans) <<endl;
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
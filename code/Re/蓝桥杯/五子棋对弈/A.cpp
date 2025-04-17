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
int qp[6][6];
int ans = 0;
bool check(){
	int h = 0,b = 0;
	for(int i = 1;i <=5;i++){
		for(int j = 1;j <= 5;j++){
			h+=qp[i][j];
		}
	}
	if(h!=13) return false;
	if(qp[1][1]==qp[2][2]&&qp[2][2]==qp[3][3]&&qp[3][3]==qp[4][4]&&qp[5][5]==qp[4][4]){
		return false;
	}
  if(qp[1][5]==qp[2][4]&&qp[2][4]==qp[3][3]&&qp[3][3]==qp[4][2]&&qp[5][1]==qp[4][2]){
		return false;
	}
	for(int i = 1;i <= 5;i++){
		if(qp[i][1]==qp[i][2]&&qp[i][2]==qp[i][3]&&qp[i][3]==qp[i][4]&&qp[i][5]==qp[i][4]){
			return false;
		}
	}
	for(int i = 1;i <= 5;i++){
		if(qp[1][i]==qp[2][i]&&qp[2][i]==qp[3][i]&&qp[3][i]==qp[4][i]&&qp[5][i]==qp[4][i]){
			return false;
		}
	}
	return true;
}
void dfs(int r,int c){
	if(c>5) c = 1,r++;
	if(r==6){
		ans+=check();
		return;
	}
	qp[r][c] = 1;
	dfs(r,c+1);
	qp[r][c] = 0;
	dfs(r,c+1);
}
void solve(){

	dfs(1,1);
	cout << ans << endl;
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
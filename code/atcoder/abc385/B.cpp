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
int n,m,x,y;
string  gd[210];
int vis[210][210];
void solve(){
	cin >> n >> m >> x >>y;
	for(int i = 1;i <= n;i++){
		cin >> gd[i];
		gd[i] = " " + gd[i];
	}
	string t;
	cin >> t;
	int ans = 0;
	for(int i = 0;i < t.size();i++){
		char ch = t[i];
		int nx = x,ny = y;
		if(ch=='U') nx -= 1;
		if(ch=='D') nx+=1;
		if(ch=='L') ny-=1;
		if(ch=='R') ny+=1;
		if(nx <= 0 || ny <= 0 || nx > n || ny > m || gd[nx][ny] == '#') continue;
		if(gd[nx][ny] == '@' & !vis[nx][ny]){
			vis[nx][ny] = 1;
			ans++;
		}
		x = nx,y = ny;
	}
	cout << x <<" " <<y << " "<< ans << endl;

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
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
int a,b,x,y;
int g[10][10];
void solve(){
	
	cin >> a >> b >> x >> y;
	cout << min(g[a][x] + g[b][y],g[a][y]+g[b][x]) << endl;
}

signed main(){
	std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
	int times = 1;
	memset(g,0x3f,sizeof g);
	g[1][2] = 1;
	g[2][1] = 1;
	g[1][3] = 1;
	g[3][1] = 1;
	g[4][2] = 1;
	g[2][4] = 1;
	g[4][3] = 1;
	g[3][4] = 1;

	g[4][5] = 1;
	g[5][4] = 1;
	g[4][6] = 1;
	g[6][4] = 1;
	g[7][5] = 1;
	g[5][7] = 1;
	g[6][7] = 1;
	g[7][6] = 1;
	for(int k = 1;k <= 7;k++){
		for(int i = 1;i <= 7;i++){
			g[i][i] = 0;
			for(int j = 1;j <= 7;j++){
				if(i==j||j==k||i==k) continue;
				g[i][j] =min(g[i][j],g[i][k]+g[k][j]);
			}
		}
	}
	cin >> times;
	while(times--){
		solve();
	}
	return 0;
}
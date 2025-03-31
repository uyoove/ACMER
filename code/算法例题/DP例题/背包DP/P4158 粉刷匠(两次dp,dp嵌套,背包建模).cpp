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
const int N = 3005;
int n,m,t;
int f[75][N]; // 代表前i个木板粉刷j次的最大可粉刷数量
int g[75][N][75]; //代表第i个木板,用了j次的粉刷数量,前k的最大粉刷数量
string grid[75];
int cnt[75][75]; //对没行分别做前缀和,记录1的个数
void solve(){
	cin >> n >> m >> t;
	for(int i = 1;i <= n;i++){
		cin >> grid[i];
		grid[i] = " " + grid[i];
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			cnt[i][j] = cnt[i][j - 1] + (grid[i][j] == '1');
		}
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= t;j++){
			for(int k = 1;k <= m;k++){
				//从j-1因为我粉刷了j-1次,那我肯定至少有j-1个格子
				for(int q = j - 1;q < k;q++){
					//两种颜色取最大
					g[i][j][k] = max(g[i][j][k],g[i][j - 1][q]+max(cnt[i][k] - cnt[i][q],k - q - (cnt[i][k] - cnt[i][q])));
				}
			}
		}
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= t;j++){
			//我一块的最多涂得数量是木板长度或者是j
			for(int k = 0;k <= min(j,m);k++){
				f[i][j] = max(f[i][j],f[i - 1][j - k] + g[i][k][m]);
			}
		}
	}
	cout << f[n][t] << endl;
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
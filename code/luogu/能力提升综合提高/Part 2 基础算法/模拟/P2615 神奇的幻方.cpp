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
const int N = 200;
int grid[N][N],c[N*N],r[N*N];
int n;
void solve(){
	cin >> n;
	grid[1][n/2 + 1] = 1;
	c[1] = n/2 + 1;r[1] = 1;
	for(int i = 2;i <= n*n;i++){
		if(r[i - 1]==1&&c[i - 1]!=n){
			grid[n][c[i - 1] + 1] = i;
			c[i] = c[i - 1] + 1,r[i] = n; 
		}else if(c[i - 1]==n&&r[i-1]!=1){
			grid[r[i - 1] - 1][1] = i;
			r[i] = r[i-1]-1,c[i] = 1;
		}else if(c[i-1]==n&&r[i-1]==1){
			grid[r[i-1]+1][c[i - 1]] = i;
			r[i]=r[i-1]+1,c[i]=c[i-1];
		}else{
			if(grid[r[i - 1] - 1][c[i - 1] + 1]==0){
				grid[r[i - 1]- 1][c[i-1]+1]=i;
				r[i]=r[i-1]-1,c[i]=c[i-1]+1;
			}else{
				grid[r[i - 1]+1][c[i-1]]=i;
				r[i]=r[i-1]+1,c[i]=c[i-1];
			}
		}
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			cout << grid[i][j] << " ";
		}
		cout << endl;
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
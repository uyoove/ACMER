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
int n,m;
int idx = 0;
void gb1(int x,int y,vector<vector<int>> &grid,int &idx){
	grid[x][y] = idx;
	grid[x+1][y] = idx;
	grid[x][y+1] = idx;
	grid[x][y+2] = idx;
	++idx;
	grid[x + 1][y+1] = idx;
	grid[x+1][y+2] = idx;
	grid[x+1][y+3] = idx;
	grid[x+1][y+4] = idx;
	++idx;
	grid[x][y+3] = idx;
	grid[x][y+4] = idx;
	grid[x][y+5] = idx;
	grid[x+1][y+5] = idx;
}
void gb2(int x,int y,vector<vector<int>> &grid,int &idx){
	grid[x][y + 1] = idx;
	grid[x][y] = idx;
	grid[x + 1][y] = idx;
	grid[x + 2][y] = idx;
	++idx;
	grid[x + 1][y + 1] = idx;
	grid[x+2][y + 1] = idx;
	grid[x+3][y + 1] = idx;
	grid[x+4][y + 1] = idx;
	++idx;
	grid[x + 5][y + 1] = idx;
	grid[x + 3][y] = idx;
	grid[x + 4][y] = idx;
	grid[x+5][y] = idx;
}
void solve(){
	cin >> n >> m;
	idx = 0;
	vector<vector<int>> grid(n + 1,vector<int> (m+1,0));
	if((n*m % 4)!=0 || (n==2&&m==2)){
		cout << "NO" << endl;
		return;
	} 
	cout << "YES" << endl;
	if(n%4==0){
		for(int i = 1;i<=n;i++){
			for(int j = 1;j <= m;j++){
				if(!grid[i][j]){
					++idx;
					for(int k = 0;k < 4;k++){
						grid[i+k][j] = idx;
					}
				}
			}
		}
		for(int i = 1;i<=n;i++){
			for(int j = 1;j <= m;j++){
				cout << grid[i][j];
				if(j!=m) cout << " ";
			}
			cout << endl;
		}
		return;
	}
	if(m%4==0){
		for(int i = 1;i<=n;i++){
			for(int j = 1;j <= m;j++){
				if(!grid[i][j]){
					++idx;
					for(int k = 0;k < 4;k++){
						grid[i][j + k] = idx;
					}
				}
			}
		}
		for(int i = 1;i<=n;i++){
			for(int j = 1;j <= m;j++){
				cout << grid[i][j];
				if(j!=m) cout << " ";
			}
			cout << endl;
		}
		return;
	}
	if(n>=6){
		bool f = false; //填一次即可
		for(int i = 1;i<=n;i++){
			for(int j = 1;j <= m;j++){
				if(!grid[i][j]){
					++idx;
					if(i+5 <= n && j+1 <= m && !f){
						gb2(i,j,grid,idx);
						f = true;
						continue;
					}
					if(n - i + 1 >= 4){
						for(int k = 0;k < 4;k++){
							grid[i + k][j] = idx;
						}
						continue;
					}
					if(m - j + 1 >= 4){
						for(int k = 0;k < 4;k++){
							grid[i][j+k] = idx;
						}
						continue;
					}
				}
			}
		}
		for(int i = 1;i<=n;i++){
			for(int j = 1;j <= m;j++){
				cout << grid[i][j];
				if(j!=m) cout << " ";
			}
			cout << endl;
		}
	}else{
		bool f = false; //填一次即可
		for(int i = 1;i<=n;i++){
			for(int j = 1;j <= m;j++){
				if(!grid[i][j]){
					++idx;
					if(i+1 <=n && j+5 <= m && !f){
						gb1(i,j,grid,idx);
						f = true;
						continue;
					}
					if(n - i + 1 >= 4){
						for(int k = 0;k < 4;k++){
							grid[i + k][j] = idx;
						}
						continue;
					}
					if(m - j + 1 >= 4){
						for(int k = 0;k < 4;k++){
							grid[i][j+k] = idx;
						}
						continue;
					}
				}
			}
		}
		for(int i = 1;i<=n;i++){
			for(int j = 1;j <= m;j++){
				cout << grid[i][j];
				if(j!=m) cout << " ";
			}
			cout << endl;
		}
	}
	
}

signed main(){
	std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
	int times = 1;
	cin >> times;
	while(times--){
		solve();
	}
	return 0;
}
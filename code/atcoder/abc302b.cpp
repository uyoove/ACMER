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
char ch[200][200];
int n,m;
int mx[8] = {-1,-1,0,1,1,1,-1,0};
int my[8] = {0,1,1,1,0,-1,-1,-1};
void solve(){
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			cin >> ch[i][j];
		}
	}
	vector<char>c = {'s','n','u','k','e'};
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			int id = 0;
			if(ch[i][j] == c[id]){
				//out2(i,j);
				id++;
				for(int k = 0;k < 8;k++){
					id = 1;
					int nx = i,ny = j;
					while(true){
						nx = nx + mx[k],ny = ny + my[k];
						//out2(nx,ny);

						if(nx <= 0 || ny <=0 || nx > n || ny > m)break;
						if(ch[nx][ny] != c[id]) break;
						id++;
						if(id == 5){
							int p = i,q = j;
							cout << p << " "<< q <<endl;
							//cout << ch[p][q] <<endl;
							for(int t = 1;t <= 4;t++){
								p+=mx[k],q+=my[k];
								cout << p << " "<< q <<endl;
								//cout << ch[p][q] <<endl;
							}
							return;
						}
					}
					//cout << "-------------" <<endl;
				}

			}
		}
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
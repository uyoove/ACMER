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
int mx[4] = {-1,-1,1,1};
int my[4] = {1,-1,-1,1};
void solve(){
	int h,w;
	cin >> h >> w;
	char ch[h+2][w+2];
	for(int i = 1;i <= h;i++){
		for(int j = 1;j<= w;j++){
			cin >> ch[i][j];
		}
	}
	int mi = min(h,w);
	int cnt[mi + 1];
	memset(cnt,0,sizeof cnt);
	for(int i = 1;i <= h;i++){
		for(int j = 1;j<= w;j++){
			int mi = 0x3f3f3f3f;
			if(ch[i][j] == '#'){
				for(int k = 0;k < 4;k++){
					int nx = i,ny = j;
					int cnt = 0;
					while(true){
						nx = nx + mx[k],ny = ny + my[k];
						if(nx <= 0 || ny <= 0 || nx > h || ny > w) break;
						if(ch[nx][ny]=='.') break;
						cnt++;
					}
					mi=min(cnt,mi);
					//cout << i << " "  << j << " " << cnt << endl;
				}

				cnt[mi]++;
			}
		}
	}
	for(int i = 1;i <= mi;i++){
		cout << cnt[i] << " ";
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
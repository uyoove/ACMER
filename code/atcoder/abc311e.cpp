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
const ll inf = 0x3f3f3f3f3f3f3f3fLL;
const int infi = 0x3f3f3f3f;
const int P = 13331;
const int N = 200005;
int pre[3010][3010];
int n,m,k;
int qy(int r1,int c1,int r2,int c2){
	return pre[r2][c2] + pre[r1 - 1][c1 - 1] - pre[r1 - 1][c2] - pre[r2][c1 - 1];
}
void solve(){
	cin >> n >> m >> k;
	for(int i = 1;i <= k;i++){
		int x,y;
		cin >> x >> y;
		pre[x][y]++;
		
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			pre[i][j] = pre[i][j] + pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1];
		}
	}
	long long res = 0;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			int l = 0,r = min(n - i,m-j),ans = -1;
			while(l <= r){
				int mid = l + r >> 1;
				if(!qy(i,j,i + mid,j + mid)){
					l = mid +1;
					ans = mid;
				}else{
					r = mid - 1;
				}
			}
			//cout << ans <<endl;
			res += ans + 1;

		}
	}
	cout << res << endl;

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
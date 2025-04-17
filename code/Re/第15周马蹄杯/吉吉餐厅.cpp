//最后一舞
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
mt19937_64 rnd(time(0));
const ll inf = 0x3f3f3f3f3f3f3f3fLL;
const int infi = 0x3f3f3f3f;
const int P = 13331;
const int N = 10010;
int f[N][N]; //表示前i个人中 有j个副厨师的最小收益; j < i/2
int a[N],b[N];
int n;
void solve(){
	cin >> n;
	memset(f,0x3f,sizeof f);
	f[n + 1][0] = 0;
	for(int i = 1;i <= n;i++){
		cin >> a[i] >> b[i];
	}
	for(int i = n;i >= 1;i--){
		//我是厨师长的
		for(int j = 0;j <= n;j++){
			f[i][j] = f[i + 1][j] + a[i];
		}
		for(int j = 1;j <= (n - i + 1)/2;j++){
			f[i][j] = min(f[i][j],f[i + 1][j - 1] + b[i]);
		}
	}
	cout << f[1][n/2] << endl;

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
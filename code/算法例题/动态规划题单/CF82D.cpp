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
int n;
int a[N];
int f[1010][1010];
//我选择x,y的时候的最小时间
//当前生成的三个数是 i,j,j+1,递归下去的是遗留的那个
int dfs(int x,int y){
	if(f[x][y]) return f[x][y];
	if(y==n + 1) return f[x][y] = a[x];
	if(y==n) return f[x][y] = max(a[x],a[y]);
	f[x][y] = max(a[x],a[y]) + dfs(y + 1,y+2);
	f[x][y] = min(max(a[y + 1],a[y]) + dfs(x,y+2),f[x][y]);
	f[x][y] = min(max(a[y + 1],a[x]) + dfs(y,y+2),f[x][y]);
	return f[x][y];
}
void ptr(int x,int y){
	if(y==n+1){
		cout << x << endl;
		return;
	}
	if(y==n){
		cout << x << " " << y << endl;
		return;
	}
	if(f[x][y]==max(a[x],a[y]) + f[y + 1][y+2]){
		cout << x << " " << y << endl;
		ptr(y + 1,y+2);
	}else if(f[x][y]==max(a[x],a[y + 1]) + f[y][y+2]){
		cout << x << " " << y + 1 << endl;
		ptr(y,y+2);
	}else if(f[x][y]==max(a[y],a[y + 1]) + f[x][y+2]){
		cout << y << " " << y + 1 << endl;
		ptr(x,y+2);
	}
}
void solve(){
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	dfs(1,2);
	cout << f[1][2] << endl;
	ptr(1,2);
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
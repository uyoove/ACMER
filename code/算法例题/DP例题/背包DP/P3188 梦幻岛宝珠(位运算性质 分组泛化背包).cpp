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
int n,w;
int f[50][5000],g[50][5000];//前一个表示前i组用了不超过j * 2 ^ i的最大值,后一个表示第i组用了j * 2^i的最大值

void solve(){
	
	for(int i = 0;i <= n;i++){
		for(int j = 0;j <= 10*n;j++){
			f[i][j]=g[i][j] =0;
		}
	}
	int s = 0;
	while(w>>s) s++;
	vt<vt<int>> val(s + 1),a(s + 1);
	for(int i = 1;i <= n;i++){
		int x,y;
		cin >> x >> y;
		int t = 0;
		while(((x >> t)&1) == 0) ++t;
		val[t].pb(y); 
		a[t].pb((x >> t)); //a*2^t
	}
	for(int i = 0;i <= s;i++){
		for(int j = 0;j < a[i].size();j++){
			for(int k = 10*n;k>=a[i][j];k--){
				g[i][k]=max(g[i][k],g[i][k - a[i][j]]+val[i][j]);
			}
		}
	}
	for(int i = 0;i <= s;i++){
		for(int j = 10*n;j>=0;--j){
			for(int k = 0;k<=j;++k){
				f[i][j]=max(f[i][j],f[i-1][(j-k)*2+((w>>(i-1))&1)]+g[i][k]);
			}
		}
	}
	cout << f[s - 1][1] << endl;

}

signed main(){
	std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
	int times = 1;
	//cin >> times;
	while(cin >> n >> w){
		if(n==-1&&w==-1) return 0;
		solve();
	}
	return 0;
}
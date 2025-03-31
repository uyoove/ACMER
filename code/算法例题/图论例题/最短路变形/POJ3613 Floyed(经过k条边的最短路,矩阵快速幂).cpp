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
const int N = 200005;
int sz;
int idx = 0;
struct matrix
{
	int a[300][300];
	matrix operator * (const matrix &x)const{
		matrix c;
		memset(c.a,0x3f,sizeof c.a);
		for(int k = 1;k <= idx;k++){
			for(int i = 1;i <= idx;i++){
				for(int j = 1;j <= idx;j++){
					c.a[i][j] = min(c.a[i][j],a[i][k] + a[k][j]);
				}
			}
		}
		return c;
	}

};
matrix ksm(matrix x,int n){
	n--;
	matrix res = x;
	while(n){
		if(n&1) res = res * x;
		x = x*x;
		n >>= 1;
	}
	return res;
}
int n,t,s,e;
int h[10000];

void solve(){
	matrix g;
	memset(g.a,0x3f,sizeof g.a);
	cin >> n >> t >> s >> e;
	for(int i = 0;i < t;i++){
		int w,u,v;
		cin >> w>> u >> v;
		if(!h[u]) h[u]= ++idx;
		if(!h[v]) h[v]= ++idx;
		g.a[h[u]][h[v]] = g.a[h[v]][h[u]]=w;
	}
	s = h[s],e = h[e];
	cout << s << " " << e << endl;
		
	
	matrix res = ksm(g,n);
	cout << res.a[s][e] << endl;
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
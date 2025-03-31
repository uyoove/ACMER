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
const int N = 55;
int n,m,k;
int f[N*N],fg[N*N],sz[N*N];
int fd(int x){
	if(f[x]!=x) f[x] = fd(f[x]);
	return f[x];
}
void merge(int x,int y){
	x = fd(x),y = fd(y);
	if(x==y) return;
	if(fg[x]) fg[y] = 1;
	if(fg[y]) fg[x] = 1;
	if(sz[y]>sz[x]){
		sz[y] += sz[x];
		f[x] = y;
	}else{
		sz[x] += sz[y];
		f[y] = x;
	}
}
char grid[N][N];
string s;
int id(int r,int c){return r*(m - 1) + c;}
void solve(){
	cin>>n>>m>>k;
	vector<PII> v;
	set<int> se;
	for(int i = 1;i<=n*m+1;i++) sz[i] = 1,f[i] = i;
	for(int i = 1;i <= n;i++){
		cin >> s;
		for(int j = 1;j<=m;j++){
			grid[i][j] = s[j - 1];
		}
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			if(i == 1 || i == n || j == 1 || j==m) fg[fd(id(i,j))] = 1;
			if(grid[i][j] == '.'){
				if(grid[i +1][j] == '.') merge(id(i,j),id(i+1,j));
				if(grid[i][j + 1] == '.') merge(id(i,j),id(i,j + 1));
			}
		}
	}
	for(int i = 2;i <= n - 1;i++){
		for(int j = 2;j <= m-1;j++){
			if(!fg[fd(id(i,j))] && grid[i][j] == '.'){
				int x = fd(id(i,j));
				if(se.count(x)) continue;
				se.insert(x);
				v.pb({sz[x],x});
			}
		}
	}
	sort(v.begin(),v.end());
	int sz = v.size();
	int xy = sz - k;
	int res = 0;
	set<int> bc;
	for(int i = 0;i < xy;i++){
		res += v[i].fi;
		bc.insert(v[i].se);
	}
	cout << res <<endl;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			if(bc.count(fd(id(i,j)))){
				grid[i][j] = '*';
			}
			cout << grid[i][j];
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
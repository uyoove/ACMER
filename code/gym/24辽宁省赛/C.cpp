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
int n;
vector<int> v[N];
int sz[N];
int a[N];
vt<int> gl;
vt<int> bg;
int mx = 0;
void dfs(int u){
	if(v[u].size()==0){
		sz[u]+=a[u];
		mx=max(mx,sz[u]);
		return;
	}
	if(u!=0) gl.push_back(a[u]);
	for(auto p:v[u]){
		dfs(p);
		sz[u]+=sz[p];
	}
	if(u!=0) bg.push_back(sz[u]);
	mx=max(mx,sz[u]);
}
void solve(){
	cin >> n;
	 
	for(int i = 1;i <= n;i++){
		int f,v1;
		cin >> f >> v1;
		v[f].pb(i);
		a[i] = v1;
	}
	a[0] = 2200;
	dfs(0);
	sort(bg.rbegin(),bg.rend());
	sort(gl.rbegin(),gl.rend());
	if(sz[0] > 2200){
		cout << "NO" << endl;
		return;
	}
	for(int i = 0;i < bg.size();i++){
		//cout << bg[i] << " " << gl[i] << endl;
		if(bg[i] > gl[i]){
			cout << "NO" << endl;
			return;
		}
	}
	cout << "YES" << endl;
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
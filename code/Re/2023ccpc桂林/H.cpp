//最后一舞
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
const int N = 1000005;
struct edges
{
	int v,ne;
}e[N<<1];
int h[N],idx = 1;
void add(int u,int v){
	e[++idx] = {v,h[u]};
	h[u]=idx;
}
int a[N];
int n,k;
int f[N][2];
int ans = 0;
void dfs(int u,int fa){
	int sum1 = 0,sum0 = 0;//奇偶分类代表到没个点我在此之前的奇最大和偶最大
	for(int i = h[u];i;i=e[i].ne){
		int v= e[i].v;
		if(v==fa) continue;
		dfs(v,u);
		if((k%2==0 && f[v][0]>=k) || (k%2==1 && f[v][1]>=k) ){
			ans++;
			continue;
		}
		int t1 = sum1,t0 = sum0; //临时变量
		if(sum1) t1 = max(t1,f[v][0] + sum1); //偶+奇=奇
		if(f[v][1]) t1 = max(t1,f[v][1] + sum0); //奇+偶=奇

		t0 = max(t0,f[v][0] + sum0); //偶+偶=偶
		if(sum1 && f[v][1])t0 = max(t0,f[v][1] + sum1); //奇+奇=偶

		sum1 = t1,sum0 = t0;
	}
	if(a[u]&1){
		f[u][1] = a[u] + sum0;
		if(sum1) f[u][0] = sum1 + a[u];  
	}else{
		f[u][0] = a[u] + sum0;
		if(sum1) f[u][1] = sum1 + a[u];  
	}

}
void solve(){
	cin >> n >> k;
	idx = 1;
	ans = 0;
	for(int i = 1;i <= n;i++) cin>>a[i],h[i]=0,f[i][0]=0,f[i][1]=0;
	for(int i = 1;i <= n - 1;i++){
		int u,v;
		cin >> u >> v;
		add(u,v);
		add(v,u);
	}
	dfs(1,0);
	if((k%2==0 && f[1][0]>=k) || (k%2==1 && f[1][1]>=k) ){
		ans++;
	}
	cout << ans << endl;
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
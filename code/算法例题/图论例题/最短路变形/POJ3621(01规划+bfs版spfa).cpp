#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <iostream>
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
const int N = 5005;
int n,m;
//01规划转换边权为 mid*w - a[i],有负环代表mid可以更大 
struct edges{
	int v;
	double w;
	int ne;
}e[N << 1];
int h[N],idx = 1;
void add(int u,int v,double w){
	edges p = {v,w,h[u]};
	e[++idx] = p;
	h[u] = idx;
}
int a[N];
double dis[N];
int vis[N],cnt[N];
bool check(double x){
	queue<int> q;
	for(int i = 1;i <= n;i++){
		q.push(i);
		dis[i] = 0;
		vis[i] = cnt[i] = 1;
	}
	while(!q.empty()){
		int u = q.front();
		q.pop();vis[u] = 0;
		for(int i =h[u];i;i=e[i].ne){
			int v = e[i].v;
			double w = e[i].w;
			if(dis[v] > dis[u] + w*x - a[u]){
				dis[v] = dis[u] + w*x - a[u];
				if(!vis[v]){
					q.push(v);vis[v] = 1;
					if(++cnt[v]>=n) return 1;
				}
			}
		}
	}
	return 0;
}
void solve(){
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	for(int i = 1;i <= m;i++){
		int u,v;
		double w;
		cin >> u >> v >> w;
		add(u,v,w);
	}
	double l = 0,r = 100000,ans = 0;
	while(r -l > 1e-4){
		double mid = (l+r)/2;
		if(check(mid)){
			l = mid;
			ans = mid;
		}else{
			r = mid;
		}
	}
	printf("%.2lf",ans);
}

signed main(){

	int times = 1;
	//cin >> times;
	while(times--){
		solve();
	}
	return 0;
}
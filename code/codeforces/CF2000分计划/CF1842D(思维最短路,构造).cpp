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
const int N = 205;
//发现性质 n点连接的点的宴会时长最多为边权;
// 然后连接那些连接n点的点的点,比如说 y -> x -> n
//比如说边权都是2 那么 xy 2次 y单独2次则x的总时长是2,y的总时长也是2
//类比发现一个人的宴会总时长即是它的最短路
int dis[150][150];
int n,m;
int ans[N][N];
int tot = 0;
void solve(){
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			dis[i][j] = (inf) * (i != j);
		}
	} 
	for(int i = 1;i <= m;i++){
		int u,v,w;
		cin >> u >> v >> w;
		dis[u][v] = dis[v][u] = min(dis[u][v],w);
	}
	for(int k = 1;k <= n;k++){
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++){
				dis[i][j] = min(dis[i][j],dis[i][k] + dis[k][j]);
			}
		}
	}
	if(dis[1][n] >= inf){
		cout << "inf" << endl;
		return;
	}
	cout << dis[1][n] << " ";
	priority_queue<int,vt<int>,greater<int>> pq;
	tot = 0;
	for(int i = 1;i <= n;i++) if(dis[i][n])pq.push(dis[i][n]);
	int val = 0;
	while(dis[1][n]){
		int p = pq.top();pq.pop();
		p -= val;
		//cout << p << endl;
		val+=p;
		++tot;
		for(int i = 1;i <= n;i++){
			if(dis[i][n]) ans[tot][i] = 1,dis[i][n] -= p;
			else ans[tot][i] = 0;
		}
		ans[tot][0] = p;
	}
	cout << tot << endl;
	for(int i = 1;i <= tot;i++){
		for(int j = 1;j <= n;j++){
			cout << ans[i][j];
		}
		cout <<" "<< ans[i][0] <<endl;
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
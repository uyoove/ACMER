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
int n,m,x;
struct edges{
	int v,ne,k;
}e[N << 1];
int h[N],idx = 1;
struct nodes{
	int v,val,op;
	bool operator<(const nodes& t1)const{
		return val > t1.val;
	}
};
void add(int u,int v,int op){
	e[++idx] = {v,h[u],op};
	h[u] = idx;
}
int dis[N][2],vis[N][2];
void solve(){
	cin >> n >> m >> x;
	for(int i = 1;i <= m;i++){
		int u,v;
		cin >> u >> v;
		add(u,v,1);
		add(v,u,0);
	}
	for(int i =0;i<N;i++){
		for(int j = 0;j<2;j++){
			dis[i][j] = inf;
		}
	}
	priority_queue<nodes> pq;
	pq.push({1,0,1});
	dis[1][1] = 0;
	while(pq.size()){
		auto p = pq.top();pq.pop();
		int u = p.v,val = p.val,op = p.op;
		if(vis[u][op]) continue;
		vis[u][op] = 1;
		for(int i = h[u];i;i=e[i].ne){
			int v = e[i].v;
			if(e[i].k != op){
				if(dis[u][op] + 1 + x < dis[v][op^1]){
					dis[v][op^1] = dis[u][op] + 1 +x;
					pq.push({v,dis[v][op^1],op^1});
				}
			}else{
				if(dis[u][op] + 1 < dis[v][op]){
					dis[v][op] = dis[u][op] + 1 ;
					pq.push({v,dis[v][op],op});
				}
			}
		}
	} 
	cout << min(dis[n][1],dis[n][0]) << endl;
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
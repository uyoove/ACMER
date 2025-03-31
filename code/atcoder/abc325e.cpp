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
const ll inf = 0x3f3f3f3f3f3f3f3fLL;
const int infi = 0x3f3f3f3f;
const int P = 13331;
const int N = 1010;
int n,a,b,c;
int g[N][N];
int dis[N][2],vis[N][2];
struct nodes{
	int u,val,op;
	bool operator<(const nodes &t1)const{
		return t1.val < val;
	}
};
void solve(){
	cin >> n >> a >> b >> c;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			cin >> g[i][j];
		}
	}
	memset(dis,0x3f,sizeof dis);
	memset(vis,0,sizeof vis);
	priority_queue<nodes> q;
	dis[1][0] = 0;
	dis[1][1] = 0;
	q.push({1,0,0});
	q.push({1,0,1});
	while(q.size()){
		auto p = q.top();q.pop();
		int u = p.u,val = p.val,op = p.op;
		if(vis[u][op]) continue;
		vis[u][op] = 1;
		for(int i = 1;i <= n;i++){
			//if(i==u) continue;
			if(op==0){
				if(dis[u][op] + g[u][i]*a < dis[i][op]){
					dis[i][op] = dis[u][op] + g[u][i]*a;
					q.push({i,dis[i][op],0});
				}
				if(dis[u][op] + g[u][i]*b + c < dis[i][1]){
					dis[i][1] = dis[u][op] + g[u][i]*b + c;
					q.push({i,dis[i][1],1});
				}
			}else{
				if(dis[u][op] + g[u][i]*b + c < dis[i][op]){
					dis[i][op] = dis[u][op] + g[u][i]*b + c;
					q.push({i,dis[i][op],1});
				}
			}
		}
	}
	cout << min(dis[n][0],dis[n][1]) << endl;
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
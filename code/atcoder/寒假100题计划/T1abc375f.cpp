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
int dis[400][400];
struct qs
{
	int op,x,y;
};
PII e[N];
int vis[N],val[N];
int ans[N];
void solve(){
	for(int i = 0;i<400;i++){
		for(int j=0;j<400;j++){
			dis[i][j] = inf;
		}
	}
	int n,m,q;
	cin >> n >> m >> q;
	for(int i = 1;i <= n;i++){
		dis[i][i] = 0;
	}
	for(int i = 1;i<=m;i++){
		int x,y,z;
		cin >> x >> y >> z;
		e[i] = {x,y};
		val[i] = z;
	}
	vt<qs> res;
	for(int i = 1;i <= q;i++){
		int op;
		cin >>op;
		if(op==1){
			int x;
			cin >> x;
			res.pb({op,x});
			vis[x] = 1;
		}else{
			int x,y;
			cin >> x >> y;
			res.pb({op,x,y});
		}
	}
	for(int i = 1;i <= m;i++){
		if(!vis[i]){
			dis[e[i].fi][e[i].se] = dis[e[i].se][e[i].fi] = min(dis[e[i].se][e[i].fi],val[i]);
		}
	}
	for(int k = 1;k <= n;k++){
		for(int i = 1;i <= n;i++){
			for(int j = 1;j<=n;j++){
				dis[i][j] = min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	int id = 0;
	for(int i = q - 1;i>=0;i--){
		int op = res[i].op;
		if(op==2){
			int x = res[i].x,y = res[i].y;
			if(dis[x][y] == inf){
				ans[++id] = -1;
				continue;
			}
			ans[++id] = dis[x][y];
		}else{
			int id = res[i].x;
			dis[e[id].fi][e[id].se] = dis[e[id].se][e[id].fi] = min(dis[e[id].se][e[id].fi],val[id]);
			
				for(int i = 1;i <= n;i++){
					for(int j = 1;j<=n;j++){
						dis[i][j] = min(dis[i][j],dis[i][e[id].fi]+dis[e[id].se][j] + val[id]);
						dis[i][j] = min(dis[i][j],dis[i][e[id].se]+dis[e[id].fi][j] + val[id]);
					}
				}
			
		}
	}
	for(int i = id;i >= 1;i--){
		cout << ans[i] << endl;
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
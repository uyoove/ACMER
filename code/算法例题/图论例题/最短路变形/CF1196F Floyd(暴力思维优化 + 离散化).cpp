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
const int N = 1005;
int n,m,k;
int dis[N][N];
struct node{
	int u,v,w;
	bool operator<(const node &t1)const{
		return w < t1.w;
	}
};
vector<node> e;
vector<int> ls;
int gt(int x){return lower_bound(ls.begin(),ls.end(),x) - ls.begin() + 1;};
void solve(){
	for(int i = 1;i < N;i++){
		for(int j = 1; j< N;j++){
			if(i==j) continue;
			dis[i][j] = 1e18;
		}
	}
	cin >> n >> m >> k;
	if(n > 400){
		for(int i = 1;i <= m;i++){
			int u,v,w;
			node n1;
			cin >> u >> v >> w;
			n1 = {u,v,w};
			e.push_back(n1);

		}
		sort(e.begin(),e.end());
		while(e.size() > k) e.pop_back();
		for(int i = 0;i < k;i++){
			ls.push_back(e[i].u);
			ls.push_back(e[i].v);
		}
		sort(ls.begin(),ls.end());
		ls.erase(unique(ls.begin(),ls.end()),ls.end());
		for(int i = 0;i < k;i++){
			dis[gt(e[i].u)][gt(e[i].v)] = e[i].w;
			dis[gt(e[i].v)][gt(e[i].u)] = e[i].w;
		}
		int sz = ls.size();
		for(int k = 1;k <= sz;k++){
			for(int i = 1;i <= sz;i++){
				for(int j = 1;j <= sz;j++){
					//if(i==j || k==j || i==k) continue;
					dis[i][j] = min(dis[i][j],dis[i][k] + dis[k][j]);
				}
			}
		}
		priority_queue<int,vector<int>,greater<int>> q;
		for(int i = 1;i <= sz;i++){
			for(int j = i + 1;j <= sz;j++){
				 q.push(dis[i][j]);
			}
		}
		for(int i = 1;i < k;i++){
			//cout << q.top() <<endl;
			q.pop();
		}

		cout << q.top() << endl;
	}else{
		for(int i = 1;i <= m;i++){
			int u,v,w;
			cin >> u >> v >> w;
			dis[u][v] = dis[v][u] = w;
		}
		for(int k = 1;k <= n;k++){
			for(int i = 1;i <= n;i++){
				for(int j = 1;j <= n;j++){
					//if(i==j || k==j || i==k) continue;
					dis[i][j] = min(dis[i][j],dis[i][k] + dis[k][j]);
				}
			}
		}
		priority_queue<int,vector<int>,greater<int>> q;
		for(int i = 1;i <= n;i++){
			for(int j = i + 1;j <= n;j++){
				 q.push(dis[i][j]);
			}
		}
		for(int i = 1;i < k;i++){
			//cout << q.top() <<endl;
			q.pop();
		}

		cout << q.top() << endl;
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
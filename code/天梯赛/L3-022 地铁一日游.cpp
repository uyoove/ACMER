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
const int N = 210;
int n,m,k;
int a[N];
int dis[N][N];
struct nodes{
	int val,id;
	bool operator<(const nodes &t1)const{
		if(val!=t1.val) return val < t1.val;
		return t1.id < id;
	}
};
map<int,multiset<nodes>> sj[N];
int check[N];
set<int> tmp;
void dfs(int u){
	if(tmp.count(u)) return;
	tmp.insert(u);
	for(auto &[k,mu]:sj[u]){
		for(auto &p:mu){
			dfs(p.id);
		}
	}
}
void solve(){
	cin >> n >> m >> k;
	memset(dis,0x3f,sizeof dis);
	for(int i = 1;i <= m;i++){
		int p;
		vt<int> v;
		while(true){
			cin >> p;
			v.pb(p);
			if(getchar()=='\n'){
				break;
			}
		}
		int pre = v[0];
		check[pre] = 1;
		for(int i = 1;i < v.size();i+=2){
			int d = v[i],u = v[i + 1];
			dis[pre][u] = min(d,dis[pre][u]);
			dis[u][pre] = min(d,dis[u][pre]);
			pre = u;
		}
		check[pre] = 1;
	}
	for(int k = 1;k <= n;k++){
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++){
				dis[i][j] = min(dis[i][k] + dis[k][j],dis[i][j]);
			}
		}
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			if(i==j) continue;
			if(dis[i][j] >= 4557430888798830399) continue;
			int t = (dis[i][j])/k;
			sj[i][t].insert({dis[i][j],j});
		}
		for(auto &it:sj[i]){
			vt<nodes> v;
			for(auto &d:it.se){
				nodes z = *it.se.rbegin();
				int ppp = z.val;
				if(d.val < ppp && !check[d.id]){
					v.pb(d);
				}
			}
			for(auto &p:v) it.se.erase(p);
		}
	}
	int q;
	cin >> q;
	while(q--){
		tmp.clear();
		int u;
		cin >> u;
		dfs(u);
		bool f = 1;
		for(auto &p:tmp){
			if(!f) cout << " " <<p;
			else {
				f = 0;
				cout << p;
			}
		}
		cout << endl;
	}
}

signed main(){
	int times = 1;
	//cin >> times;
	while(times--){
		solve();
	}
	return 0;
}
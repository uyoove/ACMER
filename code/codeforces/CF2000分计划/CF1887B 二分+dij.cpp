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
int n,t;
map<int,vt<PII>> mp;
struct edges{
	int v,ne;
}e[N << 1];
int h[N],idx = 1;
void add(int u,int v){
	e[++idx] = {v,h[u]};
	h[u] = idx;
}
int dis[N],vis[N],a[N];
map<int,vt<int>> id;
void solve(){
	memset(dis,0x3f,sizeof dis);
	cin >> n >> t;
	for(int i = 1;i <= t;i++){
		int p;cin>>p;
		while(p--){
			int u,v;
			cin >> u >> v;
			if(u < v) swap(u,v);
			mp[u].pb({v,i});
			mp[v].pb({u,i});
		}
	}
	int k;
	cin >> k;
	for(int i = 1;i<=k;i++) cin >> a[i],id[a[i]].pb(i);
	dis[1] = 0;
	priority_queue<PII,vt<PII>,greater<PII>> pq;
	pq.push({0,1});
	while(pq.size()){
		auto p = pq.top();pq.pop();
		int u = p.se,w = p.fi;
		if(vis[u]) continue;
		vis[u] = 1;
		for(auto p:mp[u]){
			int v = p.fi,id1 = p.se;
			//out2(u,v);
			auto it = lower_bound(all(id[id1]),w + 1);
			if(it==id[id1].end()) continue;
			if(dis[v] > *it){
				dis[v] = *it;
				pq.push({dis[v],v});
			}
		}
	}
	if(dis[n] > k){
		cout << -1 << endl;
	}else{
		cout << dis[n] << endl;
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
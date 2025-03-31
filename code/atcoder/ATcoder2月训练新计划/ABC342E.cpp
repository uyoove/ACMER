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
int n,m;
struct edges
{
	int v,ne,l,d,k,c;
}e[N << 1];
int h[N],idx = 1;
void add(int u,int v,int l,int d,int k,int c){
	e[++idx] = {v,h[u],l,d,k,c};
	h[u] = idx;
}
int dis[N],vis[N];
void dij(){
	priority_queue<PII> q;
	q.push({inf,n});
	while(q.size()){
		auto p = q.top();q.pop();
		if(vis[p.se]) continue;
		vis[p.se] = 1;
		for(int i = h[p.se];i;i=e[i].ne){
			int v = e[i].v;
			int l = e[i].l,d = e[i].d,k = e[i].k,c = e[i].c;
			int tmp = min(k - 1,(p.fi - c - l)/d);
			//cout << v << " " << tmp << endl;
			if(l > p.fi) continue;
			if(dis[v] < l + (tmp) * d){
				dis[v] = l + tmp * d;
				q.push({dis[v],v});
			}
		}
	}
}
void solve(){
	cin >> n >> m;
	for(int i = 1;i <= m;i++){
		int l,d,k,c,a,b;
		cin >> l >> d >> k >> c >> a >> b;
		add(b,a,l,d,k,c);
	}
	dij();
	for(int i = 1;i < n;i++){
		if(dis[i]==0){
			cout << "Unreachable" <<endl;
			continue;
		}
		cout << dis[i] << endl;
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
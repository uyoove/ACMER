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
const int N = 100005;
int dis[N],vis[N];
int n,m;
string b;
int getit(string s){
	int res = 0;
	for(int i = 1;i < s.size();i++){
		res = res * 2 + s[i] - '0'; 
	}
	return res;
}
struct edges{
	int v,ne,w;
}e[N << 1];
int h[N],idx = 1;
void add(int u,int v,int w){
	e[++idx] = {v,h[u],w};
	h[u] = idx;
}
int s;
int x[N],y[N],val[N];
void solve(){
	//n一共10一共1024个状态,dij转移不会超时
	cin >> n >> m;
	cin >> b;
	b = " " + b;
	s = getit(b);
	idx = 1;
	for(int i = 0;i <= (1 << n);i++){
		h[i] = 0;
		dis[i] = 1000000000000000;
		vis[i] = 0;
	}
	for(int i = 1;i <= m;i++){
		int d;
		string s1,s2;
		cin >> d >> s1 >> s2;
		s1 = " " + s1,s2 = " " + s2;
		val[i] = d,x[i] = getit(s1),y[i] = getit(s2);
	}
	priority_queue<PII,vt<PII>,greater<PII>> q;
	q.push({0,s});
	dis[s] = 0;
	while(q.size()){
		auto p = q.top();q.pop();
		int u = p.se;
		if(vis[u]) continue;
		vis[u] = 1;
		for(int i = 1;i <= m;i++){
			//将健康取反表示不能治疗的位置,不能治疗的位置&原来生病的位置那不就是治完病的状态吗
			int v = (u & (((1 << n)-1)^x[i])) | y[i];
			//cout << u << " " <<i << " " <<v << endl;
			if(dis[v] > dis[u] + val[i]){
				dis[v] = dis[u] + val[i];
				q.push({dis[v],v});
			}
		}
	}
	cout << (dis[0]==1000000000000000 ? -1 : dis[0]) << endl;

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
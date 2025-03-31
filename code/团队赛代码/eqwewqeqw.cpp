//和爸爸一起学编程真好,不过要小学四年级分流考试了,最近没时间写代码了,呜呜呜
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define out(x) cout << #x << '=' << (x) << endl
#define out2(x, y) cout << #x << '=' << (x) << ',' << #y << '=' << (y) << endl 
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
const int N = 50;
int a,b;
int lcm(int a,int b){
	return a*b/__gcd(a,b);
}
struct edgse
{
	int v,ne,w;
}e[N << 1];
int h[N],idx = 1;
void add(int u,int v,int w){
	e[++idx] = {v,h[u],w};
	h[u] = idx;
}
int dis[N],vis[N];
int gt(int x,vt<int> v){
	return lower_bound(all(v),x) - v.begin() + 1;
}
void spfa(vt<int> ls){
	queue<int> q;
	dis[gt(a,ls)] = 0;
	vis[gt(a,ls)] = 1;
	q.push(gt(a,ls));
	while(q.size()){
		int u = q.front();q.pop();
		vis[u] = 0;
		for(int i = h[u];i;i=e[i].ne){
			int v = e[i].v;
			if(dis[u] + e[i].w < dis[v]){
				dis[v] = dis[u] + e[i].w;
				if(!vis[v]) q.push(v),vis[v] = 1;
			}
			
		}
	}
}

void solve(){
	idx = 1;
	cin >> a >> b;
	int res = 0;
	int a1 = a,b1 = b;
	for(int i = 2;i <= sqrt(a);i++){
		if(a%i==0){
			a1 = i;
			break;
		}
	}
	for(int i = 2;i <= sqrt(b);i++){
		if(b%i==0){
			b1 = i;
			break;
		}
	}
	vt<int> v = {a,b,2,a1,b1}; 

	if(__gcd(a,b)!=1) v.pb(__gcd(a,b));
	vt<int> ls = v;
	sort(all(ls));
	ls.erase(unique(all(ls)),ls.end());
	for(auto p:v){
		for(auto q:v){
			if(p!=q) add(gt(p,ls),gt(q,ls),lcm(p,q));
		}
	}
	spfa(ls);
	cout << dis[ls.size()] <<endl;
	for(auto p:v) p = gt(p,ls),h[p] = 0,dis[p] = inf,vis[p] = 0;
}

signed main(){
	for(int i = 1;i < N;i++) dis[i] = inf;
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
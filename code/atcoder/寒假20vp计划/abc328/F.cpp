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
int n,q;
int f[N],d[N];
int fd(int x){
	if(x != f[x]){
		int t = f[x];
		f[x] = fd(f[x]);
		d[x] += d[t];
	}
	return f[x];
}
void mg(int x,int y,int val){
	int u = fd(x),v = fd(y);
	if(u==v) return;
	f[u] = v;
	d[u] = d[y] - d[x] + val;
}
void solve(){
	cin >> n >> q;
	set<int> se;
	for(int i = 1;i <= n;i++) f[i] = i;
	for(int i = 1;i <= q;i++){
		int u,v,w;
		cin >> u >> v >> w;
		if(fd(u) == fd(v)){
			int p = d[u],p2 = -d[v];
			//cout <<i << " "<<  p << " " << p2 << endl;
			if(p+p2==w){
				se.insert(i);
			}
		}else{
			mg(u,v,w);
			se.insert(i);
		}
	}
	for(auto p:se){
		cout << p << " ";
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
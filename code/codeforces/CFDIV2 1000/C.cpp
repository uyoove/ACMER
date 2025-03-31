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
int n;
int dg[N];
int dg2[N];
void solve(){
	cin >> n;
	for(int i = 1;i <= n;i++) dg[i] = 0,dg2[i] = 0;
	vt<PII> e;
	vt<int> ls;
	for(int i = 1;i < n;i++){
		int u,v;
		cin >> u >> v;
		e.pb({u,v});
		dg[u]++;
		dg[v]++;
	}
	if(n==2){
		cout << 0 << endl;
		return;
	}
	for(int i = 1;i <= n;i++){
		ls.pb(dg[i]);
	}
	sort(ls.rbegin(),ls.rend());
	int a = ls[0],b = ls[1];
	int sz1 = 0,sz2 = 0;
	for(int i = 1;i <= n;i++){
		if(dg[i]==a) sz1++;
		if(dg[i]==b) sz2++; 
	}
	for(auto [u,v]:e){
		if(dg[u]==b || dg[u]==a){
			if(dg[u]==b && dg[v]==a){
				dg2[u]++;
				dg2[v]++;
				continue;
			}else if(dg[u]==a && dg[v]==b){
				dg2[u]++;
				dg2[v]++;
			}
		}
		
	}
	int ct = 0;
	for(int i = 1;i <= n;i++){
		if(dg[i]==a){
			if((a!=b && dg2[i] < sz2) || (a == b && dg2[i] <sz2-1)) ct = 1;
		}else if(dg[i]==b){
			if((a!=b && dg2[i] < sz1) || (a == b && dg2[i] <sz1-1)) ct = 1;
		}
		
	}
	if(ct){
		cout << a + b  - 1 << endl;
	}else{
		cout << a + b  - 2 <<endl;
	}
	
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
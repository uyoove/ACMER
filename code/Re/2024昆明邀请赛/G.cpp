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
const int N = 2000005;
int n;
//001 001 011 
//1 0 2
//001 001 011 111 000
//1 0 2 4 3
//001 001 011 111 000 101
//1 0 2 4 3 5
//001 001 011 111 000 101 011
int now = 1;
int vis[N];
void solve(){
	cin >> n;
	if(n==1){
		cout <<"impossible"<<endl;
		return;
	}
	
	if(n==2){
		cout <<"1 0 ";
		cout<<endl;
		return;
	}
	vt<int> res;
	int p = 1;
	bool f = 1;
	for(int i=2;i<n;i++){
		if(vis[i]!=now){
			if((p^i)==0){
				if(i+1>=n){
					cout <<"impossible"<<endl;
					return;
				}
				res.pb(i+1);
				vis[i+1]=now;
				p^=i+1;
			}
			p^=i;
			res.pb(i);
		}
	}
	cout <<"1 0 ";
	for(auto p:res){
		cout << p << " ";
	}
	cout<<endl;
}

signed main(){
	std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
	int times = 1;
	cin >> times;
	while(times--){
		now++;
		solve();
	}
	return 0;
}
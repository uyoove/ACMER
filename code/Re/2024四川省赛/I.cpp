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
const int N = 200005;
int n,x,y;
struct nodes{
	int r,c;
	bool operator<(const nodes &t1)const{
		if(t1.r==r) return t1.c < c;
		return t1.r < r;
	}
};
struct ns{
	int x1,y1,x2,y2;
};
bool check(int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4){
	if(x2 <= x3 || y2 <= y3 || x4 <= x1 || y4 <= y1) return true;
	return false;
}
void solve(){
	cin >> n >> x >> y;
	vt<ns> q;
	set<int> mx,my;
	mx.insert(0);
	my.insert(0);
	for(int i = 1;i <= n;i++){
		int r,c;
		cin >> r >> c;
		bool f1 = 0;
		for(auto lx:mx){
			for(auto ly:my){
				int f = 1;
				if(lx + r > x || ly + c > y) continue;
				for(auto [x1,y1,x2,y2]:q){
					if(!check(x1,y1,x2,y2,lx,ly,lx+r,ly+c)){
						f = 0;
						break;
					}
				}
				if(f){
					f1 = 1;
					cout << lx << " " << ly <<endl;
					q.pb({lx,ly,lx+r,ly+c});
					mx.insert(lx + r);
					my.insert(ly + c);
					break;
				}
			}
			if(f1) break;
		}
		if(!f1){
			cout << -1 << endl;
		}	
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
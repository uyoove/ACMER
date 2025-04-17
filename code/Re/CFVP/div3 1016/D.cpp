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
int n,q;
void solve(){
	cin >> n >> q;
	while(q--){
		string op;
		cin >> op;
		if(op=="->"){
			int x,y;
			cin >> x >> y;
			int res = 1;
			for(int i = n - 1;i >= 0;i--){
				if(x > powl(2,i) && y >powl(2,i)){
					x-=powl(2,i),y-=powl(2,i);
					res+=powl(2,2*(i));
				}else if(x > pow(2,i)){
					x-=powl(2,i);
					res+=powl(2,2*(i))*2;

				}else if(y > powl(2,i)){
					y-=powl(2,i);
					res+=powl(2,2*(i))*3;
				}
			}
			cout << res << endl;
		}else{
			int d;
			cin >> d;
			int m = d%4;
			int r = 1, c = 1;
			for(int i = n - 1;i >= 0;i--){
				int t = 0;
				for(int j = 1;j <= 4;j++){
					if(powl(2,i * 2) * j >= d){
						t = j;
						break;
					}
				}
				if(t==2){
					r += powl(2,i);
					c += powl(2,i) ;
				}
				if(t==3){
					r += powl(2,i);
				}
				if(t==4){
					c += powl(2,i);
				}
				
				d -= powl(2,i*2) * (t - 1);
				
			}
			cout <<r <<  " " << c << endl;
		}
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
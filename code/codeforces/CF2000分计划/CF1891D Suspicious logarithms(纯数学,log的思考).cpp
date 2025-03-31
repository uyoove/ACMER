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
const int P = 1e9+7;
const int N = 200005;
int p2[70];
void init(){
	p2[0] = 1;
	for(int i =1;i<=60;i++) p2[i] = p2[i - 1]*2;
}
int ls(int x1,int y1,int x2,int y2,int x3,int y3){
	return max(0ll,min(min(y1,y2),y3) - max(max(x1,x2),x3) + 1);
}
void solve(){
	ll l,r;
	cin >> l >> r;
	__int128 fx;
	int ans = 0;
	int L,R;
	//枚举f
	for(int i = 1;i <= 60;i++){
		fx = i;
		for(int j = 1;j <= 10;j++){ //枚举g
			L = fx,fx = min((__int128)fx * i,(__int128)1e18+1),R = fx - 1;
			ans += j * ls(L,R,l,r,p2[i],p2[i + 1]-1)%P; //算差值贡献
			ans%=P;
			//if(fx > p2[i + 1] - 1 || fx > r) break;
		}
	}
	cout << ans << endl;
}

signed main(){
	std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
	ll times = 1;
	init();
	cin >> times;
	while(times--){
		solve();
	}
	return 0;
}
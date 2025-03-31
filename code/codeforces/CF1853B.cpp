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
const ll inf = 0x3f3f3f3f3f3f3f3fLL;
const int infi = 0x3f3f3f3f;
const int P = 13331;
const int N = 200005;
int tb[100][2];
void solve(){
	int n,k;
	cin >> n >> k;
	int p1 = 0,p2 = 1; 
	for(int i = 3;i <= k;i++){
		int p3 = p1 + p2;
		p1 = p2;
		p2 = p3;
		//cout <<p3 << endl;
		 if(p3 > n){
		 	cout << 0 << endl;
		 	return;
		}
	}
	int cnt = 0;
	for(int i = 0;i <= n;i++){
		int p = i*tb[k][0];
		//out2(i,p);
		if(p > n) break;
		int t = n - p;
		if(t%tb[k][1]==0 && t/tb[k][1] >= i) cnt++; 
	}

	
	cout << cnt << endl;

}

signed main(){
	std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
	int times = 1;
	cin >> times;
	tb[3][0] = 1;
	tb[3][1] = 1;
	tb[2][0] = 0;
	tb[2][1] = 1;
	for(int i = 4;i < 50;i++){
		tb[i][0] = tb[i - 1][0] + tb[i - 2][0];
		tb[i][1] = tb[i - 1][1] + tb[i- 2][1];
	}
	while(times--){
		solve();
	}
	return 0;
}
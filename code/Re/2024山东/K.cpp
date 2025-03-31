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
int n;
int ch[56][56];
void solve(){
	cin >> n;
	cout << "Yes" << endl;
	for(int i = 1;i <= 2;i++){
		for(int j = 1;j <= 2;j++){
			ch[i][j] = (i - 1)*2 + j;
		}
	}
	int cnt = 5;
	for(int i = 3;i <= n;i++){
		for(int j = 1;j <= n;j++){
			ch[i][j] = cnt;
		}
		cnt++;
		if(cnt >= 2*n) cnt = 2*n;
	}
	
	for(int j = 3;j <= n;j++){
		for(int i = 1;i <= 2;i++){
		ch[i][j] = cnt;
		}
		cnt++;
		if(cnt >= 2*n) cnt = 2*n;
	}
		
	
	// for(int i = 3;i <= n;i++){
	// 	for(int j =3;j <= n;j++){
	// 		ch[i][j] = 4;
	// 	}
	// }

	for(int i = 1;i <= n;i++){
		for(int j = 1;j<=n;j++){
			cout << ch[i][j] << " ";
		}
		cout << endl;
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
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
const int N = 4000005;
int n;
int a[N],f[N * 2];
int s = (1 << 22) - 1;
//该题求一下反集即可
void solve(){
	cin >> n;
	memset(f,-1,sizeof f);
	for(int i = 1;i <= n;i++) cin >> a[i],f[a[i]] = a[i];
	for(int i = 0;i < 22;i++){
		for(int j = 0;j <= s;j++){
			if(1 & (j >> i)) f[j] = max(f[j^(1 << i)],f[j]);
		}
	}
	for(int i = 1;i <= n;i++){
		cout << f[s & (~a[i])] << " ";
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
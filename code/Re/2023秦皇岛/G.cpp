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
int n,m;
int a[N],b[N];
void solve(){
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	for(int j = 1;j <= m;j++) cin >> b[j];
	int i = 1,j = 1;
	int res = 0;
	int cur = a[1] + b[1];
	while(i < n || j < m){
		if(i>=n){
			res += abs(a[n] + b[j + 1] - cur);
			cur = a[n] + b[j + 1];
			j++;
		}else if(j >= m){
			res += abs(a[i + 1] + b[m] - cur);
			cur = a[i + 1] + b[m];
			i++;
		}else{
			if(abs(a[i + 1] + b[j] - cur) > abs(a[i] + b[j + 1] - cur)){
				res += abs(a[i + 1] + b[j] - cur);
				cur = a[i + 1] + b[j];
				i++;
			}else{
				res += abs(a[i] + b[j + 1] - cur);
				cur = a[i] + b[j + 1];
				j++;
			}
		}
	}
	cout << res << endl;
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
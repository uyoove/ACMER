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
int n,m,q;
int a[N],b[N][3];
int f[N];
int sz;
int check(int su){
	int l = 1,r = sz,ans1 = inf;
	while(l<=r){
		int mid=l+r>>1;
		if(f[mid]<=su){
			ans1 = f[mid];
			l = mid + 1;
		}else{
			r = mid - 1;
		}
	}
	l = 1,r = sz;
	int ans2 = inf;
	while(l<=r){
		int mid=l+r>>1;
		if(f[mid]>=su){
			ans2 = f[mid];
			r = mid - 1;
		}else{
			l = mid + 1;
		}
	}
	return min(abs(ans1 - su),abs(ans2 - su));
}
void solve(){
	cin >> n >> m >> q;
	int su = 0;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		if(i%2) su+=a[i];
		else su-=a[i];
	}
	for(int i = 1;i <= m;i++) {
		cin >> b[i][0];
		b[i][1] = b[i - 1][1];
		b[i][2] = b[i - 1][2];
		if(i%2==0) b[i][1] += b[i][0];
		else b[i][2] += b[i][0];
	}
	for(int i = 1; i + n - 1 <= m;i++){
		if(i%2==0) f[i] = b[i + n - 1][1] - b[i - 1][1] - b[i + n - 1][2] + b[i - 1][2];
		else f[i] = b[i + n - 1][2] - b[i - 1][2] - b[i + n - 1][1] + b[i - 1][1];
	}
	sz = m - n + 1;
	sort(f +1,f +1 +sz);
	cout << check(su) << endl;
	while(q--){
		int l,r,x;
		cin >> l >> r >>x;
		if((r - l +1)%2){
			if(l%2==1){
				su+=x;
			}else{
				su-=x;
			}
			cout << check(su) << endl; 
		}else{
			cout << check(su) << endl; 
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
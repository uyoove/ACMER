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
int n,k,m,c,d;
int a[N];
int d1[N];
bool check(int x){
	memset(d1,0,sizeof d1);
	for(int i = 1;i <= n;i++){
		if(a[i]>=x){
			d1[1]++;
		}else{
			int l=max(1ll,i-m+1);
			if(a[i] + c + (i-l) * d < x) continue;
			int j = 0;
			int len =x - (a[i] + c);
			if(d==0) j = 0;
			else j = (len-1)/d + 1;
			j=max(j,0ll);
			int r = i - j;
			d1[l]++;
			d1[r + 1]--;
		}
	}
	for(int i  = 1;i<=n;i++){
		d1[i]+=d1[i - 1];
		if(d1[i] >= k) return true;
	}
	return false;
}
void solve(){
	cin >> n >> k >> m >> c >> d;
	for(int i = 1;i <= n;i++) cin >> a[i];
	int l = 0,r = 1e18,ans = -1;
	while(l<=r){
		int mid = l + r >> 1;
		if(check(mid)){
			ans = mid;
			l = mid + 1;
		}else{
			r = mid - 1;
		}
	}
	cout << ans <<endl;

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
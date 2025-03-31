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
int a[N],b[N];
int n,m;
int x = 0;
int c[N];
bool check(int m){
	for(int i = 1;i <= n;i++) c[i] = a[i];
	c[1] = m;
	sort(c + 1,c + 1 + n);
	int l = 1,r = n + 1,ans = n + 1;
	while(l<=r){
		int mid = l + r >> 1;
		bool f = true;
		for(int i=mid;i <= n;i++){
			if(b[i] <= c[i - mid+1]) f=false;
		}
		
		if(!f){
			l = mid + 1;
		}else{
			r = mid - 1;
			ans = mid;
		}
	}
	ans-=1;
	return ans==x;
}
void solve(){
	cin >> n >> m;
	a[1] = 1;
	for(int i = 2;i <= n;i++) cin >> a[i];
	for(int j = 1;j <= n;j++) cin >> b[j];
	sort(a + 1,a + 1 + n);
	sort(b + 1,b + 1 + n);
	int l = 1,r = n + 1,ans = n + 1;
	while(l<=r){
		int mid = l + r >> 1;
		bool f = true;
		for(int i=mid;i <= n;i++){
			if(b[i] <= a[i - mid+1]) f=false;
		}
		
		if(!f){
			l = mid + 1;
		}else{
			r = mid - 1;
			ans = mid;
		}
	}
	ans -= 1;
	l = 1, r = m;
	x= ans;
	int num = 1;
	while(l<=r){
		int mid= (l+r)>>1;
		if(check(mid)){
			num = mid;
			l = mid + 1;
		}else{
			r = mid - 1;
		}
	}
	cout << num*(x) + (x + 1) * (m - num) << endl;

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
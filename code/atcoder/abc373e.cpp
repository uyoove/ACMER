//和爸爸一起学编程真好,不过要小学四年级分流考试了,最近没时间写代码了,呜呜呜
#include<bits/stdc++.h>
using namespace std;
#define out(x) cout << #x << '=' << (x) << endl
#define out3(x, y,z) cout << #x << '=' << (x) << ',' << #y << '=' << (y) << ',' << #z << '=' << (z)<< endl 
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
int n,m,k;
int su = 0;
int sy;
int a[N],b[N],pre[N];
int ma = 0;
bool check(int x,int val,int xh){
	int big = n - (upper_bound(b + 1,b + 1 + n,x) - b - 1);
	if(big >= m) return false;
	int ss = m - big;
	int p = upper_bound(b + 1,b + 1 + n,x) - b - 1;
	int tp = (p - ss + 1);
	bool f = true;
	if(b[tp] < val) f = false,tp--;
	if(b[tp]==val){
		if(b[tp - 1] != val) f = false,tp--;
	}
	if(tp <= 0) return true;
	int d = (x+1) * (ss) - (pre[p] - pre[tp - 1]);
	//out3(x,d,tp);
	//out3(p,pre[p]-pre[tp-1],tp);
	if(!f){
		d+=val;
	} 
	return d > sy-xh;
}
void solve(){
	cin >> n >>m >>k;
	for(int i = 1;i<=n;i++) cin >> a[i],b[i] = a[i],su+=a[i];
	sort(b + 1,b + 1 + n);
	for(int i = 1;i <= n;i++) pre[i] = pre[i - 1] + b[i];
	sy = k - su;
	for(int i = 1;i <=n;i++){
		int l = 0,r = sy, ans = -1;
		while(l <= r){
			int mid = l + r >>1;
			if(check(a[i]+mid,a[i],mid)){
				r = mid - 1;
				ans = mid;
			}else{
				l = mid + 1;
			}
		}
		cout << ans << " ";
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
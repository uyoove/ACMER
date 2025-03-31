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
int a,b;
bool check(int x){
	//out(x);
	int len = x/2;
	int js = len,os = len;
	js+=(x%2==1);
	int sj = js * (1 + 1 + (js - 1) * 2)/2;
	int so = os * (2 + 2 + (os - 1) * 2)/2;
	
	sj*=2;
	so*=2;
	if(x%2==0) sj+=x;
	else so+=x;
	//cout << x << " " << so << " " << sj << endl;
	if(sj < so) swap(sj,so);
	if(a < sj || b < so) return false;
	return true;
}
void solve(){
	cin >> a >> b;
	//cout << check(2) << endl;
	if(a==2&&b==2){
		cout << 3 << endl;
		return;
	}
	if(b > a) swap(a,b);
	int l = 1,r = 1e9,ans = -1;
	//设上半高度为mid;
	while(l <= r){
		int mid = l + r >> 1;
		if(check(mid)){
			l = mid + 1;
			ans = mid;
		}else{
			r = mid - 1;
		}
	}
	cout << ans*2 + 1 << endl;

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
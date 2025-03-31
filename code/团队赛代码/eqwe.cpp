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
int a[N];
int tp = 0;
int ans[N];
void solve(){
	int n;
	cin >> n;
	for(int i = 1;i <=  n;i++){
		cin >> a[i];
	}
	sort(a + 1,a+1+n);
	int op = 0;
	int l = 1,r = n;
	for(int i = n;i>=1;i--){
		if(op%2){
			ans[l] = a[i];
			l++;
		}else{
			ans[r] = a[i];
			r--;
		}
		op++;
	}
	int mi = 0;
	for(int i = 2;i <= n;i++) mi=max(mi,abs(ans[i]-ans[i-1]));
	mi=max(mi,abs(ans[n] - ans[1]));
	cout << mi << endl;	


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
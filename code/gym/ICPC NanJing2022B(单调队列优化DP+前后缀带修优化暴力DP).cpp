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
const ll inf = 1e18;
const int infi = 0x3f3f3f3f;
const int P = 13331;
const int N = 5e5+10;
int a[N],f[N],s[N],h[N];
string xy;
int n,k;
void dp(int f[]){
	deque<int> dq;
	dq.push_back(0);
	f[0] = 0;
	for(int i = 1;i <= n + 1;i++){
		while(dq.front() < i - k) dq.pop_front();
		f[i] = a[i] + f[dq.front()];
		if(xy[i]=='1') dq.clear();
		while(dq.size() && f[dq.back()] >= f[i]) dq.pop_back();
		dq.push_back(i);
	}
}
int dp2(int p,int x){
	int tp = a[p];
	a[p] = x;
	deque<int> dq;
	int res = inf;
	for(int i = k;i > 0;i--){
		if(p - i >=0){
			h[p - i] = f[p - i];
			if(xy[p - i]=='1') dq.clear();
			while(dq.size() && f[dq.back()] >= f[p - i]) dq.pop_back();
			dq.push_back(p - i);
		}
		
	}
	for(int i = p;i <= min(p + k-1,n+1);i++){
		while(dq.front() < i - k) dq.pop_front();
		h[i] = a[i] + h[dq.front()];
		res=min(res,h[i] + s[i]);
		if(xy[i]=='1') dq.clear();
		while(dq.size() && f[dq.back()] >= h[i]) dq.pop_back();
		dq.push_back(i);
	}
	a[p] = tp;
	return res;
}
void solve(){
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	a[n+1]=0;
	cin >> xy;
	xy = " " + xy;
	dp(f);
	reverse(xy.begin()+1,xy.end());
	reverse(a+1,a+n+1);
	dp(s);
	reverse(xy.begin()+1,xy.end());
	reverse(a+1,a+n+1);
	reverse(s,s+n+2);
	for(int i = 1;i<=n;i++) s[i]-=a[i]; //后缀但不包含
	int q;
	cin>>q;
	while(q--){
		int p,x;
		cin>>p>>x;
		cout << dp2(p,x) << endl;
	}
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
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
int n;
int a[N],b[N];
int tr[N];
void add(int k,int val){
	for(int i = k;i < N;i+=(i&-i)) tr[i]=max(val,tr[i]);
}
int query(int k){
	int res = 0;
	for(int i = k;i > 0;i-=(i&-i)) res=max(tr[i],res);
	return res;
}
void solve(){
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> a[i],tr[i] = 0;
	if(n==1){
		cout << 0 << endl;
		return;
	}	
	for(int i = 1;i < n;i++) b[i] = min(a[i],a[i + 1]);
	int mx = 0;
	for(int i = 1;i < n;i++){
		int d = query(b[i]) + 1;
		mx = max(mx,d);
		add(b[i],d);
	}	

	cout << mx << endl;
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
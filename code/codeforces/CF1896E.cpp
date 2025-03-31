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
const int N = 2000005;
//破环成链,二维偏序
int tr[N];
int n;
int lb(int x){return  x&-x;}
void add(int k,int v){
	for(int i = k;i <= 2*n;i+=lb(i)) tr[i]+=v;
}
int query(int k){
	int res = 0;
	for(int i = k;i > 0;i-=lb(i)){
		res+=tr[i];
	}
	return res;
}

int a[N],r[N],ans[N];
void solve(){
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		a[i + n] = a[i];
		ans[i] = 0;
		r[i] = inf;
	}
	for(int i = 1;i<=n;i++){
		if(a[i] < i){
			r[i] = a[i] + n;
			r[i + n] = 2e6+3;
		}else{
			r[i] = a[i];
			r[i + n] = a[i] + n; 
		}
	}

	for(int i = 2*n;i>=1;i--){
		if(i <= n){
			ans[a[i]] = r[i] - i - query(r[i]);
		}
		add(r[i],1);
	}

	for(int i = 1;i <= n;i++){
		cout << ans[i] << " ";
	}
	for(int i = 2*n;i>=1;i--){
		add(r[i],-1);
	}
	cout << endl;
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
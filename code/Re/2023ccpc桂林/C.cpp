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
const int mod = 998244353;
struct Lb{
	int lb[61];
	int rank; //多少个线性基,线性基的大小
	void clear(){
		rank = 0;
		for(int i = 0;i <= 60;i++) lb[i] = 0;
	} 
	bool insert(int x){
		for(int i = 60;i>=0;i--){
			if(x>>i&1){
				if(lb[i]==0){
					lb[i]=x;
					rank++;
					return 1; //插入成功
				}
				x^=lb[i];
			}
		}
		return false;
	}
}b[N];
//只有两种可能,一种是总异或为序列的max或者0;
int pw[N];
int n;
int cnt[N],a[N];
int sz[N]; //第i个数有多少个约数 
void solve(){
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		cnt[a[i]]++;
	}
	for(int i = 1;i <= n;i++){
		if(cnt[i]){
			for(int j = 0;i*j <= n;j++){
				sz[i*j]+=cnt[i];
				b[i*j].insert(i);
			}
		}
	}
	int ans = pw[n - b[0].rank] - 1; //线性基外元素随便选,但空集不行所以-1
	for(int i = 1; i <= n;i++){
		if(cnt[i]){
			ans = (ans + pw[sz[i] - b[i].rank]) % mod; //i为lcm那么线性基把线性基rank全选,sz是i的约数集合大小,其他可以任意,所以是 2^(sz-rank)
		}
	}
	for(int i =0;i<=n;i++) b[i].clear(),sz[i]=0,cnt[i]=0;
	ans = (ans + mod)%mod;
	cout << ans  << endl; 

}

signed main(){
	std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
	int times = 1;
	cin >> times;
	pw[0] = 1;
	for(int i = 1;i < N;i++) pw[i] = pw[i - 1] * 2%mod;
	while(times--){
		solve();
	}
	return 0;
}
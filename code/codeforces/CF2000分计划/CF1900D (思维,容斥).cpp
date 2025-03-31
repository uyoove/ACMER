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
vector<int> g[N]; //对每个数提出因子
int a[N];
int num[N];//表示每个因数个数
int cnt[N]; //将每个公因子,算出贡献,在后面容斥后才是最大公因子贡献.在前面一直算的是公因子的贡献
void solve(){
	memset(cnt,0,sizeof cnt);
	memset(num,0,sizeof num);
	int n;
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	for(int i = 1;i <= n;i++){
		for(auto j:g[a[i]]){
			cnt[j] += (n - i) * num[j]; //后面的数都可与前面两两匹配的因数匹配
			num[j]++; 
		}
	}
	//从大到小容斥 -> 将公因数转换为最大公因数,转化过程,就是把公因数的倍数的贡献全部容斥掉
	for(int i = a[n];i >= 1;i--){
		for(int j = 2;j * i <= a[n];j++){
			cnt[i] -= cnt[j * i];
		}
	}
	int ans = 0;
	for(int i = 1;i<=a[n];i++) ans+=i*cnt[i]; //最后贡献累计
	cout << ans << endl;

}

signed main(){
	std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
	int times = 1;
	for(int i = 1;i <= 1e5;i++){
		for(int j = i;j <= 1e5;j+=i){
			g[j].pb(i);
		}
	}
	cin >> times;
	while(times--){
		solve();
	}
	return 0;
}
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
const int N = 1000005;
int f[N][2],a[N],n;
int s = (1 << 18) - 1;
//求对于每个k (1<= k <= 2^n-1)找出最大的a[i]+a[j]
//i,j要满足 (i | j) <= k,(i!=j)
//思路:i和j肯定是k以内某个数的子集 可能11011 分成 11010 和 11000 这样子的两个数
//所以我们对sosdp求某个子集下的最大值和次大值即可
void solve(){
	cin >> n;
	for(int i = 0;i < (1 << n);i++) cin >> a[i],f[i][0] = a[i];
	for(int i = 0;i < n;i++){
		for(int j = 0;j <= s;j++){
			if(j & (1 << i)){
				int b[4] = {f[j][0],f[j][1],f[j^(1<<i)][0],f[j^(1<<i)][1]};
				sort(b,b+4);
				f[j][0] = b[3];
				f[j][1] = b[2];
			}
		}
	}
	int mx = 0; //循环找最大的 <=k的
	for(int i = 1;i < (1 << n);i++){
		mx = max(mx,f[i][0] + f[i][1]);
		cout << mx << endl;
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
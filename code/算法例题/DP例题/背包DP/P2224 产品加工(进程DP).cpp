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
const int N = 60005;
int n;
int t1[N],t2[N],t3[N];
int f[N]; //dp[i][j] 表示前i个物品a消耗j的时长,b的最小消耗时长
void solve(){
	int up = 0,down = 0; //因为时间是递增的所以不断提高下界优化复杂度
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> t1[i] >> t2[i] >> t3[i];
		up += max(t1[i],max(t2[i],t3[i]));
	}
	memset(f,0x3f,sizeof f);
	f[0] = 0;
	for(int i = 1;i <= n;i++){
		for(int j = up;j>=down;j--){
			int tp = f[j]; //初始化前存一下原来的值，但是只有t2能用,用来防止同层影响转移
			f[j] = 0x3f3f3f3f; //相当于每次初始化
			if(t1[i] > 0 && j - t1[i] >= 0){
				f[j] = min(f[j],f[j - t1[i]]); //a做
			}
			if(t3[i] > 0 && j - t3[i] >= 0){
				f[j] = min(f[j],f[j - t3[i]] + t3[i]); //ab一起做
			}
			if(t2[i] > 0){
				f[j] = min(f[j],tp + t2[i]); //b做
			}
			
		}
		while(f[down] >= 1e9) down++;
	}
	int mx = 1e9 + 7;
	for(int i = down;i<=up;i++){
		mx=min(mx,max(i,f[i]));
	}
	cout << mx << endl;
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
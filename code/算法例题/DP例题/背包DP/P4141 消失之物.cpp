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
int n,m;
int w[N];
//回退背包
int f[N][2]; //f[N][0] 表示选第i个背包容量为j的方案数
			//f[N][1] 表示不选第i个背包容量为j的方案数
			//那么f[j][1] =f[j][0] -  f[j - v[i]][1]; //表示上一个容量没选过i但是这个容量选了i,那么我就要变成当然容量选了j的-上一次没选j的
void solve(){
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> w[i];
	}
	f[0][0] = 1,f[0][1] = 1;
	for(int i = 1;i <= n;i++){
		for(int j = m;j>=w[i];j--){
			f[j][0] += f[j - w[i]][0];
			f[j][0]%=10;
		}
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			if(j < w[i]){
				f[j][1] = f[j][0]%10;
			}else{
				//总方案数-上一个不选i的方案数=这一次不选i的方案数  
				f[j][1] = (f[j][0] - f[j - w[i]][1] + 100)%10;
			}
			cout << f[j][1];
		}
		cout << endl;
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
//最后一舞
#include<bits/stdc++.h>
using namespace std;
#define out(x) cout << #x << '=' << (x) << endl
#define out2(x, y) cout << #x << '=' << (x) << ',' << #y << '=' << (y) << endl 
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
const int N = 500000;
const int SZ = 710;
ll f[SZ][SZ]; //代表下标模i结果为j的总和 ,sqrt以下用f表
ll a[N + 10];
void solve(){
	int q;
	q=read();
	int tmp = sqrt(N);
	int op,x,y;
	while(q--){
		op=read(),x=read(),y =read();
		if(op==1){
			for(int i = 1;i<=tmp;i++){
				f[i][x%i]+=y;
			}
			a[x]+=y;
		}else{
			if(x <= tmp) printf("%lld\n", f[x][y]);
			else{
				ll res = 0;
				for(int i = y;i <= N;i+=x) res+=a[i];
				printf("%lld\n", res);
			}
		}
	}

}

signed main(){
	int times = 1;
	//cin >> times;
	while(times--){
		solve();
	}
	return 0;
}
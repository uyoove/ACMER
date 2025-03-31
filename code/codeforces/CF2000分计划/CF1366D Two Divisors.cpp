//和爸爸一起学编程真好,不过要小学四年级分流考试了,最近没时间写代码了,呜呜呜
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
const int N = 10000005;
int a[N],b[N],c[N];
int prm[N];
void getprm(){
	for(int i = 2;i<N;i++){
		if(prm[i]==0) prm[++prm[0]] = i;
		for(int j = 1;j <= prm[0] && prm[j]*i < N;j++){
			prm[i*prm[j]] = -1;
			if(i%prm[j]==0) break;
		}
	}
}
void solve(){
	int n;
	cin >> n;
	getprm();
	memset(b,-1,sizeof b);
	memset(c,-1,sizeof c);
	for(int i = 1;i <= n;i++){
		int t;
		cin >> t;
		int res = 1;
		for(int j = 1;j < N && prm[j]*prm[j] <= t;j++){
			if(t%prm[j]==0){
				while(t%prm[j]==0) t/=prm[j],res*=prm[j];
				break;
			}
		}
		if(res!=1 && t!=1){
			b[i] = res;
			c[i] = t;
		}
	}
	for(int i = 1;i<=n;i++){
		cout << b[i] << " ";
	}
	cout << endl;
	for(int i = 1;i<=n;i++){
		cout << c[i] << " ";
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
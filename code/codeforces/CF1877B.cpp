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
int a[N],b[N];
PII c[N];
void solve(){
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	for(int j = 1;j <= n;j++) cin >> b[j],c[j]={b[j],a[j]};
	sort(c+1,c+1+n);
	int pp = 0;
	int res = 0;
	int dd = 0;
	for(int i = 1; i <= n;i++){
		if(c[i].fi > m) break;
		if(dd==0){
			pp++;
			res+=m;
			if(pp>=n) {
				cout << res <<endl;
				return;
			}
			dd = 1;
		}
		dd--;	
		res += c[i].fi * min(n - pp,c[i].se);
		pp+=min(n - pp,c[i].se);
		dd+=min(n - pp,c[i].se);
		if(pp>=n) {
			cout << res <<endl;
			return;
		}
	}
	if(pp < n){
		int sy = n - pp;
		res+=sy*m;
		cout << res <<endl;
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
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
int n,p;
int k[N],b[N];
const int MOD = 1e9+7;
const int MX = 1e6 + 7;
struct cmp{
	bool operator()(int a1,int b1)const{
		return a1 > b1;
	}
};
int ksm(int x,int n){
	int res = 1;
	for(;n > 0;n>>=1,x=x*x%MOD) if(n&1) res = res*x%MOD;
	return res;
}

void solve(){
	map<int,int,cmp> h;
	cin >> n >> p;
	for(int i = 1;i <= n;i++){
		cin >> k[i];
		h[k[i]]++;
	}
	if(p==1){
		cout << (n&1) << endl;
		return;
	}
	int a = 0,b = 0; //a为大数组,b为小数组
	bool f = 0; //判断是否找到一个大数无法构造,找到则一直1往小集合加数字即可
	//一个k由p个k-1构成
	for(auto [k,cnt]:h){
 		int v = ksm(p,k);
 		if(f){
 			b = b + v*cnt%MOD;
 			b%=MOD;
 			continue;
 		}
 		if(cnt%2){
 			int need = 1;
 			for(int i = k - 1;i >= 0;i--){
 				need*=p;
 				if(need > MX) break; //剪枝,无论如何都不行了,之后的,使该步骤时间复杂度缩减至log
 				if(!h.count(i)) continue;
 				if(h[i] >= need){
 					need = 0;
 					break;
 				}
 				need -= h[i];
 			}
 			if(need==0){
 				int need = 1;
	 			for(int i = k - 1;i >= 0;i--){
	 				need*=p;
	 				if(need > MX) break; //剪枝,无论如何都不行了,之后的,使该步骤时间复杂度缩减至log
	 				if(!h.count(i)) continue;
	 				if(h[i] >= need){
	 					h[i]-=need;
	 					need = 0;
	 					break;
	 				}
	 				need -= h[i];
	 				h[i]=0;
	 			}
	 			a = a + v*(cnt/2 + 1)%MOD;
	 			a%=MOD;
 				b = b + v*(cnt/2 + 1)%MOD;
 				b%=MOD;
 			}else{
 				f = 1;
 				a = a + v*(cnt/2 + 1)%MOD;
	 			a%=MOD;
 				b = b + v*(cnt/2)%MOD;
 				b%=MOD;
 			}
 		}else{
 			a = a + v*(cnt/2)%MOD;
 			a%=MOD;
 			b = b + v*(cnt/2)%MOD;
 			b%=MOD;
 		}
	}

	int res = ((a - b)%MOD + MOD)%MOD;
	cout << res << endl; 
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
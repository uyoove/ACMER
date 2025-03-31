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
const int N = 1000005;
int prm[N];
void get_prim(){
	for(int i = 2;i < N;i++){
		if(prm[i]==0) prm[++prm[0]] = i;
		for(int j = 1;j <= prm[0] && prm[j] * i < N;j++){
			prm[i * prm[j]] = -1;
			if(i%prm[j]==0) break;
		}
	}
}
int ksm(int x,int n,int mod){
	int res = 1;
	while(n){
		if(n&1) res = res * x % mod;
		x = x * x %mod;
		n >>= 1;
	}
	return res;
}
void solve(){
	int n,q;
	cin >> n >> q;
	map<int,int> h,h2;
	int x = n;
	for(int i = 1;i <= x;i++){
		while(x%prm[i]==0) x/=prm[i],h[prm[i]]++;
	}
	if(x > 1) h[x]++;
	h2 = h;
	while(q--){
		int op;
		cin >> op;
		if(op==2) h = h2;
		else{
			int x;
			cin >> x;
			for(int i = 1;i <= x;i++){
				while(x%prm[i]==0) x/=prm[i],h[prm[i]]++;

			}

			if(x > 1) h[x]++;
			int dn = 1,curn = 1; //ans为d(n),mod为当前的n,dn可以为多个质数累乘,排列组合
			for(auto p:h) dn*=(p.se + 1); //+1是因为可以选或者不选
			for(auto p:h) curn*=ksm(p.fi,p.se,dn),curn%=dn;
			if(curn%dn==0){
				cout << "Yes" << endl; //如果ys dn一定是n的因数
			} else{
				cout << "No" << endl;
			}
		}
	}

}

signed main(){
	get_prim();
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
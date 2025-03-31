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
//因为不管哪个口袋,都会有第一组卡排中的一个元素
//我们固定第一组第一个为a口袋,第二组第二个为b口袋
//那么公约数就在这个卡牌的约数中
//枚举约数,看看在一组中能不能完成对a1和b1的约数同时都是因数
int n;
vt<int> v1,v2;
int a[N],b[N];
int res = 0;
int lcm(int a,int b){
	return a*b/__gcd(a,b);
}
void solve(){
	cin >> n;
	int a1,b1;
	cin >> a1 >> b1;
	for(int i = 1;i < n;i++){
		cin >> a[i] >> b[i];
	} 
	for(int i = 1;i * i <= a1;i++){
		if(a1%i==0){
			v1.pb(i);
			v1.pb(a1/i);
		}
	}
	for(int i = 1;i * i <= b1;i++){
		if(b1%i==0){
			v2.pb(i);
			v2.pb(b1/i);
		}
	}
	int res = 0;
	for(auto i:v1){
		for(auto j:v2){
			bool f = true;
			for(int x = 1;x < n;x++){
				if((a[x]%i!=0 || b[x]%j!=0) && (a[x]%j!=0 || b[x]%i!=0)){
					f = false; //不管交不交换换都不行,那么就退出
					break;
				}
			}
			if(f){
				res = max(res,lcm(i,j));
			}
		}
	}
	cout << res << endl;
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
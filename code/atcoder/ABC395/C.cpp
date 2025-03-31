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
int n,q;
int f[N];
vt<int> p[N]; 
int t[N]; //笼子原先编号
int z[N]; //这个笼子现在表示谁
void solve(){
	cin >> n >> q;
	for(int i = 1;i <= n;i++){
		f[i] = i;
		t[i] = i;
		z[i] = i;
	}
	while(q--){
		int op;
		cin >> op;
		if(op==1){
			int a,b;
			cin >>a  >> b;
			f[a] = z[b];
		}else if(op==2){
			int a,b;
			cin >>a >> b;
			t[z[a]] = b;
			t[z[b]] = a;
			swap(z[a],z[b]);
		}else{
			int a;
			cin >> a;
			cout << t[f[a]] <<endl;
			
		}
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
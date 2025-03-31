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

void solve(){
	int n,a,b;
	cin >> n >>a >> b;
	if(a > 1 && b > 1){
		cout << "NO" << endl;
		return;
	} 
	if(a == 1 && b == 1){
		if(n==2 || n==3){
			cout << "NO" << endl;
			return;
		}else{
			cout << "YES" << endl;
			for(int i = 1;i <= n;i++){
				for(int j = 1;j <= n;j++){
					if(j==i + 1) cout << "1";
					else if(j==i-1) cout << "1";
					else cout << "0";
				}
				cout << endl; 
			}
		}
	}else if(a > 1){
		cout << "YES" << endl;
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++){
				if(i <= a - 1 || j == i) cout << "0";
				else if(j >= a && i >= a) cout << "1";
				else cout << "0";
			}
			cout << endl; 
		}
	}else {
		cout << "YES" << endl;
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++){
				if(i==j) {
					cout << "0";
					continue;
				}
				if(i <= b - 1) cout << "1";
				else if(j >= b && i >= b) cout << "0";
				else cout << "1";
			}
			cout << endl; 
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
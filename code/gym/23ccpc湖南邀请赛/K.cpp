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
int n,m,k;
//字符串要两两不同
void solve(){
	cin >> n >> m >> k;
	if(k <= m || (m==0 && n > 26)){
		cout << "No" << endl;
		return;
	}
	if(m==0){
		cout << "Yes" << endl;
		for(int i = 0;i < n;i++){
			for(int j = 0;j < k;j++){
				cout << (char)(i + 'a');
			}
			cout << endl;
		}
	}else{
		cout << "Yes" << endl;
		int cnt = 1;
		int jc = 0;
		for(int i = 1; i <= n;i++){
			int x = jc;
			int j = 1;
			if(i <= 2) for(;j <= m;j++) cout << 'z';
			for(;j <= k;j++){
				if(j%2) cout << (char)(x+'a');
				else cout << (char)(x + cnt + 'a');
			}
			jc++;
			if(jc + cnt >= 25){
				jc = 0;
				cnt++;
			} 
			cout <<endl;
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
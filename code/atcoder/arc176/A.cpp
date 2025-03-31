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
const ll inf = 0x3f3f3f3f3f3f3f3fLL;
const int infi = 0x3f3f3f3f;
const int P = 13331;
const int N = 200005;
int n,m;
int vis[N];//代表每个编号是否选择
void solve(){
	cin >> n >> m;
	vector<int> ans;
	for(int i = 1;i <= m;i++){
		int x,y;
		cin >> x >> y;
		x--,y--;
		if(!vis[(x + y)%n]){
			vis[(x + y)%n] = 1;
			ans.pb((x+y)%n);
		}
		
	}
	for(int i = 0;i < n;i++){
		if(ans.size() < m && !vis[i]) ans.pb(i);
	}
	cout << n*m <<endl;
	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++){
			int r = i + 1,c = (ans[j] - i + n)%n + 1;
			cout <<r  << " " << c << endl;
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
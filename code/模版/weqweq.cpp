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
//int dp[4][2];表示该位置向上,向下转换到指定位置的最小
int ans;
string s, t;
void dfs(int xs,int xx,int i,int res){
	if(i==5) {
		ans=min(res,ans);
		return;
	}
	int xyxs = 0;
	int x = t[i] - 'a',y = s[i] - 'a';
	
	if(x >= y){
		xyxs = x - y; 
	}else{
		xyxs = 10 - (y) + (x);
	}
	int xyxx = 0;
	if(x <= y){
		xyxx = y - x; 
	}else{
		xyxx = 10 - (x) + (y);
	}
	if(s[i]==t[i]){
		dfs(0,0,1+i,res);
		return;
	}
	dfs(0,max(xyxx,xx),i + 1,res + max(xyxx - xx,0ll)); //向下
	dfs(max(xyxs,xs),0,i + 1,res + max(xyxs - xs,0ll)); //向上
}
void solve(){
	
	cin >> s >> t;
	s = " " + s,t = " " + t;
	ans = 0x3f3f3f3f;
	
	dfs(0,0,1,0);
	cout << ans << endl;
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
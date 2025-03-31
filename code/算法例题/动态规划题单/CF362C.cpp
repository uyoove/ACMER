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
const int N = 200005;
int n;
int a[N];
struct Fenwick{
	vector<int> tr;
	int sz;
	void init(int n){
		tr.resize(n + 1);
		sz = n;
	}
	Fenwick(){}
	Fenwick(int n){
		init(n);
	}
	void add(int k,int val){
		for(int i = k;i <= sz;i+=(i&-i)){
			tr[i]+=val;
		}
	}
	int query(int k){
		int res = 0;
		for(int i = k;i > 0;i-=(i&-i)){
			res+=tr[i];
		}
		return res;
	}
	int ask_sum(int l,int r){
		return query(r) - query(l - 1);
	}
};
//dp[n][n]代表第i个数是j的时候有多少个数比他小
int dp[5010][5010],g[5010][5010];
void solve(){
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> a[i],a[i]++;
	Fenwick fk(n + 1);
	int su = 0;
	for(int i = 1;i <= n;i++){
		su += (i-1) - fk.query(a[i]);
		fk.add(a[i],1);
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++) dp[i][j] = dp[i - 1][j];
		for(int j = a[i] + 1;j <= n;j++){
			dp[i][j] ++;
		}
		for(int j = 1;j <= n;j++) g[i][j] = g[i - 1][j];
		for(int j = a[i] - 1;j >= 1;j--){
			g[i][j] ++;
		}
	}
	int res = infi,cnt = 0;
	for(int j = 1;j <= n;j++){
		for(int i = j + 1;i <= n;i++){
			int tp = 0;
			int p1 = dp[i][a[j]] - dp[j][a[j]];
			int p2 = g[i][a[j]] - g[j][a[j]];
			int p3 = dp[i][a[i]] - dp[j][a[i]];
			int p4 = g[i][a[i]] - g[j][a[i]];
			tp = p2 - p1 + p3 - p4;
			//cout << i << " " << j <<" "<<tp <<endl;
			if(tp+su < res){
				cnt = 1;
				res = tp+su;
			}else if(tp+su == res){
				cnt++;
			}
		}
	}
	cout << res << " " << cnt << endl;

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
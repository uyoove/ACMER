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
const int N = 2000005;
int t[N][20];
int dp[N][20];//表示我当前这块变成目标块的最小花费
int n;
string s;
void solve(){
	cin >> n;
	int len = pow(3,n);
	cin >> s;
	for(int i = 0;i < len;i++){
		t[i][0] = s[i] - '0';
	}
	for(int i = 1;i <= n;i++){
		int t1 = 1;
		for(int j = 0;j<=pow(3,n-i);j++){
			int l = t1 - 1,r = l + 3 - 1;
			int cnt0 = 0,cnt1 = 0;
			for(int p = l;p <= r;p++){
				if(t[p][i - 1] == 1) cnt1++;
				else cnt0++;
			}
			if(cnt1 > cnt0){
				t[j][i] = 1;
			}else{
				t[j][i] = 0;
			}
			t1+=3;
		}
	}
	int pp = t[0][n];
	//cout << pp << endl;
	for(int i = 0;i < len;i++){
		dp[i][0] = ((s[i] - '0') == pp);
		//cout << dp[i][0] << " ";
	}
	for(int i = 1;i <= n;i++){
		int t1 = 1;
		for(int j = 0;j<=pow(3,n-i);j++){
			int l = t1 - 1,r = l + 3 - 1;
			int cnt0 = 0,cnt1 = 0,cnt = 0;
			vt<int> v;
			for(int p = l;p <= r;p++){
				if(t[p][i - 1] == 1) cnt1++;
				else cnt0++;
				if(t[p][i - 1]==pp){
					cnt++;
					v.pb(dp[p][i-1]);
				}
			}
			sort(all(v));
			if(cnt == 3){
				dp[j][i] = v[0] + v[1];
			}else if(cnt == 2){
				dp[j][i] = v[0];
			}
			t1+=3;
		}
	}
	cout << dp[0][n] << endl;
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
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
const int N = 205;
int n,m,k;
string s[N][N];
void solve(){
	map<string,int> mp;
	cin >> n >>m >> k;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j<=m;j++){
			string s1;
			for(int i = 1;i <= k;i++){
				char ch;
				cin >>ch;
				s1+=ch;
			}
			s[i][j] = s1;
			mp[s[i][j]]++;
		}
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j<=m;j++){
			if(mp[s[i][j]]==1){
				cout << i << " " << j;
				return;
			}
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
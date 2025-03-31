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
const ll inf = 0x3f3f3f3f3f3f3f3fLL;
const int infi = 0x3f3f3f3f;
const int P = 13331;
const int N = 200005;
int n;
int a[N];
string s;
int mp[N][200][3];// 后缀0,1,2的最近
int mp2[N][200][3];
int mx(set<int> se){
	int res = 0;
	for(auto p : se) if(res == p) res++;
	return res;
}
void solve(){
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> a[i];
	cin >> s;
	s = " " + s;
	for(int i = n;i >= 1;i--){
		for(int j = 'A';j <= 'Z';j++){
			for(int k = 0;k < 3;k++){
				mp[i][j][k] = mp[i+1][j][k]; 
			}
		}
		mp[i][s[i]][a[i]] += 1;
	}
	for(int i = 1;i <= n;i++){
		for(int j = 'M';j <= 'X';j++){
			for(int k = 0;k < 3;k++){
				mp2[i][j][k] = mp2[i-1][j][k]; 
			}
		}
		mp2[i][s[i]][a[i]] += 1;
	}
	long long ans = 0;
	for(int i = 1;i <= n;i++){
		if(s[i]=='E'){
			//cout << i << endl;
			for(int q = 0;q <= 2;q++){
				for(int s = 0;s <= 2;s++){
					set<int> se;
					se.insert(q),se.insert(a[i]),se.insert(s);
					ans+=mx(se) *1ll*mp2[i]['M'][q]*1LL*mp[i]['X'][s];
					//cout << q <<  " " << mp[i]['M'][q] <<endl;
					//cout << s <<  " " << mp[i]['X'][s] <<endl;
					//cout << endl;
				}
			}
		}
	}
	cout << ans << endl;
	

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
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
	string s1,s2;
	cin >> s1 >> s2;
	int n = s1.size();
	int m = s2.size();
	int res = 5000;
	for(int i = 0;i < n;i++){
		int pp = 0;
		for(int j = 0;j < m;j++){
			if(i + j >= n) break;
			if(s1[i + j] == s2[j]) pp++;
		}
		res = min(res,m - pp);
	}
	for(int j = 0;j < m;j++){
		int t = j;
		int pp = 0;
		for(int i = 0;i < n && t < m;i++){
			if(s2[t]==s1[i]) pp++;
			t++;
		}
		res = min(res,m - pp);
	}
	cout << res <<endl;

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
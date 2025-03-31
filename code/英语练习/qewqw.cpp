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
int t, a, b;
string str;
void solve(){
	int sum1 = 0, sum2 = 0;
		cin >> a >> b >> str;
		for(int i = 2; i <= b; i++) 
			if(str[i] == 'R') sum1++;
		for(int i = b; i <= a-1; i++) {
			if(str[i] == 'L') sum2++;
		} 
		printf("%d\n", sum1>sum2?sum2:sum1);
}

signed main(){

	int times = 1;
	cin >> times;
	while(times--){
		solve();
	}
	return 0;
}
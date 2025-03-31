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

void solve(){
	int k;
	cin >> k;
	int now = 0;//当前长度
	int len = 0;//当前数字长度
	int g = 9,sum = 1;//9,90,900,sum是初始位置
	while(now<k){
		len++;
		now+=g*len;
		g*=10;
		sum*=10;
	}
	g/=10,now-=g*len;
	long long tp = (k - now)/len + sum/10;//前面是第几位,后面是变成一个完整的数字
	int rk = (k - now)%len;//这位的第几个

	if(rk==0) rk = len,tp--; //正好除尽就是上一个数字的最后一位
	for(int i = 1;i <= len - rk;i++) tp/=10;
	cout << tp%10 << endl;
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
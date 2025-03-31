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
int a,b,p,q;
double x,y;
double res = 0;
double f[N]; 
//f[i] = 
//max(x * (f[i - b] + 2) + (1 - x) * (f[i - b] + 1),
//y * (f[i - b + 1] + 1) + (1 - y) * (f[i - b] +1));
//f[i] = max(f[i-b] + x + 1,y * (f[i - b + 1] + 1) + (1 - y) * (f[i - b] +1));
//当b等于1的时候 后半部分f[i] = f[i]*y + y + (1 - y) *(f[i - 1] + 1);
//(1 - y)*f[i] = y + (1-y) * (f[i - 1] + 1);
//f[i] = y/(1-y) + f[i - b] + 1;
//最大期望等于期望值=sum(概率*（数值+变化)）由小到大是期望dp的本质
//通常来说，有时题目会跟你说：1.做啥啥事的概率是P，做了之后的收益是Q，那么Q就是变化；2.不做啥啥事的概率是1-P，不做的收益也是Q，Q也是变化；把2种情况的和加起来就是当前状态的期望值。  
double dfs(int h){
	if(f[h]) return f[h];
	if(h < b) return 0;
	f[h] = dfs(h - b) + x + 1;
	if(b==1) f[h] = max(f[h],y/(1-y) + dfs(h - 1) + 1);
	else f[h] =  max(f[h],y * (dfs(h - b + 1) + 1) + (dfs(h - b) + 1)*(1-y));
	return f[h];
} 
void solve(){
	cin >> a >> b >> p >> q;
	x = p/100.0;
	y = q/100.0;
	dfs(a);
	printf("%.10lf\n",f[a]);
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
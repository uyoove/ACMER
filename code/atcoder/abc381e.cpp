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
int n,q;
vector<int> v;//存储/的下标
int pre[N],suf[N];
void work(){
	int l,r;
	cin >> l >> r;
	int pl = l,pr = r;
	l = lower_bound(all(v),l) - v.begin();
	if(l >= v.size()){
		cout << 0 << endl;
		return;
	}
	r = lower_bound(all(v),r + 1) - v.begin() - 1;
	int zl = l,zr = r;
	if(r < 0){
		cout << 0 << endl;
		return;
	}
	int ans = l;
	int res = 0;
	while(l<=r){
		int mid = (l + r) >> 1;
		//res = max(min(pre[v[mid]]- pre[pl - 1],suf[v[mid]]- suf[pr + 1])*2 + 1,res);
		if(pre[v[mid]] - pre[pl - 1] < suf[v[mid]] - suf[pr + 1]){
			l = mid + 1;
			ans = mid;
		}else{
			r = mid - 1;
		}
	}
	
	int m=  v.size();
	//因为最后长度由最小值决定,所以我们适当缩小最大值,放大最小值,就能保证最优
	//因为在区间内操作比如说 我前一个/前缀 3 后缀 6;
	//那么 我可以右移一个/ 使得前缀可能去增加到更大,后缀变小一点
	//可能变成 4 5(更优)  7 3(更劣) 但是因为二分性质会回来,
	//然后在均衡点的左右两个和自身取最大值即可
	for(int i = max(zl,ans - 1);i <= min(zr,ans + 1);i++){
		//cout << min(pre[v[i]]- pre[pl - 1],suf[v[i]]- suf[pr + 1])*2 + 1 << endl;
		res = max(min(pre[v[i]]- pre[pl - 1],suf[v[i]]- suf[pr + 1])*2 + 1,res);
	}
	cout << res << endl;
}
void solve(){
	string s;
	cin >> n >> q >> s;
	s = " " + s;
	for(int i = 1;i <= n;i++){
		pre[i] = pre[i - 1] + (s[i] == '1');
		if(s[i] == '/'){
			v.pb(i);
		}
	}
	for(int i = n;i>=1;i--){
		suf[i] = suf[i + 1] + (s[i] == '2');
	}
	while(q--){
		work();
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
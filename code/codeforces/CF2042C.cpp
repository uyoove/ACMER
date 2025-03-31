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
int n,k;
string s;
//一条分割线的代价是 后面1-0的数量 + 前面1-0的数量
int pre[N];

void solve(){
	cin >> n >> k;
	cin >> s;
	s = " " + s;
	pre[n + 1] = 0;
	vector<int> res;
	for(int i = n;i >= 1;i--){
		
		if(s[i]=='1') pre[i] = pre[i +1] +1;
		else pre[i] = pre[i +1] -1;
		if(i!=1) res.push_back(pre[i]);

		
	}
	sort(res.rbegin(),res.rend());
	int mx = 0;
	for(int j = 0;j < n -1;j++){
		if(j > 0) res[j]+=res[j - 1];
		if(res[j] >=k){
			cout << j+2 <<endl;
			return;
		}
	}
	cout << -1 <<endl;


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
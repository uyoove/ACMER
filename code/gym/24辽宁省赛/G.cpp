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
const int N = 1000005;
vector<int> v[N]; //存储值域下标
int n,k;
int a[N]; 
ll pre[N]; //记录每个值域 离它前面最近第k个的下标

void solve(){
	cin >> n >> k;
	for(int i = 1;i <= n;i++) v[i].clear(),pre[i] = 0;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		v[a[i]].pb(i);
	}
	for(int i = 1;i <= n;i++){
		for(int j = 0;j < v[i].size();j++){
			if(j-k+1<0) continue;
			pre[v[i][j]] = v[i][j - k + 1];
		}
	}
	stack<ll> st; //单调递减
	ll su = 0; //当前累加和
	ll ans = 0; //最后答案

	a[0] = infi;
	st.push(0); //虚拟最大节点,防止越界

	for(int i = 1;i <= n;i++){
		while(!st.empty() && a[i] >= a[st.top()]){
			int pretop = st.top(); 
			st.pop();
			su-=max(pre[pretop] - st.top(),0ll);
		}
		su+=max(0ll,pre[i] - st.top());
		ans+=su;
		st.push(i);
	}
	cout << ans << endl;


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
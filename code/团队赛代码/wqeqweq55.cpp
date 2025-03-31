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
int n,m,k;
struct nodes{
	int w,v;
	bool operator<(const nodes &n1)const{
		return v < n1.v;
	}
};
int dp[10007];
int cnt[5010];
void solve(){
	cin >> n >> m >> k;
	memset(cnt,0,sizeof cnt);
	memset(dp,0,sizeof dp);
	vector<nodes> v;
	for(int i = 0;i < n;i++){
		nodes n1;
		cin >> n1.w >> n1.v;
		v.push_back(n1);
	}
	sort(v.begin(),v.end());
	priority_queue<int,vector<int>,greater<int>> pq;
	for(int i = n;i >= 1;i--){
		cnt[i] = cnt[i + 1];
		if(pq.size() < k){
			cnt[i] += v[i - 1].v;
			pq.push(v[i-1].v);
		}else{
			if(pq.size() && pq.top() < v[i-1].v){
				cnt[i]-=pq.top();
				pq.pop();
				pq.push(v[i-1].v);
				cnt[i]+=v[i-1].v;
			}
		}
	}
	int res = 0;
	for(int i = 1;i <= n;i++){
		int mx = 0;
		for(int j = m;j>=v[i - 1].w;j--){
			dp[j] = max(dp[j],dp[j - v[i - 1].w] + v[i - 1].v);
			mx=max(mx,dp[j]);
		}
		res=max(mx + cnt[i + 1],res);
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
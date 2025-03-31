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
int n;
int gt[N];
int t = 0;
void solve(){
	cin >> n;
	for(int i = 1;i <= n - 1;i++){
		int u,v;
		cin >> u >> v;
		gt[u]++;
		gt[v]++;
	}
	map<int,int> h;
	for(int i = 1;i <= n;i++){
		if(gt[i] >= 2) h[gt[i]]++;
	}
	int res = 0;
	int mx = 0;
	for(auto [k,v]:h){
		if(k!=2) t+=v;
		else mx = v;
	}
	int l = 0,r = mx,ans = 0;
	while(l<=r){
		int i = l+r>>1;
		if((mx+t-1)*2>=3*i){
			ans = i;
			l = i +1;
		}else{
			r = i - 1;
		} 
	}
	 for(auto [k,v]:h){
	 	if(k==2) v=v-ans;
	 	while(v--){
	 		cout << k << " ";
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
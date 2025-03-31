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
const int P = 2e14;
const int N = 200005;
int a[N],n;
__int128 pre[N],pre2[N];
void solve(){
	cin >> n;
	pre[0] = 1;
	pre2[0] = 0;
	for(int i = 1;i <= n;i++) cin >> a[i];
	int l = 0,r = 0;
	vector<int> v;
	for(int i = 1;i <= n;i++){
		if(a[i]!=1) r = i,v.pb(i);
		if(a[i]!=1 && l == 0) l = i;
		
	}
	if(l==0 && r == 0){
		cout << 1 << " " << 1 << endl;
		return;
	}
	for(int i = 1;i <= n;i++){
		pre[i] = pre[i - 1] * a[i];
		pre2[i] = pre2[i - 1] + a[i];
	}
	__int128 mx = 1;
	for(int i = l;i <= r;i++){
		mx*=a[i];
		//防止越界
		if(mx >= P){
			cout << l <<  " " << r << endl;
		return;
		}
	}
	mx = -1e18;
	l = 1,r = 1;
	for(int i = 0;i < v.size();i++){
		for(int j = i;j < v.size();j++){
			if(mx < pre[v[j]] / pre[v[i] - 1] - pre2[v[j]] + pre2[v[i] - 1]){
				mx = pre[v[j]] / pre[v[i] - 1] - pre2[v[j]] + pre2[v[i] - 1];
				l = v[i],r = v[j];
			}
		}
	}
	cout << l << " " << r << endl;
	
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
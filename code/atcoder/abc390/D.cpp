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
int n;
int a[N];
set<int> se;
int t[N];
vt<int> v;
void dfs(int val,int mask){

	if(mask == (1 << n) - 1){
		v.pb(val);
		return;
	}
	int d = mask ^ ((1 << n) - 1);
	int b = d & -d;
	for(int i = d;i != 0;i = (i - 1)&d){
		if(i&mask) continue;
		if(i&b){
			dfs(val^t[i],mask | i);
		}	
	}
}
void solve(){
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> a[i];
	for(int i = 0 ;i < (1 << n);i++){
		int t1 = 0;
		for(int j = 0;j < n;j++){
			if((i >>j)&1){
				t1+=a[j + 1];
			}
		}
		t[i] = t1;
	}
	dfs(0,0);
	sort(all(v));
	v.erase(unique(all(v)),v.end());
	cout << v.size() << endl;

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
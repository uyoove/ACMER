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
const int N = 400005;
int tr[N][2];
void add(int k,int x,int op){
	for(int i = k; i < N;i+=(i&-i)) tr[i][op]+=x;
}
int qy(int k,int op){
	int res = 0;
	for(int i = k; i > 0;i-=(i&-i)) res+=tr[i][op];
	return res;
}
vector<int> ls;
int gt(int x){
	return lower_bound(ls.begin(),ls.end(),x) - ls.begin() + 1;
}
int n,a[N];
void solve(){
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		ls.push_back(a[i]);
	}
	sort(ls.begin(),ls.end());
	ls.erase(unique(ls.begin(),ls.end()),ls.end());
	int ans = 0;
	for(int i = 1;i <= n;i++){
		int gs = qy(gt(a[i]),0);
		int val_s = qy(gt(a[i]),1);
		ans += gs*a[i] - val_s;
		add(gt(a[i]),1,0);
		add(gt(a[i]),a[i],1);
	}
	cout << ans;

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
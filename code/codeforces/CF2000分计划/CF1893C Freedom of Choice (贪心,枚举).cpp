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
int l[N],r[N],cnt[N];
//为什么复杂度是对的,因为sum(m)的大小一共就2e5个,如果每次都能正中枚举的x显然是不可能的
void solve(){
	cin >> n;
	vt<vt<PII>> a(n + 1);
	map<int,vt<PII>> mp;
	int L = 0,R = 0;
	int tot = 0;
	for(int i = 1;i <= n;i++){
		int m;
		cnt[i] = 0;
		cin >> m >> l[i] >> r[i];
		tot+=m;
		a[i].resize(m + 1);
		for(int j = 1;j <= m;j++){
			cin >> a[i][j].fi;
		}
		for(int j = 1;j <= m;j++){
			cin >> a[i][j].se;
			cnt[i] += a[i][j].se;
			mp[a[i][j].fi].pb({i,a[i][j].se});
		}
		L+=l[i],R+=r[i];
	}
	if(R - L + 1 > tot){
		cout << 0 << endl;
		return;
	}
	int ans = inf;
	for(int x = L;x <= R && ans!=0;x++){
		int su = R;//假设全部放满
		int must = 0;//一定要放x的数量
		for(auto [i,val]:mp[x]){
			su-=r[i];//减掉包含x的所有,重新组建
			if(cnt[i] - val >= l[i]){
				su+=min(cnt[i]-val,r[i]);
			}else{
				su+=l[i];
				must+=l[i] - (cnt[i] - val); // 要补的部分l-其他数凑的,就是要补充的x
			}
		}
		ans = min(ans,must + max(0ll,x - su));//需要的+剩下用其他数补不上的
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
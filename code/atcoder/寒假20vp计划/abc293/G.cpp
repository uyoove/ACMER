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
int n,m;
int a[N];
int block;
struct mdb{
	int l,r,id;
} md[N];
bool cmp(mdb m1,mdb m2){
	if(m1.l /block !=m2.l/block){
		return m1.l /block < m2.l/block;
	}
	if(m1.l/block&1){
		return m1.r > m2.r;
	}
	return m1.r < m2.r;
}
int ans[N];
int mp[N];
int c(int n){
	int p = n * (n - 1) * (n - 2)/6;
	return p;
}
int res = 0;
void add(int x){
	mp[a[x]]++;
	if(mp[a[x]] == 3){
		res += 1;
	}else if(mp[a[x]] > 3){
		res -= c(mp[a[x]] - 1);
		res += c(mp[a[x]]);
	}
}
void del(int x){
	mp[a[x]]--;
	if(mp[a[x]] == 2){
		res--;
	}else if(mp[a[x]] > 2){
		res -= c(mp[a[x]] + 1);
		res += c(mp[a[x]]);
	}
}
void solve(){
	cin >> n >> m;
	block = sqrt(n);
	for(int i = 1;i <= n;i++) cin >> a[i];
	for(int i = 1;i <= m;i++){
		cin >> md[i].l >> md[i].r;
		md[i].id = i;
	}
	sort(md + 1,md + 1 + m,cmp);
	int l = 1,r = 0;
	for(int i = 1;i <= m;i++){
		while(l > md[i].l) add(--l);
		while(l < md[i].l) del(l++);
		while(r > md[i].r) del(r--);
		while(r < md[i].r) add(++r);
		ans[md[i].id] = res;
	}
	for(int i = 1;i <= m;i++){
		cout << ans[i] << endl;
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
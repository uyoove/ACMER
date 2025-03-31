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
const int N = 500005;
struct node{
	int r,c,id,ff;
	bool operator<(const node &t)const{
		if(t.r == r) return c < t.c;
		return r < t.r;
	}
}a[N],b[N*4];
int tr[N*4];
void add(int x){
	for(int i = x;i < N;i+=(i&-i)){
		tr[i]++;
	}
}
int query(int x){
	int res = 0;
	for(int i = x;i > 0;i-=(i&-i)){
		res+=tr[i];
	}
	return res;
}
int idx = 0;
vector<int> v;
int gidx(int x){return lower_bound(v.begin(),v.end(),x) - v.begin() + 1;}
int n,m;
int ans[N];
void solve(){
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i].r >> a[i].c;
		v.push_back(a[i].c);
	}
	sort(a+1,a+n+1);
	for(int i = 1;i <= m;i++){
		int r1,c1,r2,c2;
		cin >> r1 >> c1 >> r2 >> c2;
		b[++idx] = {r2,c2,i,1};
		b[++idx] = {r1 - 1,c1 - 1,i,1};
		b[++idx] = {r1 - 1,c2,i,-1};
		b[++idx] = {r2,c1 - 1,i,-1};
		v.push_back(c2);
		v.push_back(c1 - 1);
	}
	sort(b+1,b+idx+1);
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	int tot = 0;
	for(int i = 1;i <= idx;i++){
		int by = gidx(b[i].c),id = b[i].id,ff = b[i].ff;
		while(tot+1 <= n && a[tot+1].r<= b[i].r){
			add(gidx(a[++tot].c));
		}
		ans[id]+=ff*query(by);
	}
	for(int i = 1;i<=m;i++){
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
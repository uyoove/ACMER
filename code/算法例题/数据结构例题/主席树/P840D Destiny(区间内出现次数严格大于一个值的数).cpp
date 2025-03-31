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
const int N = 300005;
int n,q;
int a[N];
int ls[N << 5],rs[N << 5],tr[N << 5];
int root[N],tot;
void update(int &u,int v,int l,int r,int x){
	u = ++tot;
	ls[u] = ls[v],rs[u] = rs[v];
	tr[u] = tr[v] + 1;
	if(l==r) return;
	int mid = l + r >> 1;
	if(x <= mid) update(ls[u],ls[v],l,mid,x);
	else update(rs[u],rs[v],mid + 1,r,x);
}
int query(int u,int v,int l,int r,int k,int len){
	if(l==r) return l;
	int mid = l + r >> 1;
	int res = -1;
	if((tr[ls[u]] - tr[ls[v]]) * k > len){
		res = query(ls[u],ls[v],l,mid,k,len);
		if(res!=-1) return res;
	}
	if((tr[rs[u]] - tr[rs[v]]) * k > len){
		res = query(rs[u],rs[v],mid+1,r,k,len);
	}
	return res;
}
void solve(){
	cin >> n >> q;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		update(root[i],root[i - 1],1,N - 1,a[i]);
	}
	for(int i = q;i >=1;i--){
		int l,r,k;
		cin >> l >> r >> k;
		cout << query(root[r],root[l - 1],1,N - 1,k,r-l+1) << endl;
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
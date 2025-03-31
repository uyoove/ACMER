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
const int N = 500005;
int n,m;
int a[N];
int root[N],ls[N <<5],rs[N<<5];
int tr[N<<5];
int cnt;
void modify(int &u,int v,int l,int r,int x){
	u = ++cnt;
	tr[u] = tr[v] + 1;
	ls[u] = ls[v];
	rs[u] = rs[v];
	if(l==r) return;
	int mid = l + r >> 1;
	if(x <= mid){
		modify(ls[u],ls[v],l,mid,x);
	}else{
		modify(rs[u],rs[v],mid + 1,r,x);
	}
}
int query(int u,int v,int l,int r,int val){
	if(l==r) return l;
	int mid = (l + r )>> 1;
	if(2 * (tr[ls[u]] -tr[ls[v]]) > val) return query(ls[u],ls[v],l,mid,val);
	if(2 * (tr[rs[u]] -tr[rs[v]]) > val) return query(rs[u],rs[v],mid + 1,r,val);
	return 0; //如果都没有就返回0
}
void solve(){
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		modify(root[i],root[i-1],1,N,a[i]);
	}
	for(int i = 1;i <= m;i++){
		int l,r;
		cin >> l >> r;
		cout << query(root[r],root[l-1],1,N,r-l+1) << endl;;
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
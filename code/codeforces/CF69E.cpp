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
const int N = 2000005;
int n,k;
int tr[N],ls[N],rs[N],flag[N];
int rt,tot;
int a[N];
int len = 2e9+1; 
void update(int& p,int l,int r,int pos,int val){
	if(!p) p = ++tot;
	if(l==r){
		tr[p]+=val;
		if(tr[p]==1){
			flag[p] = 1;
		}else{
			flag[p] = 0;
		}
		return;
	}
	int mid = l + r >> 1;
	if(pos <= mid){
		update(ls[p],l,mid,pos,val);
	}else{
		update(rs[p],mid+1,r,pos,val);
	}
	flag[p] = flag[ls[p]] | flag[rs[p]];
	tr[p]=tr[ls[p]]+tr[rs[p]];
}
int query(int p,int l,int r){
	if(!flag[p]) return -1;
	if(l==r) return l;
	int mid = l+r>>1;
	if(flag[rs[p]]){
		return query(rs[p],mid+1,r);
	}
	return query(ls[p],l,mid);
}
int p = 1e9+1;
void solve(){
	cin >> n >> k;
	for(int i = 1;i <= n;i++) cin >> a[i],a[i]+=p;
	for(int i = 1; i < k;i++) update(rt,1,len,a[i],1);
	for(int i = 1;i <= n-k+1;i++){
		update(rt,1,len,a[i + k - 1],1);
		int x = query(rt,1,len);
		if(x==-1){
			cout << "Nothing" << endl;
		}else{
			cout << x-p <<endl;
		}
		update(rt,1,len,a[i],-1);
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
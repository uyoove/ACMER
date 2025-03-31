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
struct FHQ{
	int ls,rs,key,sz,val;
}fhq[N];
int root,idx,T1,T2,T3;
void split(int u,int v,int &x,int &y){
	if(!u){
		x=y=0;
		return;
	}
	if(fhq[u].val > v){
		y = u;
		split(fhq[u].ls,v,x,fhq[u].ls);
	}else{
		x = u;
		split(fhq[u].rs,v,fhq[u].rs,y);
	}
}
int merge(int x,int y){
	if(!x||!y){
		return x+y;
	}
	if(fhq[x].key > fhq[y].key){
		fhq[x].rs = merge(fhq[x].rs,y);
		return x;
	}else{
		fhq[y].ls = merge(x,fhq[y].ls);
		return y;
	}
}
void insert(int v){
	fhq[++idx] = {0,0,rnd(),1,v};
	split(root,v,T1,T2);
	root = merge(merge(T1,idx),T2);
}
void erase(int v){
	split(root,v,T1,T2);
	split(T1,v - 1,T1,T3);
	T3 = merge(fhq[T3].ls,fhq[T3].rs);
	root = merge(merge(T1,T3),T2);
}
int get_pre(int u,int v){
	if(u==0) return -inf;
	if(fhq[u].val < v){
		int res = get_pre(fhq[u].rs,v);
		return res == -inf ? fhq[u].val:res;
	}else{
		return get_pre(fhq[u].ls,v);
	}
}
int get_suf(int u,int v){
	if(u==0) return inf;
	if(fhq[u].val > v){
		int res = get_suf(fhq[u].ls,v);
		return res == inf ? fhq[u].val:res;
	}else{
		return get_suf(fhq[u].rs,v);
	}
}
int stk[N];
int vis[N];
void solve(){
	cin >> n >> m;
	int top = 0;
	while(m--){
		char op;
		cin >> op;
		if(op=='D'){
			int x;
			cin >> x;
			if(!vis[x]) insert(x),stk[++top] = x;
			vis[x] = 1;
		}else if(op=='R'){
			if(top) erase(stk[top]),vis[stk[top]] = 0,top--;
		}else{
			int t;
			cin >> t;
			if(vis[t]){
				cout << 0 << endl;
				continue;
			}
			int pre = max(1ll,get_pre(root,t) + 1);
			int suf = min(n,get_suf(root,t) - 1);
			int ans = suf - pre+1;
			cout << ans << endl;
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
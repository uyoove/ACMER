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
struct FHQ{
	int ls,rs,val,key,sz;
}fhq[N];
int root,idx,T1,T2,T3;
void push_up(int u){
	fhq[u].sz=fhq[fhq[u].ls].sz+fhq[fhq[u].rs].sz+1;
}
void split(int u,int v,int &x,int &y){
	if(u == 0){
		x=y=0;
		return;
	}
	if(fhq[u].val <= v){
		x = u;
		split(fhq[u].rs,v,fhq[u].rs,y);
	}else{
		y = u;
		split(fhq[u].ls,v,x,fhq[u].ls);
	}
	push_up(u);
}
int merge(int x,int y){
	if(!x||!y) return x+y;
	if(fhq[x].key > fhq[y].key){
		fhq[x].rs = merge(fhq[x].rs,y);
		push_up(x);
		return x;
	}else{
		fhq[y].ls = merge(x,fhq[y].ls);
		push_up(y);
		return y;
	}
}
void insert(int v){
	fhq[++idx] = {0,0,v,rnd(),1};
	split(root,v,T1,T2);
	root=merge(merge(T1,idx),T2);
}
int get_pre(int u,int v){
	if(u == 0) return -infi;
	if(fhq[u].val <= v){
		int res = get_pre(fhq[u].rs,v);
		return res == -infi ? fhq[u].val : res;
	}else{
		return get_pre(fhq[u].ls,v);
	}
}
int get_suf(int u,int v){
	if(u == 0) return infi;
	if(fhq[u].val >= v){
		int res = get_suf(fhq[u].ls,v);
		return res == infi ? fhq[u].val : res;
	}else{
		return get_suf(fhq[u].rs,v);
	}
}
void erase(int v){
	split(root,v,T1,T2);
	split(T1,v - 1,T1,T3);
	T3 = merge(fhq[T3].ls,fhq[T3].rs);
	root = merge(merge(T1,T3),T2);
}
void solve(){
	cin >> n;
	int tp = -1;
	int su = 0;
	while(n--){
		int op,x;
		cin >> op >> x;
		if(op==tp || tp==-1 ||fhq[root].sz==0){
			insert(x);
			tp = op;
		}else{
			int p1 = get_pre(root,x),p2 = get_suf(root,x);
			if(abs(p1 - x) <= abs(p2 - x)){
				su+=abs(p1-x);
				su%=1000000;
				erase(p1);
			}else{
				su+=abs(p2-x);
				su%=1000000;
				erase(p2);
			}
			if(fhq[root].sz==0) tp = -1;
		}
	}
	cout << su%1000000 << endl;
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
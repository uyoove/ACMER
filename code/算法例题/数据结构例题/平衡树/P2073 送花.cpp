//和爸爸一起学编程真好,不过要小学四年级分流考试了,最近没时间写代码了,呜呜呜
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define out(x) cout << #x << '=' << (x) << endl
#define out2(x, y) cout << #x << '=' << (x) << ',' << #y << '=' << (y) << endl 
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
struct FHQ{
	int ls,rs,key,ma,mi,c,w,su,su1;
}fhq[N];
int root,idx,T1,T2,T3;
void push_up(int u){
	fhq[u].mi = min(min(fhq[fhq[u].ls].mi,fhq[fhq[u].rs].mi),fhq[u].c);
	fhq[u].ma = max(max(fhq[fhq[u].ls].ma,fhq[fhq[u].rs].ma),fhq[u].c);
	fhq[u].su = fhq[fhq[u].ls].su + fhq[fhq[u].rs].su + fhq[u].w;
	fhq[u].su1 = fhq[fhq[u].ls].su1 + fhq[fhq[u].rs].su1 + fhq[u].c;
}
void split(int u,int val,int &x,int &y){
	if(u==0){
		x = y = 0;
		return;
	}
	if(fhq[u].c > val){
		y = u;
		split(fhq[u].ls,val,x,fhq[u].ls);
	}else{
		x = u;
		split(fhq[u].rs,val,fhq[u].rs,y);
	}
	if(u)push_up(u);
}
int merge(int x,int y){
	if(!x||!y) return x+y;
	if(fhq[x].key >= fhq[y].key){
		fhq[x].rs = merge(fhq[x].rs,y);
		if(x)push_up(x);
		return x;
	}else{
		fhq[y].ls = merge(x,fhq[y].ls);
		if(y)push_up(y);
		return y;
	}
}
void insert(int c,int w){
	fhq[++idx] = {0,0,rnd(),c,c,c,w,w,c};
	split(root,c,T1,T2);
	root = merge(merge(T1,idx),T2);
}
void erase(int c){
	split(root,c,T1,T2);
	split(T1,c - 1,T1,T3);
	T3 = merge(fhq[T3].ls,fhq[T3].rs);
	root = merge(merge(T1,T3),T2);
}
void solve(){
	fhq[0].mi = inf;

	int op;
	while(true){
		cin >> op;
		if(op==-1) break;
		if(op==1){
			int w,c;
			cin >> w >> c;
			split(root,c,T1,T2);
			if(fhq[T1].ma == c){ //注意是ma不是c,因为平衡树根节点随机
				root = merge(T1,T2);
				continue;
			}
			root = merge(T1,T2);
			insert(c,w);
		}else if(op==2){
			int mx = fhq[root].ma;
			erase(mx);
		}else{
			int mx = fhq[root].mi;
			erase(mx);
		}
	}
	cout << fhq[root].su << " " << fhq[root].su1 << endl;
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
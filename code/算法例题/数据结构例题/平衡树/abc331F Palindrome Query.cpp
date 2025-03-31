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
const int N = 1000005;
string s1,s2;
string s;
ULL p[N],h[N];//p1[i] = P^i,P的i次方,h[i]为s[0-i]的hash值 
//初始化 
int n,q;
void init(){
	p[0] = 1;
	h[0] = 0;
	for(int i = 1; i <= n;i++){
		p[i] = p[i - 1]*P;
		h[i] = h[i - 1]*P+(s[i]);
	}
}
struct FHQ{
	int ls,rs,key,sz,val,tval,rval,tag;
}fhq[N];
int root,T1,T2,T3,idx;
int add(int v){
	fhq[++idx] = {0,0,(int)rnd(),1,v,v,v,0};
	return idx;
}
void push_up(int u){
	fhq[u].sz = fhq[fhq[u].ls].sz + fhq[fhq[u].rs].sz + 1;	
	fhq[u].val = fhq[fhq[u].ls].val * p[(fhq[fhq[u].rs].sz + 1)] +fhq[u].tval*p[fhq[fhq[u].rs].sz]  +fhq[fhq[u].rs].val;
	fhq[u].rval = fhq[fhq[u].ls].rval  +fhq[u].tval*p[fhq[fhq[u].ls].sz]  +fhq[fhq[u].rs].rval* p[(fhq[fhq[u].ls].sz + 1)];
}
void push_down(int u){
	if(fhq[u].tag){
		fhq[fhq[u].ls].tag^=1;
		fhq[fhq[u].rs].tag^=1;
		swap(fhq[fhq[u].ls].val,fhq[fhq[u].ls].rval);
		swap(fhq[fhq[u].rs].val,fhq[fhq[u].rs].rval);
		swap(fhq[u].ls,fhq[u].rs);
		fhq[u].tag = 0;
	}
}
void split(int u,int k,int &x,int &y){
	if(u==0){
		x=y=0;
		return;
	}
	push_down(u);
	int temp = fhq[fhq[u].ls].sz + 1;
	if(k==temp){
		x = u,y = fhq[u].rs;
		fhq[u].rs = 0; 
	}else if(k < temp){
		y = u;
		split(fhq[u].ls,k,x,fhq[u].ls);
	}else{
		x = u;
		split(fhq[u].rs,k - temp,fhq[u].rs,y);
	}
	push_up(u);
}
int merge(int x,int y){
	if(!x || !y) return x+y;

	if(fhq[x].key > fhq[y].key){
		push_down(x);
		fhq[x].rs = merge(fhq[x].rs,y);
		push_up(x);
		return x;
	}else{
		push_down(y);
		fhq[y].ls = merge(x,fhq[y].ls);
		push_up(y);
		return y;
	}
}
void swap(int l){
	split(root,l,T1,T2);
	root = merge(T2,T1);
}
void rs(int u){
	fhq[u].tag ^= 1;
	swap(fhq[u].val,fhq[u].rval);
}
bool check(int l,int r){
	split(root,l - 1,T1,T2);
	split(T2,r - l + 1,T2,T3);
	rs(T2);
	int p = fhq[T2].val;
	rs(T2);
	int p2 = fhq[T2].val;
	//cout << p << " " << p2 << " "<< fhq[T2].sz <<endl;
	root = merge(T1,merge(T2,T3));
	if(p==p2){
		return true;
	} 

	return false;
}
void solve(){
	cin >> n >> q;
	cin >> s;
	s = " " + s;
	init();
	for(int i = 1;i <= n;i++){
		root = merge(root,add(s[i]));
	}
	while(q--){
		int op;
		cin >> op;
		if(op==2){
			int l,r;
			cin  >> l >> r;
			if(check(l,r)){
				cout << "Yes" << endl;
			}else{
				cout << "No" << endl;
			}
		}else{
			int l;
			char r;
			cin >> l >> r;
			split(root,l,T1,T2);
			split(T1,l - 1,T1,T3);
			fhq[T3].tval = (r);
			fhq[T3].val = r;
			fhq[T3].rval = r;
			root = merge(merge(T1,T3),T2);
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
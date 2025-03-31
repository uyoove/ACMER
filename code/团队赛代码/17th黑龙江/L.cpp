//和爸爸一起学编程真好,不过要小学四年级分流考试了,最近没时间写代码了,呜呜呜
#include<bits/stdc++.h>
using namespace std;
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
const int N = 500005;
string s1,s2;
ULL p[N],h2[N];//p1[i] = P^i,P的i次方,h[i]为s[0-i]的hash值 
int n;
//初始化 
void init(){
	p[0] = 1;
	h2[0] = 0;
	for(int i = 1; i <= n;i++){
		p[i] = p[i - 1]*P;
		h2[i] = h2[i-1]*P + s2[i];
	}
}
struct FHQ{
	int ls,rs,key,sz;
	ULL val,tval,rval;
	int tag;
}fhq[N];
int root,T1,T2,T3,idx;
il int add(int v){
	fhq[++idx] = {0,0,(int)rnd(),1,v,v,v,0};
	return idx;
}
il void push_up(int u){
	fhq[u].sz = fhq[fhq[u].ls].sz + fhq[fhq[u].rs].sz + 1;	
	fhq[u].val = fhq[fhq[u].ls].val * p[(fhq[fhq[u].rs].sz + 1)] +fhq[u].tval*p[fhq[fhq[u].rs].sz]  +fhq[fhq[u].rs].val;
	fhq[u].rval = fhq[fhq[u].ls].rval  +fhq[u].tval*p[fhq[fhq[u].ls].sz]  +fhq[fhq[u].rs].rval* p[(fhq[fhq[u].ls].sz + 1)];
}
il void push_down(int u){
	if(fhq[u].tag){
		fhq[fhq[u].ls].tag^=1;
		fhq[fhq[u].rs].tag^=1;
		swap(fhq[fhq[u].ls].val,fhq[fhq[u].ls].rval);
		swap(fhq[fhq[u].rs].val,fhq[fhq[u].rs].rval);
		swap(fhq[u].ls,fhq[u].rs);
		fhq[u].tag = 0;
	}
}
il void split(int u,int k,int &x,int &y){
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
il int merge(int x,int y){
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
il void swap(int l){
	split(root,l,T1,T2);
	root = merge(T2,T1);
}
il void rs(int u){
	fhq[u].tag ^= 1;
	swap(fhq[u].val,fhq[u].rval);
}
int a[3];
unordered_set<int> se;
bool f= false;


// void dfs(int t,int op){
// 	if(t >= n*2) return;
	
// 	if(se.count(fhq[root].val)) return;
// 	se.insert(fhq[root].val);
	
// 	if(f) return;
// 	if(op==1){
// 		swap(a[1]);
// 		rs(root);
// 		dfs(t+1,2);
// 	}else{
// 		swap(a[2]);
// 		rs(root);
// 		dfs(t+1,1);
// 	}
	
	
// }
void solve(){
	cin >> s1 >> s2;
	idx = 0;
	f = 0;
	se.clear();
	n = s1.size();
	root = 0;
	s1 = " " + s1;
	s2 = " " + s2;
	init();
	for(int i = 1;i <= n;i++){
		root = merge(root,add(s1[i]));
		//cout << fhq[2].val << " "<< (s1[i] + 0) <<endl;
	}
	a[1] = read(),a[2] = read();
	if(a[1]<a[2])swap(a[1],a[2]);
	if(fhq[root].val==h2[n]){
			f = true;
		}
	for(int t = 1;t <= 2*n;t++){
		if(fhq[root].val==h2[n]){
			f = true;
			break;
		}
		if(se.count(fhq[root].val)) continue;
		se.insert(fhq[root].val);
		if(t%2){
			swap(a[1]);
			rs(root);
		}else{
			swap(a[2]);
			rs(root);
		}
	}
	if(fhq[root].val==h2[n]){
			f = true;
		}
	if(f){
		cout << "yes" << endl;
	}else{
		cout << "no" << endl;
	}
}

signed main(){
	int times = 1;
	cin >> times;
	while(times--){
		solve();
	}
	return 0;
}
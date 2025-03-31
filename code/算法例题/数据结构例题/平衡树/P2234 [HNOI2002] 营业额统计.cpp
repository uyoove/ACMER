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
struct FHQ{
	int ls,rs,v,key,sz;
}fhq[N];
int root,T1,T2,T3,idx;
int add(int v){
	fhq[++idx] = {0,0,v,rnd(),1};
	return idx;
}
void push_up(int u){
	fhq[u].sz = fhq[fhq[u].ls].sz + fhq[fhq[u].rs].sz; 
}
void split(int u,int v,int &x,int &y){
	if(u==0){
		x = 0,y = 0;
		return;
	}
	if(v < fhq[u].v){
		y = u;
		split(fhq[u].ls,v,x,fhq[u].ls);
	}else{
		x = u;
		split(fhq[u].rs,v,fhq[u].rs,y);
	}
	push_up(u);
}
int merge(int x,int y){
	if(!x||!y) return x + y;
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
int get_pre(int u,int v){
	if(u==0) return -infi;
	if(fhq[u].v <= v){
		int res = get_pre(fhq[u].rs,v);
		return res == -infi ? fhq[u].v : res;
	}else{
		return get_pre(fhq[u].ls,v);
	}
}
int get_suf(int u,int v){
	if(u==0) return infi;
	if(fhq[u].v >= v){
		int res = get_suf(fhq[u].ls,v);
		return res == infi ? fhq[u].v : res;
	}else{
		return get_suf(fhq[u].rs,v);
	}
}
void solve(){
	int n;
	cin >> n;
	int s = 0;
	int t;
	cin >> t;
	s+=t;
	root = add(t);
	for(int i = 1;i < n;i++){
		cin >> t;
		int d = abs(t-get_pre(root,t));
		int d2 = abs(t-get_suf(root,t));
		int mi = min(d,d2);
		s+=mi;
		//cout << mi << endl;
		split(root,t,T1,T2);
		root = merge(merge(T1,add(t)),T2);
	}	
	cout << s <<endl;
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
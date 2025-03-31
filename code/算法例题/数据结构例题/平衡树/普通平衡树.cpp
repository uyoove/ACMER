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
mt19937 rnd(114514);
const int infi = 0x3f3f3f3f;
const int N = 100005;
struct FHQ{
	int ls,rs,key,sz,val;
}fhq[N];
int root,T1,T2,T3,idx;
int add(int v){
	fhq[++idx] = {0,0,(int)rnd(),1,v};
	return idx;
}
void push_up(int u){
	fhq[u].sz = fhq[fhq[u].ls].sz + fhq[fhq[u].rs].sz + 1;	
}
//按值分裂,把<=v 与 >v分成两部分
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
	split(root,v,T1,T2);
	root = merge(merge(T1,add(v)),T2);
}
void erase(int v){
	split(root,v,T1,T2);
	split(T1,v - 1,T1,T3);
	T3 = merge(fhq[T3].ls,fhq[T3].rs);
	root = merge(merge(T1,T3),T2);
}

int get_rank(int v){
	split(root,v - 1,T1,T2);
	int res = fhq[T1].sz + 1;
	root = merge(T1,T2);
	return res;
}

int get_kth(int k){
	int u = root;
	while(u){
		int tp = fhq[fhq[u].ls].sz + 1;
		if(tp == k){
			break;
		}
		if(tp > k){
			u = fhq[u].ls;
		}else{
			u = fhq[u].rs;
			k-= tp;
		}
	}
	return fhq[u].val;
}
int find_pre(int u,int v){
	if(u==0) return -infi;
	if(fhq[u].val < v){
		int res = find_pre(fhq[u].rs,v);
		return res == -infi ? fhq[u].val : res; 
	}else{
		return find_pre(fhq[u].ls,v);
	}
}
int find_suf(int u,int v){
	if(u==0) return infi;
	if(fhq[u].val > v){
		int res = find_suf(fhq[u].ls,v);
		return res == infi ? fhq[u].val : res; 
	}else{
		return find_suf(fhq[u].rs,v);
	}
}
void solve(){
	int n;
	cin >> n;
	while(n--){
		int op,x;
		cin >> op >> x;
		if(op==1) insert(x);
		if(op==2) erase(x);
		if(op==3) cout << get_rank(x) <<endl;
		if(op==4) cout << get_kth(x) << endl;
		if(op==5) cout << find_pre(root,x) << endl;
		if(op==6) cout << find_suf(root,x) << endl;
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
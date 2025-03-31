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
const ll inf = 0x3f3f3f3f3f3f3f3fLL;
const int infi = 0x3f3f3f3f;
const int P = 13331;

mt19937_64 rnd(time(0));
const int N = 1000005;
struct FHQ
{
	int ls,rs,key,val,sz;
}fhq[N];
int root,T1,T2,T3,idx;
int add(int v){
	fhq[++idx] = {0,0,rnd(),v,1};
	return idx;
}
void push_up(int u){
	fhq[u].sz = fhq[fhq[u].ls].sz + fhq[fhq[u].rs].sz + 1;
}
void split_rank(int u,int k,int &x,int &y){
	if(u==0){
		x=y=0;
		return;
	}
	int temp = fhq[fhq[u].ls].sz + 1;
	if(k==temp){
		x = u,y = fhq[u].rs;
		fhq[u].rs = 0; 
	}else if(k < temp){
		y = u;
		split_rank(fhq[u].ls,k,x,fhq[u].ls);
	}else{
		x = u;
		split_rank(fhq[u].rs,k - temp,fhq[u].rs,y);
	}
	push_up(u);
}
int merge(int x,int y){
	if(!x || !y) return x+y;
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
void solve(){
	int n;
	cin >> n;
	for(int i = 1;i <= n;i++){
		root = merge(root,add(i));
	}
	for(int i = 1;i <= n;i++){
		int x;
		cin >> x;
		x%=fhq[root].sz;
		split_rank(root,x,T1,T2);
		split_rank(T2,1,T2,T3);
		root = merge(T3,T1);//删除一张后倒着合并,比如说1234 2 那么就是 3412删3,那么就是412
		cout << fhq[T2].val << endl;
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
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
const ll inf = 0x3f3f3f3f3f3f3f3fLL;
const int infi = 0x3f3f3f3f;
const int P = 13331;
const int N = 200005;
mt19937_64 rnd(time(0));
struct FHQ{
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
		x = y = 0;
		return;
	}
	int tp = fhq[fhq[u].ls].sz + 1;
	if(tp == k){
		x = u;
		y = fhq[u].rs;
		fhq[u].rs = 0;
	}else if(tp > k){
		y = u;
		split_rank(fhq[u].ls,k,x,fhq[u].ls);
	}else{
		x = u;
		split_rank(fhq[u].rs,k - tp,fhq[u].rs,y);
	}
	push_up(u);
}
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
void solve(){
	int n;
	cin >> n;
	for(int i = 1;i <= n;i++){
		int t;
		cin >> t;
		split(root,t - 1,T1,T2);
		root = merge(merge(T1,add(t)),T2);

	}
	int q;
	cin >> q;
	while(q--){
		string op;
		cin >> op;
		if(op=="add"){
			int x;
			cin >> x;
			split(root,x - 1,T1,T2);
			root = merge(merge(T1,add(x)),T2);
		}else{
			int sz = fhq[root].sz;
			int p = sz/2;
			//cout << p << endl;
			if(sz%2 == 0){
				split_rank(root,p,T1,T2);
				split_rank(T1,p - 1,T1,T3);
				cout << fhq[T3].val << endl;
				root = merge(merge(T1,T3),T2);
			}else{
				split_rank(root,p,T1,T2);
				split_rank(T2,1,T2,T3);
				cout << fhq[T2].val << endl;
				root = merge(merge(T1,T2),T3);
			}	
			
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
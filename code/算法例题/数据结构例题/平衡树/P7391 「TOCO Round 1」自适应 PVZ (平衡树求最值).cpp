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
const int N = 200005;
struct FHQ{
	int ls,rs,key,ma,mi,sz,val;
}fhq[N << 1];
int root,idx,T1,T2,T3;
void push_up(int u){
	fhq[u].sz = fhq[fhq[u].ls].sz + fhq[fhq[u].rs].sz + 1;
	fhq[u].mi = min(min(fhq[fhq[u].ls].mi,fhq[fhq[u].rs].mi),fhq[u].val); //注意是自己的val不是自己的mi或者ma
	fhq[u].ma = max(max(fhq[fhq[u].ls].ma,fhq[fhq[u].rs].ma),fhq[u].val);
}
void split(int u,int v,int &x,int &y){
	if(u==0){
		x = y = 0;
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
	if(fhq[x].key >= fhq[y].key){
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
	fhq[++idx] = {0,0,rnd(),v,v,1,v};
	split(root,v,T1,T2);
	root = merge(merge(T1,idx),T2);
}
void erase(int v){
	split(root,v,T1,T2);
	split(T1,v - 1,T1,T3);
	T3 = merge(fhq[T3].ls,fhq[T3].rs);
	root = merge(merge(T1,T3),T2);
}
void solve(){
	int n,m;
	cin >> n >> m;
	fhq[0].mi = 0x3f3f3f3f,fhq[0].ma = -10000;//注意对0的时候操作
	if(m >= n){
		cout << 0 << endl;
		return;
	}
	vt<PII> v;
	for(int i = 1;i <= n;i++){
		int l,r;
		cin >> l >> r;
		v.pb({l,r});
	}
	sort(all(v));
	int ans = 0;
	int us = 0;
	for(auto [l,r] : v){
		//cout << l << " " << r << " ";
		if(us < m){
			insert(r);
			us++;
		}else{
			int p = fhq[root].mi;
			//cout << p << " ";
			if(p <= l){
				erase(p);
				insert(r);
			}else{
				int p2 = fhq[root].ma;
				//cout << p2 << endl;
				ans++;
				if(p2 > r){
					erase(p2);
					insert(r);
				}
			}
		}
		//cout << endl;
	}
	cout << ans << endl;

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
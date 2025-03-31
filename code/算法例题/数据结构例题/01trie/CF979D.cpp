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
const int N = 100005;
int root[N],tr[N * 200][2],mi[N * 200],tot,val[N * 200]; //根,叶子,该节点下最小值,编号,最后原来值的大小
void add(int &u,int x,int d){
		if(!u) u = ++tot,mi[u] = inf;
		mi[u] = min(mi[u],x);
		if(d<0){
			val[u] = x;
			return;
		}
		add(tr[u][(x >> d) & 1],x,d - 1);
}
int query(int u,int x,int d,int k){
	if(!u) return -1;
	if(d < 0){
		return val[u];
	}
	int t0 = tr[u][0],t1 = tr[u][1];
	if(!t0 || mi[t0] > k) return query(t1,x,d - 1,k);
	if(!t1 || mi[t1] > k) return query(t0,x,d - 1,k);
	return query(tr[u][1 ^ ((x >> d) & 1)],x,d - 1,k); 
}
vt<int> v[N];
void solve(){
	for(int i = 1;i < N;i++){
		for(int j = i;j < N;j+=i){
			v[j].pb(i);
		}
	}
	int q;
	cin >> q;
	while(q--){
		int op;
		cin >> op;
		if(op == 1){
			int x;
			cin >> x;
			for(auto p:v[x]){
				add(root[p],x,16);
			}
		}else{
			int x,k,s;
			cin >> x >> k >> s;
			if(x%k || s - x < 0){
				cout << -1 << endl;
				continue;
			}
			cout << query(root[k],x,16,s - x) << endl;
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
//和爸爸一起学编程真好,不过要小学四年级分流考试了,最近没时间写代码了,呜呜呜
#include<bits/stdc++.h>
using namespace std;
#define out(x) cout << #x << '=' << (x) << endl
#define out2(x, y) cout << #x << '=' << (x) << ',' << #y << '=' << (y) << endl 
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
const int N = 9000005; //30 * 3e5 最坏每条链延伸30次 并且有3e5个点插入
#define lc tr[u][0]
#define rc tr[u][1]
int tr[N][2],idx;
int m[N],c[N],d[N];//到m这个节点的子树异或最小值,节点数量,节点真实值
int q;
int fa[N];
void update(int x,int k){
	int u = 0;
	//自底向上更新,因为低位可以先改保证最优性,所以从高到低枚举
	for(int i = 30;i >= 0;i--){
		int v = (x >> i)&1;
		if(tr[u][v]==-1) tr[u][v] = ++idx,fa[tr[u][v]] = u;
		c[u]+=k;
		u = tr[u][v];
	}
	c[u]+=k;
	m[u]=(c[u] >= 2 ? 0 : inf);
	d[u] = x;
	u = fa[u];
	while(u != -1){
		//当前节点2个子节点都没有,无法构成
		if(c[u] < 2){
			m[u] = inf;
		}
		else if(lc == -1){
			m[u] = m[rc];
		}else if(rc == -1){
			m[u] = m[lc];
		}else if(c[rc] == 1 && c[lc] == 1){
			m[u] = d[lc] ^ d[rc]; //如果一边一个那么只能异或
		}else{
			m[u] = min(m[lc],m[rc]); //不然就是两边最小
		}
		if(c[lc] + c[rc] ==1){
			d[u] = (c[lc] == 1 ? d[lc] : d[rc]);
		}else{
			d[u] = 0; //只有单个节点子儿子数量是1时候他的真实值才有意义
		}
		u = fa[u];
	}
}
void solve(){
	cin >> q;
	memset(fa,-1,sizeof fa);
	memset(tr,-1,sizeof tr);
	while(q--){
		int op,x;
		cin >> op;
		if(op==1) cin >> x,update(x,1);
		else if(op==2) cin >> x,update(x,-1);
		else cout << m[0] << endl;
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
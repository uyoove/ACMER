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
int n,k;
int p[N],c[N];
struct edgse{
	int v,ne;
}e[N << 1];
int h[N],idx = 1;
void add(int u,int v){
	e[++idx] = {v,h[u]};
	h[u] = idx;
}
int dfn[N],low[N],tot = 0; //时间戳,最小追溯值,编号 
int stk[N],instk[N],top = 0; //栈,是否在栈,编号 
int scc[N],siz[N],cnt = 0; //强联通分量表,每个强联通分量的大小,编号
int val[N];
void tarjan(int x){
	//入的操作
	dfn[x]=low[x]=++tot; //编号都统一从1开始
	stk[++top] = x,instk[x] = 1;
	for(int i = h[x];i;i=e[i].ne){
		int y = e[i].v;
		//如果没有时间戳 就继续走 走到底 走完了往回带值 
		if(!dfn[y]){
			tarjan(y);
			low[x] = min(low[x],low[y]); //更新 
		}else if(instk[y]){                   //如果拥有并且在栈中 说明是祖先节点或同辈节点 跟新low 
			low[x] = min(low[x],dfn[y]); 
		} 
		//还有就是有dfn时间戳 但是不在栈中 不执行操作 程序会\跳过,因为这种情况这个y值是属于了
		//另一个强联通分量,所以不操作就行了,程序会自动回溯; 
	}
	//走回来发现 自己就是最小时间戳,那么就确定scc组是自己以及刚遍历出去的节点; 
	if(dfn[x] == low[x]){
		int y;++cnt; //1编号开始; 
		 while(true){
		 	y = stk[top--];
		 	instk[y] = 0;
		 	scc[y] = cnt;
		 	++siz[cnt];
		 	val[cnt] += c[y];
		 	if(y==x){
		 		break;
			 }
		 }
	} 	 
}
int res = -inf,tmp = 0;
void dfs(int u,int bs){
	//cout << u << " " << bs << " " << tmp << endl;
	if(bs<=0) return;
	int v = p[u];
	tmp += c[v];
	res = max(res,tmp);
	dfs(v,bs - 1);
	tmp-=c[v];
	
}
void solve(){
	cin >> n >> k;
	for(int i = 1;i <= n;i++){
		cin >> p[i];
		add(i,p[i]);
	}
	for(int i = 1;i <= n;i++){
		cin >> c[i];
		res = max(res,c[i]);
	}
	for(int i = 1;i <= n;i++){
		if(!scc[i]){
			tarjan(i);
		}
		//cout << scc[i] << endl;
	}
	for(int i = 1;i <= n;i++){
		int bs = k;
		tmp = 0;
		if(k >= siz[scc[i]]){
			int t = siz[scc[i]];
			int num = k/t - 1;
			bs = k%t + t;
			tmp += num * (val[scc[i]]);
			if(num!=0) res = max(res,tmp);
		}
		//cout << "------" << endl;
		dfs(i,bs);
		tmp = 0;
		dfs(i,min(siz[scc[i]],k));
	}
	cout << res << endl;
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
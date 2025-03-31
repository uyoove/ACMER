//和爸爸一起学编程真好,不过要小学四年级分流考试了,最近没时间写代码了,呜呜呜
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <iostream>
#include <map>
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
const int N = 55;
struct node{
	int v,w;
	bool operator<(const node&t)const{
		return w > t.w;
	}
};
map<string,int> mp;
int n,k;
int g[N][N]; //邻接矩阵存图
//每个节点组号,每个点对于生成树的前驱,对于park节点最近的每组节点编号,prim的距离数组
int col[N],pre[N],fst[N],dis[N],tb[N]; 
int mx[N];//当前点连接的生成树最大边

int Prim(int u,int id){
	priority_queue<node>q;
	dis[u]=0;
	node t1 = {u,0};
	q.push(t1);
	int ans = 0;
	while(!q.empty()){
		node p = q.top();q.pop();
		int u = p.v;
		if(col[u]) continue;
		col[u] = id;
		ans += dis[u];
		for(int i = 1;i <= n;i++){
			if(!col[i] && g[u][i]!=0 && dis[i] > g[u][i]){
				pre[i] = u;
				dis[i] = g[u][i];
				node t1 = {i,dis[i]};
				q.push(t1);
			}
		}
	}
	return ans;
}
//找最大前驱边
void update(int cur,int last,int maxside){
	mx[cur] = maxside > g[cur][last] ? maxside : g[cur][last];
	for(int i = 1;i <= n;i++){
		//因为是生成树,只要不往回走就不会死循环
		if(i!=last && g[cur][i]!=0 &&(pre[cur]==i || pre[i]==cur)){
		 //因为是生成树,可能前驱顺序相反,所以有绝对序就看一会进入节点,另last!=i防止走重复节点
			update(i,cur,mx[cur]);
		}
	}
}
void work(){
	for(int i = 0;i <= n;i++){
		dis[i] = 0x3f3f3f3f;
		col[i] = pre[i] = fst[i] = 0;
	}
	int res = 0, cnt = 0; //cnt个最小生成树的答案,cnt个除去park节点的连通块
	for(int i = 1;i <= n;i++){
		if(!col[i]) res+=Prim(i,++cnt);
	}
	for(int i = 1;i <= n;i++){ //找与park最近的每个生成树森林的最近点操作
		int id = col[i];
		if(g[0][i]!=0 && (!fst[id] || g[fst[id]][0] > g[i][0])){
			fst[id] = i;
		}
	}
	for(int i = 1;i <= cnt;i++){
		res+=g[0][fst[i]]; //加入边并且删掉该边,就相当于绑定了park和各森林的边,这条边是最小的不能动
		g[0][fst[i]] = g[fst[i]][0] = 0;
		update(fst[i],0,0);// 找该森林最大边
	}
	//然后我们可以取找 k - cnt个边来试图更新最小生成树
	//设d为mx[i] - g[0][i],我们的res不断减掉d,最大化d
	//如果g[0][i] >= mx[i] 则不可更新
	k = k - cnt;
	while(k--){
		int tp = 0;
		for(int i = 1;i <= n;i++){
			if(g[0][i]!=0 && (tp==0 || mx[tp] - g[0][tp] < mx[i] - g[0][i])){
				tp = i;
			}
		}
		if(mx[tp] <= g[tp][0]) break;
		res=res-mx[tp]+g[tp][0];
		g[0][tp] = g[tp][0] = 0;
		//难理解,建议画图理解配合update理解
		int p = 0;
		for(int i = tp;pre[i]!=0;i=pre[i]){
			if(p==0||g[p][pre[p]] < g[i][pre[i]]){
				p = i;
			}
		}
		pre[p] = 0;//删除最大边
		update(tp,0,0);
	}
	 printf("Total miles driven: %d\n",res);
}
//输入,字符串映射建图
void solve(){
	string s1,s2;
	int m;
	cin >> m;
	memset(g,0,sizeof g);
	mp["Park"] = 0;//默认park节点为0,方便处理
	for(int i = 1;i <= m;i++){
		int w;
		cin >> s1 >> s2 >> w;
		if(!mp.count(s1)){
			mp[s1] = ++n;
		}
		if(!mp.count(s2)){
			mp[s2] = ++n;
		}
		int u = mp[s1],v = mp[s2];
		if(!g[u][v] || g[u][v] > w){
			g[u][v] = g[v][u] = w;
		}
	}
	cin >> k;
	work();
}

signed main(){
	int times = 1;
	//cin >> times;
	while(times--){
		solve();
	}
	return 0;
}
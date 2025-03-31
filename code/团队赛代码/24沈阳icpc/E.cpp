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
const int N = (1 << 16) + 7;
int a[4];
PII op[9];
//全为0的矩阵为1,左上角为1其余为0的矩阵为1 << 1,右上角为1其余为0的矩阵为1 << 2,以此类推
int change(int x,int tag){
	//默认0为全集即答案
	int y = 0;
	for(int i = 0;i < 16;i++){
		if(x >> i & 1){
			y |= 1 << (i ^ tag); 
		}
	}
	y &= (1 << 15) - 1; //第15位抹除掉 这样就能用0快速判断是否还有模块没有响起来
	return y;
}
struct edges{
	int v,w,ne;
}e[1 << 21];
int h[N],idx = 1;
void add(int u,int v,int w){
	e[++idx] = {v,w,h[u]};
	h[u] = idx;
}
int vis[N],dis[N];
void init(){
	memset(dis,0x3f,sizeof dis);
	op[0] = {1,a[0]}; //单改左上角
	op[1] = {2,a[0]}; //单改右上角
	op[2] = {4,a[0]}; //单改左下角
	op[3] = {8,a[0]}; //单改右下角

	op[4] = {3,a[1]};//上横
	op[5] = {12,a[1]};//下横	

	op[6] = {5,a[2]};//左竖
	op[7] = {10,a[2]};//右竖	

	op[8] = {15,a[3]};//全
	for(int i = 0;i < (1 << 16);i++){
		for(int j = 0;j < 9;j++){
			int v = change(i,op[j].fi);
			add(i,v,op[j].se);
			add(v,i,op[j].se);
		}
	}
	priority_queue<PII,vt<PII>,greater<PII>> q;
	q.push({0,0}); //全响集合反推到 每个集合
	dis[0] = 0;
	while(q.size()){
		PII p = q.top();q.pop();
		int u = p.se,val = p.fi;
		if(vis[u]) continue;
		vis[u] = 1;
		for(int i = h[u];i;i=e[i].ne){
			int v = e[i].v;
			if(dis[v] > dis[u] + e[i].w){
				dis[v] = dis[u] + e[i].w;
				q.push({dis[v],v});
			}
		}
	}
}

void solve(){
	int n;
	cin >> n;
	int jh = 0;
	for(int i = 1;i <= n;i++){
		string s1,s2;
		cin >> s1 >> s2;
		s1 += s2;
		int t = 0;
		for(int j = 0;j < 4;j++){
			if(s1[j]=='0') continue;
			t |= (1 << j);
		}
		jh |= (1 << t);
	}
	cout << dis[jh] << endl;
}

signed main(){
	std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
	int times = 1;
	cin >> times;
	for(int i = 0;i <= 3;i++) cin >> a[i];
	init();
	while(times--){
		solve();
	}
	return 0;
}
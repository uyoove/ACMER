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
//为什么时间复杂度是对的,因为每次删小的数加起来一共才是n,删和找复杂度都是log的,又因为,遍历不能遍历太多,因为吃不消
//所以我们删掉有利于时间复杂度,因为走到一个点那么他往后面能跳的所有数已经确定,不去重复找无用点
//首先尽可能置换小的,到一个点因为之前已经遍历的因素,所以不会重复遍历,每个点,只有在该加入的时候才会加入
//不该加入时候不会加入
//用set的单调控制大的数不会在不该访问时候被访问,用setlog删除不该被访问的小的节点,此为松弛
int vis[N];//表示该牌是否被换
int pos[4][N];//表示在每个人手里 j这张票的绝对位置 
int n;
set<PII> se[4],se2[4];//表示 {价值,牌号}, 表示 {价值排名,牌号}
PII last[N];
void solve(){
	cin >> n;
	for(int i = 1;i<= 3;i++){
		se[i].clear();
		se2[i].clear();
		for(int j = 1;j<=n;j++){
			pos[i][j] = 0;
			vis[j] = 0;
			last[j] = {};
			int val;
			cin >> val;
			se[i].insert({val,j});
		}
		int idx = 0;
		for(auto &[k,v]:se[i]){
			pos[i][v] = idx;
			se2[i].insert({idx,v});
			idx++;
		}
	}
	set<int> can;//我不能去的地方

	priority_queue<int,vt<int>,greater<int>> q;
	for(int i = 1;i <= 3;i++){
		for(int j = 2; j<= n;j++){
			if(pos[i][1] > pos[i][j]){
				q.push(j);
				last[j] = {1,i};
			}
		}
	}
	for(int i = 2; i<= n;i++) can.insert(i);
	while(q.size()){
		int u = q.top();q.pop();
		if(vis[u]) continue;
		vis[u] = 1;
		vt<int> v;
		for(auto &p:can){
			if(p <= u) v.pb(p);
			else break;
		}
		for(auto &p:v){
			can.erase(p);
			for(int i = 1;i <= 3;i++){
				PII p1 = {pos[i][p],p};
				if(se2[i].count(p1)) se2[i].erase(p1);
			}
		}
		
		for(int i = 1;i <= 3;i++){
			int mx = 0;
			v.clear();
			for(auto &d:se2[i]){
				int p = d.se;
				if(pos[i][u] <= d.fi) break; //大作用
				q.push(p);
				v.pb(d.se);
				last[p] = {u,i};
			}
			for(auto c:v){
				for(int i1 = 1;i1 <= 3;i1++){
					PII c1 = {pos[i1][c],c};
					if(se2[i1].count(c1)) se2[i1].erase(c1);
				}
			}
		}	
		
	}
	if(!vis[n]){
		cout << "No" << endl;
		return;
	}
	cout << "Yes" << endl;
	vt<pair<char,int>> ans;
	char ch[4] = {' ','q','k','j'};
	int x = n;
	//for(int i = 1;i <= n;i++) cout << last[i].fi <<endl;
	while(x!=1){
		char c = ch[last[x].se];
		ans.pb({c,x});
		x = last[x].fi;
	}
	cout << ans.size() << endl;
	reverse(all(ans));
	for(auto p:ans) cout << p.fi << " " << p.se << endl;
}

signed main(){
	std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
	int times = 1;
	cin >> times;
	while(times--){
		solve();
	}
	return 0;
}
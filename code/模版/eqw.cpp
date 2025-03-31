//和爸爸一起学编程真好,不过要小学四年级分流考试了,最近没时间写代码了,呜呜呜
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define out(x) cout << #x << '=' << (x) << endl
#define out2(x, y) cout << #x << '=' << (x) << ',' << #y << '=' << (y) << endl 
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
const int N = 1000005;
struct edges{
	int v,ne,w;
}e[N << 1];
int h[N],idx = 1;
void add(int u,int v,int w){
	e[++idx] = {v,h[u],w};
	h[u] = idx;
}
struct node{
	int u,v,w;
	bool operator<(const node t1)const{
		if(t1.u!=u) return t1.u < u;
		if(t1.v!=v) return t1.v < v;
		return t1.w < w;
	}
}ns[N];
int vis[100005];
int vis2[100005];
int col[100005];
void solve(){
	int n,m;
	cin >> n >> m;
	map<PII,int> h1;
	bool f = true;
	for(int i = 1;i <= m;i++){
		cin >> ns[i].u >> ns[i].v >> ns[i].w;
		if(ns[i].u == ns[i].v && ns[i].w) f= false;
		if(ns[i].u > ns[i].v) swap(ns[i].u,ns[i].v);
		if(h1.count({ns[i].u,ns[i].v})){
			if(h1[{ns[i].u,ns[i].v}] != ns[i].w){
				f = false;
			}
		}
		h1[{ns[i].u,ns[i].v}] = ns[i].w;
	}
	if(!f){
		cout << -1 << endl;
		return;
	}
	int ans = 0;
	for(int i = 0;i <= 30;i++){
		memset(col,0,sizeof col);
		memset(vis,0,sizeof vis);
		memset(vis2,0,sizeof vis2);
		memset(h,0,sizeof h);
		idx = 1;
		int res = 0;
		set<node> se;
		for(int j = 1;j <= m;j++){
			add(ns[j].u,ns[j].v,(ns[j].w>>i)&1);
			add(ns[j].v,ns[j].u,(ns[j].w>>i)&1);
			res +=(ns[j].w>>i)&1;
			if((ns[j].w>>i)&1){
				se.insert(ns[j]);
			}
		}
		while(se.size()){
			bool f=false;
			int rt = 0;
			int rt2 = 0;
			map<int,int> h1;
			int ct = 0;
			int re = 0;
			node g1;
			set<node> se2;
			for(auto &p : se){
				if(!vis[p.u] && !vis[p.v] &&(p.w>>i)&1){
					col[p.v] = 1;
					rt = p.v;
					rt2 = p.u;
					vis[p.v] = 1;
					f=true;
					ct += (1 << i);
					g1 = p;
					break;
				}
				else{
					se2.insert(p);
				}
			}
			se.erase(g1);
			for(auto &p:se2){
				se.erase(p);
			}
			//cout << i <<  " " << rt << endl;
			if(!f){

				break;
			}
			f = true;
			queue<int> q;
			//cout << rt << endl;
			q.push(rt);
			while(q.size()){
				int u = q.front();q.pop();
				int c = col[u];
				int bc;
				//cout << u << endl;
				for(int i1 = h[u];i1;i1=e[i1].ne){
					int v = e[i1].v;

					if(e[i1].w == 0) bc = c;
					else bc = c^1; 
					if(vis[v]){
						if(col[v]!=bc){
							f=false;
							break;
						}
						continue;
					}
					col[v] = bc;
					ct += (bc << i);
					vis[v] = 1;
					h1[v]++;
					q.push(v);
				}
				if(!f) break;
			}
			queue<int> p;
			q = p;
			//cout << ct << endl;
			if(!f) ct = 0x3f3f3f3f3f;
			int ct2 = 0;
			vis[rt] = 0;
			col[rt] = 0;
			for(auto [k,v]:h1) vis[k]=0,col[k] = 0;
			vis[rt2] = 1;
			col[rt2] = 1;
			ct2 += (1<<i);
			map<int,int> h2;
			//cout << rt << endl;
			q.push(rt2);
			bool f2=false;
			while(q.size()){
				if(f2) break;
				int u = q.front();q.pop();
				int c = col[u];
				int bc;
				//cout << u << endl;
				for(int i1 = h[u];i1;i1=e[i1].ne){
					int v = e[i1].v;

					if(e[i1].w == 0) bc = c;
					else bc = c^1; 
					if(vis[v]){
						if(col[v]!=bc){
							if(!f){
								cout << -1 << endl;
								return;
							}else{

								for(auto [k,v]:h1) vis[k]=1;
								vis[rt] = 1;
							    for(auto [k,v]:h2) vis[k]=0;
							    vis[rt2] = 1;
								ans+=ct;
								f2 = true;
								cout << ans << endl;
								break;
							}
						}
						continue;
					}
					col[v] = bc;
					ct2+=(bc << i);
					vis[v] = 1;
					h2[v]++;
					q.push(v);
				}
				
			}
			if(f2) continue;
			if(ct > ct2){

					ans+=ct2;
					for(auto [k,v]:h2) vis[k]=1;
				}else{
					ans+=ct;
					vis[rt] = 1;
					for(auto [k,v]:h1) vis[k]=1;
				}

		}
		
		
	}
	cout << ans << endl;
}

signed main(){
	// std::ios::sync_with_stdio(0);
    // std::cin.tie(0);
    // std::cout.tie(0);
	int times = 1;
	//cin >> times;
	while(times--){
		solve();
	}
	return 0;
}
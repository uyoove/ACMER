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
int dp[N],cs[N];
struct edges{
	int v,ne;
}e[N << 1];
int h[N],idx = 0;
int val[N],c[N];
void add(int u,int v){
	e[idx] = {v,h[u]};
	h[u] = idx++;
}
void dfs(int u,int f){
	dp[u] = 0;
	int mx3 = 0,i3 = 0; //最大的sum3权值
	int mx2 = 0,i2 = 0; //最大的sum2权值
	int mx1 = 0,i1 = 0; //最大的sum1权值

	int mxx3 = 0,ii3 = 0; //次大的sum3权值

	int vx3 = 0,iv3 = 0;//最大的v3权值
	int vx2 = 0,iv2 = 0;//最大的v2权值
	int vx1 = 0,iv1 = 0;//最大的v1权值
	bool f1 = false;
	int vxx3 = 0,ivv3 = 0; //次大的sum3权值

	int suu = 0;
	for(int i = h[u];~i;i = e[i].ne){
		int v = e[i].v;
		if(v==f) continue;
		f1= true;
		dfs(v,u);
		int lx = c[v];
		int su = dp[v];
		int ct = val[v];
		suu+=dp[v];
		cs[u] += val[v];
		if(lx == 1){
			if(su > mx1){
				mx1 = su;
				i1 = v;
			}
			if(ct > vx1){
				vx1 = ct;
				iv1 = v;
			}
		}else if(lx==2){
			if(su > mx2){
				mx2 = su;
				i2 = v;
			}
			if(ct > vx2){
				vx2 = ct;
				iv2 = v;
			}
		}else{
			if(su > mx3){
				mxx3 = mx3;
				ii3 = i3;
				mx3 = su;
				i3 = v;
			}else if(su == mx3){
				mxx3 = mx3;
				ii3 = v;
			}
			if(ct > vx3){
				vxx3 = vx3;
				ivv3 = iv3;
				vx3 = ct;
				iv3 = v;
			}else if(ct == vx3){
				vxx3 = ct;
				ivv3 = v;
			}else {
				if(ct > vxx3){
					vxx3 = ct;
				}
			}
		}
	}
	if(!f1) return;
	int res = 0;
	int sumx = max(max(vx3,vx2),vx1);
	//cout << u << " " << sumx << endl;
	int d = 0;
	for(int i = h[u];~i;i = e[i].ne){
		int v = e[i].v;
		if(v==f) continue;
		int lx = c[v];
		if(iv3 != v) res = max(res,val[v] + vx3 - cs[v]);
		else res = max(res,val[v] + vxx3 - cs[v]);
		res = max(res,val[v]);
	}
	
	
	
	//cout << u << " " << vx3 << " " << sumx << endl;
	dp[u] = dp[u] + res + suu;
}
void solve(){
	idx = 0;
	int n;
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> val[i];
		h[i] = -1;
		dp[i] = 0;
		cs[i] = 0;
	}
	for(int i = 1;i <= n;i++){
		cin >> c[i];
	}
	for(int i = 1;i < n;i++){
		int u,v;
		cin >> u >> v;
		add(u,v);
		add(v,u);
	}
	dfs(1,0);
	cout << dp[1] + val[1] << endl;
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
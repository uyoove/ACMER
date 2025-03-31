//题意:给你一个信号装置转换表n*k,然后 后m个 信号是有效的,问有没有有效路径
//然后每个节点有一个编号
#include<bits/stdc++.h>
using namespace std;
#define out(x) cout << #x << '=' << (x) << endl
#define out2(x, y) cout << #x << '=' << (x) << ',' << #y << '=' << (y) << endl 
#define int long long
#define lc u<<1
#define rc u<<1|1
#define pb push_back

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
int n,m,k;
const int M = 201;
struct node{
	int ld,rd;
};
vector<node> vt[M][M];
char tree[10006];
int h;
int id;
bool dfs(int node,int xh){
	if(tree[node]=='*'||node>=id){
		if(xh<n-m) return false;
		return true;
	}
	int k = tree[node] - 'a';
	int l = (node*2) + 1;
	int r = l + 1;
	for(int i = 0;i < vt[xh][k].size();i++){
		int xh1 = vt[xh][k][i].ld;
		int xh2 = vt[xh][k][i].rd;
		if(dfs(l,xh1) && dfs(r,xh2)) return true; 
	}
	return false;
}
void solve(){
	for(int i = 0;i<n;i++){
		for(int j = 0;j < k;j++){
			vt[i][j].clear();
			while(1){
				node n1;
				cin >> n1.ld >> n1.rd;
				vt[i][j].pb(n1);
				char ch;
				ch = cin.get();
				if(ch=='\n') break;
			}
			
		}
	}

	
	while(cin >> h){
		if(h==-1) break;
		id = 0;
		for(int i = 0;i <= h;i++){
			for(int j = 0;j<(1<<i);j++){
				char ch;
				cin >> ch;
				tree[id] = ch;
				id++;
			}
		}
		if(dfs(0,0)){
			cout << "Valid" << endl;
		}else{
			cout << "Invalid" << endl;
		}
	}
	

	

}

signed main(){
	
	int times = 1;
	//cin >> times;
	int t = 0;
	while(cin >> n >> m >> k){
		if(n==0&&m==0&&k==0) break;
		++t;
		if(t!=1) cout <<endl;
		cout <<"NTA" << t <<":" << endl;
		solve();
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define vt vector
#define fi first
#define se second 
const int N = 2e5 + 10;
//struct edges{
//	int v,ne;
//}e[N << 1];
//int h[N],idx = 1;
//void add(int u,int v){
//	e[++idx] = {v,h[u]},h[u] = idx;
//} 
//int fk[N];
//void addfk(int k,int op){
//	for(int i = k;i < N ;i += (i&-i)) fk[i]+=op;
//}
//int queryfk(int k){
//	int res = 0;
//	for(int i = k;i > 0;i-= (i&-i)) res+=fk[i];
//	return res;
//}
int n,l,r;
//void memo[N][N];
vt<int> v1,v2;
vt<int> t;
int dfs(int pos,int val,int limit,int down){
	if(pos==n){
		 cout << val << endl;
		return 1;
	}
	int res = 0;
		int low = down ? v1[pos] : 0;
		int up = limit ? v2[pos] : 9; 
		for(int i = low;i <= up;i++){
			int t = val*10+i;
			if(t%(pos+1)==0) res+=dfs(pos+1,val*10 + i,limit&&i==v2[pos],down&&i==v1[pos]);
		}
	
	return res;
}
void solve(){
	cin >> n >> l >> r;
	int x = l;
	while(x){
		v1.push_back(x%10);
		x/=10;
	}
	reverse(v1.begin(),v1.end());
	x = r;
	while(x){
		v2.push_back(x%10);
		x/=10;
	}
	reverse(v2.begin(),v2.end());
	dfs(0,0,1,1);
//	sort(t.begin(),t.end());
//	for(auto p:t){
//		cout << p << endl;
//	}
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	solve();
}

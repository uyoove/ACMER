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
int n;
struct nodes{
	int x1,y1,x2,y2,x3,y3;
	bool operator<(const nodes &t1)const{
		if(x2 != t1.x2) return x2 < t1.x2;
		return x1 < t1.x1;
	}
};
set<nodes> v;
vt<int> p[3];
void solve(){
	cin >> n;
	for(int i = 1;i <= n;i++){
		int x,y;
		cin >> x >> y;
		p[y].push_back(x);
	} 
	for(int i = 0;i < p[0].size();i++){
		int x1 = p[0][i];
		for(int j = 0;j < p[1].size();j++){
			int x2 = p[1][j];
			if(x1==x2) continue;
			for(int k = 0;k < p[2].size();k++){
				int x3 = p[2][k];
				if(x3==x2||x3==x1) continue;
				
				double p1 = abs(x2 - x1)*1.0/1.0;
				double p2 = abs(x3 - x2)*1.0/1.0;
				double p3 = abs(x3 - x1)*1.0/2.0;
				if(p1==p2&&p2==p3&&p3==p1){
					v.insert({x1,0,x2,1,x3,2});
				}
				
			}
		}
	}
	for(auto p:v){
		cout << "[" << p.x1 << ", " << p.y1 << "] " <<"[" << p.x2 << ", " << p.y2 << "] " <<"[" << p.x3 << ", " << p.y3 << "]" << endl; 
	}

}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	solve();
}

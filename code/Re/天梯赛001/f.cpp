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
		if(x1!=t1.x1) x1 < t1.x1;
		if(y1!=t1.y1) y1 < t1.y1;
		if(x3!=t1.x3) x3 < t1.x3;
		if(y3!=t1.y3) y1 < t1.y3;
		return y2 < t1.y2;
	}
};
vt<nodes> v;
vt<int> p[3];
map<int,int> cnt;
void solve(){
	cin >> n;
	for(int i = 1;i <= n;i++){
		int x,y;
		cin >> x >> y;
		p[y].push_back(x);
		if(y==2){
			cnt[x]++;
		}
	} 
	for(int i = 0;i < p[0].size();i++){
		int x1 = p[0][i];
		for(int j = 0;j < p[1].size();j++){
			int x2 = p[1][j];
			int t = abs(x2-x1);
			int t3 = max(x2,x1) + t,t4 = min(x2,x1) - t;
			int d1 = cnt[t3],d2 = cnt[t4];
			int x3 = t3;
			if(x3 - x2 == x2 - x1 && (double)(x3 - x1)*1.0/2 == x2-x1){
				if(d1--){
					v.push_back({x1,0,x2,1,t3,2});
				}
			}
			x3 = t4;
			if(x3 - x2 == x2 - x1 && (double)(x3 - x1)*1.0/2 == x2-x1){
				if(d2--){
					v.push_back({x1,0,x2,1,t4,2});
				}
			}
			
		}
	}
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	if(v.size()==0){
		cout << -1 << endl;
		return;
	}
	for(auto p:v){
		cout << "[" << p.x1 << ", " << p.y1 << "] " <<"[" << p.x2 << ", " << p.y2 << "] " <<"[" << p.x3 << ", " << p.y3 << "]" << endl; 
	}

}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	solve();
}

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
void solve(){
	int n;
	cin >> n;
	
	for(int p = 10;p >= 1;p--){
		int t = 0;
		int id = 1;
		while(t < n){
			t+=powl(id,p);
			id++;
			if(t > 1000000000) {
				t = -1;
				break;
			}
		}	
		if(t==n){
			bool f = 1;
			for(int i = 1;i < id;i++){
				if(!f) cout << "+" << i << "^" << p;
				else{
					f = 0;
					cout << i << "^" << p;
				} 
			}
			return;
		}
	}
	cout <<"Impossible for " << n << endl;
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	solve();
}

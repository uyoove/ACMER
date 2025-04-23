#include<bits/stdc++.h>
using namespace std;
#define vt vector
#define fi first
#define se second 
const int N = 1e3 + 10;

int r[N],c[N];
struct nodes{
	int x,y,val;
	bool operator <(const nodes &t1)const{
		if(val!=t1.val) return val < t1.val;
		if(x!=t1.x) return x<t1.x;
		return y<t1.y;
	}
		
};
int g[N][N];
void solve(){
	int n,m,k;
	cin >> n >> m >> k;
	vector<nodes> vd;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			cin>>g[i][j];
			vd.push_back({i,j,g[i][j]});
		}
	}
	sort(vd.begin(),vd.end());
	while(k--){
		while(true){
			int id = vd.size() - 1;
			nodes t = vd[id];
			if(c[t.y] || r[t.x]){
				vd.pop_back();
                if(vd.size()==0) break;
			}else{
				c[t.y] = 1,r[t.x] = 1;
				vd.pop_back();
				break;
			}
		}	
	}
	for(int i = 1;i <= n;i++){
		bool f=  1;
		for(int j = 1;j <= m;j++){
			if(r[i]||c[j]) continue;
			if(f){
				f = 0;
				cout << g[i][j];
			}else{
				cout << " " << g[i][j];
			}
		}
		if(!f) cout << '\n';
	}
	
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	solve();
}

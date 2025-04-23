#include<bits/stdc++.h>
using namespace std;
#define int long long
#define vt vector
#define fi first
#define se second 
const int N = 2e5 + 10;
int n,m;
void solve(){
	cin >> n >> m;
	vt<vt<int>> p(n + 1,vt<int>(m + 1,0)); 
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			cin >> p[i][j];
		}
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			int cnt = 0;
			for(int k = 1;k <= n;k++){
				cnt += k;
			}
			for(int k = 1;k <= m;k++){
				cnt+= k;
			}
			if(j==1){
				cout << cnt * p[i][j];
			}else{
				cout << " " <<  cnt * p[i][j];
			}
		}
		cout << endl;
	}
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	solve();
}

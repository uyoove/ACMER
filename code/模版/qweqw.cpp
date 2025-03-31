#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 7;
int n,m;
int sz[N],bz[N],f[N];
int fd(int x){
	if(f[x]!=x){
		f[x] = fd(f[x]);
	}
	return f[x];
}
void merge(int x,int y){
	x = fd(x),y = fd(y);
	if(x==y) return;
	f[x] = y;
	sz[y]+=sz[x];
	bz[y]+=bz[x];
}
void solve(){
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		f[i] = i;
		sz[i] = 1;
	}
	int res = 0;
	set<int> se;
	for(int i = 1;i <= m;i++){
		int u,v;
		cin >>u >> v;
		merge(u,v);
		bz[fd(u)]++;
	}
	int mi1 = 1e12,mi2 = 1e12; 
	for(int i = 1;i <= n;i++){
		if(!se.count(fd(i))){
			se.insert(fd(i));
			res += -bz[fd(i)] +  sz[fd(i)] * (sz[fd(i)] - 1)/2;
			if(sz[fd(i)] < mi1){
				mi2 = mi1;
				mi1 = sz[fd(i)];
			}else if(sz[fd(i)] < mi2){
				mi2 = sz[fd(i)];
			}
		}
	}

	if(res==0){
		cout << res + mi1*mi2 << endl;

	}else{
		cout << res << endl;
	}

}

signed main(){
	std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
	int t = 1;
	//cin >> t;
	while(t--){
		solve();
	}
}
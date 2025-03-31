#include<bits/stdc++.h>
#define LL long long
#define endl '\n'
using namespace std;
const int N = 1e6 + 10;
int n;
int in[N];
int fa[N];
void solve(){
	cin >> n;
	for(int i = 1;i <= n;i++){
		in[i] = 0;
		fa[i] = 0;
	}
	for(int i = 2;i <= n;i++){
		int t;
		cin >> t;
		fa[i] = t;
		in[t]++;
	}
	vector<int> v,v1;
	for(int i=1;i<=n;i++){
		if(in[i]==0){
			v.push_back(i);
		}
	}
	int ans = 1;
	int mx = 1e9;
	int sz = v.size();
	mx = min(mx,1 + sz - 1);
	while(v.size()>1){
		v1.clear();
		for(int x:v){
			if(--in[fa[x]]==0){
				v1.push_back(fa[x]);
			}
		}
		v = v1;
		ans++;
		int sz = v.size();
		mx = min(mx,ans + sz - 1);
	}
	cout << mx << endl;
}

signed main(){

	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
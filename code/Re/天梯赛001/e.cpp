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
int ch[26];
int val[26];
void solve(){
	string s;
	cin >> s;
	int ans = 0;
	for(int i = 0;i < 26;i++) cin >> val[i];
	for(auto p:s){
		ch[p-'a']++;
		ans+=val[p-'a'];
	}
	bool f = 1;
	for(int i = 0;i < 26;i++){
		if(f){
			f = 0;
			cout << ch[i];
		}else{
			cout << " " << ch[i];
		}
	}
	cout << endl;
	cout << ans << endl; 
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	solve();
}

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
	string s;
	cin >> s;
	stack<string> st;
	string tmp = "";
	int t = 1;
	for(auto &p:s){
		if(p=='('){
			if(tmp!=""){
				st.push(tmp);
				tmp = "";
			}
			t++;
		}else if(p==')'){
			if(tmp!=""){
				st.push(tmp);
				tmp = "";
			}
			if(st.size()){
				cout << st.top() <<endl;
				st.pop();
			}
		}else{
			tmp += p;
		}
	}
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	solve();
}

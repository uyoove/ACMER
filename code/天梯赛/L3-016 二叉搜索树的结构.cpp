#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 110;
const int d = 1e9 + 139213;
int n;
map<int,int> dep,fa;
set<int> se;
struct edges{
	int val,ls,rs;
};
map<int,edges> e;
int root;
void dfs(int u,int p){
	dep[p]++;
	if(p < e[u].val){
		if(e[u].ls==d){
			fa[p] = u;
			e[u].ls = p;
			e[p] = {p,d,d};
			dep[p]++;
		}else{
			dfs(e[u].ls,p);
		}
	}else{
		if(e[u].rs==d){
			fa[p] = u;
			e[u].rs = p;
			e[p] = {p,d,d};
			dep[p]++;
		}else{
			dfs(e[u].rs,p);
		}
	}
}
void solve(){
	cin >> n;
	cin >> root;
	se.insert(root);
	fa[root] = 321414210421;
	e[root] = {root,d,d};
	for(int i = 1;i < n;i++){
		int v;
		cin >> v;
		dfs(root,v);
		se.insert(v);
	}
	int q;
	cin >> q;
	while(q--){
		int u,v;
		cin >> u;
		string op;
		cin >> op;
		if(op=="is"){
			cin >> op;
			cin >> op;
			if(op=="root"){
				if(root == u && se.count(u)){
					cout << "Yes" << endl;
				}else{
					cout << "No" << endl;
				}
				continue;
			}else if(op=="left"){
				cin >> op >> op;
				cin >> v;
				if(e[v].ls==u&& se.count(u) && se.count(v)){
					cout << "Yes" << endl;
				}else{
					cout << "No" << endl;
				}
			}else if(op=="right"){
				cin >> op >> op;
				cin >> v;
				if(e[v].rs==u && se.count(u) && se.count(v)){
					cout << "Yes" << endl;
				}else{
					cout << "No" << endl;
				}
			}else{
				cin >> op;
				cin >> v;
				if(fa[v]==u && se.count(u) && se.count(v)){
					cout << "Yes" << endl;
				}else{
					cout << "No" << endl;
				}	
			}
		}else{
			cin >> v;
			cin >> op >> op;
			if(op=="siblings"){
				if(fa[v]==fa[u] && se.count(u) && se.count(v)){
					cout << "Yes" << endl;
				}else{
					cout << "No" << endl;
				}
			}else{
				if(dep[v]==dep[u] && se.count(u) && se.count(v)){
					cout << "Yes" << endl;
				}else{
					cout << "No" << endl;
				}
				cin >> op >> op >> op;
			}
		}
	}
}
signed main(){
	solve();
}

#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
	int a,op,b;
	cin >> a >> op >> b;
	if(op==1){
		if(a > 35){
			cout << "Bu Tie" << endl;
			cout << a << endl;
			return;
		}
		cout << "Bu Re" << endl;
		cout << a << endl;
	}else{
		if(b >= 33){
			cout << "Shi Nei" << endl;
			cout << a << endl;
			return;
		}
		cout << "Shu Shi" << endl;
		cout << b << endl;
	} 
}
signed main(){
	solve();
}

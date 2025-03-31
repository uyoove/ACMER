#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 7;
int n,m;
int a[N];
void solve(){
	//6 11 19 25 26 34
	cin >> n >> m;
	int su = 0;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		su += a[i];
	}
	int p = su%m;
	int xy = m - p;
	if(p==0){
		cout << 0 << endl;
		cout << 0 << " " << 0 << endl;
		return;
	}
	int k = (1 +n)*n/2;
	int g = __gcd(__gcd(k,n),m);
	 for(int i = 1;i <= 10;i++){
	 	cout << (21 * i)%24 << " ";
	 }
	 cout << endl;
	 for(int i = 1;i <= 10;i++){
	 	cout << (6 * i)%24 << " ";
	 }
	cout<<endl <<"---------------------------" <<endl;

	for(int i = 1;i <= 10;i++){
		for(int j = 1;j <= 10;j++){
			cout << (21* i + 6* j)%24 << " ";
		}
		cout << endl;
	}
	if(g==1){
		cout<< 0 << endl;

	}else{
		cout << (((xy + g - 1)/g) * g + su)%m << endl;
	}
	
	
}

signed main(){

	int t = 1;
	//cin >> t;
	while(t--) solve();
}
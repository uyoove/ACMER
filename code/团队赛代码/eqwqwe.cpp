#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 3e5+7;
int n;
pair<int,int> p;
int query(int u,int v){
	cout << "? " << u << " " << v << endl;
	int t;
	cin >> t;
	return t;
}
int solve(){
	cin >> n;
	int cnt = 0;
	for(int i = 1;i <= n;i+=2){
		if(i+1>n) continue;
		int t = query(i,i+1);
		if(t){
			std::vector<int> v;
			int a=i,b=i+1,cnt=0,c=0;
			for(int j=1;j<=n;j++){
				if(j!=a && j!=b){
					v.push_back(j);
					if(v.size()>=2) break;
				}
			}
			t = query(a,v[0]);
			if(t==1){
				int t1 = query(a,v[1]);
				if(t1==1) return 2;		
				return 1;
			}
			t = query(b,v[0]);
			if(t==0) return 1;
			t = query(b,v[1]);
			if(t==0) return 1;
			return 2;

		}
	}
	if(n%2==0) return 1;
	int t1 = query(1,n);
	int t2 = query(2,n);
	int t3 = query(3,n);
	return t1+t2+t3==3 ? 2 : 1;
}

signed main(){

	int times = 1;
	cin >> times;
	while(times--){
		int j = solve();
		cout << "! " << j << endl;
	}
	return 0;
}
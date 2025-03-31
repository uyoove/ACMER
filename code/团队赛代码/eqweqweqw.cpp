#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 7;
struct nb{
	string s;
	int id;
	bool operator<(const nb& t1)const{
		return s < t1.s;
	}
};
string s[N];
int cnt[26];//表示当前是字符p的时候的逆序对数量
void solve(){
	int n,m;
	cin >> n >> m;
	vector<int> v[26];
	for(int i = 1;i <= n;i++){
		cin >> s[i];
		cnt[s[i][0] - 'a']+=i-v[s[i][0] - 'a'].size()-1;
		v[s[i][0] - 'a'].push_back(i);	
	}
	for(int i = 0;i < 26;i++){
		cout << (char)(i + 'a') << " " << cnt[i] << endl; 
	}

	
	
}

signed main(){

	int t = 1;
	//cin >> t;
	while(t--) solve();
}
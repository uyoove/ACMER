#include<bits/stdc++.h>
using namespace std;
#define ULL unsigned long long
const int N = 1e5 + 7;
const int B = 131;
ULL p[N],h[N],bh[N];
int n,m;
int a[N],len[N];
int f[N];
pair<int,int> hs[N];
ULL fd(int l,int r){
	return h[r] - h[l - 1]*p[r-l+1];
}
void solve(){
	p[0] = 1;
	for(int i = 1;i <= N;i++){
		p[i] = p[i - 1] * B;
	}
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		h[i] = h[i - 1]*B + a[i];
	}
	cin >> m;
	for(int i = 1;i <= m;i++){
		cin >> len[i];
		for(int j = 1;j <= len[i];j++){
			int t;
			cin >> t;
			bh[i] = bh[i]*B + t;
		}
	}
	f[0] = 1;
	bool f1=false;
	for(int i = 1;i <= n;i++){
		int id = -1,hq = -1;
		for(int j = 1;j <= m;j++){
			//if(dp[i][j]) continue;
			if(i-len[j]+1 <= 0) continue;
			int l = i - len[j] + 1;
			if(fd(l,i)==bh[j]  && f[l - 1]==1){
				f[i - 1] = 1;
				id = l - 1;
				hq = j;
				hs[i] = {l,j};
			}
		}
	}
	vector<int> res;
	int idx = n;
	while(true){

		res.push_back(hs[idx].second);
		idx = hs[idx].first;
		if(idx==0) break;
	}
	reverse(res.begin(),res.end());
	for(int i = 1;i < res.size();i++){
		if(i!=1) cout << " ";
		cout << res[i];
	}
}

signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	solve();
}
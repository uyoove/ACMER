#include <bits/stdc++.h>
#define int long long
using namespace std;
int b=13331;
const int N=1e6+10;
unsigned long long pre[N],suf[N],p[N];

void solve(){
	int n,q;cin>>n>>q;
	string s;cin>>s;
	s="s"+s;
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]*b+(s[i]-'a'+1);	
	}
	for(int i=n;i>=1;i--){
		suf[i]=suf[i+1]*b+(s[i]-'a'+1);
	}
	p[1]=b;
	for(int i=2;i<=n;i++){
		p[i]=p[i-1]*b;
	}
	while(q--){
		int l,r;cin>>l>>r;
		if((pre[r]-pre[l-1])*(p[r - l + 1])==(suf[l]-suf[r+1])*(p[r-l+1]))cout<<"B";
		else{
			if((r-l)&1)cout<<"B";
			else cout<<"A";
		}
	}
	return;
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	solve();
	return 0;
}
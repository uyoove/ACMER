#include<bits/stdc++.h>
using namespace std;
#define ULL unsigned long long
#define ll long long
const ll P= 13331;
const ll mod1 = 1e9+7;
const ll mod2 = 1e9+9;
const ll N= 1e6+5;
ULL p[N],p1[N],hs[N],rhs[N],hs1[N],rhs1[N];
bool check(ll l,ll r){
	ULL  p0=(hs[r]-hs[l-1]*p[r-l+1]%mod1 +mod1)%mod1;
	ULL  p2=(rhs[l]-rhs[r+1]*p[r-l+1]%mod1 +mod1)%mod1;
	ULL  p3=(hs1[r]-hs1[l-1]*p1[r-l+1]%mod2 +mod2)%mod2;
	ULL  p4=(rhs1[l]-rhs1[r+1]*p1[r-l+1]%mod2 +mod2)%mod2;
	return p0==p2 && p3==p4;
}
void solve(){
	string s;
	cin >> s;
	ll n=s.size();
	if(n==1){
		cout << s;
		return;
	}
	s=' '+s;
	p[0]=1;
	p1[0] = 1;
	rhs[n+1]=0;
	rhs1[n+1]=0;
	for(ll i=1;i<=n;i++){
		p[i]=p[i-1]*P%mod1;
		hs[i]=hs[i-1]*P+s[i];
		hs[i]%=mod1;
	}
	for(ll i=1;i<=n;i++){
		p1[i]=p1[i-1]*P%mod2;
		hs1[i]=hs1[i-1]*P+s[i];
		hs1[i]%=mod2;
	}
	for(ll i=n;i>=1;i--){
		rhs[i]=rhs[i+1]*P+s[i];
		rhs[i]%=mod1;
	}
	for(ll i=n;i>=1;i--){
		rhs1[i]=rhs1[i+1]*P+s[i];
		rhs1[i]%=mod2;
	}
	ll l=1,r=n,t=0;
	while(l<=r){
  		ll mid=(l-r)/2+r;
 		ULL q1=(hs[mid]-hs[1-1]*p[mid-1+1]%mod1 +mod1)%mod1;  // l==1,r==mid
		ULL q2=(hs1[mid]-hs1[1-1]*p1[mid-1+1]%mod2 +mod2)%mod2;
		ULL h1=(rhs[n-mid+1]-rhs[n+1]*p[n-(n-mid+1)+1]%mod1 +mod1)%mod1; // l==n-mid+1,r==n;
		ULL h2=(rhs1[n-mid+1]-rhs1[n+1]*p1[n-(n-mid+1)+1]%mod2 +mod2)%mod2;
		if(q1==h1 && q2==h2){
			l=mid+1;
			t=mid;
		}else{
			r=mid-1;
		}
 	}
 	ll lmin=0,rmax=0,lenmax=0;
	ll l1=t+1,r1=n-t;   //在l+1到n/2的范围里查找单独的回文串；
	if(l1 >= r1){
		cout << s.substr(1) << endl;
		return;
	}
	for(ll i=l1;i<=r1;i++){
		if(check(i,r1)){     // 先查找右边是否有独立的子串；
			if(r1-i+1>lenmax){
				lmin=i;
				rmax=r1;
				lenmax=r1-i+1;
				//break;
			}
		}
	}
	//cout << check(1,1) << endl;
	for(ll i=r1;i>=l1;i--){  //固定左边，查找左边最大的子串;
        if(check(l1,i)){
        	if(i-l1+1>lenmax){
        		lmin=l1;
				rmax=i;
				lenmax=i-l1+1;
				//break;
			}
		}
	}
	for(ll i=1;i<=t;i++){
		cout << s[i];
	}
	if(lenmax){
		for(int i=lmin;i<=rmax;i++){
			cout << s[i];
		}
	}
	for(ll i=n-t+1;i<=n;i++){
		cout << s[i];
	}
}
int main(){
	ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	ll T=1;
	cin >> T;
	while(T--){
		solve();
		cout << '\n';
	}
	return 0;
}

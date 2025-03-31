#include<bits/stdc++.h>
#define forn(i,a,b)for(int i=(a),_b=(b);i<=_b;i++)
#define fore(i,b,a)for(int i=(b),_a=(a);i>=_a;i--)
#define rep(i,n)for(int i=0,_n=n;i<n;i++)
#define ll long long
#define pii pair<int,int>
#define m_p make_pair
#define pb push_back
#define fi first
#define se second
#define int ll
#define foreach(i,c) for(__typeof(c.begin())i=(c.begin());i!=(c).end();i++)
using namespace std;
const int N=200010;
int n;
pii dp[N][2];
vector<int>g[N]; 
int ans[N];
bool cmp(pii x,pii y){
	if(x.fi!=y.fi)return x.fi>y.fi;
	return x.se<y.se;
}
void dfs(int u,int fa){
	dp[u][1]=m_p(1,g[u].size());
	dp[u][0]=m_p(0,1);
	rep(i,g[u].size()){
		int v=g[u][i];
		if(v==fa)continue;
		dfs(v,u);
		dp[u][1].fi+=dp[v][0].fi;dp[u][1].se+=dp[v][0].se;
		if(cmp(dp[v][0],dp[v][1])){
			dp[u][0].fi+=dp[v][0].fi;dp[u][0].se+=dp[v][0].se;
		}
		else{
			dp[u][0].fi+=dp[v][1].fi;dp[u][0].se+=dp[v][1].se;
		}
	}
}
void _dfs(int u,int fa,int st){
	if(st)ans[u]=g[u].size();
	else ans[u]=1;
	rep(i,g[u].size()){
		int v=g[u][i];
		if(v==fa)continue;
		if(st){
			_dfs(v,u,0);
		}
		else{
			if(cmp(dp[v][0],dp[v][1])){
				_dfs(v,u,0);
			}
			else{
				_dfs(v,u,1);
			}
		}
	}
}
signed main(){
    cin.tie(0);
	ios::sync_with_stdio(0);
	cin>>n;
	rep(i,n-1){
		int u,v;
		cin>>u>>v;
		g[u].pb(v);g[v].pb(u);
	} 
	if(n==2){
		cout<<"2 2\n";
		cout<<"1 1\n";
    	return 0;
	}
	dfs(1,0);
	if(cmp(dp[1][0],dp[1][1])){
		cout<<dp[1][0].fi<<" "<<dp[1][0].se<<"\n";
		_dfs(1,0,0);
	}
	else{
		cout<<dp[1][1].fi<<" "<<dp[1][1].se<<"\n";
		_dfs(1,0,1);
	}
	forn(i,1,n)cout<<ans[i]<<" ";cout<<"\n";
	return 0;
}
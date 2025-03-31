#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 1;
int n,m,k;
int a[N];
int grid[1001][1001];
struct node 
{
	pair<int,int> zs;
	pair<int,int> yx;
};
void change(vector<vector<int>> &v,int x1,int y1,int x2,int y2){
	//cout << x1 << " " << y1 << " " << x2 << " " << y2 <<endl; 
	v[x1][y1]++;
	v[x1][y2+1]--;
	v[x2+1][y1]--;
	v[x2+1][y2+1]++;

}
void solve(){
	int d[4]; //d[0] = u,d[1] = d,d[2] = l, d[3] = r
	memset(d,0,sizeof d);

	//set<node> se;
	map<char,int> h;
	h['U'] = 0;
	h['D'] = 1;
	h['L'] = 2;
	h['R'] = 3;
	cin >> n >> m >> k;
	vector<vector<int>> v(n + 2,vector<int>(m + 2,0));
	string s;
	cin >> s;
	int xm = m,xn = n;
	int u = 0,r = 0;
	int mxu = -0x3f3f3f3f,miu = 0x3f3f3f3f,mxr = -0x3f3f3f3f,mir = 0x3f3f3f3f;
	for(auto &p:s){
		if(h[p] <= 1){
			if(h[p]==1) u++;
			else u--;
			mxu = max(mxu,u);
			miu = min(miu,u);
		}else{
			if(h[p]==2) r++;
			else r--;
			mxr = max(mxr,r);
			mir = min(mir,r);
		}
	}
	//cout << mir << " " << mxr << " " << mxu << " " << miu << endl;

	int cnt = 0;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			if(i + mxu > n || i + miu <= 0 || j + mir <= 0 || j + mxr > m) grid[i][j] = 1;
			else cnt++;
			cout << grid[i][j] << " ";
		}
		cout <<endl;
	}
	cout << endl;
	int sy = cnt - k;
	if(sy==0){
		cout << n*m << endl;
		return;
	}else if(sy < 0){
		cout << 0 <<endl;
		return;
	}
	pair<int,int> h1,h2,h3,h4;
	for(int i = 1;i <= n;i++){
		bool f= false;
		for(int j = 1;j <= m;j++){
			if(grid[i][j]==0){
				h1.first = i,h1.second = j;
				f= true;
				break;
			}
		}
		if(f) break;
	}
	for(int i = n;i >=1;i--){
		bool f= false;
		for(int j = m;j >=1;j--){
			if(grid[i][j]==0){
				h4.first = i,h4.second = j;
				f= true;
				break;
			}
		}
		if(f) break;
	}
	//cout << h1.first <<endl;
	node n1 = {h1,h4};
	change(v,n1.zs.first,n1.zs.second,n1.yx.first,n1.yx.second);
	int x1 = h1.first,x2 = h4.first,y1 = h1.second,y2 = h4.second;
	for(auto &p:s){
		if(h[p] <= 1){
			if(h[p]==0) x1--,x2--;
			else x1++,x2++;
			
		}else{
			if(h[p]==2) y1--,y2--;
			else y1++,y2++;
		}
		cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl; 
		change(v,x1,y1,x2,y2);
		
	}
	int ans = 0;
	for(int i = 1;i<=n;i++){
		for(int j = 1;j <= m;j++){
			v[i][j] += v[i - 1][j] + v[i][j - 1] - v[i - 1][j - 1];
			if(v[i][j] == sy) ans++; 
			cout << v[i][j] << " ";
		}
		cout <<endl;
	}
	cout << ans <<endl;
}	

signed main(){
	int t = 1;
	std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
	cin >> t;
	while(t--) solve();
}
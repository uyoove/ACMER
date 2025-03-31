//和爸爸一起学编程真好,不过要小学四年级分流考试了,最近没时间写代码了,呜呜呜
#include<bits/stdc++.h>
using namespace std;
#define out(x) cout << #x << '=' << (x) << endl
#define out2(x, y) cout << #x << '=' << (x) << ',' << #y << '=' << (y) << endl 
#define lc u<<1
#define rc u<<1|1
#define pb push_back
#define vt vector
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define PII pair<int,int>
#define endl "\n"
#define il inline
typedef unsigned long long ULL;
typedef long long ll;
il int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x*f;
}
const ll inf = 0x3f3f3f3f3f3f3f3fLL;
const int infi = 0x3f3f3f3f;
const int P = 13331;
const int N = 200005;
int n,m;
vector<vt<int>> res;
bool dfs(int pos,vector<int>& v,int last){
	if(last + 10 > m) return false;
	if(pos==n){
		if(last + 10 > m) return false;
		for(int i = last + 10;i <= m;i++){
			v.pb(i);
			res.pb(v);
			v.pop_back();
		}
		return true;
	}
	int j;
	if(last==-1) j =1;
	else j = last + 10;
	for(;j <= m - (n-pos)*10;j++){
		v.push_back(j);
		if(!dfs(pos +1,v,j)) {
			v.pop_back();
			break;
		}
		v.pop_back();
	}
	return true;
}
void solve(){
	cin >> n >> m;
	vt<int> v1;
	dfs(1,v1,-1);
	cout << res.size() <<endl;
	for(auto &p:res){
		for(auto &q:p){
			cout << q << " ";
		}
		cout <<endl;
	}
}

signed main(){
	std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
	int times = 1;
	//cin >> times;
	while(times--){
		solve();
	}
	return 0;
}
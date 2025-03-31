//和爸爸一起学编程真好,不过要小学四年级分流考试了,最近没时间写代码了,呜呜呜
#include<bits/stdc++.h>
using namespace std;
#define out(x) cout << #x << '=' << (x) << endl
#define out2(x, y) cout << #x << '=' << (x) << ',' << #y << '=' << (y) << endl 
#define int long long
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
int vis[501][501];
int mx[4] = {0,0,1,-1};
int my[4] = {1,-1,0,0};
void solve(){
	int h,w;
	cin >> h >> w;
	string pp[h + 1];
	for(int i = 0;i < h;i++) cin >> pp[i];
	map<char,int> mp;
	mp['s'] = 1;
	mp['n'] = 2;
	mp['u'] = 3;
	mp['k'] = 4;
	mp['e'] = 5;
	if(pp[0][0]!='s'){
		cout << "No" << endl;
		return;
	}	
	queue<PII> q;
	q.push({1,1});
	while(q.size()){
		auto p = q.front();q.pop();
		int x = p.fi,y = p.se;
		if(vis[x][y] ) continue;
		vis[x][y] = 1;
		for(int i = 0;i < 4;i++){
			int nx = x + mx[i],ny = y + my[i];
			if(nx <0 || ny < 0 || nx >= h || ny >= w || !mp.count(pp[nx][ny])) continue;
			if(mp[pp[nx][ny]] != (mp[pp[x][y]])%5 + 1) continue;
			q.push({nx,ny});
		}
	}
	if(vis[h-1][w-1]){
		cout << "Yes" << endl;
	}else{
		cout << "No" << endl;
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
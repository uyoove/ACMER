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
mt19937_64 rnd(time(0));
const ll inf = 0x3f3f3f3f3f3f3f3fLL;
const int infi = 0x3f3f3f3f;
const int P = 13331;
const int N = 1605;
int n;
int ax,ay,bx,by;
string s[N];
int dis[N][N][4];
struct nodes{
	int r,c,fx;
};
int mx[4] = {1,1,-1,-1};
int my[4] = {-1,1,1,-1};
void solve(){
	memset(dis,0x3f,sizeof dis);
	cin >> n >> ax >> ay >> bx >> by;
	for(int i = 1;i <= n;i++){
		cin >> s[i];
		s[i] = " " + s[i];
	}
	deque<nodes> dq;
	for(int i = 0;i < 4;i++){
		dis[ax][ay][i] = 1;
		dq.push_back({ax,ay,i});
	}
	while(dq.size()){
		auto p = dq.front();dq.pop_front();
		int r = p.r,c = p.c,fx = p.fx;
		if(r==bx&&c==by){
			cout << dis[r][c][fx] << endl;
			return;
		}
		for(int k = 0; k < 4;k++){
			int nr = r + mx[k],nc = c + my[k];
			if(nr > n || nc > n ||  nr < 1 || nc < 1 || s[nr][nc] == '#') continue;
			if(k==fx){
				if(dis[nr][nc][k] <= dis[r][c][k]) continue;
				dis[nr][nc][k] = dis[r][c][k];
				dq.push_front({nr,nc,k});
			}else{
				if(dis[nr][nc][k] <= dis[r][c][fx] + 1) continue;
				dis[nr][nc][k] = dis[r][c][fx] + 1;
				dq.push_back({nr,nc,k});
			}
		}
	}
	cout << -1 << endl;
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
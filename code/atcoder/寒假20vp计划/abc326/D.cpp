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
const int N = 200005;
int n;
string s,t;
char res[6][6];
void ptr(){
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			cout << res[i][j];
		}
		cout << endl;
	}
}
int vis[6][3]; //表示每个单词有没有用过
int vis2[6][3];
int r[6];  //表示我这一行第一个有没有用过约束
int c[6]; //表示我这一列第一个有没有用过约束
char us(int r){
	for(int i = 0;i < 3;i++){
		if(!vis[r][i]) return (char)(i + 'A');
	}
	return 'A';
}
bool dfs(int r){

	if(r==n+1){
		int p = 0;
		cout << "Yes" << endl;
		ptr();
		return true;
	}
	for(int i = 1;i <= n;i++){
		int tci = 0;
		if(vis2[i][s[r] - 'A']==1) continue;
		if((c[i]==0 && s[r]==t[i]) || (c[i]<3 && c[i] > 0)){
			res[r][i] = s[r];
			vis[r][s[r] - 'A'] = 1;
			c[i]++,tci = 1;
			vis2[i][s[r] - 'A'] = 1; 
		}else{
			continue;
		}
		for(int j = i + 1;j <= n;j++){
			for(int j1 = 0;j1 < 3;j1++){
				if(vis[r][j1]) continue;
				if(vis2[j][j1]) continue;
				int ck = 0;
				if((c[j]<3 && c[j] > 0) || (c[j]==0 && j1 == t[j] - 'A')){
					c[j]++,ck = 1;
					res[r][j] = (char)(j1+'A');
					vis[r][j1] = 1;
					vis2[j][j1] = 1;
				}else{
					continue;
				}
				for(int k = j + 1;k <= n;k++){
					char p = us(r);
					int ck = 0;
					if(vis2[k][p - 'A']) continue;
					if((c[k] > 0 && c[k] < 3) || (c[k]==0&&p==t[k])){
						 c[k]++,ck = 1;
						res[r][k] = p;
						vis[r][p - 'A'] = 1;
						vis2[k][p - 'A'] = 1;
					}else{
						continue;
					}
					if(dfs(r+1)) return true;
					if(ck) c[k]--;
					res[r][k] = '.';
					vis[r][p - 'A'] = 0;
					vis2[k][p - 'A'] = 0;
				}
				if(ck) c[j]--;
				vis[r][j1] = 0;
				res[r][j] = '.';
				vis2[j][j1] = 0;

			}
		}
		res[r][i] = '.';
		vis[r][s[r] - 'A'] = 0;
		if(tci==1) c[i]--;
		vis2[i][s[r] - 'A'] = 0; 
	}
	return false;
}
void solve(){
	cin >> n >> s >> t;
	s = " " + s;
	t = " " + t;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
		 	res[i][j]='.';
		}
	}
	if(!dfs(1)){
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
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
int dis[103][103];
void floyd(){
	for(int k = 1;k <= n;k++){
		for(int i = 1;i <= n;i++){
			dis[i][i] = 0;
			if(k==i) continue;
			for(int j = 1;j <= n;j++){
				if(j==i || j== k) continue;
				dis[i][j] = min(dis[i][j],dis[i][k] + dis[k][j]);	
			}		
		}
	}
}
void solve(){
	cin >> n;
	for(int i = 1;i <= n;i++){
		string s;
		cin >> s;
		for(int j = 1;j <= n;j++){
			int t = s[j - 1] - '0';
			dis[i][j] = (t == 1 ? 1 : 1e9);
			//cout << dis[i][j] << " ";
		}
	}
	floyd();
	cin >> m;
	vt<int> v;
	int p[m + 1];
	for(int i = 1;i <= m;i++) cin >> p[i];
	int last = p[1];
	v.pb(p[1]);
	int cur = 0;
	for(int i = 2;i <= m;i++){
		cur += dis[p[i - 1]][p[i]];
		if(dis[last][p[i]] < cur){
			last = p[i - 1],cur = dis[last][p[i]];
			v.pb(last);	
			//cout << last << " "; 
		}
	}
	v.pb(p[m]);
	cout << v.size() << endl;
	for(auto x:v) cout << x << " ";

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
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
const int N = 2000005;
int tr[N][30];
int sum[N][30];
int cnt[30][30];//如果i名次靠前产生的贡献
int idx;
void insert(string s){
	int p = 0;
	for(int i = 0;i < s.size();i++){
		int u = s[i] - 'a' + 1;
		if(!tr[p][u]) tr[p][u] = ++idx;
		for(int j = 0;j < 27; j++){
			if(j==u) continue;
			cnt[j][u] += sum[p][j];
		}
		sum[p][u]++;
		p = tr[p][u];
	}
}
int pos[30];
void solve(){
	int n,q;
	cin >> n >> q;
	for(int i = 0;i < n;i++){
		string s;
		cin >> s;
		s += ('a' - 1);
		insert(s);
	}
	while(q--){
		string s;
		cin >> s;
		s = (char)('a' - 1) + s;
		int ans = 0;
		for(int i = 0;i < 27;i++) pos[s[i] - 'a' + 1] = i;
		for(int i = 0;i < 27;i++){
			for(int j = 0;j < 27;j++){
				if(pos[i] > pos[j]) ans+=cnt[i][j];
			}
		}
		cout << ans << endl;
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
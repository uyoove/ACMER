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
int cnt[N][27];
void solve(){
	string s;
	cin >> s;
	int n = s.size();
	int q;
	s=  " " + s;
	cin >> q;
	
	memset(cnt,0,sizeof cnt);
	for(int i = 1;i<=n;i++){
		cnt[i][s[i] - 'a']++;
	}
	for(int i = 1;i <= n;i++){
		for(int j = 0;j < 26;j++){
			cnt[i][j] += cnt[i - 1][j];
		}
	}
	while(q--){
		int l,r;
		cin >> l >> r;
		if(l==r){
			cout << "Y" << endl;
			continue;
		}
		bool f = false;
		for(int i = 0;i < 26;i++){
			if(cnt[r][i] - cnt[l - 1][i] == r-l+1){
				cout << "N" << endl;
				f = true;
				break;
			}
		}
		if(!f) cout << "Y" << endl;

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
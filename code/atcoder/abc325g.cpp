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
string s;
int k;
int f[500][500];
void solve(){
	cin >> s >> k;
	int n = s.size();
	s = " " + s;
	memset(f,0x3f,sizeof f);
	f[1][1] = 1;
	for(int i = 2;i <= n;i++){
		f[i][i] = 1;
		//f[i][i - 1] = 0;
		if(s[i-1]=='o' && s[i]=='f'){
			f[i - 1][i] = 0; 
		}else{
			f[i - 1][i] = 2;
		}
	}
	for(int len = 3;len <= n;len++){
		for(int l = 1;l + len - 1 <= n;l++){
			int r = l + len - 1;
			f[l][r] = min(f[l + 1][r] + 1,f[l][r]);
			if(s[l] != 'o') continue;
			for(int t= l + 1;t <= r;t++){
				//判断越界情况
				if(s[t] == 'f' && (t-l==1 ||  f[l + 1][t - 1] == 0)){
					if(t==r){
						f[l][r] = 0;
						continue;
					}
					f[l][r] = min(f[l][r],max(0ll,f[t + 1][r] - k));
				}
			}
		}
	}
	cout << f[1][n] << endl;
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
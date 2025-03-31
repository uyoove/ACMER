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
const int N = 1e6 + 7;
//碰到1取反,碰到0变成1
int pre[N],lst[N]; //1的数量,离i的0最近的位置
int ans = 0;
string s;
int n;
void solve(){
	cin >> n >> s;
	s = " " + s;
	for(int i = 1;i <= n;i++){
		lst[i] = lst[i - 1];
		if(s[i]=='1'){
			pre[i]++;
		}else{
			lst[i] = i;
		}
		pre[i] += pre[i - 1];
	}
	for(int i = 1;i <= n;i++){
		if(s[i]=='0'){
			ans += i - 1;
		}else{
			
			if(lst[i]==0){
				ans+=(i + 1)/2;
			}else{
				ans += (i - lst[i] + 1)/2;
				if((i - lst[i])%2 == 1){
					ans += 1;
				}else{
					ans += lst[i] - 1;
				}
			}
		}
	}
	cout << ans << endl;
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
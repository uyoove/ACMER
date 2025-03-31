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
int a,b,c;
void solve(){
	cin >> a >> b >> c;
	int pa = 0, pb = 0,ca = 0,cb = 0;
	for(int i = 0;i <= 60;i++){
		if((c >> i)&1){
			if(a-ca > b-cb){
				ca++;
				pa |= (1ll << i);
			}else if(a-ca <= b-cb){
				cb++;
				pb |= (1ll << i);
			}
		}
	}
	for(int i = 0;i <= 60;i++){
		if((c >> i)&1) continue;
		if(ca < a && cb < b){
			cb++;
			pb |= (1ll << i);
			ca++;
			pa |= (1ll << i);
		}
	}
	if(ca != a || cb!=b){
		cout << -1 << endl;
		return;
	}
	cout << pa << " " << pb << endl;
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
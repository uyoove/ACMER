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
int cnt[20][11]; //第i位,首尾是j的数量
int check(int r){

	string sr = to_string(r);
	if(sr.size()==1) return r;
	int sz = to_string(r).size();
	int mx = cnt[sz][to_string(r)[0] - '0' - 1];
	if(sr[sr.size() - 1] >= sr[0]){
		int d = 0;
		int p = 1;
		for(int j = 1;j  <= sr.size() - 2;j++){
			d =d*10 +  (sr[j] - '0');
		}
		mx+=d+1;
	}else{
		int d = 0;
		int p = 1;
		for(int j = 1;j  <= sr.size() - 2;j++){
			d =d*10 +  (sr[j] - '0');
		}
		mx+=d;
	}
	return mx;
}
ll power(ll x, ll n){ //快速幂
    ll ans = 1;
    while (n > 0){
        if  (n & 1)
            ans = (ans * x);
        x = (x * x);
        n >>= 1;
    }
    return ans;
}
void solve(){
	int l,r;
	
	cin >> l >> r;
	vector<int> v;
	for(int i = 1;i <= 18;i++){
		int p = 0;
		for(int j = 1;j <= 9;j++){
			if(i <= 2)cnt[i][j] = 1 + cnt[i][j - 1];
			else cnt[i][j] = powl(10ll,i-2) + cnt[i][j - 1];
			//cout << i << " " <<j << " " << cnt[i][j] << endl;
			p=cnt[i][j];
		}
		cnt[i + 1][0] = p;
	}
	int mx = check(r);
	int low = check(l - 1);
	cout << mx - low << endl;
	
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
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
const int N = 1000005;
int n;
int p[N];
void solve(){
	cin >> n;
	p[2] = 0;
	vector<int> v;
	for(int i = 2;i < N;i++){
		if(!p[i]){
			v.pb(i);
			for(int j = i * i;j < N;j += i){
				p[j] = 1;
			}
		}
	}
	int res = 0;
	for(int i = 1;i < v.size();i++){
		__int128 p = v[i]*v[i]*v[i];
		//cout << p << endl;
		if(p > n) break;
		int l =0,r = i - 1,ans = -1;
		while(l <= r){
			int mid = l+r>>1;
			__int128 c = p * v[mid];
			if(c <= n){
				l = mid + 1;
				ans = mid;
			}else{
				r = mid - 1;
			}
		}
		res+=ans+1;
	}
	cout << res <<endl;
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
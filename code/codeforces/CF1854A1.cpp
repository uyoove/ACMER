//和爸爸一起学编程真好,不过要小学四年级分流考试了,最近没时间写代码了,呜呜呜
#include<bits/stdc++.h>
using namespace std;
#define out(x) cout << #x << '=' << (x) << endl
#define out2(x, y) cout << #x << '=' << (x) << ',' << #y << '=' << (y) << endl 
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
const int N = 105;
int n;
int a[N];
void solve(){
	cin >> n;
	vt<int> cs[N];
	int ma = 0,id = 0;
	int p1 = 0,p2 = 0;
	for(int i = 1;i <= n;i++) {
		cin >> a[i];
		if(a[i] >= 0)p1++;
		else  p2++;
		if(abs(a[i]) > ma){
			
			ma=abs(a[i]);
			id = i;
		}else if(abs(a[i]) == ma){
			if(a[i] <0){
				id = i;
			}
		}

	}
	int idx = n;
	vt<PII> res;
	while(a[idx]==0 && idx > 0) idx--;
	if(idx == 0){
		cout << 0 << endl;
		return;
	}
	
		for(int i = 1;i <= n;i++){
			if(i!=id){
				res.pb({i,id});
			}
		}
	
	
	
	if(a[id] < 0){
		for(int i = n;i > 1;i--){

				res.pb({i - 1,i});
		}
	}else{
		for(int i = 2;i <= n;i++){
				res.pb({i,i-1});
			
		}
	}
	cout << res.size() << endl;
	for(auto [k,v]:res) {
		cout << k << " " << v << endl;
	}
	

}

signed main(){
	std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
	int times = 1;
	cin >> times;
	while(times--){
		solve();
	}
	return 0;
}
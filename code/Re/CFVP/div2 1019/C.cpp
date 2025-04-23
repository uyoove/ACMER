//最后一舞
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
//三段中至少有两段中位数大于等于 k
int n,k;
int a[N],pre[N];

void solve(){
	multiset<int> se;
	cin >> n >> k;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		if(a[i] <= k) a[i] = 1;
		else a[i] = 0;
		pre[i] = pre[i - 1] + a[i];
		if(i!=n) se.insert(i - 2*pre[i]);
	}
	int nx = n - 2*pre[n];
	for(int l = 1;l < n - 1;l++){
		int p = l - 2*pre[l];
		se.erase(se.find(p));
		if((l + 1)/2 <= pre[l]){
			auto it = se.lower_bound(p);
			if(it!=se.end()){
				int tb = *it;
				if(tb==p){
					cout << "Yes" << endl;
					return;
				}
			}
			
			if(it!=se.begin()){
				it--;
				cout << "Yes" << endl;
				return;
			}
			it = se.lower_bound(nx);
			if(it!=se.end()){
				cout << "Yes" << endl;
				return;
			}
		}else{
			if(nx > p) continue; 
			auto it = se.lower_bound(p);
			if(it!=se.end()){
				int tb = *it;
				if(tb==p && tb >= nx){
					cout << "Yes" << endl;
					return;
				}
			}
			if(it!=se.begin()){
				it--;
				int tb = *it;
				if(tb >= nx){
					cout << "Yes" << endl;
					return;
				}
			}
		}
	}
	cout << "No" << endl;

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
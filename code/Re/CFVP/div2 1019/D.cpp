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
int ans[N];
int a[N];
int n;
int f;
void solve(){
	cin >> n;
	vt<vt<int>> pos(n + 2,vt<int>());
	set<int> se;
	set<int> wz;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		wz.insert(i);
		if(a[i]!=-1){
			pos[a[i]].pb(i);
		}else{
			f = i;
		}
		se.insert(i);
	}
	int r = n;
	int l = 1;

	for(int i = 1;pos[i].size();i++){
		for(auto p:pos[i]) wz.erase(p);
		int zz = f;
		
		if(i%2){
			int ll = 0,rr = pos[i].size() - 1,ppos = inf;
			while(ll <= rr){
				int mid = ll+rr>>1;
				if(pos[i][mid] > zz){
					ppos = pos[i][mid];
					rr = mid - 1;
				}else{
					ll = mid + 1;
				}
			}
			int lr = r - pos[i].size();
			int ll1 = lr + 1;
			for(int j = 0;j < pos[i].size();j++){
				if(pos[i][j] >= ppos){
					ans[pos[i][j]] = ll1++;
					se.erase(ll1-1);
				}else{
					ans[pos[i][j]] = r--;
					se.erase(r+1);
				}
			}
			r = lr;
		}else{
			int zz = f;
			int ll = 0,rr = pos[i].size() - 1,ppos = 0;
			while(ll <= rr){
				int mid = ll+rr>>1;
				if(pos[i][mid] < zz){
					ppos = pos[i][mid];
					ll = mid + 1;
				}else{
					rr = mid - 1;
				}
			}
			int lr = l + pos[i].size();
			int ll1 = lr - 1;

			for(int j = pos[i].size() - 1;j >= 0;j--){
				if(pos[i][j] > ppos){
					ans[pos[i][j]] = l++;
					se.erase(l-1);
				}else{
					ans[pos[i][j]] = ll1--;
					se.erase(ll1+1);
				}
			}
			l = lr;
		}
	}
	int p = *se.begin();
	ans[f] = p;
	for(int i = 1;i <= n;i++){
		cout << ans[i] << " ";
	}
	cout << endl;


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
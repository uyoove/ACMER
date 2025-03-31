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
int n,m;
//枚举选多少个2类型,可以二分出要多少开罐器,剩下的由0类型补
void solve(){
	cin >> n >> m;
	vector<int> v[3];
	for(int i = 1;i <= n;i++){
		int op,t;
		cin >> op >> t;
		v[op].pb(t);
	}	
	sort(v[0].rbegin(),v[0].rend());
	sort(v[1].rbegin(),v[1].rend());
	sort(v[2].rbegin(),v[2].rend());
	for(int i = 1;i < v[0].size();i++){
		v[0][i]+=v[0][i - 1];;
	}
	for(int i = 1;i < v[2].size();i++){
		v[2][i]+=v[2][i - 1];;
	}
	int t = 0;
	int ans = 0;
	int p = v[0].size() - 1;
	if(v[0].size()) ans = v[0][min(m - 1,p)];
	for(int i = 0; i < v[1].size();i++){
		t += v[1][i];
		int l = 0,r = v[2].size() - 1,as = -1;
		while(l <= r){
			int mid = l + r >> 1;
			if(v[2][mid] >= i + 1){
				r = mid - 1;
				as = mid;
			}else{
				l = mid + 1;
			}
		}
		if(as==-1) break;
		//cout << i << " " << as << endl;
		int hf = i + 1 + as + 1;
		//cout << i << " " << hf <<" " << t  << endl;
		if(hf > m) continue;
		if(hf==m){
			ans=max(ans,t);
			continue;
		}
		int sz = v[0].size();
		ans = max(ans,t + v[0][min(m - hf - 1,sz - 1)]);
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
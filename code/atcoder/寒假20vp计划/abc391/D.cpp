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
mt19937_64 rnd(time(0));
const ll inf = 0x3f3f3f3f3f3f3f3fLL;
const int infi = 0x3f3f3f3f;
const int P = 13331;
const int N = 200005;
int n,w;
vector<PII> f[N];//表示每一行的第i个掉落的所需
int d[N];//每一层的最大值
int dd[N];
void solve(){
	cin >> n >> w;
	for(int i = 1;i <= n;i++){
		int x,y;
		cin >> x >> y;
		f[x].pb({y,i});
	}
	set<int> se;
	for(int i = 1;i <= w;i++){
		sort(all(f[i]));
		if(f[i].size()) se.insert(i);
		int t = 1;
		for(auto p:f[i]){
			dd[p.se] = t++;
			//cout << p.se << " " << t -1 << endl;
		}
	}
	int t = se.size();
	for(int i = 1;i <= n;i++){
		vt<int> v;
		int p1 = d[i - 1];
		if(se.size() != w) break;
		for(auto p:se){
			if(f[p].size()==i) v.pb(p);
			//cout << p << " " << f[p][i - 1] << endl;
			d[i] = max(f[p][i - 1].fi - p1,d[i]);
		}
		d[i] += d[i - 1];
		//cout << d[i] <<endl;
		for(auto p:v) se.erase(p);
	}
	int q;
	cin >> q;
	while(q--){
		int t,id;
		cin >> t >> id;
		int sj = dd[id];
		if(d[sj]==0){
			cout << "Yes" << endl;
		}else{
			if(t + 0.5 > d[sj]){
				cout << "No" << endl;
			}else{
				cout << "Yes" << endl;
			}
		}
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
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
int n;
unordered_map<int,int> h[N];
unordered_map<int,int> h2;
int ks[N];
void solve(){
	cin >> n;
	for(int i = 1;i <= n;i++){
		int k;
		cin >> k;
		for(int j = 1;j <= k;j++){
			int t;
			cin >> t;
			h[i][t]++;
		}
		ks[i] = k;
	}
	double res = 0;
	for(int i = 1;i <= n;i++){
		for(int j = i + 1;j <= n;j++){
			if(i==j) continue;
			if(h[j].size() < h[i].size()){
				double tp = 0;
				for(auto &[k,v]:h[j]){
					if(!h[i].count(k)) continue;
					tp += (v*1.0/ks[j])*(h[i][k]*1.0/ks[i]);
				}
				res = max(res,tp);
			}else{
				double tp = 0;
				for(auto &[k,v]:h[i]){
					if(!h[j].count(k)) continue;
					tp += (v*1.0/ks[i])*(h[j][k]*1.0/ks[j]);
				}
				res = max(res,tp);
			}

		}
	}
	printf("%.10lf",res);
	
}

signed main(){
	int times = 1;
	//cin >> times;
	while(times--){
		solve();
	}
	return 0;
}
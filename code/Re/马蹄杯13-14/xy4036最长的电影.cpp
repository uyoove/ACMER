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
map<string,int> mp;
vt<int> q[N];
string s;
int tot = 0;
int n,m,l;
int check(string s,string &t,int n){
	int cnt = 0;
	for(int i = 0;i < n;i++) if(s[i]!=t[i]) cnt++;
	return cnt;
}
void solve(){
	cin >> n >> m >> l;
	cin >> s;
	if(l<3){
		cout << m << endl;
		return;
	}
	int w = l/3;
	for(int i = 0;i + w < n;i++){
		string tp = s.substr(i,w);
		if(!mp.count(tp)){
			mp[tp]=++tot;
		}
		q[mp[tp]].pb(i);
	}
	int cnt = 0;
	for(int i = 1;i <= m;i++){
		string t;
		cin >> t;
		bool ok = 0;
		string s1 = t.substr(0,w);
		string s2 = t.substr(w,w);
		string s3 = t.substr(w*2,w);
		if(!ok && mp.count(s1)){
			for(auto st:q[mp[s1]]){
				if(st + l <= n && check(s.substr(st,l),t,l) <= 2){
					ok = 1;
					break;
				}
			}
		}
		if(!ok && mp.count(s2)){
			for(auto st:q[mp[s2]]){
				if(st - w >=0 && st + l - w <= n && check(s.substr(st - w,l),t,l) <= 2){
					ok = 1;
					break;
				}
			}
		}
		if(!ok && mp.count(s3)){
			for(auto st:q[mp[s3]]){
				if(st - 2*w >= 0 && st - 2*w + l <= n && check(s.substr(st - 2*w,l),t,l) <= 2){
					ok = 1;
					break;
				}
			}
		}
		if(ok) cnt++;
	}
	cout << cnt << endl;


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
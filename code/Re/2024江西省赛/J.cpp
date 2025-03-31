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
set<string> se;
void solve(){
	set<string> sp;
	map<string,int> mp;
	string s;
	cin >> s;
	for(int i = 0;i < 28;i+=2){
		string d = "";
		d+=s[i];
		d+=s[i+1];
		sp.insert(d);
		//cout << d << endl;
		mp[d]++;
	}
	bool f = 1;
	for(auto p:mp){
		if(p.se!=2){
			f = 0;
		}
	}
	if(f){
		cout << "7 Pairs" << endl;
	}else{
		if(sp==se){
			cout << "Thirteen Orphans" << endl;
		}else{
			cout << "Otherwise" << endl;
		}
	}

}

signed main(){
	std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
	int times = 1;
	se.insert("1p");
	se.insert("9p");
	se.insert("1s");
	se.insert("9s");
	se.insert("1m");
	se.insert("9m");
	se.insert("1z");
	se.insert("2z");
	se.insert("3z");
	se.insert("4z");
	se.insert("5z");
	se.insert("6z");
	se.insert("7z");
	cin >> times;
	while(times--){
		solve();
	}
	return 0;
}
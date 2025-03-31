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
map<int,int> mp;
int a[N],b[N];
int ha[N],hb[N];
void solve(){
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> a[i];
	for(int i = 1;i <= n;i++) cin >> b[i];
	set<int> se;
	for(int i = 1;i <= n;i++){
		if(!mp.count(a[i])){
			mp[a[i]] = rnd();
		}
		if(!se.count(a[i])){
			se.insert(a[i]);
			ha[i] = ha[i - 1] ^ mp[a[i]]; 
		}else{
			ha[i] = ha[i - 1];
		}
		 	
	}
	se.clear();
	for(int i = 1;i <= n;i++){
		if(!mp.count(b[i])){
			mp[b[i]] = rnd();
		}
		if(!se.count(b[i])){
			se.insert(b[i]);
			hb[i] = hb[i - 1] ^ mp[b[i]]; 
		}else{
			hb[i] = hb[i - 1];
		}
	}
	int q;
	cin >> q;
	while(q--){
		int x,y;
		cin >> x >> y;
		cout << (ha[x] == hb[y] ?  "Yes" : "No") << endl;
		//cout << ha[x] << " " << hb[y] << endl;
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
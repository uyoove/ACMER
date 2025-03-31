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
const int N = 1000005;
int n,m,x,y;
vector<PII> poi; 
map<int,vector<PII>> mx,my,mx2,my2;
vector<int> tr1[N],tr2[N];
vector<int> ls;
int gt(int x){
	return lower_bound(all(ls),x) - ls.begin() +1;
}
void add(int x,int val,int op,int z){
	if(op==1){
		for(int i = x;i < tr1[z].size();i+=(i&-i)){
			tr1[z][i]=max(tr1[z][i],val);
		}
	}else{
		for(int i = x;i < tr2[z].size();i+=(i&-i)){
			tr2[z][i]=max(tr2[z][i],val);
		}
	}
}
int query(int x,int op,int z){
	int res = 0;
	if(op==1){
		for(int i = x;i > 0;i-=(i&-i)){
			res=max(tr1[z][i],res);
		}
	}else{
		for(int i = x;i > 0;i-=(i&-i)){
			res=max(tr2[z][i],res);
		}
	}
	return res;
}
void solve(){
	cin >> n >> m >> x >> y;
	ls.pb(x),ls.pb(y);
	for(int i = 1;i <= n;i++){
		int x,y;
		cin >> x >> y;
		poi.pb({x,y});
		ls.pb(x);
		ls.pb(y);
	}

	for(int i = 1;i<=m;i++){
		char ch;
		int x1;
		cin >> ch >> x1;
		int nx = x,ny = y;
		if(ch=='U') ny+= x1;
		if(ch=='D') ny-=x1;
		if(ch=='L') nx-=x1;
		if(ch=='R') nx+=x1;
		mx[x].pb({min(y,ny),max(y,ny)});
		mx[nx].pb({min(y,ny),max(y,ny)});
		my[ny].pb({min(x,nx),max(x,nx)});
		my[y].pb({min(x,nx),max(x,nx)});
		x = nx,y = ny;
		ls.pb(x);
		ls.pb(y);
	}
	sort(ls.begin(),ls.end());
	ls.erase(unique(ls.begin(),ls.end()),ls.end());
	cout << x << " " << y << " ";
	for(auto &p:mx){
		sort(all(p.se));
		for(auto &p1:p.se){
			p1 = {gt(p1.fi),gt(p1.se)};

		}
		mx2[gt(p.fi)] = p.se;
	}
	for(auto &p:my){
		sort(all(p.se));
		for(auto &p1:p.se){
			p1 = {gt(p1.fi),gt(p1.se)};

		}
		my2[gt(p.fi)] = p.se;
	}
	for(auto &p:mx2){
		tr1[p.fi].resize(p.se.size() + 3);
		for(int j = 0;j < p.se.size();j++){
			//cout << p.fi << " " << p.se[j].fi << " " << p.se[j].se <<endl; 
			add(j + 1,p.se[j].se,1,p.fi);
		}
	}
	for(auto &p:my2){
		tr2[p.fi].resize(p.se.size() + 3);
		for(int j = 0;j < p.se.size();j++){
			add(j + 1,p.se[j].se,2,p.fi);
		}
	}
	int ans1 = 0;
	for(auto &p:poi){
		bool f = false;
		int x = gt(p.fi),y = gt(p.se);
		vt<PII>& v = mx2[x];
		//for(auto p:v) cout << p.fi << " " << p.se <<endl;
		//cout << x << endl;
		//cout << x << " " << y << " "<<v.size() <<endl;
		int l = 0, r = v.size() - 1,ans = -1;

		while(l <= r){
			int mid = l +r >> 1;
			if(v[mid].fi <= y){
				l = mid  + 1;
				ans = mid;
			}else{
				r = mid - 1;
			}
		}

		if(ans!=-1){
			int mx = query(ans + 1,1,x);
			if(mx >= y) {
				ans1++;
				continue;
			}
		}

		vt<PII>&v1 = my2[y];
		l = 0, r = v1.size() - 1,ans = -1;
		while(l <= r){
			int mid = l +r >> 1;
			if(v1[mid].fi <= x){
				l = mid  + 1;
				ans = mid;
			}else{
				r = mid - 1;
			}
		}
		if(ans!=-1){
			int mx = query(ans + 1,2,y);
			if(mx >= x) {
				ans1++;
				continue;
			}
		}
	}
	cout << ans1 <<endl;
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
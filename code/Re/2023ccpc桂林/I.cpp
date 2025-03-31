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
const int N = 500005;
int n,m;
int a[N];
vt<int> pos[N];
int idx[N],pre[N];
int cnt[N];
struct Fenwick{
	vector<int> tr;
	int sz;
	void init(int n){
		tr.resize(n + 1);
		sz = n;
	}
	Fenwick(){}
	Fenwick(int n){
		init(n);
	}
	void add(int k,int val){
		for(int i = k;i <= sz;i+=(i&-i)){
			tr[i]+=val;
		}
	}
	int query(int k){
		int res = 0;
		for(int i = k;i > 0;i-=(i&-i)){
			res+=tr[i];
		}
		return res;
	}
	int ask_sum(int l,int r){
		return query(r) - query(l - 1);
	}
};
void solve(){
	cin >> n >> m;
	Fenwick fk(n + 1);

	for(int i = 1;i <= n;i++){
		cin >> a[i];
		cnt[a[i]]=1;
		pos[a[i]].pb(i);
	}
	int ans = -1e9;
	for(int i = 1;i <= n;i++){
		int mex = a[i];
		int r =i - 1;
		int l;
		if(pos[mex][idx[mex]]==i){
			l=0;
		}else{
			l = pos[mex][idx[mex]];
			idx[mex]++;	
		}
		ans = max(ans,fk.query(r)-fk.query(l)-mex);
		if(pre[mex]) fk.add(pre[mex],-1);
		pre[mex] = i;
		fk.add(i,1);
	}
	for(int i = 1;i <= n;i++){
		int mex = a[i];
		int r = n,l = *pos[mex].rbegin();
		ans = max(ans,fk.query(r) - fk.query(l)-mex);
	}
	for(int i = 1;i <= m;i++){
		if(!cnt[i]){
			ans = max(ans,fk.query(n) - i);
			break;
		}
	}
	cout << ans << endl;
	for(int i = 1;i <= n;i++){
		pos[i].clear();
		cnt[a[i]] = 0;
		pre[a[i]] = 0;
		idx[a[i]] = 0;	
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
//最后一舞
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define out(x) cout << #x << '=' << (x) << endl
#define out2(x, y) cout << #x << '=' << (x) << ',' << #y << '=' << (y) << endl 
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

int n,k;
int a[N];
int tr[N<<5][2],tot;
int cnt[N<<5];
void add(int u,int id,int op){
	int p = 0;
	for(int i = 31;i >= 0;i--){
		int d = (u >> i)&1;
		if(!tr[p][d]) tr[p][d] = ++tot;
		p = tr[p][d];
		cnt[p] = max(cnt[p],id);
	}
}
int query(int x){
	int res = 0,p = 0;
	int mx =0;
	for(int i = 31;i >= 0;i--){
		int d = (k >> i) & 1;
		if(d==1){
			int u = x >> i & 1;
			if(!tr[p][u ^ 1]) {p=0;break;}
			p = tr[p][u ^ 1];
		}else{
			int u = x >> i & 1;
			if(tr[p][u ^ 1]){
				mx = max(mx,cnt[tr[p][u ^ 1]]);
				if(tr[p][u]) p = tr[p][u];
				else {p=0;break;}
			}else{
				if(tr[p][u]) p = tr[p][u];
				else {p=0;break;}
			}
			
		}
		
	}
	mx = max(mx,cnt[p]);
	return mx;
}

void solve(){
	n = read(),k = read();
	int ans = inf;
	tot = 0;
	for(int i = 1;i <= n;i++) {
		cin >> a[i];
		add(a[i],i,1);
		int l = query(a[i]);
		if(l==0) continue;
		
		ans=min(ans,i-l+1);
	}
	if(ans==inf) ans = -1;
	printf("%lld\n",ans);
	for(int i = 0;i <= tot;i++){
		tr[i][0] = tr[i][1] = 0,cnt[i] = 0;
	}
}

signed main(){
	int times = 1;
	times = read();
	while(times--){
		solve();
	}
	return 0;
}
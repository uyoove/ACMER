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
const int N = 1000005;
const int MOD = 998244353;
int n,m;
int a[N];
map<int,int> mp;
int f[N],pw[N],bt[N*10];
void solve(){
	cin >> n >> m;
	int z = m;
	for(int i = 2;i*i <= z;i++){
		while(z%i==0){
			mp[i]++;
			z/=i;
		}
	}
	if(z>1) mp[z]++;
	int sz = mp.size();
	int s = (1 << sz) - 1;
	int cnt = 0;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		if(m%a[i]==0){
			cnt++;
			auto it = mp.begin();
			int mask = 0;
			for(int j = 0;j < sz;j++){
				int cnt = 0;
				while(a[i]%it->first==0){
					a[i]/=it->first;
					cnt++;
				}
				if(cnt==it->second) mask |= (1 << j);
				it++;
			}
			f[s & (~mask)]++;
		}
	}

	pw[0] = 1;
	for(int i = 1;i < N;i++) pw[i] = (pw[i - 1] * 2)%MOD;
	//注意坑点 m==1那么只有1的组合可以,1的组合在cnt中
	if(m==1){
		cout << pw[cnt] - 1 << endl; 
		return;
	}
	for(int i = 0;i < 20;i++){
		for(int j = 0;j <= s;j++){
			if(j & (1 << i)) f[j ^ (1 << i)] += f[j];
		}
	}
	int ans = pw[cnt] - 1; //总方案数,只算符合条件的也就是cnt个
	int r = 0; //非法方案数
	for(int i = 1;i <= s;i++){
		bt[i] = (bt[i >> 1]) + (i&1);
		if(bt[i]&1){
			r = (r + pw[f[i]] - 1 + MOD)%MOD;
		}else{
			r = (r - pw[f[i]] + 1 + MOD)%MOD;
		}
	}
	cout << (MOD + ans-r)%MOD << endl;
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
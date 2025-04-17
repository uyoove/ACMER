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
string s;
int n;
ULL h[N],p[N],rh[N];
int gt(int l,int r,int op){
	if(op==1){
		return h[r] - h[l - 1] *p[r-l + 1];
	}else{
		return rh[r] - rh[l - 1] *p[r-l + 1];
	}
}
void solve(){
	string ts = s;
	string s2 = s;
	n=s.size();
	s = " " + s;
	for(int i = 1;i <= n;i++) h[i] = h[i - 1]*P + s[i];
	reverse(all(s2));
	s2 = " " + s2;
	for(int i = 1;i <= n;i++) rh[i] = rh[i - 1]*P + s2[i];
	int ans = n;
	for(int i = 0;i < n;i++){
		int t = gt(n-i,n,1),t2 = gt(1,1+i,2);
		if(t==t2){
			ans = i + 1;
		}
	}	
	cout << ts;
	for(int i = n - ans-1;i>=0;i--) cout << ts[i];
	cout << endl;
}

signed main(){
	std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    p[0] = 1;
    for(int i = 1;i < N;i++) p[i] = p[i - 1] * P;
    int times = 1;
	while(cin >> s){
		solve();
	}
	return 0;
}
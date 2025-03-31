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
	int n;
	string s1,s2;
	int l = 0,r = 0;
	void solve(){
		cin >> n >> s1 >> s2;
		int cnt = 0;
		for(int i = 0;i<n;i++){
			if(s1[i]!=s2[i]){
				if(i==0){
					l = i;
					cnt++;
					r = i;
				}else{
					if(s1[i - 1]==s2[i-1]){
						cnt++;
						l = i;
					}
					r = i;
				}
			}
		}
		if(cnt > 2){
			cout << 0 << endl;
		}else if(cnt == 2){
			cout << 6 << endl;
		}else if(cnt == 1){
			int p = n - r - 1 + l;
			p*=2;
			cout << p +(r - l + 1 - 1)*2 << endl;
		}else{
			cout << (1 +n)*n/2<< endl;
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
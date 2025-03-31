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
set<vt<int>> se;
void ptr(int a,int b,int c,int d){
	cout << "Cube = " << a <<", Triple = (" << b <<"," << c << "," << d << ")" <<endl;
}
void solve(){
	map<int,int> h;
	for(int p = 2;p <= 200;p++){
		h[p*p*p] = p;
	}
	//cout << 9*9*9 << " "<< 1 + 6*6*6 + 8*8*8 << endl;
	vt<vt<int>> re;
	for(int i = 1;i<=200;i++){
		for(int j = 2;j<=i;j++){
			for(int k = j + 1;k<=i;k++){
				int d = j*j*j + k*k*k;
				int s = i*i*i;
				vt<int> v;
				v.pb(j);
				v.pb(k);

				if(h.count(s-d)){
					v.pb(h[s-d]);
					sort(all(v));
					if(se.count(v)) continue;
					se.insert(v);
					vt<int> re2;
					re2.pb(i);
					for(auto p : v){
						re2.pb(p);
					}
					re.pb(re2);
				}

			}
		}
	}
	sort(all(re),[](auto a1,auto a2){return a1[0] != a2[0] ? a1[0] < a2[0] : a1[1] < a2[1];});
	for(auto p:re){
		ptr(p[0],p[1],p[2],p[3]);
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
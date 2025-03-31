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
int n,x,y;
vt<int> vx,vy;
int work(vt<int> v,int x){
	int ans = 0;
	map<int,int> h;
	int su = 0;
	for(auto p:v) su-=p;//默认全是负的
	int sz = v.size();
	int hf = sz/2;
	for(int i = 0;i < (1 << hf);i++){
		int res = 0;
		for(int j =0;j<hf;j++){
			if((i >> j)&1) res += 2*v[j];
		}
		h[res] = i;
		//cout <<res << " " << i <<endl;
		if(su + res == x){
			return i;
		}
	} 
	for(int i = 0;i < (1 << (sz - hf));i++){
		int res = 0;
		for(int j =0;j<sz-hf;j++){
			if((i >> j)&1) res += 2*v[j + hf];
		}
		if(su + res == x){
			return i << hf;
		}
		if(h.count(x-(su+res))){
			//cout << su << " " << res<<  " "<< x-(su+res)<<  endl;
			return (i << hf) + h[x-(su+res)]; 
		}
	} 
	return -1;

}
void solve(){
	cin >> n >> x >> y;
	for(int i = 1;i <= n;i++){
		int t;
		cin >> t;
		if(i%2) vx.pb(t);
		else vy.pb(t);
	}
	int ans1 = work(vx,y),ans2 = work(vy,x);
	//cout << ans1 << " " <<ans2 << endl;
	if(ans1==-1||ans2==-1){
		cout << "No" << endl;
		return;
	}
	int to = 1;//1右,2下,3左,4上
	cout << "Yes" << endl;
	int i1 = 0,i2 = 0;
	for(int i = 1;i <= n;i++){
		if(i%2){
			if(to == 1){
				if((ans1 >> i1) & 1) to = 4,cout << "L" ;
				else to = 2,cout << "R";

			}else{
				if((ans1 >> i1) & 1) to = 4,cout << "R" ;
				else to = 2,cout << "L";
			}
			i1++;
		}else{
			if(to == 4){
				if((ans2 >> i2) & 1) to = 1,cout << "R" ;
				else to = 3,cout << "L";

			}else{
				if((ans2 >> i2) & 1) to = 1,cout << "L";
				else to = 3,cout << "R" ;
			}
			i2++;
		}
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
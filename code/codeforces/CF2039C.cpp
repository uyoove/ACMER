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
const ll inf = 0x3f3f3f3f3f3f3f3fLL;
const int infi = 0x3f3f3f3f;
const int P = 13331;
const int N = 200005;

void solve(){
	int x,m;
	cin >> x >> m;
	int cnt = 0;
	set<int> se;
	for(int i = 1;i*i <= x;i++){
		if(x%i==0){
			int d = x^(i);
			if(d > 0&&d <= m) cnt++,se.insert(d);
			if(i == x/i) break;
			if(x/i > m) continue;
			int p = x/i;
			int d2 = x^p;
			if(d2>0&&d2<=m) cnt++,se.insert(d2);
		}
	} 
	int id = 0;
	for(int i = 0;i <= 21;i++){
		if(pow(2,i) >= x){
			id = i;
			break;
		}
	}
	
	for(int i = 1;i <= min(2*x,m);i++){
		if((i^x)==0) continue;
		if(i==x) continue;
		if(i%(x ^ i)==0) cnt++,se.insert(i),cout << i << endl; 
		
	}
	cout << cnt << endl;

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
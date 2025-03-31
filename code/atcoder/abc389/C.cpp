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
const int N = 500005;
PII stk[N];
int x1[N];
int top = 1,h = 1,sz = 0;
void solve(){
	int q;
	cin >> q;
	while(q--){
		int op;
		cin >> op;
		if(op==1){
			int x;
			cin >> x;
			if(top==h){
				stk[top].fi = 0;
				stk[top].se = x;
			}else{
				stk[top].fi = stk[top-1].se;
				stk[top].se = stk[top].fi + x;
			}
			x1[top] = x;
			top++;
		}else if(op==2){
			sz+=x1[h];
			h++;
		}else{
			int k;
			cin >> k;

			cout << stk[h + k -1].fi -sz << endl;
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
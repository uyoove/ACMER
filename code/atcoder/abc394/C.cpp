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
string s;
stack<char> st;
void solve(){
	cin >> s;
	for(auto p:s){
		if(st.empty()){
			st.push(p);
		}else{
			if(st.top()=='W' && p=='A'){
				st.pop();
				int t = 1;
				while(st.size() && st.top() == 'W'){
					st.pop();
					t++;
				}
				st.push('A');
				for(int j = 1;j <= t;j++){
					st.push('C');
				}
			}else{
				st.push(p);
			}
		}
	}
	vt<char> v;
	while(st.size()){
		v.pb(st.top());st.pop();
	}
	reverse(all(v));
	for(auto p:v){
		cout << p;
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
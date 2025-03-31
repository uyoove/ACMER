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
int res[N];
void solve(){
	string s;
	cin >> s;
	int n = s.size();
	reverse(s.begin(),s.end());
	int val;
	cin >> val;
	bool f = false;
	bool ff = false;
	for(int i = 62;i >= 0;i--){
		if(i > n - 1){
			if(val & (1ll << i)){
				ff=true;
				break;
			}
			continue;
		}
		if(s[i] != '1' && (val & (1ll << i))){
			break;
		}
		if(s[i] == '1' && (val & (1ll << i)) == 0){
			cout << -1 << endl;
			return;
		}
	}
	stack<int> st;
	stack<int> st2;
	
	for(int i = n - 1;i >= 0;i--){
		//cout << s[i] << " "
		if(s[i] == '0' && (val & (1ll << i))){
			ff=true;
			continue;
		}
		if(s[i] == '?' && (val & (1ll << i))){
			res[i] = 1;
			while(st2.size()) st2.pop();
			st.push(i);
			continue;
		}

		if(s[i] == '?' && (val & (1ll << i)) == 0){

			if(ff) res[i] = 1;
			else res[i] = 0;
			st2.push(i);
			continue;
		}
		if(!ff && s[i] == '1' && (val & (1ll << i)) == 0){
			res[i] = 1;
			if(st.size()) res[st.top()] = 0;
			while(st2.size()) res[st2.top()] = 1,st2.pop();
			ff= true;
			continue;
		}
		res[i] = s[i] - '0';
	}
	int ans = 0;
	for(int i = n - 1;i>=0;i--){
		if(res[i]) ans|=(1ll << i);
	}
	cout << ans << endl;
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
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
string s[N];
int a[N];
int n,m;
bool check(){
	for(int i = 1;i < n;i++){
		string s1 = s[a[i]],s2 = s[a[i + 1]];
		int cnt = 0;
		for(int k = 0; k < m;k++) if(s1[k]!=s2[k]) cnt++;
		if(cnt != 1) return false;
	}
	return true;
}
void solve(){
	cin >> n >>m;
	for(int i = 1;i <= n;i++) cin >> s[i];
	iota(a,a+n+1,0);
	do{
		if(check()){
			cout << "Yes" << endl;
			return;
		}
	}while(next_permutation(a+1,a+n+1));
	cout << "No" << endl;
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
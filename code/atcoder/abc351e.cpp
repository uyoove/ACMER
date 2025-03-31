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
//奇数格 偶数格分类讨论, 考虑选择方格,那么原先 x,y坐标,在选择45度后变为 (x - y)/2,(x + y)/2
//这只适用于偶数,但奇数格让他们y集体+1就会变成偶数,因为绝对位置不变 所以不影响答案
int n;
bool cmp1(PII p1,PII p2){
	return p1.se < p2.se;
}
int work(vector<PII>& v){
	for(auto &p:v){
		int x = p.fi,y = p.se;
		p.fi = (x - y)/2;
		p.se = (x + y)/2;
	}
	int res = 0;
	sort(v.begin(),v.end());
	int pre = 0,cnt = 0;
	for(auto [x,_]:v){
		res+= x*cnt - pre;
		pre+=x;
		cnt++;
	}
	pre = 0,cnt = 0;
	sort(v.begin(),v.end(),cmp1);
	for(auto [_,y]:v){
		res+= y*cnt - pre;
		pre+=y;
		cnt++;
	}
	return res;
}
void solve(){
	cin >> n;
	vector<PII> p1,p2;
	for(int i = 1;i <= n;i++){
		int l,r;
		cin >> l >> r;
		if((l+r)%2){
			p2.pb({l,r + 1});
		}else{
			p1.pb({l,r});
		}
	}
	cout << work(p1) + work(p2) << endl;

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
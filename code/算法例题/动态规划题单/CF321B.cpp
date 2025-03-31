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
const int N = 205;
int n,m;
//我一个牌可以打a,也可以打d
//显而易见,打d就得全部打完;
//那我就用最小的能打d的打完
int vis[N];//表示打d什么用了
vt<int> a,d;
int c[N];
void solve(){
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		string s;
		cin >> s;
		int v;
		cin >> v;
		if(s[0]=='A'){
			a.pb(v);
		}else{
			d.pb(v);
		}
	}
	int sz = d.size();
	for(int i = 1;i <= m;i++) cin >> c[i];
	sort(c + 1,c + m + 1);
	sort(all(d));
	bool f = true;//能不能打完所有防御牌
	int res1 = 0;//第一种情况
	for(int i = sz - 1;i >= 0;i--){
		bool f1 = false;
		for(int j = 1;j <= m;j++){
			if(!vis[j] && c[j] > d[i]){
				vis[j] = 1;
				f1=true;
				break;
			}
		}
		if(!f1){
			f = false;
		}
	}
	sort(a.begin(),a.end());
	if(f){
		
		int sz = a.size();
		int su = 0;
		int p = 0;
		
		for(int i = sz - 1;i >= 0;i--){
			bool f1 = false;
			for(int j = 1;j <= m;j++){
				if(!vis[j] && c[j] >= a[i]){
					vis[j] = 1;
					su += c[j] - a[i];
					f1=true;
					//cout << c[j] << " " << a[i] <<endl;
					break;
				}
			}
			if(!f1){
				f = false;
			}
		}
		if(f) for(int i = 1;i <= m;i++) if(!vis[i]) su+=c[i];
		res1 = su;
	}
	//cout << res1 <<endl;
	int res2 = 0;
	for(int i = 0,j = m;i < a.size() && j >= 1;i++,j--){
		if(a[i] <= c[j]){
			res2 += c[j] - a[i];
		}
	}
	cout << max(res2,res1) <<endl; //打一半退出res2,全部打完res1
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
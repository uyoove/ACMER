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
set<int> se; //存储每个被占用的下标
struct nodes{
	int l,r;
	bool operator<(const nodes& t1)const{
		return l < t1.l;
	}
}a[N];
void solve(){
	int n;
	cin >> n;
	se.insert(0);//防止越界
	for(int i = 1;i <= n;i++){
		cin >> a[i].l >> a[i].r; 
		a[i].r+=a[i].l;
	}
	sort(a + 1,a + 1 + n);
	int ans = 0;
	priority_queue<int,vector<int>,greater<int>> q;
	int now;
	for(int i = 1;i <= n;i++){
		int j = i;
		now = a[i].l;
		while(j <= n && a[j].l == now) q.push(a[j++].r);
		while(!q.empty() && now < a[j].l){
			int t = q.top();q.pop();
			if(t >= now){
				now++;
				ans++;
			}
		}
		i = j - 1;
	}
	while(!q.empty()){
			int t = q.top();q.pop();
			if(t >= now){
				now++;
				ans++;
			}
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
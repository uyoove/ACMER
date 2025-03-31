//最后一舞
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
const int N = 300005;
int n,m;
int a[N],b[N];
struct nodes
{
	int val,op;
	bool operator<(const nodes& n1)const{
		return val > n1.val;
	}
}c[N];
void solve(){
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i],c[i].val = a[i],c[i].op = 0;
	for(int j = 1;j <= m;j++) cin >> b[j];
	sort(a + 1,a + 1 + n);
	for(int i = 1;i <= n;i++) c[i].val = a[i],c[i].op = 0;
	sort(b + 1,b + 1 + m);
	int del = n - m;
	int cnt = 0;
	bool f = 1;
	for(int i = 1;i <= m;i++){
		int id = n - m + i;
		if(a[id] > b[i]) f=0;
		cnt+=b[i]-a[id]; 
		c[id] = {a[id],b[i]};
	}
	if(!f || cnt > del){
		cout << -1 << endl;
		return;
	} 
	priority_queue<nodes> q2,q;
	for(int i = 1;i <= del;i++) q2.push(c[i]);
	for(int i = del + 1;i <= n;i++) q.push(c[i]);
	vt<int> ans;
	f = 1;
	while(cnt < del){
		if(q2.empty()){
			f = 0;
			break;
		}
		nodes p = q2.top();q2.pop();
		ans.pb(p.val);
		++p.val;
		if(p.val > q.top().val){
			cnt--;   //刚好只会超过1个单位
			nodes u = q.top();
			q.pop();
			if(p.val > u.op){ //不能超过
				f = 0;
				break;
			}
			p.op = u.op;
			q2.push(u);
			q.push(p);
		}else{
			q2.push(p);
		}
		del--;
		q2.pop();
	}
	if(!f || cnt > del){
		cout << -1 << endl;
		return;
	}
	while(q.size()){
		nodes p = q.top();q.pop();
		int d = p.op - p.val;
		while(d--){
			ans.pb(p.val);
			p.val++;
		}
	}
	cout << ans.size() << endl;
	for(auto p:ans){
		cout << p << " ";
	}
	cout << endl;
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
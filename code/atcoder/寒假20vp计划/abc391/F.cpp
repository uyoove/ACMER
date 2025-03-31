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
int n,k;
int a[N],b[N],c[N];
struct nodes
{
	int val,a,b,c;
	bool operator<(const nodes &t1)const{
		return val < t1.val;
	}
};
bool cmp(int a,int b){return a > b;}
int ta[N],tb[N],tc[N];
void solve(){
	cin >> n >> k;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		ta[i] = rnd();
	}
	for(int i = 1;i <= n;i++){
		cin >> b[i];
		tb[i] = rnd();
	}
	for(int i = 1;i <= n;i++){
		cin >> c[i];
		tc[i] = rnd();
	}
	sort(a + 1,a + 1 + n,cmp);
	sort(b + 1,b + 1 + n,cmp);
	sort(c + 1,c + 1 + n,cmp);
	priority_queue<nodes> pq;
	pq.push({a[1]*b[1] + a[1]*c[1] + c[1]*b[1],1,1,1}); 
	int cnt = 0;
	set<int> se;//三个坐标按顺序映射成哈希值
	int y = rnd(), e = rnd(),s = rnd();
	while(pq.size()){
		auto p = pq.top();pq.pop();
		if(se.count(p.a*y+p.b*e+s * p.c)) continue; //注意重复
		se.insert(p.a*y+p.b*e+s * p.c);
		cnt++;
		//cout << cnt << endl;
		if(cnt==k){
			cout << p.val << endl;
			return;
		}
		if(p.a + 1<=n) pq.push({a[p.a+1]*b[p.b] + a[p.a+1]*c[p.c] + c[p.c]*b[p.b],p.a+1,p.b,p.c});
		if(p.b + 1<=n) pq.push({a[p.a]*b[p.b + 1] + a[p.a]*c[p.c] + c[p.c]*b[p.b + 1],p.a,p.b + 1,p.c});
		if(p.c + 1<=n) pq.push({a[p.a]*b[p.b] + a[p.a]*c[p.c + 1] + c[p.c + 1]*b[p.b],p.a,p.b,p.c + 1});
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
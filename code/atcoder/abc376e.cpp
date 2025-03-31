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
const int N = 1000005;
int n,k;
int a[N],b[N],p[N];
struct nodes{
	int a,b;
	bool operator<(const nodes&t1)const{
		return a < t1.a;
	}
}v[N];
void solve(){
	cin >> n >> k;
	set<int> se;
	for(int i = 1;i <= n;i++) cin >> v[i].a,se.insert(v[i].a);
	for(int i = 1;i <= n;i++) cin >> v[i].b;
	int j = 1;
	priority_queue<int> q;
	sort(v + 1,v+1+n);
	int cnt = 0;
	int res = 1e18;
	for(auto p:se){
		while(j <= n && v[j].a <= p){
			if(q.size() == k){
				if(q.top() >  v[j].b){
					cnt-=q.top();q.pop();
					cnt+=v[j].b;
					q.push(v[j].b);
				}
			}else if(q.size() < k){
				q.push(v[j].b);
				cnt+=v[j].b;
			}
			if(q.size()==k) res=min(res,cnt*p);
			//cout << j << " " <<cnt << endl;
			j++;
		}
	}
	cout << res << endl;
	
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
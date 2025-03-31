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
int n,q1;
int h[N];
//pre[i] 为第一个高于i的数的位置
//pre[i] >= l && r < i
struct qys{
	int l,r,id;
}; 
struct nodes{
	int i;
	bool operator<(const nodes & t1)const{
		return h[i] > h[t1.i]; 
	}
};
int pre[N];
int tr[N],ans[N];
void add(int k,int x){
	for(int i = k;i < N;i+=(i&-i)) tr[i]+=x;
}
int query(int k){
	int res = 0; 
	for(int i = k;i > 0;i-=(i&-i)) res+=tr[i];
	return res;
}
void solve(){
	cin >> n >> q1;
	for(int i = 1;i<=n;i++){
		cin >> h[i];
	}
	vt<vt<qys>> v(n + 1);
	for(int i = 1;i <= q1;i++){
		int l,r;
		cin >>l >> r;
		v[r].pb({l,r,i});
	}
	priority_queue<nodes> q;
	for(int i = n;i >= 1;i--){
		while(q.size() && h[q.top().i] < h[i]){
			pre[q.top().i] = i;
			q.pop();
		}
		q.push({i});
	}
	for(int i = n;i >= 1;i--){
		for(auto p:v[i]){
			int id = p.id;
			int l = p.l;
			ans[id] += query(l);
		}
		if(pre[i]) add(pre[i],1);
		else add(1,1);
		//cout << pre[i] <<endl;
	}
	for(int i = 1;i<=q1;i++){
		cout << ans[i] << endl;
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
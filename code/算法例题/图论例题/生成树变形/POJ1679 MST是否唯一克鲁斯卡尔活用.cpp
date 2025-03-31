//和爸爸一起学编程真好,不过要小学四年级分流考试了,最近没时间写代码了,呜呜呜
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <iostream>
#include <map>
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
struct edges{
	int u,v,w,flag;
	bool operator<(const edges e1)const{
		if(w==e1.w) return flag < e1.flag;
		return w < e1.w;
	}
}e[N];
int n,m;
int f[N];
int fd(int x){
	if(f[x]!=x) f[x] = fd(f[x]);
	return f[x];
}

int klu(int op){
	int ans = 0,cnt=0;
	bool flag = false;
	for(int i = 0;i <= n;i++) f[i] = i;
	sort(e + 1,e + 1 + m);
	for(int i = 1;i<=m;i++){
		int x = fd(e[i].u),y = fd(e[i].v);
		if(x==y) continue;
		f[x] = y; 
		ans += e[i].w;
		cnt++;

		if(op){
			if(!e[i].flag){
				flag = 1;
				break;
			}
		}
		e[i].flag = 1;
		if(cnt==n-1) break;
	}
	if(op && flag){
		return -1;
	}
	return ans;
}
void solve(){
	cin >> n >> m;
	for(int i = 1;i <= m;i++){
		cin >> e[i].u >> e[i].v >> e[i].w;
		e[i].flag = 0;
	}
	int p = klu(0);
	int f = klu(1);
	if(f==-1){
		cout << "Not Unique!" <<endl;
	}else{
		cout << p << endl;
	}

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
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
// 对每个1找后面最先符合条件的3
struct nodes{
	int op,v,id;
};
vector<nodes> h;
int res[N];
int q;
int suf[N];
int t3[N],tot = 0;

void solve(){
	cin >> q;
	int d = q;
	int idx = -1;
	while(d--){
		int op;
		cin >> op;
		if(op==1){
			h.push_back({op,0,++idx});
		}else{
			int v;
			cin >> v;
			h.push_back({op,v,++idx});
			if(op==3) t3[++tot] = idx;
		}
	}
	for(int i = q-1;i>=0;i--){
		suf[i] = suf[i + 1] + (h[i].op==2 ? h[i].v : 0);
	}
	for(int i = 0;i <= q-1;i++){
		if(h[i].op==1){
			int l = lower_bound(t3 + 1,t3 + tot + 1,h[i].id) - t3;
			int r = tot,ans=-1;
			while(l<=r){
				int mid = l+r>>1;
				//cout << i << " " << mid << " "<< suf[h[i].id] - suf[h[t3[mid]].id]  << endl;
				if(suf[h[i].id] - suf[h[t3[mid]].id]>=h[t3[mid]].v){
					r = mid - 1;
					ans = mid;
				}else{
					l = mid + 1;
				}
			}
			if(ans!=-1) res[ans]++;
		}
	}
	for(int i = 1;i<=tot;i++) cout << res[i] << endl;


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
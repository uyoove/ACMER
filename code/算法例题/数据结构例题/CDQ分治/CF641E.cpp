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
int n;
struct node{
	int op,t,x,id;
}a[N];
int ans[N];
int cnt[N];
vector<int> ls;
int gt(int x){
	return lower_bound(ls.begin(),ls.end(),x) - ls.begin() + 1;
}
bool cmp(node a,node b){
	return a.t < b.t;
}
void cdq(int l,int r){
	if(l==r) return;
	int mid = l + r >> 1;
	cdq(l,mid),cdq(mid+1,r);
	sort(a + l,a + mid +1,cmp);
	sort(a + mid + 1,a + r +1,cmp);
	int i = l,j = mid + 1;
	while(i <= mid && j <= r){
		if(a[i].t <= a[j].t){
			if(a[i].op == 1){
				cnt[a[i].x]++;
			}else if(a[i].op==2){
				cnt[a[i].x]--;
			}
			i++;
		}else{
			if(a[j].op==3){
				ans[a[j].id]+=cnt[a[j].x];
			}
			j++;
		}
	}
	while(j<=r){
		if(a[j].op==3){
			ans[a[j].id]+=cnt[a[j].x];
		}
		j++;
	}
	for(int i = l;i <= mid;i++){
		cnt[a[i].x] = 0;
	}
}
void solve(){
	cin >> n;
	memset(ans,0,sizeof ans);
	set<int> se;
	for(int i = 1;i <= n;i++){
		cin >> a[i].op >> a[i].t >> a[i].x;
		a[i].id = i;
		ls.push_back(a[i].x);
		if(a[i].op==3) se.insert(i);
	}
	sort(ls.begin(),ls.end());
	ls.erase(unique(ls.begin(),ls.end()),ls.end());
	for(int i = 1;i <= n;i++){
		a[i].x = gt(a[i].x);
	}
	cdq(1,n);
	for(int i = 1;i <= n;i++){
		if(se.count(i)) cout << ans[i] << endl;
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
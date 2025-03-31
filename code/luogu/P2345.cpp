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
	int val,x;
}a[N];
bool cmp(node a,node b){
	return a.val < b.val;
}
bool cmp2(node a,node b){
	return a.x < b.x;
}
int ans = 0;
void cdq(int l,int r){
	if(l==r) return;
	int mid = l+r>>1;
	cdq(l,mid),cdq(mid+1,r);
	sort(a + l,a+mid+1,cmp2);
	sort(a+mid+1,a+r+1,cmp2);
	int i = l, j = mid + 1;
	int su = 0;
	for(int i = l;i <= mid;i++) su += a[i].x;
	int small = 0;
	while(j <= r){
		while(i <= mid && a[i].x <= a[j].x){
			small+=a[i].x;
			i++;
		}
		int slen = i - l;//小的个数
		int blen = mid - i + 1;//大的个数
		ans += (slen * a[j].x - small) * a[j].val;
		ans += (-blen * a[j].x + su - small) * a[j].val;
		j++;
	}
}
void solve(){
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i].val >> a[i].x;
	}
	sort(a + 1, a + 1 + n,cmp);
	cdq(1,n);
	cout <<ans;
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
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
const int N = 100005;
int n,k;
int a[N],pre[N];
int ans = 0;
void cdq(int l,int r){
	if(l==r) {
		return;
	}
	int mid = l+r>> 1;
	cdq(l,mid),cdq(mid+1,r);
	sort(pre + l,pre + mid + 1);
	sort(pre + mid + 1,pre + r + 1);
	int i = l, j = mid + 1;
	while(j <= r){
		 while(i <= mid && pre[i] <= pre[j]){
		 	i++;
		 }
		 j++;
		 ans+=(i - l);
	}
}
void solve(){
	cin >> n >> k;
	for(int i = 1;i <= n;i++) {
		cin >> a[i];
		pre[i] = pre[i - 1] + a[i] - k;
	}
	cdq(0,n);
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
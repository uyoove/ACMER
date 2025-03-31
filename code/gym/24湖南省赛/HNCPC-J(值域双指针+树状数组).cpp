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
int tr1[N],tr2[N];
void add(int k,int val,int op){
	if(op==1){
		for(int i = k;i < N;i+=(i&-i)) tr1[i]+=val;
	}else{
		for(int i = k;i < N;i+=(i&-i)) tr2[i]+=val;
	}
}
int query(int k,int op){
	int res = 0;
	if(op==1){
		for(int i = k;i > 0;i-=(i&-i)) res+=tr1[i];
	}else{
		for(int i = k;i > 0;i-=(i&-i)) res+=tr2[i];
	}
	return res;
}
int pos1[N],pos2[N],a[N],b[N];
void solve(){
	cin >> n;
	for(int i = 1;i<=n;i++) cin >> a[i],pos1[a[i]] = i;
	for(int i = 1;i<=n;i++) cin >> b[i],pos2[b[i]] = i;
	int l = 1;
	int ans = 0;
	for(int r = 1;r <= n;r++){
		add(pos1[r],1,1);
		add(pos2[r],1,2);
		int q1 = query(pos1[r],1);
		int q2 = query(pos2[r],2);
		while(l<r && q1!=q2){
			add(pos1[l],-1,1);
			add(pos2[l],-1,2);
			q1 = query(pos1[r],1);
			q2 = query(pos2[r],2);
			l++;
		}
	
		ans += r-l+1;
		
	}
	cout << ans;
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
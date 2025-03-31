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
const int N = 400005;
int mod = 1e9+7;
int n,q;
int inv[600];
int prm[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89,97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293};
void getprm(){
	for(int i = 2;i<N;i++){
		if(prm[i]==0) prm[++prm[0]] = i;
		for(int j = 1;j <= prm[0] && prm[j]*i < N;j++){
			prm[i*prm[j]] = -1;
			if(i%prm[j]==0) break;
		}
	}
}
//欧拉函数 f(x) = x * 积(pi - 1/pi) pi为x的所有质因数
int a[N];
ll powerMod(ll x, ll n, ll mod){ //快速幂
    ll ans = 1;
    while (n > 0){
        if  (n & 1)
            ans = (ans * x) % mod;
        x = (x * x) % mod;
        n >>= 1;
    }
    return ans;
}
struct Tree{
	int l,r,len,p,val,tag,tagp;
}tr[N << 2];
Tree calc(Tree x,Tree y){
	Tree t;
	t.p = x.p | y.p;
	t.val = x.val * y.val % mod;
	return t;
}
void push_up(int u){
	Tree t = calc(tr[lc],tr[rc]);
	tr[u].p = t.p;
	tr[u].val = t.val;
}
void build(int u,int l,int r){
	tr[u] = {l,r,r-l+1,0,a[l],1,0};
	if(l==r){
		for(int i = 0;i<62;i++){
			if(a[l]%prm[i]==0) tr[u].p |= (1ll) << (i);
		}
		return;
	}
	int mid = l + r >> 1;
	build(lc,l,mid);
	build(rc,mid + 1,r);
	push_up(u);
}
void push_down(int u){
	int tag = tr[u].tag;
	tr[lc].val = tr[lc].val * powerMod(tag,tr[lc].len,mod) % mod;
	tr[rc].val = tr[rc].val * powerMod(tag,tr[rc].len,mod) % mod;
	tr[rc].tag = tr[rc].tag * tag % mod;
	tr[lc].tag = tr[lc].tag * tag % mod;
	tr[u].tag = 1;

	tr[lc].p |= tr[u].tagp;
	tr[rc].p |= tr[u].tagp;
	tr[lc].tagp |= tr[u].tagp;
	tr[rc].tagp |= tr[u].tagp;
	tr[u].tagp = 0;
}
void update(int u,int l,int r,int x,int p){
	if(tr[u].l > r || tr[u].r < l) return;
	if(tr[u].l >= l && tr[u].r <= r){
		tr[u].p|=p;
		tr[u].tagp|=p;
		tr[u].val=powerMod(x,tr[u].len,mod) * tr[u].val%mod;
		tr[u].tag *= x;
		tr[u].tag%=mod;
		return;
	}
	push_down(u);
	update(lc,l,r,x,p);
	update(rc,l,r,x,p);
	push_up(u);
}
Tree query(int u,int l,int r){
	if(tr[u].l > r || tr[u].r < l) return {0,0,0,0,1};
	if(tr[u].l >= l && tr[u].r <= r){
		return tr[u];
	}
	push_down(u);
	return calc(query(lc,l,r),query(rc,l,r));
}
int f[N];
void solve(){
	cin >> n >> q;
	for(int i = 1;i <= n;i++) cin >> a[i];
	build(1,1,n);
	while(q--){
		string s;
		cin >> s;
		if(s[0] == 'M'){
			int l,r,x;
			cin >> l >> r >> x;
			int p = 0;
			for(int i = 0;i < 62;i++){
				if(x%prm[i]==0){
					p |= (1ll) << (i);
				}
			}
			update(1,l,r,x,p);
		}else{
			int l,r;
			cin >> l >> r;
			Tree ans = query(1,l,r);
			int val = ans.val;
			int res = val;
			//cout << res << endl;
			for(int i = 0;i < 62;i++){
				if((ans.p >> i) & (1ll)){
					//cout << res << " " << f[i + 1] << endl;
					res = res * f[i]%mod;
				}
			}
			cout << res << endl;
		}
	}

}

signed main(){
	std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
	int times = 1;
	//cin >> times;
	inv[1] = 1;
	//getprm();
	for(int i = 2; i <= 500; ++i) inv[i] = inv[mod % i] * (mod - mod / i) % mod;
	for (int i = 0; i < 62; ++i){

		f[i] = inv[prm[i]] * (prm[i] - 1) % mod;
	}
	while(times--){
		solve();
	}
	return 0;
}
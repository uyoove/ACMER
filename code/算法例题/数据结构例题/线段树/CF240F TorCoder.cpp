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
int n,q;
string s;
struct Tree{
	int l,r,len,sz[26],key,tag;
}tr[N << 2];
//每个节点的单词个数;
void push_up(int u){
	for(int i = 0;i < 26;i++) tr[u].sz[i] = tr[lc].sz[i] + tr[rc].sz[i];
}
void build(int u,int l,int r){
	tr[u].l=l,tr[u].r=r,tr[u].tag = -1;
	tr[u].len = tr[u].r-tr[u].l + 1;
	if(l==r){
		tr[u].sz[s[l] - 'a'] = 1;
		tr[u].key = s[l] - 'a';
		return;
	}
	int mid = l + r >> 1;
	build(lc,l,mid);
	build(rc,mid+1,r);
	push_up(u);
}
void push_down(int u){
	if(tr[u].tag != -1){
		tr[lc].tag = tr[rc].tag = tr[u].tag;
		for(int i = 0;i < 26;i++){
			tr[lc].sz[i] = tr[rc].sz[i] = 0;
		}
		tr[lc].key = tr[rc].key = tr[u].tag;
		tr[lc].sz[tr[u].tag] = tr[lc].len;
		tr[rc].sz[tr[u].tag] = tr[rc].len;
		tr[u].tag = -1;
	}
}
int tp[26]; //每次把单词都抽出来进行重构
void query_num(int u,int l,int r){
	if(tr[u].l > r || tr[u].r < l) return;
	if(tr[u].l >= l && tr[u].r <= r){
		for(int i = 0;i < 26;i++){
			tp[i] += tr[u].sz[i];
		}
		return;
	}
	push_down(u);
	query_num(lc,l,r);
	query_num(rc,l,r);
}
int qs(int u,int x){
	if(tr[u].l > x || tr[u].r < x) return -1;
	if(tr[u].l == x && tr[u].r == x){
		return tr[u].key;
	}
	push_down(u);
	int p = qs(lc,x);
	if(p==-1) return qs(rc,x);
	return p;
}
void modify(int u,int l,int r,int x){
	if(tr[u].l > r || tr[u].r < l) return;
	if(tr[u].l >= l && tr[u].r <= r){
		tr[u].tag = x;
		for(int i = 0;i < 26;i++){
			tr[u].sz[i] = 0;
		}
		tr[u].sz[x] = tr[u].len;
		tr[u].key = x;
		return;
	}
	push_down(u);
	modify(lc,l,r,x);
	modify(rc,l,r,x);
	push_up(u);
}
void solve(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	cin >> n >> q >> s;
	s = " " + s;
	build(1,1,n);
	while(q--){
		int l,r;
		cin >> l >>r ;
		memset(tp,0,sizeof tp);
		query_num(1,l,r);
		int j = 0;
		int ch;
		for(int i = 0; i < 26;i++){
			if(tp[i]%2) j++,ch = i;
		}
		if(j >= 2) continue;
		if((r-l+1)%2==0 && j>=1) continue;
		if((r-l + 1)%2==1){
			int mid = (r + l)/2;
			modify(1,mid,mid,ch);
			int p = 0;
			for(int i = 0;i < 26;i++){
				if(i==ch) tp[i]--;
				modify(1,l + p,l + p + tp[i]/2 - 1,i);
				modify(1,r-p-tp[i]/2+1,r-p,i);
				p += tp[i]/2;
			}
		}else{
			int p = 0;
			for(int i = 0;i < 26;i++){
				modify(1,l + p,l + p + tp[i]/2 - 1,i);
				modify(1,r-p-tp[i]/2+1,r-p,i);
				p += tp[i]/2;
			}
		}
	}
	for(int i = 1;i <= n;i++){
		cout << (char)(qs(1,i) + 'a');
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
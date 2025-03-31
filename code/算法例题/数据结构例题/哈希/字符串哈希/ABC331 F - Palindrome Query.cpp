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
const int N = 1000005;

int n,q;
ULL p[N];
struct Tree{
	int l,r;
	ULL sz,hs;
};
struct TR{
	string s;
	vector<Tree> tr;
	TR(){}
    TR(string s1,int n) {
        s = s1;
        tr.resize((n << 2) + 3);
    }
	void push_up(int u){
		tr[u].sz = tr[lc].sz + tr[rc].sz;
		tr[u].hs = tr[lc].hs + tr[rc].hs * p[tr[lc].sz];
	}
	void build(int u,int l,int r){
		tr[u] = {l,r,1,s[l]};
		if(l==r) return;
		int mid = l + r >> 1;
		build(lc,l,mid);
		build(rc,mid + 1,r);
		push_up(u);
	}
	void modify(int u,int x,int val){
		if(tr[u].l > x || tr[u].r < x) return;
		if(tr[u].l==x&&tr[u].l==tr[u].r){
			tr[u].hs = val;
			return;
		}
		modify(lc,x,val);
		modify(rc,x,val);
		push_up(u);
	}
	Tree query(int u,int l,int r){
		if(tr[u].l >=l && tr[u].r <= r){
			return tr[u];
		}
		int mid = tr[u].l + tr[u].r >> 1;
		if(r<= mid){
			return query(lc,l,r);
		}
		if(l> mid){
			return query(rc,l,r);
		}
		Tree T1 = query(lc,l,r);
		Tree T2 = query(rc,l,r);
		Tree ans = {0,0,T1.sz + T2.sz,T1.hs + T2.hs * p[T1.sz]};
		return ans;
	}
};
string s;
int hs[N];
void solve(){
	cin >> n >> q >> s;
	string s2 = s;
	p[0] = 1;
	for(int i = 1;i <= n;i++) p[i] = p[i - 1]*P; 
	reverse(s2.begin(),s2.end());
	s2 = " " + s2;
	s = " " + s;
	TR T1(s,n),T2(s2,n);
	T1.build(1,1,n),T2.build(1,1,n);
	while(q--){
		int op;
		cin >>op;
		if(op==2){
			int l,r;
			cin >> l >> r;
			if(T1.query(1,l,r).hs == T2.query(1,n-r+1,n-l+1).hs){
				cout << "Yes" << endl;
			}else{
				cout << "No" << endl;
			}
		}else{
			int x;
			char ch;
			cin >> x >> ch;
			T1.modify(1,x,ch);
			T2.modify(1,n-x+1,ch);
		}
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
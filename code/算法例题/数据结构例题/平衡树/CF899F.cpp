//和爸爸一起学编程真好,不过要小学四年级分流考试了,最近没时间写代码了,呜呜呜
#include<bits/stdc++.h>
using namespace std;
#define out(x) cout << #x << '=' << (x) << endl
#define out2(x, y) cout << #x << '=' << (x) << ',' << #y << '=' << (y) << endl 
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
int n,m;
struct Fenwick{
	vector<int> tr;
	int sz;
	void init(int n){
		tr.resize(n + 1);
		sz = n;
	}
	Fenwick(){}
	Fenwick(int n){
		init(n);
	}
	void add(int k,int val){
		for(int i = k;i <= sz;i+=(i&-i)){
			tr[i]+=val;
		}
	}
	int query(int k){
		int res = 0;
		for(int i = k;i > 0;i-=(i&-i)){
			res+=tr[i];
		}
		return res;
	}
	int ask_sum(int l,int r){
		return query(r) - query(l - 1);
	}
	int kth(int k){
		int l=0,tot=0,x,y;
		for(int i=20;i>=0;--i)
		{
			x=l+(1<<i);
			if(x>n)continue;
			y=tot+tr[x];
			if(y<k)l=x,tot=y;
		}
		return l+1;
	}
};
Fenwick fk(N - 2);
struct FHQ{
	int ls,rs,key,val;
}fhq[65][N];
int root[65],T1,T2,T3,idx[65];
void split(int u,int v,int &x,int &y,int op){
	if(!u){
		x=y=0;
		return;
	}
	if(fhq[op][u].val > v){
		y = u;
		split(fhq[op][u].ls,v,x,fhq[op][u].ls,op);
	}else{
		x = u;
		split(fhq[op][u].rs,v,fhq[op][u].rs,y,op);
	}
}
int merge(int x,int y,int op){
	if(x==0||y==0) return x + y;
	if(fhq[op][x].key > fhq[op][y].key){
		fhq[op][x].rs = merge(fhq[op][x].rs,y,op);
		return x;
	}else{
		fhq[op][y].ls = merge(x,fhq[op][y].ls,op);
		return y;
	}
}
int add(int v,int op){
	fhq[op][++idx[op]] = {0,0,rnd(),v};
	return idx[op];
}
void insert(int v,int op){
	split(root[op],v,T1,T2,op);
	root[op] = merge(merge(T1,add(v,op),op),T2,op);
}
int ans[N];
void ptr(int u,int op){
	if(!u) return;
	ans[fhq[op][u].val] = op;
	ptr(fhq[op][u].ls,op);
	ptr(fhq[op][u].rs,op);
}
void del(int op,int u){
	if(u==0) return;
	if(fhq[op][u].ls!=0) del(op,fhq[op][u].ls);
	fk.add(fhq[op][u].val,-1);
	if(fhq[op][u].rs!=0) del(op,fhq[op][u].rs);
}
void erase(int l,int r,int op){
	split(root[op],l - 1,T1,T2,op);
	split(T2,r,T2,T3,op);
	root[op] = merge(T1,T3,op);
	del(op,T2);
}

string s;
map<char,int> mp;
map<int,char> f;
int tot;

void solve(){
	for(char i = 'a';i<='z';i++) mp[i] = ++tot,f[tot] = i;
	for(char i = 'A';i<='Z';i++) mp[i] = ++tot,f[tot] = i;
	for(char i = '0';i<='9';i++) mp[i] = ++tot,f[tot] = i;
	cin >> n >> m;
	cin >> s;
	s = " " + s;
	
	for(int i = 1;i <= n;i++){
		insert(i,mp[s[i]]);
		fk.add(i,1);
	}
	
	for(int i = 1;i <= m;i++){
		int l,r;
		char ch;
		cin >> l  >> r >> ch;
		l = fk.kth(l),r = fk.kth(r);
		erase(l,r,mp[ch]);
		//cout << l << " " << r << " "<< t << endl;
	}
	for(int i = 1;i <= tot;i++){
		ptr(root[i],i);
	}
	for(int i = 1;i <= n;i++){
		if(!ans[i]) continue;
		cout << f[ans[i]]<<"";
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
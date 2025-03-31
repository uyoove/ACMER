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
int n,m;
int ain[N],bin[N];
int ans[N];
string ch[N];
int cnt = 0;//判环
struct nodes{
	int id,op,val;
	bool operator<(const nodes &t1)const{
		return t1.val < val;
	}
};
struct DSU {
    vector<int> f, val;
    DSU(){}
    DSU(int n) {
        init(n);
    }
    void init(int n) {
        f.resize(n);
        iota(f.begin(), f.end(), 0);
        val.assign(n, 0);
    }
    int fd(int x) {
        if(f[x]==x) return x;
        return f[x] = fd(f[x]);
    }
    bool same(int x, int y) {
        return fd(x) == fd(y);
    }
    bool mg(int x, int y) {
        x = fd(x);
        y = fd(y);
        if (x == y)return false;
        f[y] = x;
        return true;
    }
};
int vis[N][3];
struct edges{
	int v,ne;
}e[N << 1];
int h[N],idx = 1;
void add(int u,int v){
	e[++idx] = {v,h[u]};
	h[u] = idx;
}
void solve(){
	cin >> n >> m;
	int cur = 0;
	DSU dsu(n + m + 2);
	for(int i = 1;i <= n;i++){
		string s;
		cin >> s;
		ch[i] = s;
		ch[i] = " " + ch[i];
		for(int j = 0;j < s.size();j++){
			if(s[j]=='>'){
				bin[j + 1]++;
			}else if(s[j]=='<'){
				ain[i]++;
			}else{
				dsu.mg(i,j + 1 + n);
				
			}
		}
		
	}
	set<PII> se2;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			if(ch[i][j]=='>'){
				//if(se2.count({dsu.fd(i),dsu.fd(j + n)})) continue;
				//se2.insert({dsu.fd(i),dsu.fd(j + n)});
				add(dsu.fd(j + n),dsu.fd(i));
				dsu.val[dsu.fd(i)]++;
			}else if(ch[i][j]=='<'){
				//if(se2.count({dsu.fd(j + n),dsu.fd(i)})) continue;
				//se2.insert({dsu.fd(j + n),dsu.fd(i)});
				add(dsu.fd(i),dsu.fd(j+n));
				dsu.val[dsu.fd(j+n)]++;
			}
		}
	}
	queue<PII> q;
	int cnt = 0;
	int t = 0;
	for(int i = 1;i <= n + m;i++){
		if(dsu.fd(i) == i){
			t++;
			if(dsu.val[i] == 0){
				q.push({i,1});
			}
		}
	}
	while(q.size()){
		auto p = q.front();q.pop();
		ans[p.fi] = p.se;
		set<int> se;
		for(int i = h[p.fi];i;i=e[i].ne){
			int v = e[i].v;
			dsu.val[v]--;
			if(dsu.val[v]==0){
				q.push({v,ans[p.fi] + 1});
			}
		}
		cnt++;
	}
	if(cnt!=t){
		cout << "No" << endl;
		return;
	}
	cout << "Yes" << endl;
	for(int i = 1;i <= n;i++){
		cout << ans[dsu.fd(i)] << " ";
	}
	cout << endl;
	for(int i = 1;i <= m;i++){
		cout << ans[dsu.fd(i + n)] << " ";
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
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
const ll inf = 0x3f3f3f3f3f3f3f3fLL;
const int infi = 0x3f3f3f3f;
const int P = 13331;
const int N = 1000005;
int n;
struct node{
	int a,b,c;
}v[N];
bool cmp1(node n1,node n2){
	if(n1.a==n2.a) return n1.b < n2.b;
	return n1.a < n2.a;
}
bool cmp2(node n1,node n2){
	//if(n1.b==n2.b) return n1.a <n2.a;
	return n1.b < n2.b;
}
int ans = 0;
int tr[N];
vector<int> ls;
int gt(int x){return lower_bound(ls.begin(),ls.end(),x) - ls.begin() + 1;}
void add(int k,int val){
	for(int i = k;i < N;i += (i & -i)) tr[i] += val;
}
int query(int k){
	int res = 0;
	for(int i = k;i > 0;i -= (i & -i)) res += tr[i];
	return res;
}
void cdq(int l,int r){
	if(l==r) return;
	int mid = l+r >> 1;
	cdq(l,mid),cdq(mid + 1,r);
	sort(v + l,v + mid + 1,cmp2),sort(v + mid + 1,v + r + 1,cmp2);
	int i = l;
	for(int j = mid + 1;j <= r;j++){
		while(i <= mid && v[i].b < v[j].b){
			add(v[i].c,1);
			i++;
		}
		ans += query(v[j].c - 1);
	}
	for(int t =l;t < i;t++){
		add(v[t].c,-1);
	}
}
map<int,vt<PII>> h;
void solve(){
	cin >> n;
	for(int i = 1;i <= n;i++) {
		int p[3];
		cin >> p[0] >> p[1] >> p[2];
		sort(p,p+3);
		v[i].a = p[0];
		v[i].b = p[1];
		v[i].c = p[2];
		ls.pb(v[i].c);
		
	}
	sort(ls.begin(),ls.end());
	ls.erase(unique(ls.begin(),ls.end()),ls.end());
	for(int i = 1;i <= n;i++){
		v[i].c = gt(v[i].c);
		h[v[i].a].pb({v[i].b,v[i].c});
	}
	sort(v + 1,v + 1 + n,cmp1);
	cdq(1,n);
		//把a相等的部分去掉即可
	int anst = 0;
	memset(tr,0,sizeof tr);
	for(auto &[k,v]:h){
		sort(v.begin(),v.end());
		int pre = -1;
		stack<int> st;
		stack<int> st2;
		for(auto &p:v){
			//add(p.se,1);
			
			if(p.fi!=pre && pre!=-1){
				while(st.size()) add(st.top(),1),st2.push(st.top()),st.pop();
			}
			st.push(p.se);
			pre = p.fi;
			ans-=query(p.se - 1); 
		}
		while(st2.size()) add(st2.top(),-1),st2.pop();
		while(st.size()) st.pop();
	}
	cout << (ans > 0 ? "Yes" : "No") << endl;
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
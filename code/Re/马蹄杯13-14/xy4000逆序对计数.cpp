//最后一舞
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define vt vector
#define all(x) x.begin(), x.end()
#define endl "\n"
typedef long long ll;
const int N = 200005;
int n,m;
ll ans[N];//区间 mi< x < mx,x的数量,如果a[v] > a[u] 那么总的答案会 + 2 * ans[i] + 1,其余是2*ans[i]-1;
int ql[N],qr[N],a[N];
struct nodes{
	int x,val,add,id,op; //1是增加/减少, 0是询问
}qs[N*9];
int tot = 0;
int tr[N];
void add(int k,int val){
	for(int i = k;i < n+1;i+=(i&-i)) tr[i]+=val;
}
int query(int k){
	int res = 0;
	for(int i = k;i > 0;i-=(i&-i)){
		res += tr[i];
	}
	return res;
}
bool cmp(nodes x,nodes y){
	if(x.x!=y.x) return x.x<y.x;

	if(x.val==y.val) return x.op > y.op;
	return x.val<y.val;
}
vt<nodes> tmp;
void cdq(int l,int r){
	if(l==r) return;
	int mid = l + r >> 1;
	cdq(l,mid),cdq(mid + 1,r);
	tmp.clear();
	for(int i = l;i <= mid;i++){
		if(qs[i].op==1){
			tmp.pb(qs[i]);
		}
	}
	for(int i = mid + 1;i <= r;i++){
		if(qs[i].op==0){
			tmp.pb(qs[i]);
		}
	}
	sort(all(tmp),cmp);
	for(auto &p:tmp){
		if(p.op==1){
			add(p.val,p.add);
		}else{
			ans[p.id] += query(p.val) * p.add;
		}
	}
	for(auto &p:tmp){
		if(p.op==1){
			add(p.val,-(p.add));
		}
	}
	
}
void solve(){
	cin >> n >> m;
	for(int i = 1;i <= n;i++) a[i]=i,qs[++tot]={i,a[i],1,0,1};
	for(int i = 1;i <= m;i++){
		cin >> ql[i] >> qr[i];
		int l =ql[i],r = qr[i];
		int mx = max(a[l],a[r]),mi = a[l] + a[r] - mx;
		qs[++tot] = {r-1,mx-1,1,i,0};
		qs[++tot] = {l,mx - 1,-1,i,0};
		qs[++tot] = {r-1,mi,-1,i,0};
		qs[++tot] = {l,mi,1,i,0};

		qs[++tot] = {l,a[l],-1,i,1};
		qs[++tot] = {r,a[r],-1,i,1};
		swap(a[l],a[r]);
		qs[++tot] = {l,a[l],1,i,1};
		qs[++tot] = {r,a[r],1,i,1};
		
	}
	cdq(1,tot);
	ll s = 0;
	for(int i = 1;i <= n;i++) a[i] = i;
	for(int i = 1;i <= m;i++){
		int p = ans[i];
		int u = ql[i],v = qr[i];
		if(a[u] < a[v]){
			s += 2*p +1;
		}else{
			s-=2*p+1;
		}
		swap(a[u],a[v]);
		cout << s << endl;
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
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
const int N = 2000005;
int n,m;
int mx,my;
struct node
{
	int x,y,id,op,ans;
}a[N << 1],t[N << 1],p[N<<1];
int tot;
int tr[N << 1];
bool cmp(node a,node b){
	return a.id < b.id;
}
void init(){
	for(int i = 1;i <= tot;i++ ) a[i] = p[i];
}
bool cmp2(node a,node b){
	if(a.x==b.x) return a.y < b.y;
	return a.x < b.x;
}
void add(int k,int val,int op){
	//cout << k << " "<< val <<endl;
	if(op==1) for(int i = k;i <= my;i+=(i&-i)) tr[i]=max(tr[i],val);
	else for(int i = k;i <= my;i+=(i&-i)) tr[i]=0;
}
int query(int k){
	int res = 0;
	for(int i = k;i > 0;i-=(i&-i)) res= max(res,tr[i]);
	return res;
}
void cdq(int l,int r){
	if(l==r) return;
	int mid = l+r>>1;
	cdq(l,mid),cdq(mid+1,r);
	int i = l;
	for(int j = mid + 1;j <= r;j++){
		while(i <= mid && a[i].x <= a[j].x){
			if(a[i].op == 1) add(a[i].y,a[i].x + a[i].y,1);
			++i;
		}
		if(a[j].op == 2){
			int tp = query(a[j].y);
			if(tp) p[a[j].id].ans = min(p[a[j].id].ans,a[j].x+a[j].y - tp);
			//cout << tp << " " <<a[j].id <<endl;
		}
	}
	for(int k = l;k < i;k++) if(a[k].op == 1) add(a[k].y,-(a[k].x + a[k].y),0);
	i = l;
	int j = mid +1;
	int k = l - 1;
	while(j<=r){
		while(i<=mid&&cmp2(a[i],a[j])) t[++k]=a[i],++i;
		t[++k]=a[j],++j;
	} 
	while(j<=r) t[++k]=a[j++];
	while(i<=mid) t[++k] = a[i++];
	for(int i = l;i <= r;i++) a[i] = t[i];
}
void solve(){
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		int x,y;
		cin>>x>>y;
		x++;
		y++;
		mx=max(mx,x),my = max(my,y);
		p[++tot] = {x,y,0,1,0};
	}
	for(int i = 1;i <= m;i++){
		int op,x,y;
		cin >> op >> x >> y;
		x++;
		y++;
		mx=max(mx,x),my = max(my,y);
		p[++tot] = {x,y,tot,op,inf};
	}
	init();
	 cdq(1,tot);
	 for(int i = 1;i <= tot;i++) a[i].x = mx - a[i].x + 1;
	 //init();
	sort(a + 1,a + tot + 1,cmp);
	 cdq(1,tot);
	 for(int i = 1;i <= tot;i++) a[i].y = my - a[i].y + 1;
	 //init();
	sort(a + 1,a + tot + 1,cmp);
	 cdq(1,tot);
	 for(int i = 1;i <= tot;i++) a[i].x = mx - a[i].x + 1;
	 //init();
	sort(a + 1,a + tot + 1,cmp);
	 cdq(1,tot);
	sort(a+1,a+1+tot,cmp);
	for(int i = 1;i <= tot;i++){
		if(p[i].op==2){

			//cout << a[i].x << " " <<a[i].y << " " << a[i].id << " ";
			cout << p[i].ans <<endl;
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
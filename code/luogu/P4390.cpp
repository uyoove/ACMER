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
int w;
int tr[N];
void add(int k,int val){
	for(int i = k;i <= w;i+= (i & -i)) tr[i] += val;
}
int query(int k){
	int res = 0;
	for(int i = k;i > 0;i-=(i&-i)){
		res += tr[i];
	}
	return res;
}
struct node{
	int x,y,val,id,time;
}a[N];
int tot;
bool cmp(node n1,node n2){
	return n1.time < n2.time;
}
bool cmp2(node n1,node n2){
	if(n1.x==n2.x) return n1.y < n2.y;
	return n1.x < n2.x;
}
void cdq(int l,int r){
	if(l == r) return;
	int mid = l + r >> 1;
	cdq(l,mid),cdq(mid+1,r);
	sort(a + l, a + mid + 1,cmp2);
	sort(a + mid + 1,a + r + 1,cmp2);
	int i = l;
	for(int j = mid + 1;j <= r;j++){
		while(i <= mid && a[i].x <= a[j].x){
			if(a[i].id==0) add(a[i].y,a[i].val);
			i++;
		}
		if(a[j].id == 1) a[j].val += query(a[j].y);
	}
	for(int j = l;j < i;j++) if(a[j].id==0) add(a[j].y,-a[j].val);
}
void solve(){
	int op;
	cin >> op;
	cin >> w;
	w+=1;
	cin >> op;
	while(op!=3){
		if(op==1){
			int x,y,val;
			cin >> x >> y >> val;
			a[++tot] = {x + 1,y + 1,val,0,tot};
		}else{
			int x1,y1,x2,y2;
			cin >> x1 >> y1 >> x2 >> y2;
			x1+=1;
			y1+=1;
			x2+=1;
			y2+=1;
			a[++tot] = {x1 - 1,y1 - 1,0,1,tot};
			a[++tot] = {x2,y2,0,1,tot};
			a[++tot] = {x1 - 1,y2,0,1,tot};
			a[++tot] = {x2,y1 - 1,0,1,tot};
		}
		cin >> op;
	}
	cdq(1,tot);
	sort(a + 1,a + 1 +tot,cmp);
	for(int i = 1;i<=tot;i++){
		if(a[i].id == 1){
			cout << a[i].val + a[i + 1].val - a[i + 2].val - a[i + 3].val << endl;  
			i+=3;
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
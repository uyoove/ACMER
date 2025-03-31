# FHQ Treap

无旋Treap 可以和线段树相同解决区间问题,甚至能解决区间翻转问题

## 例题

### 1.普通平衡树

https://www.luogu.com.cn/problem/P3369

**思路:**

- 板子题没什么好讲的,主要是按值分裂和合并

```c++
mt19937 rnd(114514);
const int infi = 0x3f3f3f3f;
const int N = 100005;
struct FHQ{
	int ls,rs,key,sz,val;
}fhq[N];
int root,T1,T2,T3,idx;
int add(int v){
	fhq[++idx] = {0,0,(int)rnd(),1,v};
	return idx;
}
void push_up(int u){
	fhq[u].sz = fhq[fhq[u].ls].sz + fhq[fhq[u].rs].sz + 1;	
}
//按值分裂,把<=v 与 >v分成两部分
void split(int u,int v,int &x,int &y){
	if(!u){
		x=y=0;
		return;
	}
	if(fhq[u].val > v){
		y = u;
		split(fhq[u].ls,v,x,fhq[u].ls);
	}else{
		x = u;
		split(fhq[u].rs,v,fhq[u].rs,y);
	}
	push_up(u);
}
int merge(int x,int y){
	if(!x||!y) return x+y;
	if(fhq[x].key > fhq[y].key){
		fhq[x].rs = merge(fhq[x].rs,y);
		push_up(x);
		return x;
	}else{
		fhq[y].ls = merge(x,fhq[y].ls);
		push_up(y);
		return y;
	}
}
void insert(int v){
	split(root,v,T1,T2);
	root = merge(merge(T1,add(v)),T2);
}
void erase(int v){
	split(root,v,T1,T2);
	split(T1,v - 1,T1,T3);
	T3 = merge(fhq[T3].ls,fhq[T3].rs);
	root = merge(merge(T1,T3),T2);
}

int get_rank(int v){
	split(root,v - 1,T1,T2);
	int res = fhq[T1].sz + 1;
	root = merge(T1,T2);
	return res;
}

int get_kth(int k){
	int u = root;
	while(u){
		int tp = fhq[fhq[u].ls].sz + 1;
		if(tp == k){
			break;
		}
		if(tp > k){
			u = fhq[u].ls;
		}else{
			u = fhq[u].rs;
			k-= tp;
		}
	}
	return fhq[u].val;
}
int find_pre(int u,int v){
	if(u==0) return -infi;
	if(fhq[u].val < v){
		int res = find_pre(fhq[u].rs,v);
		return res == -infi ? fhq[u].val : res; 
	}else{
		return find_pre(fhq[u].ls,v);
	}
}
int find_suf(int u,int v){
	if(u==0) return infi;
	if(fhq[u].val > v){
		int res = find_suf(fhq[u].ls,v);
		return res == infi ? fhq[u].val : res; 
	}else{
		return find_suf(fhq[u].rs,v);
	}
}
void solve(){
	int n;
	cin >> n;
	while(n--){
		int op,x;
		cin >> op >> x;
		if(op==1) insert(x);
		if(op==2) erase(x);
		if(op==3) cout << get_rank(x) <<endl;
		if(op==4) cout << get_kth(x) << endl;
		if(op==5) cout << find_pre(root,x) << endl;
		if(op==6) cout << find_suf(root,x) << endl;
	}
}
```

### 2.发牌

https://www.luogu.com.cn/problem/P3988

**思路:**

按前kth分裂,前k个分裂成T1,后面的分裂成T2,合并的时候根据题意,删一个,倒着合并即可

```c++
mt19937_64 rnd(time(0));
const int N = 1000005;
struct FHQ
{
	int ls,rs,key,val,sz;
}fhq[N];
int root,T1,T2,T3,idx;
int add(int v){
	fhq[++idx] = {0,0,rnd(),v,1};
	return idx;
}
void push_up(int u){
	fhq[u].sz = fhq[fhq[u].ls].sz + fhq[fhq[u].rs].sz + 1;
}
void split_rank(int u,int k,int &x,int &y){
	if(u==0){
		x=y=0;
		return;
	}
	int temp = fhq[fhq[u].ls].sz + 1;
	if(k==temp){
		x = u,y = fhq[u].rs;
		fhq[u].rs = 0; 
	}else if(k < temp){
		y = u;
		split_rank(fhq[u].ls,k,x,fhq[u].ls);
	}else{
		x = u;
		split_rank(fhq[u].rs,k - temp,fhq[u].rs,y);
	}
	push_up(u);
}
int merge(int x,int y){
	if(!x || !y) return x+y;
	if(fhq[x].key > fhq[y].key){
		fhq[x].rs = merge(fhq[x].rs,y);
		push_up(x);
		return x;
	}else{
		fhq[y].ls = merge(x,fhq[y].ls);
		push_up(y);
		return y;
	}
}
void solve(){
	int n;
	cin >> n;
	for(int i = 1;i <= n;i++){
		root = merge(root,add(i));
	}
	for(int i = 1;i <= n;i++){
		int x;
		cin >> x;
		x%=fhq[root].sz;
		split_rank(root,x,T1,T2);
		split_rank(T2,1,T2,T3);
		root = merge(T3,T1);//删除一张后倒着合并,比如说1234 2 那么就是 3412删3,那么就是412
		cout << fhq[T2].val << endl;
	}
}
```

### 3.中位数

https://www.luogu.com.cn/problem/P3871

**思路:**

按值分裂插入新值,按排名分裂找前sz/2个为关键点

```c++
const int N = 200005;
mt19937_64 rnd(time(0));
struct FHQ{
	int ls,rs,key,val,sz;
}fhq[N];
int root,T1,T2,T3,idx;
int add(int v){
	fhq[++idx] = {0,0,rnd(),v,1};
	return idx;
}
void push_up(int u){
	fhq[u].sz = fhq[fhq[u].ls].sz + fhq[fhq[u].rs].sz + 1;
}
void split_rank(int u,int k,int &x,int &y){
	if(u==0){
		x = y = 0;
		return;
	}
	int tp = fhq[fhq[u].ls].sz + 1;
	if(tp == k){
		x = u;
		y = fhq[u].rs;
		fhq[u].rs = 0;
	}else if(tp > k){
		y = u;
		split_rank(fhq[u].ls,k,x,fhq[u].ls);
	}else{
		x = u;
		split_rank(fhq[u].rs,k - tp,fhq[u].rs,y);
	}
	push_up(u);
}
void split(int u,int v,int &x,int &y){
	if(!u){
		x=y=0;
		return;
	}
	if(fhq[u].val > v){
		y = u;
		split(fhq[u].ls,v,x,fhq[u].ls);
	}else{
		x = u;
		split(fhq[u].rs,v,fhq[u].rs,y);
	}
	push_up(u);
}
int merge(int x,int y){
	if(!x||!y) return x+y;
	if(fhq[x].key > fhq[y].key){
		fhq[x].rs = merge(fhq[x].rs,y);
		push_up(x);
		return x;
	}else{
		fhq[y].ls = merge(x,fhq[y].ls);
		push_up(y);
		return y;
	}	
}
void solve(){
	int n;
	cin >> n;
	for(int i = 1;i <= n;i++){
		int t;
		cin >> t;
		split(root,t - 1,T1,T2);
		root = merge(merge(T1,add(t)),T2);

	}
	int q;
	cin >> q;
	while(q--){
		string op;
		cin >> op;
		if(op=="add"){
			int x;
			cin >> x;
			split(root,x - 1,T1,T2);
			root = merge(merge(T1,add(x)),T2);
		}else{
			int sz = fhq[root].sz;
			int p = sz/2;
			//cout << p << endl;
			if(sz%2 == 0){
				split_rank(root,p,T1,T2);
				split_rank(T1,p - 1,T1,T3);
				cout << fhq[T3].val << endl;
				root = merge(merge(T1,T3),T2);
			}else{
				split_rank(root,p,T1,T2);
				split_rank(T2,1,T2,T3);
				cout << fhq[T2].val << endl;
				root = merge(merge(T1,T2),T3);
			}	
			
		}
	}
}
```

### 4.New Year Tree

https://codeforces.com/problemset/problem/620/E

区间或操作,把数先序遍历处理出来,然后一个子树就是一个节点出去的l,与节点回来的r,用lazy标记维护Treap,但是或操作要或自己原来的节点

```c++
const int N = 400005;
int n,m;
int c[N];
int in[N],out[N];
int d[N];//代表每个节点的值
struct egdes{
	int v,ne;
}e[N << 1];
int h[N],idx = 1;
void add(int u,int v){
	e[++idx] = {v,h[u]},h[u] = idx;
}
int cnt;
void dfs(int u,int f){
	in[u] = ++cnt;
	d[cnt] = c[u];
	for(int i = h[u];i;i=e[i].ne){
		if(e[i].v==f) continue;
		dfs(e[i].v,u);
	}
	out[u] = cnt;
}
struct FHQ{
	int ls,rs,key,val,tag,id,sz,tval;
}fhq[N];
int root,tot,T1,T2,T3;
int ad(int v,int id){
	fhq[++tot] = {0,0,rnd(),(1ll << v),0,id,1,(1ll << v)};
	return tot;
}
void push_up(int u){
	fhq[u].val = fhq[fhq[u].ls].val | fhq[fhq[u].rs].val | fhq[u].tval;
	fhq[u].sz = fhq[fhq[u].ls].sz + fhq[fhq[u].rs].sz+1;
}
void push_down(int u){
	if(fhq[u].tag){
		if(fhq[u].ls) fhq[fhq[u].ls].tag = fhq[u].tag,fhq[fhq[u].ls].val = fhq[fhq[u].ls].tval = fhq[u].tag;
		if(fhq[u].rs) fhq[fhq[u].rs].tag = fhq[u].tag,fhq[fhq[u].rs].val = fhq[fhq[u].rs].tval = fhq[u].tag;
		fhq[u].tag = 0;
	}
}
void split(int u,int val,int &x,int &y){
	if(!u){
		x = y = 0;
		return;
	}
	push_down(u);
	int tp = fhq[fhq[u].ls].sz + 1;
	if(tp==val){
		x = u,y = fhq[u].rs;
		fhq[u].rs = 0;
	}
	else if(tp > val){
		y = u;
		split(fhq[u].ls,val,x,fhq[u].ls);
	}else{
		x = u;
		split(fhq[u].rs,val-tp,fhq[u].rs,y);
	}
	push_up(u);
}
int merge(int x,int y){
	if(x)push_down(x);
	if(y)push_down(y);
	if(x==0||y==0) return x+y;
	if(fhq[x].key <= fhq[y].key){
		fhq[y].ls = merge(x,fhq[y].ls);
		push_up(y);
		return y;
	}
	else{
		fhq[x].rs = merge(fhq[x].rs,y);
		push_up(x);
		return x;
	}
}
void insert(int id,int v){
	root = merge(root,ad(v,id));
}
void upd(int l,int r,int v){
	split(root,l - 1,T1,T2);
	split(T2,r - l + 1,T2,T3);
	fhq[T2].val = fhq[T2].tval = fhq[T2].tag = (1ll << v);
	root = merge(T1,merge(T2,T3));
}
int query(int l,int r){
	split(root,l - 1,T1,T2);
	split(T2,r - l + 1,T2,T3);
	int p = fhq[T2].val;
	root = merge(merge(T1,T2),T3);
	return p;
}
void solve(){
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> c[i];
	for(int i = 1;i <= n - 1;i++){
		int u,v;
		cin >> u >> v;
		add(u,v);
		add(v,u);
	}
	dfs(1,0);
	for(int i = 1;i <= n;i++) insert(i,d[i]);
	while(m--){
		int op;
		cin >> op;
		if(op==1){
			int u,x;
			cin >> u >> x;
			upd(in[u],out[u],x);
		}else{
			int x;
			cin >> x;
			int p = query(in[x],out[x]);
			int d = __builtin_popcountll(p);
			cout << d << endl;
		}
	}
}
```


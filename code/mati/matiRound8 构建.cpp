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
const int N = 200005;
int n;
int a[N];
multiset<int> mx[20],mi[20];
map<int,int> h; //获取当前k是否在之前遍历过
int cnt = 0; //当前编号
int ans[20]; //每个长度的答案
int len[20]; //每个编号的长度
void del(int idx,int val){
	//del操作可不调整堆,因为本题有del就有add,在add时更新即可
	auto it = mx[idx].find(val);
	if(it==mx[idx].end()){
		auto it = mi[idx].find(val);
		ans[idx]-=val;
		mi[idx].erase(it);
	}else{
		auto it = mx[idx].find(val);
		mx[idx].erase(it);
	}
}
void add(int idx,int val){
	mx[idx].insert(val);
	//调整大小,保持小根.size()==k 并且堆顶比大根的大于等于
	while(mx[idx].size() && mi[idx].size() < len[idx]){
		auto it = mx[idx].end();
		it--;
		mi[idx].insert(*it);
		ans[idx]+=*it;
		mx[idx].erase(it);
	}
	while(mi[idx].size() > len[idx]){
		auto it = mi[idx].begin();
		mx[idx].insert(*it);
		ans[idx]-=*it;
		mi[idx].erase(it);
	}
	while(mi[idx].size() && mx[idx].size()){
		auto it1 = mi[idx].begin(),it2 = mx[idx].end();
		it2--;
		int v1 = *it1,v2 = *it2;
		if(v1 >= v2) break;
		ans[idx]+=v2;
		ans[idx]-=v1;
		mi[idx].erase(it1);
		mx[idx].erase(it2);
		mi[idx].insert(v2);
		mx[idx].insert(v1);
	}

}
void solve(){
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> a[i];
	int q;
	cin >> q;
	while(q--){
		int op;
		cin >> op;
		if(op==1){
			int k;
			cin >> k;
			k--; //获取k-1个分割线
			if(h.count(k)){
				cout << a[n] - a[1] - ans[h[k]] << endl;
			}else{
				h[k] = ++cnt;
				len[cnt] = k;
				for(int i = 1;i < n;i++){
					mx[cnt].insert(a[i+1]-a[i]);
				}
				//将k个数放入小根堆
				// for(int i = 0;i < k;i++){
				// 	auto it = mx[cnt].end();
				// 	it--;
				// 	ans[cnt] += *it;
				// 	mx[cnt].erase(it);
				// 	mi[cnt].insert(*it);
				// }
				//可以直接放虚拟空节点使得ans更新 等价于上面注释的代码
				add(cnt,-inf);
				cout << a[n] - a[1] - ans[h[k]] << endl;
			}
		}else{
			int idx,val;
			cin >> idx >> val;
			for(int i = 1;i <= cnt;i++){
				if(idx==1){
					del(i,a[idx + 1] - a[idx]);
				}else if(idx==n){
					del(i,a[idx] - a[idx-1]);
				}else{
					del(i,a[idx + 1] - a[idx]);
					del(i,a[idx] - a[idx - 1]);
				}	
			}
			
			a[idx] = val;
			for(int i = 1;i <= cnt;i++){
				if(idx==1){
					add(i,a[idx + 1] - a[idx]);
				}else if(idx==n){
					add(i,a[idx] - a[idx-1]);
				}else{
					add(i,a[idx + 1] - a[idx]);
					add(i,a[idx] - a[idx - 1]);
				}	
			}
			
		}
	}
}

signed main(){
	std::ios::sync_with_stdio(0);
    // std::cin.tie(0);
    // std::cout.tie(0);
	int times = 1;
	//cin >> times;
	while(times--){
		solve();
	}
	return 0;
}
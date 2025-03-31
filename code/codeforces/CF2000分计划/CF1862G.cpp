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
int a[N],b[N];
set<int> se;
map<int,int> h;
void change(int x,int op,int val){
	if(op==1){
		if(x < *se.rbegin()){
			int p = *se.upper_bound(x);

			h[p - x]+=val;
			if(p - x < 0) out2(x,p);
			if(h[p-x] ==0 ) h.erase(p-x);
		}
	}else{
		if(x > *se.begin()){
			auto it = se.lower_bound(x);
			it--;
			int p = *it;
			h[x - p]+=val;
			if(x - p < 0) out2(x,p);
			if(h[x - p] ==0 ) h.erase(x-p);
		}
	}
}
void solve(){
	cin >> n;
	se.clear(),h.clear();
	map<int,int> mp;
	for(int i = 1;i <= n;i++) cin >> a[i],se.insert(a[i]),b[i] = a[i],mp[a[i]]++;
	cin >> q;
	//差值最大 + 最大值
	sort(b + 1,b + n + 1);
	int pre = 0;
	for(auto p:se){
		if(pre==0) pre = p;
		else h[p - pre]++,pre=p;
	}
	bool f = true;
	while(q--){
		int id,w;
		cin >> id >> w;
		if(n==1){
			cout << w << " ";
			continue;
		}
		if(a[id] == w){
			int mx = 0;
			if(se.size()) mx = *se.rbegin();
			int mx2 = 0;
			if(h.size()){
				auto it = h.rbegin();
				mx2 = it->first;
			}

			cout <<mx +  mx2<<" ";
			continue;
		}
		
		
		mp[a[id]]--;
		if(mp[a[id]]==0) {
			change(a[id],0,-1);
			change(a[id],1,-1);
			se.erase(a[id]);
			auto p = se.upper_bound(a[id]);
			if(p!=se.end()){
				change(*p,0,1);
			}else{
				auto p = se.lower_bound(a[id]);
				if(p!=se.begin()){
					p--;
					change(*p,1,1);
				}
			}
		}
		
		
		mp[w]++;
		if(mp[w]==1) {
			auto p = se.upper_bound(w);
			if(p!=se.end()){
				change(*p,0,-1);
			}else{
				auto p = se.lower_bound(w);
				if(p!=se.begin()){
					p--;
					change(*p,1,-1);
				}
			}
			change(w,1,1);
			change(w,0,1);
			

		}
		se.insert(w);
		int mx = 0;
		if(se.size()) mx = *se.rbegin();
		int mx2 = 0;
		if(h.size()){
			auto it = h.rbegin();
			mx2 = it->first;
		
		}

		cout <<mx +  mx2<<" ";
		a[id]=w;
		//f=false;
	}
	cout << endl;
}

signed main(){
	std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
	int times = 1;
	cin >> times;
	while(times--){
		solve();
	}
	return 0;
}


// 1
// 4
// 3 10 6 1
// 10
// 2 9
// 1 2
// 2 2
// 1 5
// 3 4
// 3 9
// 4 5
// 4 10
// 2 9
// 4 10

// 3 9 6 1
// 12 
// 2 9 6 1
// 13
// 2 2 6 1
// 10
// 5 2 6 1
// 9

//2 4 8
//1 6
//2 10

//6 4 8

//2 6  6-4
//7 6  7-1
//7 6  7-1
//7 5  7-2
//2 5  5-3
//2 7  7-5
//2 2  2-0
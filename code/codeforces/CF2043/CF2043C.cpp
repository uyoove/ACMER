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
//找到分界线左边区间最大/小值,右边区间最大/小值
int n,a[N];
void solve(){
	cin >> n;
	int x = 1;
	set<int> se;
	for(int i = 1;i <= n;i++) {
		cin >> a[i];
		se.insert(a[i]);
		if(abs(a[i])!=1) x = i;
	}
	if(x == -1){
		se.insert(0);
		int mi = 0,ma = 0,tp = 0;
		int pmi = 0,pma = 0;
		for(int i = 1;i<=n;i++){
			tp+=a[i];
			mi=min(tp - pma,mi);
			ma=max(tp - pmi,ma);
			pmi = min(pmi,tp);
			pma = max(pma,tp);
		}
		for(int i = mi;i <= ma;i++) se.insert(i);
		cout << se.size() << endl;
		for(auto p:se){
			cout << p << " ";
		}
		cout << endl;
		return;
	}
	int mi = 0,ma = 0,tp = 0;
		int pmi = 0,pma = 0;
		for(int i = 1;i<x;i++){
			tp+=a[i];
			mi=min(tp - pma,mi);
			ma=max(tp - pmi,ma);
			pmi = min(pmi,tp);
			pma = max(pma,tp);
		}
	//cout << mi << " " << ma << endl;
	for(int i = mi;i <= ma;i++) se.insert(i);
	mi = 0,ma = 0,tp = 0;
	pmi = 0,pma = 0;
	for(int i = n;i > x;i--){
		tp+=a[i];
		mi=min(tp - pma,mi);
		ma=max(tp - pmi,ma);
		pmi = min(pmi,tp);
		pma = max(pma,tp);
	}
	for(int i = mi;i <= ma;i++) se.insert(i);
	int lmx = -inf,lmi = inf;
	int val = 0;
	for(int j = x - 1;j >= 1;j--){
		val+=a[j];
		lmx = max(lmx,val);
		lmi = min(lmi,val);
	}
	for(int i = lmi;i <= lmx;i++){
		se.insert(i);
	}
	int rmx = -inf,rmi = inf;
	val = 0;
	for(int j = x + 1;j <= n;j++){
		val+=a[j];
		rmx = max(rmx,val);
		rmi = min(rmi,val);
	}
	
	for(int i = rmi;i <= rmx;i++){
		se.insert(i);
	}
	
	int tpmx = max(max(rmx,lmx),rmx+lmx);
	tpmx = max(0ll,tpmx);

	int tpmi = min(min(rmi,lmi),rmi+lmi);
	tpmi = min(0ll,tpmi);
	for(int i = a[x] + tpmi;i <= a[x] + tpmx;i++){
		se.insert(i);
	}
	se.insert(0);
	cout << se.size() << endl;
	for(auto p:se){
		cout << p << " ";
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
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
int tr[N]; //用两次,一次找逆序,一次存k次冒泡操作
void add(int k,int x){
	for(int i = k;i < N;i += (i&-i)) tr[i] += x;
}
int query(int k){
	int res = 0;
	for(int i = k;i > 0;i -= (i&-i)){
		res+=tr[i];
	}
	return res;
}
int n,m;
int a[N];
int before[N],record[N]; //前面有几个比a[i]大, 前面有i个数比当前大的数量
void solve(){
	cin >> n >> m;
	int tot = 0;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		int q = i - 1 - query(a[i]);
		tot += q;
		before[i] = q;
		record[q]++;
		add(a[i],1);
	}
	memset(tr,0,sizeof tr);
	add(1,tot); //差分思想,将所有操作加上逆序对数量
	tot = 0;
	for(int i = 1;i <= n;i++){
		tot += record[i - 1];
		//n-tot个数要被减逆序数贡献 5 3 2 6 1 这里3 2 1 都被影响,可以看成是一步步解锁过程
		add(i + 1,-(n - tot));//下标偏移一位,即第一次操作完是2,第二次操作完是3,以此类推,在当前逆序
	}
	while(m--){
		int op,x;
		cin >> op >> x;
		if(x >= n) x = n - 1;
		if(op==2){
			cout << query(x + 1) << endl; //偏移了一位
		}else{
			if(a[x] < a[x + 1]){
				//多一个逆序对
				swap(a[x],a[x + 1]);
				swap(before[x],before[x +1]);

				before[x + 1]++;
				add(before[x+1]+1,-1); //一个大区间多一个新的逆序对
				add(1,1);
			}else{
				//少一个逆序对
				swap(a[x],a[x + 1]);
				swap(before[x],before[x +1]);

				add(before[x]+1,1); //一个大区间都少一个原本的逆序对
				add(1,-1);
				before[x]--;
			}
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
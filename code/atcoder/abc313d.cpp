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
int n,k;
int ans[N],b[N]; //b数组存放除了自己本身以外的前k + 1个异或值
void solve(){
	cin >> n >> k;
	if(k==1){
		int x;
		for(int i = 1;i <= n;i++){
			cout << "? " << i << endl;
			cin >> x;
			ans[i] = x;
		}
		cout << "! ";
		for(int i = 1;i <= n;i++){
			cout << ans[i] << " ";
		}
		cout << endl;
		return;
	}
	for(int i = 1;i <= k + 1;i++){
		int x = 0;
		cout << "? ";
		for(int j = 1;j <= k + 1;j++){
			if(j==i) continue;
			cout << j << " ";
		}
		cout << endl;
		cin >> x;
		b[i] = x;
	}
	int op = b[k + 1];
	for(int i = 2;i <= k;i+=2){
		op ^= b[i] ^ b[i + 1]; //这样除了1的都抵消掉了,因为1是奇数个,其余都是偶数个,都会少一个
	}
	ans[1] = op;
	//b[i] ^ b[i+1] = a[i] ^ a[i + 1]; 因为bi 和bi+1 除了 i 和i+1 其余都会抵消
	//a[i + 1] = b[i] ^ b[i + 1] ^ a[i]
	//a[i] = b[i - 1] ^ b[i] ^ a[i - 1] 
	for(int i = 2;i <= k + 1;i++){
		ans[i] = b[i - 1] ^ b[i] ^ ans[i - 1];
	}
	for(int i = k + 2;i <= n;i++){
		cout << "? ";
		int p = 0;
		for(int j = 1;j < k;j++){
			cout << j << " ";
			p^=ans[j];
		}
		cout << i << endl;
		cin >> ans[i];
		ans[i]^=p;
	}
	cout << "! ";
	for(int i = 1;i <= n;i++) cout << ans[i] << " ";
	cout <<endl;


}

signed main(){
	int times = 1;
	//cin >> times;
	while(times--){
		solve();
	}
	return 0;
}
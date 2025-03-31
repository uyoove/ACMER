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
int a[N],b[N];
int l[N],r[N],check[N]; //表示我a的位置为x,b的位置为多少合适
void solve(){
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> a[i];
	for(int j = 1;j <= n;j++) cin >> b[j];
	int q;
	cin >> q;
	int j = 0;
	set<int> se;
	set<int> se2;
	for(int i = 1;i <= n;i++){
		if(se.count(a[i])){
			check[i] = check[i-1];
			l[i]=l[i-1];
			r[i]=r[i-1];
		}else{
			se.insert(a[i]);
			if(se.count(b[j + 1])){
				while(se.count(b[j + 1])){
					se2.insert(b[j+1]);
					if(se2.size()==se.size() && l[i]==0) l[i] = j + 1;
					j++;
				}
				r[i] = j;
				if(se2.size()==se.size()) check[i] = 1;
			} 
		}
		//cout << i << " " << check[i] << " " << l[i] << " " << r[i] << endl;
	}
	for(int _ = 0;_ < q;_++){
		int x,y;
		cin >> x >> y;
		if(!check[x] || y < l[x] || y > r[x]){
			cout << "No" << endl;
		}else{
			cout << "Yes" << endl;
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
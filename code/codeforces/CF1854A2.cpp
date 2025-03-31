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
const int N = 200005;
int n;
int a[N];
bool check(){

}
void solve(){
	cin >> n;
	int z = 0,f = 0;
	int mx = 0,id = 0;
	for(int i = 1;i <= n;i++) {
		cin >> a[i];
		if(a[i] > 0) z++;
		else if(a[i]<0)f++;
		if(abs(a[i]) > mx){
			id = i;
		}
	}
	if(z==0 && f==0){
		cout << 0 << endl;
		return;
	}
	if(f == 0){
		cout << n-1 << endl;
		for(int i = 2;i <= n;i++){
			cout << i << " " << i-1 << endl;
		}
		return;
	}
	if(z==0){
		cout << n-1 << endl;
		for(int i = n;i >=2;i--){
			cout << i-1 << " " << i << endl;
		}
		return;
	}
	vt<PII> v;
	if(min(z,f) > 7){
		if(a[id] > 0){
			for(int i = 1;i <= n;i++){
				if(a[i] < 0){
					a[i]+=a[id];
					v.pb({i,id});
				}
			}
			for(int i = 2;i <= n;i++){
				v.pb({i,i-1});
			}

		}else{
			for(int i = 1;i <= n;i++){
				if(a[i] > 0){
					a[i]+=a[id];
					v.pb({i,id});
				}
			}
			for(int i = n;i >=2;i--){
				v.pb({i-1,i});
			}
		}
		cout << v.size() << endl;
		for(auto [k,v1]:v){
			cout << k << " " << v1 << endl;
		}
		return;
	}
	if(z > f){
		for(int i = 1;i <= n;i++){
			if(a[i] > 0){
				id = i;
				break;
			}
		}
		for(int i = 1;i <= 5;i++) v.pb({id,id});
		for(int i = 1;i <= n;i++){
			if(a[i] < 0){
				v.pb({i,id});
			}
		}
		for(int i = 2;i <= n;i++){
			v.pb({i,i-1});
		}
	}else{
		for(int i = 1;i <= n;i++){
			if(a[i] < 0){
				id = i;
				break;
			}
		}
		for(int i = 1;i <= 5;i++) v.pb({id,id});
		for(int i = 1;i <= n;i++){
			if(a[i] > 0){
				v.pb({i,id});
			}
		}
		for(int i = n;i >=2;i--){
			v.pb({i-1,i});
		}
	}
	cout << v.size() << endl;
	for(auto [k,v1]:v){
		cout << k << " " << v1 << endl;
	}
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
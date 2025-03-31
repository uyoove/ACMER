//和爸爸一起学编程真好,不过要小学四年级分流考试了,最近没时间写代码了,呜呜呜
#include<bits/stdc++.h>
using namespace std;
#define int long long
mt19937_64 rnd(time(0));
const int infi = 0x3f3f3f3f;
const int P = 13331;
const int N = 200005;
int a[N],b[N];
void solve(){
	int n,l,r;
	cin >> n >> l >> r;
	for(int i = 1;i<=n;i++){
		cin >> a[i];
	}
	sort(a + 1,a + l - 1 + 1);sort(a + r + 1,a + n + 1);sort(a + l,a + r + 1);
	for(int i = 1;i <= n;i++){
		b[i] = a[i];
	}
	for(int i = 0;i < r-l+1 && n - i > r;i++){
		if(a[r - i] > a[r + 1 + i]){
			swap(b[r - i],b[r + 1 + i]);
		}
	}
	int su = 0;
	for(int i =l;i <= r;i++){
		su += b[i]; 
	}
	for(int i = 0;i < r-l+1 && i + 1 < l;i++){
		if(a[r - i] > a[i + 1]) swap(a[r - i],a[i + 1]);
	}
	int su2 = 0;
	for(int i =l;i <= r;i++){
		su2 += a[i]; 
	}
	su=min(su,su2);
	cout << su << endl;
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
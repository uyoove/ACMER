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

// bool check(int k){
// 	int p = to_string(k).size();
// 	if(k%4) return false;
// 	bool f = true;
// 	for(int b = 0;b <= p;b++){
// 		int d1 = pow(100,b);
// 		d1*=4;
// 		int d2 = pow(100,b + 1);
// 		if(d2 > k) break;
// 		//cout << k << " " << d1 << " " << d2 << endl;
// 		if(k%d1==0 && k%d2){
// 			continue;
// 		}
// 		return false;
// 	}
// 	return true;
// }
ll re;
int powerMod(int x, int n){ //快速幂
    int ans = 1;
    while (n > 0){
        if  (n & 1)
            ans = (ans * x);
        x = (x * x);
        n >>= 1;
    }
    return ans;
}
int work(int x){
	int cnt = 0;
	int p = 0;
	//cnt-=x/4;
	for(int i = 0;i <= 9;i++){
		int pk = powerMod(100,i);
		int pk2 = 4*powerMod(100,i);
		cnt+=x/pk;
		cnt-=x/pk2;
	}
	return cnt;
}
bool check(int x){
	
	return work(x) - work(2023) >= re;

}
void solve(){
	int s = 2024;
	cin >> re;
	int l = 2024,r = 1320000000000002025,ans = 2024; 
	while(l<=r){
		int mid = l + (r - l)/2;
		if(check(mid)){
			ans = mid;
			r = mid - 1;
		}else{
			l = mid +1;
		}
	}
	cout << ans;
	cout << endl;
}

signed main(){

	ll times = 1;
	cin >> times;
	while(times--){
		solve();
	}
	return 0;
}
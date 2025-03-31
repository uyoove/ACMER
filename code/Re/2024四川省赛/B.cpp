//最后一舞
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
int a[5];
int calc(int l,int r){
	int tp = min(a[l],a[r]);
	a[l]-=tp,a[r]-=tp;
	return tp;
}
void solve(){
	int res = 0;
	for(int i = 1;i <= 5;i++){
		cin >> a[i];
	}
	//两两组合 2,4, 3,3 x,5
	res+=calc(2,4);
	res+=a[3]/2;
	a[3]=a[3]%2;
	int l = 1;
	while(l <= 5 && a[5]){
		if(l < 5){
			res+=calc(l,5);
		}else{
			res+=a[5]/2;
			a[5]%=2; //如果a5还存在说明,前面已经都消失了
			cout << res << endl;
			return;
		}
		l++;
	}

	//三个组合 2 2 2, 2 3 x, 4 x x
	res += a[2]/3;
	a[2]%=3;

	if(a[1]){
		int t = min(min(a[2],a[3]),a[1]);
		a[2]-=t;
		a[3]-=t;
		a[1]-=t;
		res+=t;
	}

	if(a[2] >= 2 && a[3]){
		a[3]--,a[2]-=2;
		res++;
	}
	l = 1;
	while(l <= 4 && a[4]){
		if(l < 4){
			int tp = min(a[4],a[l]/2);
			a[4]-=tp,a[l]-=tp*2;
			res+=tp;
			if(a[l]==1){
				a[l+1]++,a[l] = 0;
			}
		}else{
			res += a[4]/3;
		}
		l++;
	}
	if(a[2] >= 2 && a[1] >= 2){
		a[2] -=2, a[1]-=2;
		res++;
	}
	l = 1;
	while(l <= 3 && a[3]){
		if(l < 3){
			int tp = min(a[3],a[l]/3);
			a[3]-=tp,a[l]-=tp*3;
			res+=tp;
			if(a[l]<3 && l + 1!=3){
				a[l+1]+=a[l],a[l] = 0;
			}
		}else{
			res += a[3]/4;
		}
		l++;
	}
	l = 1;
	while(l <= 2 && a[2]){
		if(l < 2){
			int tp = min(a[2],a[l]/4);
			a[2]-=tp,a[l]-=tp*4;
			res+=tp;
			if(a[l]<4 && l + 1!=2){
				a[l+1]+=a[l],a[l] = 0;
			}
		}else{
			res += a[2]/5;
		}
		l++;
	}
	cout << res + a[1]/6 << endl;

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
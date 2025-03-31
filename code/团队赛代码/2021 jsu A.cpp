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
int cnt[10];

void solve(){
	int su = 0;
	int mx = 0;
	vector<int> ns(10,0);
	int id = -1;
	for(int i = 0;i <= 9;i++){
		cin >> cnt[i];
		su+=cnt[i];
		if(cnt[i] > mx){
			mx = cnt[i];
			id = i;
		}
	}
	if(su == 1 && cnt[0] == 1){
		cout << 0 << endl;
		return;
	}
	if(mx - (su-mx) > 1 || (id == 0 && mx - (su - mx) > 0)){
		cout << -1 << endl;
		return;
	}
	int sy = su - mx;
	int pre = -1;
	if(sy+1 == mx){
		cout << id;
		cnt[id]--;
		pre = id;
	}else{
		for(int i = 1; i < 10;i++){
			if(cnt[i]!=0) {cout << i;cnt[i]--;pre = i;break;}
		}
	}

	for(int i = 1;i <= su - 1;i++){
		int sum = 0;
		int mx = 0;
		int id = -1;
		for(int j = 0;j < 10;j++){
			sum += cnt[j];
			
			if(cnt[j] > mx){
				mx = cnt[j];
				id = j;
			}
		}
		int sy = sum - mx;
		if(sy+1 == mx){
			cout << id;
			pre = id;
			cnt[id]--;
		}else{
			for(int i = 0; i < 10;i++){
				if(cnt[i]!=0 && i!=pre) {cout << i;cnt[i]--;pre = i;break;}
			}
		}

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
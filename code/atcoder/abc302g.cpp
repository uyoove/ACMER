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
int a[N],b[N];
int cnt[5][5];
void solve(){
	int n;
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> a[i],b[i] = a[i];
	sort(b + 1,b + 1 + n);
	int tot = 0;
	for(int i =1 ;i <= n;i++){
		if(a[i]!=b[i]){
			tot++;
			cnt[a[i]][b[i]]++;
		}
	}
	int res = 0;
	for(int i = 1;i <= 4;i++){
		for(int j = 1;j <= 4;j++){
			if(i==j) continue;
			while(cnt[i][j] && cnt[j][i]){
				res++;
				tot-=2;
				cnt[j][i]--;
				cnt[i][j]--;
			}
		}
	}
	for(int i = 1;i <= 4;i++){
		for(int j = 1;j <= 4;j++){
			for(int k = 1;k<=4;k++){
				if(k==j || k== i || i == j) continue;
				while(cnt[i][j] && cnt[j][k] && cnt[k][i]){
					res+=2;
					tot-=3;
					cnt[i][j]--;
					cnt[j][k]--;
					cnt[k][i]--;
				}
			}
		}
	}
	res+=tot/4*3;
	cout <<res;
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
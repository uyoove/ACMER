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
const int mod=1e9+7;
const int p[30]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67};
int basis[32],a[N],b[N];  
int ksm(int a,int b){int res=1;for(;b;b>>=1,a=a*a%mod)if(b&1)res=res*a%mod;return res;}
void insert(int x){
    for(int i=31;i>=0;i--){
        if((x>>i)&1){
            if(!basis[i]){
                basis[i]=x;
                return;  
            }  
            x^=basis[i];
        }  
    }  
}  
void solve(){
	int n;cin>>n;
	for(int i=1;i<=n;i++){
		int x,cnt=0;cin>>x;
		for(int j=0;j<=18;j++){
			int f=0;
			while(x%p[j]==0)f^=1,x/=p[j];
			if(f)cnt|=1<<j;
		}
		insert(cnt);
	}
	for(int i=0;i<=18;i++)if(basis[i])n--;
	cout<<ksm(2,n)-1;
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

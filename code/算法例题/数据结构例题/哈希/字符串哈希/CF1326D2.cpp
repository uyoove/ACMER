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
const int N = 1000005;
string s;
ULL mod = 1e9+7;
ULL mod2 = 1e9+9;
ULL p[N],hs[N],rhs[N];
ULL p1[N],hs1[N],rhs1[N];
bool check(int l,int r){
    ULL p0 = (hs[r] - hs[l - 1] * p[r - l +1]%mod + mod)%mod;
    ULL p2 = (rhs[l] - rhs[r + 1] * p[r - l +1]%mod + mod)%mod;
    ULL p3 = (hs1[r] - hs1[l - 1] * p1[r - l +1]%mod2 + mod2)%mod2;
    ULL p4 = (rhs1[l] - rhs1[r + 1] * p1[r - l +1]%mod2 + mod2)%mod2;
    return p0 == p2 && p3==p4;
}

void solve(){
    cin >> s;
    int n = s.size();
    s = " " + s;
    p[0] = 1;
    for(int i = 1;i <= n;i++){
        p[i] = p[i - 1] * P%mod;
        hs[i] = hs[i - 1] * P + s[i];
        hs[i]%=mod;
    }
    p1[0] = 1;
    for(int i = 1;i <= n;i++){
        p1[i] = p1[i - 1] * P%mod2;
        hs1[i] = hs1[i - 1] * P + s[i];
        hs1[i]%=mod2;
    }
    rhs[n +1] = 0;
    for(int i = n;i>=1;i--){
        rhs[i] = rhs[i + 1]*P+ s[i];
        rhs[i]%=mod;

    }
    rhs1[n +1] = 0;
    for(int i = n;i>=1;i--){
        rhs1[i] = rhs1[i + 1]*P + s[i];
        rhs1[i]%=mod2;
    }
    if(hs[n]==rhs[1] && hs1[n]==rhs1[1]){
        cout << s.substr(1) << endl;
        return;
    }
    int l = 1,r = n;
    while(l <= r && s[l] == s[r]){
        l++,r--;
    }
    int ans1 = 0,ans2 = 0;;
    for(int i = l;i < r;i++){
        if(check(l,i)) ans1 = i - l + 1;
    }
    for(int i = r;i > l;i--){
        if(check(i,r)) ans2 = r - i + 1;
    }
    //cout << ans1 << " " << ans2 << endl;
    if(l==1 && r==n){
        if(ans1>ans2){
            cout << s.substr(1,ans1) << endl;
        }else{
            cout << s.substr(n - ans2 + 1,ans2) << endl;
        }
        return;
    }
    cout << s.substr(1,l - 1);
    if(ans1>ans2){
        cout << s.substr(l,ans1);
    }else{
        cout << s.substr(r - ans2 + 1,ans2);
    }
    cout << s.substr(r + 1,n-r);
    cout<<endl;
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
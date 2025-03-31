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
#define ull unsigned long long
#define il inline
typedef unsigned long long ULL;
typedef long long ll;
mt19937_64 rnd(time(0));
const int N = 5e5 + 1009;
const int mod = 257;
char s[N], t[N], tmp[N];
ull hs[N], pw[N];
int a, b, c, n;
ull ask(int l, int r) {
    return hs[l] - hs[r + 1] * pw[r - l + 1];
}
ull get(int pos) {
    return ask(pos, n) + ask(1, pos - 1) * pw[n - pos + 1];
}
int check() {
    ull tar = 0;
    pw[0] = 1;
    for(int i = 1; i <= n; i++) pw[i] = pw[i - 1] * mod;
    for(int i = n; i >= 1; i--) {
        tar = tar * mod + t[i];
    }
    hs[n + 1] = 0;
    for(int i = n; i >= 1; i--) {
        hs[i] = hs[i + 1] * mod + s[i];
    }
    for(int i = 1; i <= n; i += a) {
        if(tar == get(i + a)) {
            return 1;
        }
    }
    return 0;
}
void work() {
    cin >> s + 1 >> t + 1;
    cin >> a >> b;
    n = strlen(s + 1);
    c = a;
    a = max(a, b) - min(a, b);
    a = __gcd(a, n);
    if(check()) {
        cout << "yes" << endl;
        return ;
    }
    for(int i = 1; i <= n; i++) tmp[i] = s[i];
    int cnt = 0;
    for(int i = c; i >= 1; i--) s[++cnt] = tmp[i];
    for(int i = n; i > c ; i--) s[++cnt] = tmp[i];
    if(check())
        cout << "yes" << endl;
    else cout << "no" << endl;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int Case; cin >> Case;
    while(Case--) work();
    return 0;
}
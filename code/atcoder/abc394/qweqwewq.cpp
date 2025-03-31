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
int n, m;
int w[N];
bool valid[N];
struct Node {
    int l, r;
    int cnt;
    int add, sum;
}tr[N << 2];

void pushup(int u) {
    tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
}

void pushadd(int u, int v) {
    tr[u].add += v;
    tr[u].sum += tr[u].cnt * v;
}

void pushdown(int u) {
    if (tr[u].add) {
        pushadd(u << 1, tr[u].add);
        pushadd(u << 1 | 1, tr[u].add);
        tr[u].add = 0;
    }
}

void build(int u, int l, int r) {
    tr[u] = {l, r, r - l + 1};
    if (l == r) return tr[u].cnt = valid[l], tr[u].sum = w[l], void();
    int mid = l + r >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
    pushup(u);
    tr[u].cnt = tr[u << 1].cnt + tr[u << 1 | 1].cnt;
}

void change(int u, int x) {
    if (valid[x]) tr[u].cnt++;
    else tr[u].cnt--;
    if (tr[u].l == tr[u].r) return;
    pushdown(u);
    int mid = tr[u].l + tr[u].r >> 1;
    if (x <= mid) change(u << 1, x);
    else change(u << 1 | 1, x);
}

void modify(int u, int l, int r, int x) {
    if (tr[u].l >= l && tr[u].r <= r) return pushadd(u, x);
    int mid = tr[u].l + tr[u].r >> 1;
    pushdown(u);
    if (l <= mid) modify(u << 1, l, r, x);
    if (r > mid) modify(u << 1 | 1, l, r, x);
    pushup(u);
}

int query(int u, int l, int r) {
    if (tr[u].l >= l && tr[u].r <= r) return tr[u].sum;
    int mid = tr[u].l + tr[u].r >> 1, res = 0;
    pushdown(u);
    if (l <= mid) res += query(u << 1, l, r);
    if (r > mid) res += query(u << 1 | 1, l, r);
    return res;
}
void solve(){
	cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> w[i];
    for (int i = 1; i <= n; i++) cin >> valid[i];
    build(1, 1, n);
    while (m--) {
        int op, l, r, x;
        cin >> op;
        if (op < 3) {
            cin >> x;
            valid[x] ^= 1;
            change(1, x);
        }
        if (op == 3) {
            cin >> l >> r >> x;
            modify(1, l, r, x);
        }
        if (op == 4) {
            cin >> l >> r;
            cout << query(1, l, r) << '\n';
        } 
    }
}

signed main(){
	std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
	int times = 1;
	//cin >> times;
	//cout << fixed << setprecision(10);
	while(times--){
		solve();
	}
	return 0;
}
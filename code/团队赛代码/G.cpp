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

int p[40][40], vis[30][30];
int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
 int cnt[3];
void clear(int del,int a,int b){
	if (p[a][b] != del || vis[a][b]) return;
        vt<PII> bg;
        queue<PII> q;
        q.push({a, b});
        bg.push_back({a, b});
        vis[a][b] = 1;
        bool nd = true;
        while (q.size()) {
            auto [x, y] = q.front(); q.pop();
            for (int k = 0; k < 4; k ++ ) {
                int x1 = x + dx[k], y1 = y + dy[k];
                if (p[x1][y1] == 0ll) {
                    nd = false;
                }else {
                    if (vis[x1][y1]) continue;
                    if (p[x1][y1] == del) {
                        vis[x1][y1] = true;
                        bg.push_back({x1, y1});
                        q.push({x1, y1});
                    }
                }
            }
        }           
        if (nd) {
            cnt[del] -= bg.size();
            for (auto [x, y] : bg) p[x][y] = 0;
        }
}
void solve() {
	int m; 
	cin >> m;
    for (int i = 0; i <= 20; i ++ ) p[i][0] = p[i][20] = p[0][i] = p[20][i] = 3;
    for (int i = 1; i <= m; i++){
        int x, y;
        cin >> x >> y;
        if (i & 1) cnt[1] += 1, p[x][y] = 1;
        else cnt[2] += 1, p[x][y] = 2;
        int w1 = cnt[1], w2 = cnt[2];
        memset(vis, 0, sizeof vis);
        for (int k = 0; k < 3; k ++ ) clear(((i & 1) ? 2 : 1), x + dx[k], y + dy[k]);
        clear(((i & 1) ? 1 : 2), x, y);
        cout << w1 - cnt[1] << ' ' << w2 - cnt[2] << endl;
    }
	return;
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
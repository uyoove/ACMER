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
int n;
void solve(){
    double ans = inf;
    cin >> n;
    vector<PII> s(n+1);
    for (int i = 0; i < n; i++)
        cin >> s[i].first >> s[i].second;
    if(n<=2){
        cout<<-1<<endl;
        return;
    }
    for(int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
            for (int z = j + 1; z < n; z++){
                    double t = abs((s[j].first * s[z].second - s[z].first * s[j].second) -
                                      (s[i].first * s[z].second- s[z].first * s[i].second) +
                                      (s[i].first * s[j].second - s[j].first * s[i].second) );
                    if(t!=0){
                        ans = min(ans, t / 2.0);
                    }
            }
        }
    }
    if (ans==inf) {
        cout << -1 << endl;
        return;
    }
 	cout << ans <<endl;

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
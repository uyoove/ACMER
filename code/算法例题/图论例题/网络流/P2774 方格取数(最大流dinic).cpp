//和爸爸一起学编程真好,不过要小学四年级分流考试了,最近没时间写代码了,呜呜呜
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define out(x) cout << #x << '=' << (x) << endl
#define out2(x, y) cout << #x << '=' << (x) << ',' << #y << '=' << (y) << endl 
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
const int N = 30005;
int h[N],idx = 1;
int n,m,s,t;
struct edges{
    int v,c,ne;
}e[100010];
void ad(int u,int v,int c){
    e[++idx] = {v,c,h[u]},h[u] = idx;
}
void add(int u,int v,int c){
    ad(u,v,c);
    ad(v,u,0);
}
int d[N],cur[N];
bool bfs(){
    memset(d,0,sizeof d);
    queue<int> q;
    d[s] = 1;
    q.push(s);
    cur[s] = h[s];
    while(q.size()){
        int u = q.front();q.pop();
        for(int i = h[u];i;i=e[i].ne){
            int v = e[i].v;
            if(e[i].c && !d[v]){
                d[v] = d[u] + 1;
                cur[v] = h[v];
                if(v==t) return true;
                q.push(v);
            }
        }
    }
    return false;
}
int dfs(int u,int mf){
    if(u==t) return mf;
    int su = 0;
    for(int i = cur[u];i;i=e[i].ne){
        int v = e[i].v;
        cur[u] = i;
        if(d[v] == d[u] + 1 && e[i].c){
            int f = dfs(v,min(mf,e[i].c));
            e[i].c -= f;
            e[i^1].c += f;
            su+=f;
            mf-=f;
            if(mf==0) break;
        }
    }
    if(su==0) d[u] = 0;
    return su;
}
int dinic(){
    int mf = 0;
    while(bfs()){
        mf+=dfs(s,2e9);
    }
    return mf;
}
int id(int r,int c){
    return (r-1)*m + c;
}
int mx[4] = {1,-1,0,0};
int my[4] = {0,0,1,-1};
int a[103][103];
void solve(){
    cin >> n >> m;
    s = 0;
    t = n*m+1;
    int su = 0;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            cin >> a[i][j];
            if((i+j)%2==0){
                for(int k = 0;k < 4;k++){
                    int nx = mx[k] + i,ny = my[k] + j;
                    if(nx <= 0 || ny <= 0 || nx > n || ny > m) continue;
                    add(id(i,j),id(nx,ny),2e9);
                }
                add(s,id(i,j),a[i][j]);
            }else{
                add(id(i,j),t,a[i][j]);
            }
            
            su+=a[i][j];
        }
    }
    cout << su - dinic() << endl;
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
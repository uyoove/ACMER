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
struct FhQ{
    int ls,rs,key,sz,val;
}fhq[N];
int root,T1,T2,T3,tot;
void push_up(int u){
    fhq[u].sz = fhq[fhq[u].ls].sz + fhq[fhq[u].rs].sz + 1;
}
void split(int u,int v,int &x,int &y){
    if(u==0){
        x = y = 0;
        return;
    }
    int tmp = fhq[fhq[u].ls].sz +1;
    if(v == tmp){
        x = u;
        y = fhq[u].rs;
        fhq[u].rs = 0;
    }else if(v < tmp){
        y = u;
        split(fhq[u].ls,v,x,fhq[u].ls);
    }else{
        x = u;
        split(fhq[u].rs,v - tmp,fhq[u].rs,y);
    }
    push_up(u);
}
int merge(int x,int y){
    if(!x||!y) return x+y;
    if(fhq[x].key > fhq[y].key){
        fhq[x].rs = merge(fhq[x].rs,y);
        push_up(x);
        return x;
    }else{
        fhq[y].ls = merge(x,fhq[y].ls);
        push_up(y);
        return y;
    }
}
int add(int v){
    fhq[++tot] = {0,0,rnd(),1,v};
    return tot;
}
int vis[N];
int idx = 1;
int n,m;
PII a[N];
void ptr(int u){
    if(!u) return;
    ptr(fhq[u].ls);
    if(fhq[u].val){
        cout << fhq[u].val << " ";
    }else{
        while(vis[idx] && idx <= n){
            idx++;
        }
        if(idx <= n){
            cout << idx << " ";
            vis[idx] = 1;
        }
    }
    ptr(fhq[u].rs);
}

void solve(){
    cin >> n >> m;
    for(int i = 1;i <= m;i++){
        cin >> a[i].fi >> a[i].se;
    }
    for(int i = 1;i <= n;i++){
        root = merge(root,add(0));
    }
    for(int i = m;i >= 1;i--){
        split(root,1,T1,T2),split(T2,a[i].se - 1,T2,T3); //为什么减-1 因为前面应该分出一个1,所以sz会小1,例如原来6的位置,在T2表示为5
        if(fhq[T1].val!=a[i].fi && (fhq[T1].val || vis[a[i].fi])){
            cout << -1 << endl;
            return;
        }
        fhq[T1].val = a[i].fi;
        vis[a[i].fi] = 1;
        root = merge(merge(T2,T1),T3);
    }
    ptr(root);
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
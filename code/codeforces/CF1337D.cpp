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

int a[N],b[N],c[N];
int check(int i,int j,int k)
{
    return (a[i]-b[j])*(a[i]-b[j])+(a[i]-c[k])*(a[i]-c[k])+(c[k]-b[j])*(c[k]-b[j]);
}
void solve(){
    int na,nb,nc;
    cin>>na>>nb>>nc;
    for(int i=1;i<=na;i++)
        cin>>a[i];
    for(int i=1;i<=nb;i++)
        cin>>b[i];
    for(int i=1;i<=nc;i++)
        cin>>c[i];
    sort(a+1,a+na+1);sort(b+1,b+nb+1);sort(c+1,c+nc+1);
    int res=2e18;
    for(int i=1;i<=na;i++)
    {
        int pb=lower_bound(b+1,b+nb+1,a[i])-b;
        int pc=lower_bound(c+1,c+nc+1,a[i])-c;
        if(pb==nb+1)
            pb--;
        if(pc==nc+1)
            pc--;
        res=min(res,check(i,pb,pc));
        if(pb!=1)
            res=min(res,check(i,pb-1,pc));
        if(pc!=1)
            res=min(res,check(i,pb,pc-1));
        if(pb!=1&&pc!=1)
            res=min(res,check(i,pb-1,pc-1));
    }
    for(int i=1;i<=nb;i++)
    {
        int pa=lower_bound(a+1,a+na+1,b[i])-a;
        int pc=lower_bound(c+1,c+nc+1,b[i])-c;
        if(pa==na+1)
            pa--;
        if(pc==nc+1)
            pc--;
        res=min(res,check(pa,i,pc));
        if(pa!=1)
            res=min(res,check(pa-1,i,pc));
        if(pc!=1)
            res=min(res,check(pa,i,pc-1));
        if(pa!=1&&pc!=1)
            res=min(res,check(pa-1,i,pc-1));
    }
    for(int i=1;i<=nc;i++)
    {
        int pb=lower_bound(b+1,b+nb+1,c[i])-b;
        int pa=lower_bound(a+1,a+na+1,c[i])-a;
        if(pb==nb+1)
            pb--;
        if(pa==na+1)
            pa--;
        res=min(res,check(pa,pb,i));
        if(pb!=1)
            res=min(res,check(pa,pb-1,i));
        if(pa!=1)
            res=min(res,check(pa-1,pb,i));
        if(pb!=1&&pa!=1)
            res=min(res,check(pa-1,pb-1,i));
    }
    cout<<res<<endl;
    
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
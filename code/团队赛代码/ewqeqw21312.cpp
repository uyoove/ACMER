#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define LL long long
#define PLL pair<LL,LL>
#define VLL vector<LL>
#define F LL
#define N 3010
int n,m,k,a[N][N],x,y,cnt,limit=1e8;
LL b[N][N],ans;
struct Node{
    int x,y,cnt;
    bool friend operator<(Node l,Node r){
        return l.cnt > r.cnt;
    }
};
priority_queue<Node> q;
int X[4]={0,0,-1,1},Y[4]={1,-1,0,0};
inline void write(__int128 x)
{
    if (x < 0) cout << '-', x = -x;
    if (x > 9) write(x/10);
    cout << char(x%10+'0');
}
__int128 aans,mod=1;
int main(){
    scanf("%d %d %d",&n,&m,&k);
    scanf("%d %d",&x,&y);
    a[x][y] = 0;
    q.push({x, y, 0});
    for(int i=1;i<k;i++){
        scanf("%d %d",&x,&y);
        a[x][y] = k-i;
        cout << x << " " << y << " " << a[x][y] << endl;
    }
    //cout << a[3][5] << endl;
    string s;
    char ch;
    for(int i=1;i<=n;i++) {
        cin >> s;
        for(int j=1;j<=m;j++){
            ch = s[j-1];
//            scanf("%c",&ch);
            if(ch=='#') a[i][j] = -1;
            b[i][j] = limit;
        }
    }
    while (!q.empty()){
        x = q.top().x;
        y = q.top().y;
        cnt = q.top().cnt;
        q.pop();
        b[x][y] = cnt++;
        for(int i=0;i<4;i++){
            int xx = x+X[i];
            int yy = y+Y[i];
            if(a[xx][yy]==-1) continue;
            int c = max(cnt,a[xx][yy]);
            if(c<b[xx][yy]){
                b[xx][yy] = c;
                q.push({xx,yy,c});
            }
        }
    }
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++){
//            cout << b[i][j] << " ";
            if(b[i][j]==limit) continue;
            aans += b[i][j]*b[i][j];
        }
//        ans=ans%mod;
//        cout << endl;
    }
    for(int i=1;i<=64;i++){
        mod = mod*2;
    }

    write(aans%mod);
//    printf("%lld",ans);
    return 0;
}

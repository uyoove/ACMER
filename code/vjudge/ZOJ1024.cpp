//和爸爸一起学编程真好,不过要小学四年级分流考试了,最近没时间写代码了,呜呜呜
#include<bits/stdc++.h>
using namespace std;
#define out(x) cout << #x << '=' << (x) << endl
#define out2(x, y) cout << #x << '=' << (x) << ',' << #y << '=' << (y) << endl 
//#define int long long
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
int mon[20]= {0,31,28,31,30,31,30,31,31,30,31,30,31};
int dp[220][20][40];
bool pan(int x){//判断闰年 
	x+=1900;
	if(x%4==0&&x%100!=0||x%400==0)
        return true;
    return false;
}
bool cz(int y,int m,int d){//判断当前日期是否在范围内 
	if(y>2001||y==2001&&m>11||y==2001&&m==11&&d>4)
        return false;
	if(pan(y)&&m==2&&d==29)return true;
	if(mon[m]<d)return false;
	return true;
}
int yy,mm,dd;
int dfs(int y,int m,int d){
	if(dp[y][m][d]!=-1)return dp[y][m][d];
	int flag=1;
	//日+1
	int y2=0;
	if(pan(y)&&m==2)y2=1;//判断闰2月 
	dd=d+1,mm=m,yy=y;
	if(dd>mon[m]+y2){
		dd-=mon[m]+y2;mm++;
	} 
	if(mm>12){
		mm-=12;yy++;
	}
	if(cz(yy,mm,dd)) flag&=dfs(yy,mm,dd);
	
	//月+1
	yy=y,mm=m+1,dd=d; 
	if(mm>12){
		mm-=12;yy++;
	}
	if(cz(yy,mm,dd))flag&=dfs(yy,mm,dd);
	
	return dp[y][m][d]=(!flag); 
	
}
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t,n;cin>>t;
	memset(dp,-1,sizeof(dp));
	dp[101][11][4]=1;
	while(t--){
		int y,m,d;cin>>y>>m>>d;
		if(dfs(y-1900,m,d)){
			cout<<"YES"<<endl;
		}else cout<<"NO"<<endl;
	}
	return 0;
}
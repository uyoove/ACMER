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
typedef unsigned long long ull;
typedef long long ll;
typedef pair<ull,ull> puu;
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

const ull mod1=19260817;
const ull mod2=19660813;
const ull base=233;

const int N=1e6+10;

ull pw1[N],pw2[N];
void initpw(){
    pw1[0]=pw2[0]=1;
    for(int i=1;i<=1e6;i++){
        pw1[i]=pw1[i-1]*base%mod1;
        pw2[i]=pw2[i-1]*base%mod2;
    }
}
puu gethash(char c){
    return {c*base%mod1,c*base%mod2};
}
void solve(){
	initpw();
    string ss;cin>>ss;
    int n=ss.size();
    string s="~";s+=ss;
    int flag=-1;
    for(int i=1;i<=n;i++){
        if(s[i]!=s[n-i+1]){flag=i;break;}
    }
    if(flag==-1){
        cout<<1<<" "<<1<<"\n";return ;
    }
    int m=n;
    string a="~";
    for(int i=flag;i<=n-flag+1;i++)a+=s[i];
    n=a.size()-1;
    puu hash1={0,0},hash2={0,0};
    for(int i=1;i<=n;i++){
        puu temp=gethash(a[i]);
        hash1.fi=(hash1.fi+temp.fi*pw1[i-1]%mod1)%mod1;
        hash1.se=(hash1.se+temp.se*pw2[i-1]%mod2)%mod2;
        hash2.fi=(hash2.fi+temp.fi*pw1[n-i]%mod1)%mod1;
        hash2.se=(hash2.se+temp.se*pw2[n-i]%mod2)%mod2;
    }
    puu hash3={0,0},hash4={0,0};
    for(int i=1;i<n;i++){
        puu temp=gethash(a[i]);
        hash3.fi=(hash3.fi+temp.fi*pw1[i-1]%mod1)%mod1;
        hash3.se=(hash3.se+temp.se*pw2[i-1]%mod2)%mod2;
        hash4.fi=(hash4.fi*base%mod1+temp.fi)%mod1;
        hash4.se=(hash4.se*base%mod2+temp.se)%mod2;
        puu k1={(hash1.fi+hash4.fi+mod1-hash3.fi)%mod1,(hash1.se+hash4.se+mod2-hash3.se)%mod2};
        puu k2={(hash2.fi+((hash3.fi+mod1-hash4.fi)%mod1)*pw1[n-i])%mod1,(hash2.se+((hash3.se+mod2-hash4.se)%mod2)*pw2[n-i])%mod2};
        if(k1==k2){
            cout<<flag<<" "<<flag+i-1<<"\n";return ;
        }
    }
    string b="~";
    for(int i=m-flag+1;i>=flag;i--)b+=s[i];
    n=b.size()-1;
    hash1={0,0},hash2={0,0};
    for(int i=1;i<=n;i++){
        puu temp=gethash(b[i]);
        hash1.fi=(hash1.fi+temp.fi*pw1[i-1]%mod1)%mod1;
        hash1.se=(hash1.se+temp.se*pw2[i-1]%mod2)%mod2;
        hash2.fi=(hash2.fi+temp.fi*pw1[n-i]%mod1)%mod1;
        hash2.se=(hash2.se+temp.se*pw2[n-i]%mod2)%mod2;
    }
    hash3={0,0},hash4={0,0};
    for(int i=1;i<n;i++){
        puu temp=gethash(b[i]);
        hash3.fi=(hash3.fi+temp.fi*pw1[i-1]%mod1)%mod1;
        hash3.se=(hash3.se+temp.se*pw2[i-1]%mod2)%mod2;
        hash4.fi=(hash4.fi*base%mod1+temp.fi)%mod1;
        hash4.se=(hash4.se*base%mod2+temp.se)%mod2;
        puu k1={(hash1.fi+hash4.fi+mod1-hash3.fi)%mod1,(hash1.se+hash4.se+mod2-hash3.se)%mod2};
        puu k2={(hash2.fi+((hash3.fi+mod1-hash4.fi)%mod1)*pw1[n-i])%mod1,(hash2.se+((hash3.se+mod2-hash4.se)%mod2)*pw2[n-i])%mod2};
        if(k1==k2){
            cout<<m-flag-i+2<<" "<<m-flag+1<<"\n";return ;
        }
    }
    cout<<-1<<" "<<-1<<"\n";
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
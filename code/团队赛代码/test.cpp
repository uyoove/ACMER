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
typedef long long LL;
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

typedef long long LL;
const int mod = 1e9+7;
struct MyLL
{
    LL x;
    MyLL():x(0){}
    MyLL(LL u):x(u){}
    LL qmi(LL a,LL b){
        LL res = 1;
        while(b){
            if(b & 1) res = res * a % mod;
            a = a * a % mod;
            b >>= 1;
        }
        return res;
    }
    MyLL& inv(){
        x = qmi(x,mod - 2);
        return *this;
    }
    MyLL pow(LL k){
        MyLL z;
        z.x = qmi(x,k) % mod;
        return z;
    }
    MyLL& operator+=(const MyLL& y){
        x = (x + y.x) % mod;
        return *this;
    }
    MyLL& operator-=(const MyLL& y){
        x = ((x - y.x) % mod + mod) % mod;
        return *this;
    }
    MyLL& operator*=(const MyLL& y){
        x = (x * y.x) % mod;
        return *this;
    }
    MyLL& operator/=(const MyLL& y){
        x = (x * qmi(y.x,mod - 2)) % mod;
        return *this;
    }
    bool operator<(const MyLL& y) const {
        return x < y.x;
    }
    bool operator==(const MyLL& y) const {
        return x == y.x;
    }
    bool operator>(const MyLL& y) const {
        return x > y.x;
    }
    bool operator!=(const MyLL& y) const {
        return x != y.x;
    }
    friend std::ostream& operator<<(std::ostream& os,const MyLL& y){
        os << y.x;
        return os;	
    }
    friend std::istream& operator>>(std::istream& is,MyLL& y){
        is >> y.x;
        return is;
    }
};
MyLL operator+(MyLL x,MyLL y){
    x += y;
    return x;
}
MyLL operator-(MyLL x,MyLL y){
    x -= y;
    return x;
}
MyLL operator*(MyLL x,MyLL y){
    x *= y;
    return x;
}
MyLL operator/(MyLL x,MyLL y){
    x /= y;
    return x;
}
MyLL p;
void solve(){
	cin >> p;
	cout << p << endl;

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
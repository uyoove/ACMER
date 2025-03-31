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
template <int row, int col>
struct Matrix
{
    int r, c;
    long long ele[row][col];
    Matrix() { throw "Please set row and column!"; }
    Matrix(int a, int b) : r(a), c(b) { memset(ele, 0, sizeof(ele)); }
    Matrix(int a) : r(a), c(a) {memset(ele, 0, sizeof(ele));for(int i = 0;i < a;i++)ele[i][i] = 1;}
    long long &operator()(int a, int b) { return ele[a][b]; }
    Matrix &operator+=(Matrix oth) { return *this = *this + oth; }
    Matrix &operator-=(Matrix oth) { return *this = *this - oth; }
    Matrix &operator*=(Matrix oth) { return *this = *this * oth; }
};
template <int m, int n>
Matrix<m, n> operator+(Matrix<m, n> m1, Matrix<m, n> m2)
{
    Matrix<m, n> ret;
    for (int i = 0; i < m1.r; i++)
        for (int j = 0; j < m1.c; j++)
            ret(i, j) = m1(i, j) + m2(i, j);
    return ret;
}
template <int m, int n>
Matrix<m, n> operator-(Matrix<m, n> m1, Matrix<m, n> m2)
{
    Matrix<m, n> ret;
    for (int i = 0; i < m1.r; i++)
        for (int j = 0; j < m1.c; j++)
            ret(i, j) = m1(i, j) + m2(i, j);
    return ret;
}
template <int m, int n, int p>
Matrix<m, p> operator*(Matrix<m, n> m1, Matrix<n, p> m2) //普通乘法
{
    Matrix<m, p> ret(m1.r, m2.c);
    for (int i = 0; i < m1.r; i++)
        for (int k = 0; k < m1.c; k++)
            for (int j = 0; j < m2.c; j++)
                ret(i, j) += m1(i, k) * m2(k, j);
    return ret;
}
template <int m, int n>
Matrix<m, n> operator^(Matrix<m, n> mat, long long k) //快速幂
{
    Matrix<m, n> ans = mat;
    for (k--; k; mat *= mat, k >>= 1)
        if (k & 1)
            ans *= mat;
    return ans;
}
template <int m, int n, int p>
Matrix<m, p> mulmod(Matrix<m, n>& m1, Matrix<n, p>& m2, int mod) //乘加取模
{
    Matrix<m, p> ret(m1.r, m2.c);
    for (int i = 0; i < m1.r; i++)
        for (int k = 0; k < m1.c; k++)
            for (int j = 0; j < m2.c; j++)
                ret(i, j) = (ret(i, j) + m1(i, k) * m2(k, j) % mod) % mod;
    return ret;
}
int qadd(int a,int b,int p)
{
    int res = 0;
    while(b)
    {
        if(b & 1) res = (res + a) % p;
        a = (a + a) % p;
        b >>= 1;
    }
    return res;
}
template <int m, int n, int p>
Matrix<m, p> slowmulmod(Matrix<m, n>& m1, Matrix<n, p>& m2, int mod) //龟速乘加取模,防止爆long long
{
    Matrix<m, p> ret(m1.r, m2.c);
    for (int i = 0; i < m1.r; i++)
        for (int k = 0; k < m1.c; k++)
            for (int j = 0; j < m2.c; j++)
                ret(i, j) = (ret(i, j) + qadd(m1(i, k),m2(k, j),mod) % mod) % mod;
    return ret;
}
template <int m, int n>
Matrix<m, n> qpowmod(Matrix<m, n>& mat, long long k, int mod) //快速幂取模
{
    Matrix<m, n> ans(mat.r);
    for (int p = k; p; mat = mulmod(mat, mat, mod), p >>= 1)
        if (p & 1)
            ans = mulmod(ans, mat, mod);
    return ans;
}
template <int m, int n>
ostream &operator<<(ostream &os, Matrix<m, n> &mat)
{
    for (int i = 0; i < mat.r; i++)
    {
        for (int j = 0; j < mat.c; j++)
            os << mat(i, j) << ' ';
        os << endl;
    }
    return os;
}
template <int m, int n>
istream &operator>>(istream &is, Matrix<m, n> &mat)
{
    for (int i = 0; i < mat.r; i++)
        for (int j = 0; j < mat.c; j++)
            is >> mat(i, j);
    return is;
}
int n;
int mod = 1e9 +7;
void solve(){
	Matrix<10,10> mat1(3,1);
	cin >> n;
	if(n <= 3){
		cout << 1 << endl;
		return;
	}
	int cf = n - 3;
	mat1(0,0) = 1;
	mat1(1,0) = 1;
	mat1(2,0) = 1;
	Matrix<10,10> mat2(3,3);
	mat2(0,0) = 1;
	mat2(0,2) = 1;
	mat2(1,0) = 1;
	mat2(2,1) = 1;
	auto p = qpowmod(mat2,cf,mod);
	auto res = mulmod(p,mat1,mod);
	cout << res(0,0) << endl;
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
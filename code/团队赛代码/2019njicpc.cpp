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
typedef pair<double, double> pdd;
#define x first
#define y second
int read()
{
   int x = 0, f = 1;
   char c = getchar();
   while(c < '0' || c > '9')
   {
      if (c == '-') f = -1, c = getchar();
   }
   while(c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
   return x * f;
}

pdd p;
double s;
double dis(pdd a, pdd b) {
   double xx = a.first - b.first, yy = a.second - b.second;
   return sqrt(xx * xx + yy * yy);
}
double line(pdd a, pdd b, pdd c)  
{
    pdd A = {c.x - a.x, c.y - a.y},
        B = {c.x - b.x, c.y - b.y};  

    if (A.x * B.y - B.x * A.y == 0) 
      { 
         double ff = dis(a, c) + dis(b, c) - dis(a, b);
         if (fabs(ff) < 1e-10)
            return true;  
      }

    return false;
}

double area(pdd a, pdd b, pdd c)  
{
   pdd A = {a.x - b.x, a.y - b.y}, B = {a.x - c.x, a.y - c.y};
   return fabs(A.x * B.y - A.y * B.x);
}

void f(pdd a, pdd b) {
    pdd l = a, r = b;
    pdd o = a;
    while (dis(l, r) > 1e-8) {   
      pdd mid = {(l.x + r.x) / 2, (l.y + r.y) / 2};
      double ss = area(o, mid, p);

      if (ss > s) r = mid;
      else if (ss < s) l = mid;
      else {
         l = mid;
         break;
      }
    }

    printf("%.15lf %.15lf\n", l.x, l.y);
}

void solve() {
    pdd point[4];
    for (int i = 0; i < 3; i++) {
        scanf("%lf %lf", &point[i].first, &point[i].second); 
    }
    scanf("%lf %lf", &p.first, &p.second);

    bool ok = 0;
    s = area(point[0], point[1], point[2]) / 2;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (j == i) continue;
            int k;
            if (line(point[i], point[j], p)) {   
                for (k = 0; k < 3; k++)
                    if (k != i && k != j) break;  

                ok = 1;
                double d = dis(point[i], p) - dis(point[j], p);
               if (dis(point[i], p) >= dis(point[j], p)) f(point[i], point[k]); 
               else f(point[j], point[k]);
               break;
            }
        }
        if (ok) break;
    }
    if (!ok) puts("-1");
}

signed main(){
	
	int times = 10;
	cin>>times;
	while(times--){
		solve();
	}
	return 0;
}
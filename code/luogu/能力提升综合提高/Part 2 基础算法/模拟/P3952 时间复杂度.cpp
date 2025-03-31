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
struct nodes{
	char op,my;
	string t1,t2;
	int f; //f=0是没有执行,
};
void solve(){
	int n;
	string s;
	cin >> n >> s;
	vt<nodes> v(n + 1);
	for(int i = 1;i <= n;i++){
		cin >> v[i].op;
		if(v[i].op=='E') continue;
		cin >> v[i].my >> v[i].t1 >> v[i].t2;
		if(v[i].t1==v[i].t2){
			v[i].f=0;
		}else if(v[i].t1=="n"){
			v[i].f = -1;
		}else if(v[i].t2=="n"){
			v[i].f = 2;
		}else if(v[i].t1.size() <v[i].t2.size()|| v[i].t1 < v[i].t2){
			v[i].f = 1;
		}else{
			v[i].f = -1;
		}
	}
	set<char> se;
	stack<int> st;
	int res = 0,cnt = 0;
	int f1 = 0;
	for(int i=1;i<=n;i++){
		if(v[i].op=='E'){
			if(!st.size()){
				cout << "ERR" << endl;
				return;
			}
			int tp = st.top();st.pop();
			char my = v[tp].my;
			se.erase(my);
			if(v[tp].f==2 && !f1){
				cnt--;
			}else if(v[tp].f==-1){
				f1--;
			}
		}else{
			st.push(i);
			if(se.count(v[i].my)){
				cout << "ERR" << endl;
				return;
			}
			se.insert(v[i].my);
			if(v[i].f==2 && !f1){
				cnt++;
				res=max(res,cnt);
			}else if(v[i].f==-1){
				f1++;
			}
		}
	}
	if(st.size()){
		cout << "ERR" << endl;
		return;
	}
	string ck;
	if(res==0){
		ck = "O(1)";
	}else{
		ck = "O(n^"+to_string(res)+")";
	}
	//cout << ck << endl;
	if(ck==s){
		cout << "Yes" << endl;
	}else{
		cout << "No" << endl;
	}
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
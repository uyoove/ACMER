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
int t[7];
map<char,int> mp;
int ch[7];
int n;
int res = 0;
int wn = 0;
//当前在哪里,当前值,特殊牌数量,卡牌数量
void dfs(int op){
	if(op==7){
		int d[6];
		for(int g = 1;g <= 5;g++) d[g] = ch[g];
		int tp = 0;
		for(int j = 1;j <= 4;j++) tp+=ch[j]/5,ch[j]%=5;
		sort(ch + 1,ch + 1 +4);
		for(int j = 4;j >= 1;j--){
			if(ch[j] + ch[5]>=5) ch[5] -= (5 - ch[j]),tp++;
		}
		for(int g = 1;g <= 5;g++) ch[g] = d[g];
		res = max(res,tp);
		return;
	}
	if(t[op]){
		if(op <= 4){
			int d[6];
			int v[3];
			int cnt = -1;
			for(int i =1;i <= 4;i++) if(i!=op) v[++cnt] = i;
			for(int i = 0;i <= 3;i++){
				if(i > ch[v[0]]) continue;
				for(int j = 0;j <= 3 - i;j++){
					if(j > ch[v[1]]) continue;
					for(int k = 0;k <= 3 - i - j;k++){
						if(k > ch[v[2]]) continue;
						for(int g = 1;g <= 4;g++) d[g] = ch[g];
							ch[v[0]]-=i;
							ch[v[1]]-=j;
							ch[v[2]]-=k;
							ch[op]+=i+j+k;
							dfs(op+1);
						for(int g = 1;g <= 4;g++) ch[g] = d[g];
					}
				}
			}
		}else if(op==5){
			for(int i = 1;i <= 4;i++){
				if(ch[i] > 0){
					ch[i]--;
					ch[5]++;
					dfs(op+1);
					ch[5]--;
					ch[i]++;
				}
			}
		}else{
			for(int i = 1; i <= 5;i++){
				for(int j = 1;j <= 4;j++){
					if(ch[i] && ch[j]){
						--ch[j],++ch[i];
						dfs(op+1);
						++ch[j],--ch[i];
					}
				}
			}
		}
	}
	dfs(op + 1);
}
void solve(){
	mp.clear();
	cin >> n;
	res = 0,wn = 0;
	ch[5] = 0;
	for(int i = 1;i <= n;i++){
		string s;
		cin >> s;
		mp[s[1]]++;
		
	}
	vt<int> v1;
	v1.pb(inf);
	for(int i = 1;i <= 6;i++){
		cin >> t[i];
		v1.pb(t[i]);
		ch[i] = 0;
	}
	int cnt = 0;
	for(auto &[k,v]:mp){
		cnt += v/5;
		v%=5;
		int op;
		if(k=='D'){
			op = 1;
		}else if(k == 'C'){
			op = 2;
		}else if(k == 'H'){
			op = 3;
		}else if(k == 'S'){
			op = 4;
		}
		ch[op] = v;
	}
	dfs(1);
	cout << cnt  + res <<endl;

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
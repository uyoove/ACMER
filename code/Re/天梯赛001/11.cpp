#include<bits/stdc++.h>
using namespace std;
#define vt vector
#define fi first
#define se second 
const int N = 3e6 + 10;
//struct edges{
//	int v,ne;
//}e[N << 1];
//int h[N],idx = 1;
//void add(int u,int v){
//	e[++idx] = {v,h[u]},h[u] = idx;
//} 
//int fk[N];
//void addfk(int k,int op){
//	for(int i = k;i < N ;i += (i&-i)) fk[i]+=op;
//}
//int queryfk(int k){
//	int res = 0;
//	for(int i = k;i > 0;i-= (i&-i)) res+=fk[i];
//	return res;
//}
int n;
struct ns{
	int st,ed;
};
int ts[N];
void solve(){
	cin >> n;
	vt<ns> v;
	for(int i = 1;i <= n;i++){
		int h,m,s;
		scanf("%d:%d:%d",&h,&m,&s);
		int eh,em,es;
		scanf("%d:%d:%d",&eh,&em,&es);
		v.push_back({h*60*60 + m*60 + s,eh*60*60 + em*60 + es});
	}
	int t = 70*70*70;
	for(auto p:v){
		ts[p.st]++,ts[p.ed + 1]--;
	}
	int cnt = 0;
	int mx = 0;
	for(int i = 0;i < N;i++){
		cnt+=ts[i];
		mx=max(mx,cnt);
	} 
	cout << mx << endl;
}
signed main(){
	solve();
}

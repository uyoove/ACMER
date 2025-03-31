#include <bits/stdc++.h>
using namespace std;
#define int long long
int read() {
	int x = 0, f = 1, ch = getchar();
	while(!isdigit(ch)) {if(ch == '-') f = -1; ch = getchar();}
	while(isdigit(ch)) x = (x << 1) + (x << 3) + ch - '0', ch = getchar();
	return x * f;
}
 
int n, m;
int num, T; 
struct node {
	char x;
	int cnt, tm;
}st[20];
 
struct TSK {
	int cnt, tm;
	int out_cnt, out_tm;
	bool in;
}tsk[20];
 
int tot = 0;
bool flag;
int ch[20];
void out() {
	puts("Yes");
	int now = 1;
	for(int i = 1; i <= m; i++) {
		if(st[i].x == '.') puts(".");
		else if(st[i].x == '-') printf("- %d\n", st[i].cnt);
		else if(st[i].x == '+') printf("+ %d/%d\n", st[i].cnt, st[i].tm);
		else {
			if(tsk[now].in) printf("+ %d/%d\n", tsk[now].out_cnt, tsk[now].out_tm);
			else printf("- %d\n", tsk[now].cnt);
			now++;
		}
	}
}
 
void dfs(int p, int lst) {
	if(flag) return;
	if(p > tot && lst <= num) return;
	if(lst > num) {//通过数凑到了
		int Tm = T - 240 * num;
		for(int i = 1; i <= num; i++) {
			tsk[ch[i]].out_tm = 240, Tm -= (tsk[ch[i]].cnt - tsk[ch[i]].tm) * 20;
			tsk[ch[i]].out_cnt = tsk[ch[i]].cnt - tsk[ch[i]].tm + 1;
			if(tsk[ch[i]].out_cnt > tsk[ch[i]].cnt) return;
		}
		if(Tm < 0) return;
 
		for(int i = 1; i <= num && Tm > 20; i++) {
			register int cnt1 = tsk[ch[i]].cnt, cnt2 = tsk[ch[i]].out_cnt;
			if(Tm > (tsk[ch[i]].tm - 1) * 20) Tm -= (tsk[ch[i]].tm - 1) * 20, tsk[ch[i]].out_cnt = tsk[ch[i]].cnt;
			else {
				int tmp = Tm / 20;
				Tm -= tmp * 20;
				tsk[ch[i]].out_cnt += tmp;
			}
		}
		for(int i = 1; i <= num && Tm > 0; i++) {
			if(Tm > 59) Tm -= 59, tsk[ch[i]].out_tm = 299;
			else if(Tm > 0) tsk[ch[i]].out_tm += Tm, Tm = 0;
		}
		
		if(!Tm) {flag = true; out();}
		return;
	}
	dfs(p + 1, lst);
	if(flag) return;
	tsk[p].in = true; ch[lst] = p; dfs(p + 1, lst + 1); tsk[p].in = false;
}
 
signed main() {
//	freopen("out.txt", "w", stdout);
	n = read(), m = read();
	while(n--) {
		num = read(), T = read();
		tot = 0; int sum = 0;
		flag = false;
		for(int i = 1; i <= m; i++) {
			cin >> st[i].x;
			if(st[i].x == '.') continue;
			else if(st[i].x == '-') st[i].cnt = read();
			else if(st[i].x == '+') {
				int t1 = read(), t2 = read();
				st[i].cnt = t1, st[i].tm = t2;
				T -= (t2 + t1 * 20 - 20);
				num--;
			} else {
				st[i].tm = tsk[++tot].tm = read(),
				st[i].cnt = tsk[tot].cnt = read();
				tsk[tot].in = false;
				sum += st[i].cnt - 1;
			}
		}
		
		if(num < 0 || T < 0 || tot < num || num * 240 > T || num * 299 + sum * 20 < T) 
			{puts("No"); continue;}
			
		dfs(1, 1);
		if(!flag) puts("No");
	}
	return 0;
}

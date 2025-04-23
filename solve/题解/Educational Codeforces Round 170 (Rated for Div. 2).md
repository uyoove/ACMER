# Educational Codeforces Round 170 (Rated for Div. 2) 题解D

## D. Attribute Checks

### **链接:[Problem - D - Codeforces](https://codeforces.com/contest/2025/problem/D)**

### 思路:

- **由于$m$ 还有$abs(r[i])$很小,考虑dp**
- **因为每个0能对后面多少个check做出贡献是固定的,所以预处理**
- **因为我们每次的0的个数是单调不减的 所以,我们上一次选择的最佳情况可以推广到后面**
- **通俗点讲如果你这次0对一个比较前面的check做出了贡献,那么check后面的0就不会影响前面的check,后面的0只依赖于前面的选择,不对前面选择有影响(这大体是dp的无后效性吧)  ~~做了前面的选择就不回头啦,后面影响不到我nb~~**
- **然后很简单了,定义$dp[i][j]$为在第i个有0的时候 我选$j$的智力能获取的最大收益**
### 代码:

```c++
const int N = 2000005;
int n,m;
int a[N];
//因为我们每次的0的个数是单调不减的 所以,我们上一次选择的最佳情况可以推广到后面
//为什么呢,考虑越前面的0越有用(自行体会证明)
//那么前面保证最优现在的选择是不会影响前面已经被选的数,(无后效性)
//转移思考如下:
//我可以智力此次比上次多1 dp[i][j] = max(dp[i][j],dp[i][j - 1] + cnt[i][j] + cnt[i - j]);  上一次 dp[i-1][j - 1]: 智力j - 1,力量 i - 1 - (j - 1) = i - j 这次cnt[j]就是加了一次智力,力量不变
//我可以力量比上次多1 dp[i][j] = max(dp[i][j],dp[i][j] + cnt[i][j] + cnt[i - j]); 上一次 i-j比i-1-j大1 dp[i-1][j] : 智力j,力量i-1-j; 这次cnt[j]就是智力不变,力量增加

void solve(){
	cin >> n >> m;
	vector<vector<int>> cnt1(m + 2,vector<int> (m+2)); //当前i个0选j个0可对后面多少check产生智力贡献
	vector<vector<int>> cnt2(m + 2,vector<int> (m+2)); //当前i个0选j个0可对后面多少check产生力量贡献
	for(int i = 1;i<=n;i++) cin >> a[i];
	int len = 0;
	for(int i = 1;i <= n;i++){
		if(!a[i]) ++len;
		if(a[i] > 0 && a[i] <= len){
			cnt1[len][a[i]]++;
		}else if(a[i] < 0 && abs(a[i]) <= len){
			cnt2[len][abs(a[i])]++;
		}
	}
	//做个前缀和 表示第i次 j个0最多能选多少个check
	for(int i = 1;i <= len;i++){
		for(int j = 1;j <= i;j++){
			cnt1[i][j] += cnt1[i][j - 1]; 
			cnt2[i][j] += cnt2[i][j - 1];
		}
	}
	int mx = 0;
	vector<vector<int>> dp(m + 2,vector<int> (m + 2)); // 代表我第i个0选择增加j个智力,i-j个力量获取的最大收益
	
	for(int i = 1;i <= len;i++){
		for(int j = 0;j <= i;j++){
			dp[i][j] = max(dp[i][j],dp[i - 1][j] + cnt1[i][j] + cnt2[i][i-j]);
			if(j > 0){
				dp[i][j] = max(dp[i][j],dp[i - 1][j - 1] + cnt1[i][j] + cnt2[i][i-j]);
			}
			mx = max(mx,dp[i][j]);
		}
	}
	cout << mx;
}
```


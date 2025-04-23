# 补难题记录

## 二分:

#### abc389E

https://atcoder.jp/contests/abc389/tasks/abc389_e (考虑选取的优先级,为每个p[i]取小于x的价值的商品,最后理解一下取完再把剩下的钱买ans + 1的商品,ans+1这个商品必然存在,不存在我ans为什么不是ans+1呢,这是关键点)

### 01规划问题

#### abc324F

https://atcoder.jp/contests/abc324/tasks/abc324_f (发现符合01规划性质,01规划详情见算法模版,然后因为无环,每个编号小的节点连编号大的点,可以算出到单个点的最大权值,最后算出到n点的权值是否大于等于0,二分时候重建边为bi - ci*mid)

## 思维:

#### abc312G

https://atcoder.jp/contests/abc312/tasks/abc312_g (找树形非直线的三元组)

#### abc313D

https://atcoder.jp/contests/abc313/tasks/abc313_d (将题目奇偶性转换成异或,利用异或性质解决)

#### **abc326F**

https://atcoder.jp/contests/abc326/tasks/abc326_f (考虑数据量,40的数据量分成两半一半用mp存贡献,另一半查找)

## 数据结构:

### 01trie

#### abc308G

https://atcoder.jp/contests/abc308/tasks/abc308_g    (支持修改,删除,增加,自底向上每次增删维护答案的01trie)

### 单调栈

#### abc311G

https://atcoder.jp/contests/abc311/tasks/abc311_g (思维压行,单调栈找第一个i左边比i小的数)

### 线段树:

#### MATI提高8E

https://www.matiji.net/exam/brushquestion/9/4597/2E846583B90951CA9E8BBBB03CA5ABC2 维护8个态(2x2x2)每个下标正负双态的最大最小值

### 对顶堆:

#### MATI提高8C

https://www.matiji.net/exam/brushquestion/7/4597/2E846583B90951CA9E8BBBB03CA5ABC2 (因为,a数组递增所以答案转换为a[n] - a[1] - 分割线(a[i+1] - a[i])贡献,维护前k个最大分割线贡献,10个对顶堆维护);

## DP

### 状压DP

#### abc310F

https://atcoder.jp/contests/abc310/tasks/abc310_f (概率状压)

#### abc310D

https://atcoder.jp/contests/abc310/tasks/abc310_d (状压,lowbit判断去重)



### 思维DP

#### **abc311F**

https://atcoder.jp/contests/abc311/tasks/abc311_g (思维dp,前缀和优化DP)

#### **abc320F**

https://atcoder.jp/contests/ABC320/tasks/abc320_f (双向转移,考虑抛弃一些量取获取最优)

## 数学

### 容斥

#### CF1900D

https://codeforces.com/problemset/problem/1900/D (容斥+思维)

推荐题解:https://io.zouht.com/170.html


# Atcoder ABC297 E-G

## **E - Kth Takoyaki Set**

### **链接:** 

[**E - Kth Takoyaki Set** ](https://atcoder.jp/contests/abc296/tasks/abc296_f)

### **简要题意:**

#### 问题陈述

有 $N$ 种章鱼烧出售。一个 $i$ \-种的章鱼烧售价为 $A_i$ 日元。

高桥总共至少会买一个章鱼烧。他可以购买多个同类章鱼烧。

求高桥可能支付的 $K$ 个最低价格。在这里，如果有多套章鱼烧的价格相同，那么价格只计算一次。

### **思路:**

- 我们发现求topk问题,那么想到了二分或者说堆,我们发现二分不好求解
- 想想小根堆,我们发现我们每次取出最小的数,然后暴力枚举数组,让数组与最小值相加,再丢入堆中,弹出k个即可,最后返回堆顶
- 然后记得map去重

### 代码:

```c++
const int N = 200005;
int tr1[N],tr2[N];
int n;
int lb(int x){return x&-x;}
void add(int k,int tr[]){
    for(int i = k;i < N;i+=lb(i)) tr[i]++;
}
int qy(int k,int tr[]){
    int res = 0;
    for(int i = k;i > 0;i-=lb(i)) res+=tr[i];
    return res;
}
void solve(){
    
    cin >> n;
    map<int,int> h1;
    map<int,int> h2;
    int a[n + 1],b[n+1];
    int c1 = 0,c2 = 0;
    for(int i = 1;i<=n;i++){
        cin >> a[i];
        c1+=qy(a[i],tr1);
        add(a[i],tr1);
        h1[a[i]]++;
        
    }
    for(int i = 1;i<=n;i++){
        cin >> b[i];
        c2+=qy(b[i],tr2);
        add(b[i],tr2);
        h2[b[i]]++;
        
    }
    if(h1!=h2){
        cout << "No" << endl;
        return ;
    }
    for(int i = 1;i<=n;i++){
        if(h2[b[i]]>=2||h1[a[i]]>=2){
            cout << "Yes" << endl;
            return;
        }
    }
    if(c1%2!=c2%2){
        cout << "No" << endl;
    }else{
        cout << "Yes" << endl;
    }
 
}
```

## **F - Minimum Bounding Box 2** 

组合数学+容斥  待补

## **G - Constrained Nim 2**

sg函数 待补
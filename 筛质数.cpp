//在实际应用中 一般用线性筛法来筛选质数，因为更快 但是埃氏筛法的思想很重要  可以用这种思想来解决其他问题
#include <iostream>
#include <algorithm>
using namespace std;
const int N=1000010;
int primes[N],cnt;//primes[]用于存储筛选出来的质数 cnt用于存储质数的个数，同时作为下标
bool st[N];//表示数的状态

//调和级数  ln n + c   0.577
//时间复杂度 为nlogn  这是朴素筛法的时间复杂度
//1到n中有  n/ln n 个质数  质数定理  
//经过优化之后的时间复杂度是 o(n log log n) 基本上和o(n)一个级别
//埃拉托斯特尼筛法 简称埃氏筛法  还有一个线性筛法
void get_primes1(int n)
{
    for(int i=2;i<=n;i++)
    {
        if(!st[i])//如果说当前这个数没有被筛过 说明他是一个质数
        {
            primes[cnt++]=i;//将这个数标记为质数
            for(int j=i+i;j<=n;j+=i)
            {
                st[j]=true;//其实这里并不需要把所有数的倍数都删掉 只需要删掉所有质数的倍数就好了 把循环放到判断里面来
            }
        }
    }  
}

//当数据范围 大于10000000时  线性筛法效率更高
//线性筛法 n只会被他的最小质因子筛掉（线性筛法的核心）
//j是从小到大枚举的所有质数  每一次把当前的质数和i的乘积筛掉 
//当i%primes[j]==0  那么    primes[j]一定是i 的最小质因子  因为primes[j]是从小到大枚举的所有质因子  
//第一次出现i%primes[j]==0的时候 primes[j]一定是i的最小质因子

//分两种情况，1i%primes[j]==0  primes[j]一定是i的最小质因子  primes[j]也一定是 i*primes[j]的最小质因子
//2 i&primes[j]!=0   由于是从小到大枚举的所有质数 并且我们没有枚举到i的任何一个质因子 所以说明
//primes[j]一定小于i的所有质因子  所有primes[j]也一定是primes[j]*i 的最小质因子
//此外 任何一个合数一定会被筛掉  对于一个合数x  一定存在一个最小质因子 假设 primes[j]是x的最小质因子
//当i枚举到x/primes[j]的时候  由于 i是个合数  所以最小质因子primes[j]一定是存在的  i在枚举到x之前
//一定会枚举到 x/primes[j]
//线性筛法在调试过程中会出现 arithmetic exception  需要理解为什么在运行的时候不会出错
void get_primes2(int n)
{
    //以下为线性筛法  
    for(int i=2;i<=n;i++)
    {
        if(!st[i])//如果说当前这个数没有被筛过 说明他是一个质数
        {
            primes[cnt++]=i;
        }
        for(int j=0;primes[j]<=n/i;j++)
        {
             st[primes[j]*i]=true;
            if(i%primes[j]==0) break;
        }
    } 
}

int main()
{
    int n;
    cin>>n;
    get_primes1(n);
    cout<<cnt<<endl;
    return 0;
}
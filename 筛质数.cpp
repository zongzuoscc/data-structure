
#include <iostream>
#include <algorithm>
using namespace std;
const int N=100010;
int primes[N],cnt;
bool st[N];

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
            primes[cnt++]=i;
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
//当i%primes[j]==0  那么    primes[j]一定是i 的最小质因子
void get_primes2(int n)
{
    //以下为线性筛法  
    for(int i=2;i<=n;i++)
    {
        if(!st[i])//如果说当前这个数没有被筛过 说明他是一个质数
        {
            primes[cnt++]=n;
            for(int j=0;primes[j]<=n/i;j++)
            {
                st[primes[j]*i]=true;
                if(i%primes[j]==0) break;
            }
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
//约数个数
//是基于算数基本定理的  一个数N分解完质因数之后  如果等于下式
//N=p1^a1+p2^a2+……+pk^ak
//那么 约数个数就是(a1+1)(a2+1)*……(ak+1)
//因为n的任何一个约数 d=p1^b1+p2^b2+……+pk^bk  任何一个约数都可以写成这样的形式 
//每一个b都在0到a之间
//每一项的指数只要不同 那么约数就不同
//所以说n的约数的个数 就和b1到bk 的取法个数是一样的  n的每一个约数都对应了一个 b1到bk的取法  
//每两个不同的取法都对应n的两个不同的约数
//那么b1有0到a1种选法  其他的也都是一样的选法个数  
//1到n中 约数和倍数的个数是相同的      从1到n  1的倍数是n个  2的倍数是n/2  以此类推  n的倍数为n/n 
//1到n当中总共的约数个数就是nlogn   int范围内 约数个数最多的数 大概是1600左右

//以下为约数之和
//因式分解之后的结果依然是N=p1^a1+p2^a2+……+pk^ak
//(p1^0+p1^1+……+p1^a1)*……*(pk^0+pk^1+……+pk^ak)  直接用乘法分配律展开
//每一个括号里面选一项出来


//给定 n个正整数 ai，请你输出这些数的乘积的约数个数，答案对 10^9+7取模。
//基本思路是先求a1到an的质因数分解的结果  分解方法就是 分别把a1 a2 全部分解  然后把每一个数的指数累加在一起就好了
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

const int mod=1e9+7;

int main()
{
    int n;
    cin>>n;
    unordered_map<int,int> primes;//一个哈希表用于存储所有的指数和底数
    while(n--)
    {
        int x;
        cin>>x;

        //把x分解
        for(int i=2;i<=x/i;i++)
        {
            while(x%i==0)
            {
                x/=i;
                primes[i]++;//i的质因数的指数+1  这样操作完成之后primes里面就存储卡所有质因数的指数
            }
        }
        if(x>1) primes[x]++;
    }
    long long res=1;
    for(auto prime:primes) res=res*(prime.second+1)%mod;//枚举所有的
    cout<<res<<endl;
    return 0;
}
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
    for(auto prime:primes) 
    {
        int p=prime.first;//p来表示底数
        int a=prime.second;//a来表示指数  需要先求出来p的0次方加到p的a次方
        long long t=1;
        while(a--)
        {
            t=(t*p+1)%mod;
        }
        res=res*t%mod;
    }
    cout<<res<<endl;
    return 0;
}
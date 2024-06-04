//求1到n中每个数的欧拉函数 用之前的公式法分解质因数 非常慢  时间复杂度是n*sqrt(n)
//借助线性筛法求素数的代码  可以用 o(n)的时间复杂度  来计算出每一个数的欧拉函数
//先回忆线性筛法 
#include <iostream>
#include <algorithm>
using namespace std;
const int N=100010;
int primes[N];//存储的是每一个质数
int cnt;//质数的下标
bool st[N];//表示某一个数是否已经被筛掉了 
int phi[N];//欧拉函数 
long long get_eulers(int n)
{
    //先把线性筛法过一遍
    for(int i=2;i<=n;i++)
    {
        if(!st[i])//如果说当前这个数没有被筛过 说明 i 是质数
        {
            primes[cnt++]=i;
            phi[i]=i-1;
        }
        for(int j=0;primes[j]<=n/i;j++)//从小到大枚举所有质数
        {
            st[primes[j]*i]=true;
            if(i%primes[j]==0)  //这是一个优化
            {
                
            }
        }
    }
}
int main()
{
    int n;
    cin>>n;
    cout<<get_eulers(n)<<endl;
    return 0;
}
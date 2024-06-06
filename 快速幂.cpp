//快速幂可以快速地求出  a^k mod b 的结果  时间复杂度是o(log k)
//核心思路 反复平方法
//预处理出来
// 给定 n组 ai,bi,pi，对于每组数据，求出 ai^bi mod pi的值。
#include <iostream>
#include <algorithm>
using namespace std;

//a^k%p
int qmi(int a,int k,int p)
{
    int res=1;//a^k mod p
    while(k)
    {
        if(k&1)//如果当前k的末尾是1
        {
            res=(long long)res*a%p;
        }
        //a是不断反复平方的
        k>>=1;//把k的末位删掉，因为已经处理完了  右移一位，相当于将 k 除以 2 并去掉余数部分。
        a=(long long)a*a%p;//更新a为它的平方，并取模 p。这个步骤的作用是将 a 不断平方，以便处理更高位的 k。
    }
    return res;
}

int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        int a;//底数 即需要计算的底数
        int k;//质数 即幂的指数
        int p;//模数 用于取模运算
        cin>>a>>k>>p;

        cout<<qmi(a,k,p)<<endl;
    }
    return 0;
}
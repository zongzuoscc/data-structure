//ɸ(n)1到n中与n互质的数的个数 互质就是指这两个数除了1以外没有其他公约数
//假设N=p1^a1+p2^a2+……+pk^ak
//ɸ(n)=N*(1-1/p1)(1-1/p2)……(1-1/pn)
//用容斥原理可以证明上面的式子
//1 从1 到 n中去掉p1,p2……pk的所有数的倍数
//那么就是N-N//p1-N//p2……-N//pk
//但是你知道的 有的数可能既是p1的倍数又是p2的倍数
//2 加上所有pi*pj的倍数
//再加上n//p1*p2  + n//p1p3  +  ……
//3 再减去所有pi*pj*pk的倍数
//4 以此类推
//最后你会发现上面的式子展开就是下面的式子

//给定n个正整数ai  求出每个正整数的欧拉函数

//这是欧拉函数用定义的求法
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    cin>>n;

    while(n--)
    {
        int a;
        cin>>a;
        int res=a;
        //以下为分解质因数
        for(int i=2;i<=a/i;i++)
        {
            if(a%i==0)
            {
                res=res/i*(i-1);//res*(1-1/a);前面的语句为这一句的化简
                while(a%i==0)
                {
                    a/=i;
                }
            }
        }
        if(a>1)//说明a有一个大于1 的质因子  再把质因子除去就好了
        {
            res=res/a*(a-1);
        }
        cout<<res<<endl;
    }
    return 0;
    
}
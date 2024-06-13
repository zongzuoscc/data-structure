//给定一堆两两互质的数
//要解决一个线性同余方程组
//x==a1(mod m1)


//x==ak(mod mk)
//首先 我们用 M=m1*m2*.....*mk表示所有m的乘积
//然后Mi=M/mi  就是M除了mi之外其他所有m的乘积
//由于所有的m之间之两两互质的 所以说Mi就和m互质
//所以就可以求出M mod m的逆
//x=a1*M1*M1^-1 +a2*M2*M2^-1……  求逆可以用扩展欧几里得算法  这行公式就是中国剩余定理

//x=k1*a1+m1
//x=k2*a2+m2
//k1*a1+m1=k2*a2+m2  k1 ，k2未知
//k1*a1-k2*a2=m2-m1
//不一定有解 有解就等价于(a1,a2)|m2-m1  整除
//  x=k1+k*(a2/d)
//  x=k2+k*(a1/d)  k是任意整数 

//x=(k1+k*(a2/d))*a1+m1  这就是x的所有解
//x=a1*k1+m1+k[a1,a2]   a1,a2的最小公倍数
//前面这项是固定的 记为x0   后面的这项可以记为新的a
//记作x=x0+k*a

//那么上面的n个方程组就可以合并成一个  x=k*a+x0

#include <iostream>
#include <algorithm>
using namespace std;

long long exgcd(long long a,long long b,long long &x,long long &y)
{
    if(!b)
    {
        x=1,y=0;
        return a;
    }

    long long d=exgcd(b,a%b,y,x);
    y-=a/b*x;
    return d;
}

int main()
{
    int n;
    cin>>n;

    //思路 每次把一个新的方程合并到现有的方程当中
    bool has_answer=true; //用于存储当前是否已经无解了；

    long long a1,m1;
    cin>>a1>>m1;
    for(int i=0;i<n-1;i++)
    {
        long long a2,m2;
        cin>>a2>>m2;
        //然后开始合并      合并的时候首先用扩展欧几里得算法求出来
        long long k1,k2;
        long long d=exgcd(a1,a2,k1,k2);
        if((m2-m1)%d)
        {
            has_answer=false;
            break;
        }
        k1*=(m2-m1)/d;
        long long t=a2/d;
        k1=(k1%t+t)%t;//这样就变成了最小的正整数解
        m1=a1*k1+m1;
        a1=abs(a1/d*a2);
    }
    if(has_answer)
    {
        cout<<(m1%a1+a1)%a1<<endl;//正的余数
    }
    else
    {
        cout<<"-1"<<endl;
    }
    return 0;
}
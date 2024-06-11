//之前讲过欧几里得算法 就是辗转相除法
//给定 n对正整数 ai,bi，对于每对数，求出一组 xi,yi，使其满足 ai*xi+bi*yi=gcd(ai,bi)。
//裴蜀定理
//  对于任意的 一对正整数a,b 那么存在非零整数x,y  使得ax+by=(a,b) （即a和b的最大公约数）
//而且这个最大公约数 是a和b能凑出来最小的正整数
//那么这是为什么呢 
//      假设存在ax+by=d  那么d一定是a,b最大公约数的倍数

//这个求出来的解只是其中之一  以下为通解公式 即只要求出来一个 就可以把剩下的全部求出来
//x=x0-(b/d)  *k k是整数
//y=y0+(b/d)  *k

#include <iostream>
using namespace std;

int exgcd(int a,int b,int &x,int &y)
{
    //return b?gcd(b,a%b):a; 这是简写 ，我们在这里要把它详细展开
    if(!b)
    {
        x=1,y=0;//当b等于0时
        return a;
    }
    //当我们的递归结束的时候，就已经会得到一个y和x使得  by+(a%b)*x=(a,b)
    //整理之后a mod b = a-(a/b)(向下取整)*b
    //再整理得ax + b(y-(a/b)(向下取整)*x)==d
    int d = exgcd(b,a%b,y,x);//x和y反转的原因是因为前面也翻转了  这样更有利于计算
    //x不用变
    y-=a/b*x;
    return d;
}

int main()
{
    int  n;
    cin>>n;
    while(n--)
    {
        int a,b,m;
        cin>>a>>b>>m;
        int x,y;
        int d=exgcd(a,m,x,y);
        if(b%d) cout<<"impossible"<<endl;
        else cout<<((long long)x*(b/d))%m<<endl;
    }
    return 0;
}
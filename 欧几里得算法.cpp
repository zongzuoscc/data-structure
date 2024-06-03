//也叫辗转相除法   时间复杂度为o(logn)
//如果d 能整除a且d能整除b
//那么d能整除a+b  也能整除 ax+by  就是a的几倍+b的几倍
//a和b的最大公约数就可以等于 b和a mod b的最大公约数   模完之后是余数
//a mod b==a- (a//b)*b   a整除b  
#include <iostream>
#include <algorithm>
using namespace std;
int gcd(int a,int b)//用于返回a和b的最大公约数
{
    return b?gcd(b,a%b):a;
}
int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        int a,b;
        cin>>a>>b;
        cout<<gcd(a,b)<<endl;
    }
    return 0;
}
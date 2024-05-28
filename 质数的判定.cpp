//试除法 时间复杂度 O(sqrtn )
#include <iostream>
#include <algorithm>
using namespace std;
//这是最暴力的写法 时间复杂度是O(n)  可以做优化  优化之后 只需要枚举到根号n即可  不推荐写成< sqrt(n) 因为每次都会
//求根号n  sqrt这个函数比较慢  也不推荐写成 i*i<=n  因为当i接近于int的上限的时候 两个相乘会溢出
bool is_prime(int n)
{
    if(n<2)  return false;
    for(int i=2;i<=n/i;i++)
    {
        if(n%i==0)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        int a;
        cin>>a;
        if(is_prime(a))
        {
            cout<<"Yes"<<endl;
        }
        else
        {
            cout<<"No"<<endl;
        }
    }
    return 0;
}
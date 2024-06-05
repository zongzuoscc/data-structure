//快速幂可以快速地求出  a^k mod b 的结果  时间复杂度是o(log k)
//核心思路 反复平方法
//预处理出来

#include <iostream>
#include <algorithm>
using namespace std;

//a^k%p
int qmi(int a,int k,int p)
{
    int res=1;
    while(k)
    {
        if(k&1)//如果当前k的末尾是1
        {
            res=(long long)res*a%p;
        }
        
    }
}

int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        int a,k,p;
        cin>>a>>k>>p;

        cout<<qmi(a,k,p)<<endl;
    }
    return 0;
}
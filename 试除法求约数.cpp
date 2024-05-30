//试除法求所有数的约数
//基本思路 从小到大判断 如果当前数能整除这个数  那么当前数就是这个数的约数  
//一个数 如果d是n的约数  也就是说d%n==0  那么n/d%n==0  所以说一个数的约数也一定是成对出现的 
//在枚举的时候也可以只枚举较小的约数就可以了
//时间复杂度是n*sqrt(a)
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> get_divisors(int n)
{
    vector<int> res;//定义一个存储答案的数
    for(int i=1;i<=n/i;i++)
    {
        if(n%i==0)//如果说i是n的一个约数
        {
            res.push_back(i);
            if(i!=n/i)  res.push_back(n/i);

        }
    }
    sort(res.begin(),res.end());
    return res;
}
int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        int x;
        cin>>x;
        auto res=get_divisors(x);
        for(auto t:res) cout<<t<<" ";
        cout<<endl;
    }
    return 0;
}
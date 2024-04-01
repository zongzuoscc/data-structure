//给定一个序列，求序列中每一个数左边距离他最近的数，在什么地方
//单调栈用的不多，这是常见的一种题型
//做法和双指针有异曲同工之妙，都是先想出暴力做法，然后再寻找其中的性质进行优化

//整个算法的时间复杂度为o(n)
#include <iostream>
using namespace std;
const int N=100010;
int n;
int stk[N],tt;

//每个元素最多进栈一次 出栈一次
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        while(tt&&stk[tt]>=x)
        {
            tt--;
        }
        if(tt)
        {
            cout<<stk[tt]<<" ";
        }
        else
        {
            cout<<"-1"<<" ";
        }
        stk[++tt]=x;
    }
    return 0;
}
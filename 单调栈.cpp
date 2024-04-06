//给定一个序列，求序列中每一个数左边距离他最近的数，在什么地方
//单调栈用的不多，这是常见的一种题型
//做法和双指针有异曲同工之妙，都是先想出暴力做法，然后再寻找其中的性质进行优化

/*
这里是暴力做法
for(int i=0;i<n;i++)
{
    for(int j=i-1;j>=0;j--)
    {
        if(a[j]>a[i])
        {
            cout<<a[j]<<" ";
            break;
        }
    }
}

暴力做法中的一些性质
在i++的过程中，我们可以用栈来存储i左边的数
如果a[3]>=a[5],那么a[3]永远不会被输出出来，因为a[5]在a[3]的右边，而且a[5]比a[3]小所以
x<y并且a[x]>=a[y]，那么a[x]可以被删掉，只要有逆序的关系，前面的就会被删掉，
所以最后剩下的序列一定是一个单调序列

*/
//整个算法的时间复杂度为o(n)
#include <iostream>
using namespace std;
const int N=100010;
int n;
int stk[N],tt;

//每个元素最多进栈一次 出栈一次
int main()
{
    ios::sync_with_stdio(false);//可以加快数据读入的速度
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

    //虽然有两重循环，但是每个元素最多只会进栈一次，出栈一次，加到一块也只有2n次操作，
    //该算法的时间复杂度为o(n)
}
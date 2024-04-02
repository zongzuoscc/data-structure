//最经典的应用是求滑动窗口里的最大值
//和单调栈做法类似，也是先想出暴力做法，然后再挖掘其中的性质，最后改进算法
//完全没有理解单调队列，需要再看一遍视频

#include <iostream>
using namespace std;
const int N= 1000010;
int n,k;
int a[N];//存储的是原来的值
int q[N];//q是单调队列
int main()
{
    cin>>n;
    int hh=0,tt=-1;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for (int i=0;i<n;i++)
    {
        //判断队头是否已经滑出窗口
        if(hh<=tt&&i-k+1>q[hh])
        {
            hh++;
        }
        while(hh<=tt&&a[q[tt]]>=a[i])
        {
            tt--;//出队
        }
        q[++tt]=i;//把当前这个数插到队列里面去
        if(i>=k-1)
        {
            cout<<a[q[hh]]<<" ";
        }

    }
    cout<<endl;

    hh=0,tt=-1;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for (int i=0;i<n;i++)
    {
        //判断队头是否已经滑出窗口
        if(hh<=tt&&i-k+1>q[hh])
        {
            hh++;
        }
        while(hh<=tt&&a[q[tt]]<=a[i])
        {
            tt--;//出队
        }
        q[++tt]=i;//把当前这个数插到队列里面去
        if(i>=k-1)
        {
            cout<<a[q[hh]]<<" ";
        }

    }
    cout<<endl;

    return 0;
}
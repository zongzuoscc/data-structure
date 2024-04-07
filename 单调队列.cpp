//最经典的应用是求滑动窗口里的最大值或者最小值
//和单调栈做法类似，也是先想出暴力做法，然后再挖掘其中的性质，最后改进算法
//完全没有理解单调队列，需要再看一遍视频
//相对于stl速度很快
#include <iostream>
using namespace std;
const int N= 1000010;
int n,k;
int a[N];//存储的是原来的值
int q[N];//q是单调队列，队列里存的不是值，而是下标
int main()
{
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int hh=0,tt=-1;
    for (int i=0;i<n;i++)
    {
        //判断队头是否已经滑出窗口
        //直接用队列来判断，队列中存储的是下标
        if(hh<=tt&&i-k+1>q[hh])//首先判断队列是否是空的，起点是i，终点是i-k+1,如果满足这一条件，说明已经出了窗口，则hh++
        {
            hh++;
        }
        while(hh<=tt&&a[q[tt]]>=a[i])//新插入的数比队尾小的话，队尾就没有用了，把队尾删掉
        {
            tt--;//出队
        }
        q[++tt]=i;//把当前这个数插到队列里面去，因为i有可能是最小值

        //当数不足k个的时候，就不用输出了
        if(i>=k-1)
        {
            cout<<a[q[hh]]<<" ";
        }

    }
    cout<<endl;

    hh=0,tt=-1;
    // for(int i=0;i<n;i++)
    // {
    //     cin>>a[i];
    // }
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
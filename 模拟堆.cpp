//以下是带映射版的堆的操作
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
const int N=100010;
//int n,m;
int h[N];//h 就是heap
int cnt;//存储的是当前这个数组里有多少个元素
int ph[N];//存储的是第k个插入的数  在堆里面的下标是什么  从下标映射到堆
int hp[N];//堆里面第k个下标的数  是第几个插入的数  从堆映射回下标
//hp[k]=j;ph[j]=k;大概就是这个意思

//在正常的算法里面不需要这么复杂的映射关系，但是在dijkstra算法(最短路径算法)里会用到，所以要学
void heap_swap(int a,int b)
{
    swap(ph[hp[a]],ph[hp[b]]);
    swap(hp[a],hp[b]);
    swap(h[a],h[b]);
}
void down(int u)  //一个递归的过程
{
    int t=u;
    if(u*2<=cnt&&h[u*2]<h[t])  //判断是否有左节点而且是否小于当前节点的值
    {
        t=u*2;
    }
    if(u*2+1<=cnt&&h[u*2+1]<h[t])
    {
        t=u*2+1;
    }
    //最后t存的就是三个点里面最小的那个的编号
    if(u!=t)//u!=t说明根节点存储的就不是最小值  这是为什么 
    {
        //那么根节点就需要和最小的交换一下
        heap_swap(u,t);//找到出错位置了 应该把h[u],h[t]改为u,t
        down(t);//递归处理
    }
}
void up(int u)
{
    while(u/2>0&&h[u]<h[u/2])//为什么这里也出错了  这里是已经修改过的版本
    {
        heap_swap(u,u/2);
        u=u/2;
    }
}
int  main()
{
    int n;
    int m=0;
    cin>>n;
    while(n--)
    {
        char op[5];
        int k,x;
        cin>>op;
        if(!strcmp(op,"I"))//先把要插入的数读进来
        {
            cin>>x;
            cnt++;
            m++;
            ph[m]=cnt;
            hp[cnt]=m;
            h[cnt]=x;
            up(cnt);
        }
        else if(!strcmp(op,"PM"))
        {
            cout<<h[1]<<endl;
        }
        else if(!strcmp(op,"DM"))
        {
            heap_swap(1,cnt);
            cnt--;
            down(1);
        }
        else if(!strcmp(op,"D"))
        {
            cin>>k;
            k=ph[k];//让k直接找到他在堆里面的位置
            heap_swap(k,cnt);
            cnt--;
            up(k);
            down(k);
            
        }
        else
        {
            cin>>k>>x;
            k=ph[k];
            h[k]=x;
            up(k);
            down(k);
        }
    }
    return 0;
}
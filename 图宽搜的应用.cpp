//图宽搜的应用就是求拓扑序
//拓扑序列是针对有向图来说的 无向图没有拓扑序列
//若一个图中所有点构成的序列A满足：对于图中的每条边(x,y)，x在A中都出现在y之前  则称A是该图的一个拓扑序列  
//有环则没有拓扑序  一个有向无环图一定是有拓扑序列的  有向无环图也被称为拓扑图
//拓扑序列所有的边都是从前指向后  因此当前所有入度为0的点都可以作为起点  （弹幕说可以用深搜或者并查集判断是否有环）
//一个有向无环图至少存在一个入度为0的点 

//我个人看法  这个有一点像哈斯图 从底到顶

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N=100010;
int n,m;
int h[N],e[N],ne[N],idx;
//e存储的是边
int q[N];//队列  存储所有入度为0的点 
int d[N];//存储的入度
void add(int a,int b)
{
    e[idx]=b;
    ne[idx]=h[a];
    h[a]=idx++;
}
bool topsort()
{
    int hh=0,tt=-1; 
    for(int i=1;i<=n;i++)
    {
        if(!d[i])//把所有入度不为0的点插入到队列里面去  i 序号就代表点
        {
            q[++tt]=i;
        }
    }
    while(hh<=tt)
    {
        int t=q[hh++];//每次取出队头元素   出队的序是拓扑序
        for(int i=h[t];i!=-1;i=ne[i])//拓展队头元素
        {
            int j=e[i];//找到出边
            d[j]--;//让入度--
            if(d[j]==0)
            {
                //如果减完等于0
                q[++tt]=j;
            }
        }
    }

    //最后判断是否所有点都已经入队
    return tt==n-1;//如果tt=n-1 说明一共进了n个点    
}
int main()
{

    cin>>n>>m;
    memset(h,-1,sizeof h);
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        add(a,b);
        d[b]++;//一条a指向b的边那么b++;
    }
    if(topsort())
    {
        for(int i=0;i<n;i++)
        {
            cout<<q[i]<<endl;
        }
    }
    else
    {
        cout<<"-1"<<endl;
    }
    return 0;
}
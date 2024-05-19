//for循环n次
//每次循环所有边 
//搞一个结构体来存储边和权重
//思想上总体和dijkstra算法一致
//求最短路的时候，如果有负权回路，那么最短路是不一定存在的
//bellman-Ford算法可以求出来是否有负权回路的
//当迭代到第k次的时候  dist数组的意义是 从1号点 经过不超过k条边 走到每个点的最短距离
//如果在迭代的时候 第n次更新的时候 又更新了某些边 那么就说明存在一条长度是n的
//存在一条路径，这条路径上边数是大于等于n的  有n条边，意味着有n+1个点 1到n只有n个点
//抽屉原理 证明一点有两个点编号一样 这个路径上就一定存在环  路径上存在环一定是更新过之后，所以这个环一定是负环
//有负权回路就不一定存在最短路了  也有可能是存在的
//时间复杂度为O(nm)
//spfa算法要优于bellman-ford算法 但是有一部分题只能用bellman-Ford算法完成，就是下面这道题

// 给定一个 n个点 m条边的有向图，图中可能存在重边和自环， 边权可能为负数。
// 请你求出从 1号点到 n号点的最多经过k条边的最短距离，如果无法从 1号点走到 n号点，输出 impossible。
// 注意：图中可能 存在负权回路 。
// 输入格式
// 第一行包含三个整数 n,m,k
// 接下来 m行，每行包含三个整数 x,y,z，表示存在一条从点 x到点y的有向边，边长为 z
// 点的编号为 1∼n
// 输出格式
// 输出一个整数，表示从 1号点到 n号点的最多经过 k条边的最短距离。
// 如果不存在满足条件的路径，则输出 impossible。

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N=510;//点数
const int M=10010;//边数是10000
int dist[N];//距离
int backup[N];//
int n,m,k;


struct Edge//定义一个结构体来存储所有边
{
    int a,b,w;//a,b表示起点和终点,w表示权重
}edges[M];//存储所有边

int bellman_ford()
{
    memset(dist,0x3f,sizeof dist);
    dist[1]=0;
    //由于题目要求不超过k条边 所以迭代k次
    for(int i=0;i<k;i++)
    {
        //弹幕说 每次遍历的是边
        //这个题需要做一个特殊的处理，每次在进行一次新的迭代之前，需要先把dist数组备份一下
        memcpy(backup,dist,sizeof dist);
        //在做bellman-Ford算法的时候 如果不加备份会有问题 更新过程枚举所有边的时候 可能会发生串联
        //就不能满足k条边的限制  就需要备份  备份之后 backup里存储的就是上一次迭代的结果
        //只用上一次迭代的结果就不会发生串联
        for(int j=0;j<m;j++)
        {
            int a=edges[j].a;
            int b=edges[j].b;
            int w=edges[j].w;
            dist[b]=min(dist[b],backup[a]+w);
        }
    }
    if(dist[n]>0x3f3f3f3f/2)
    {
        return 0x3f3f3f3f;//说明路径不存在
    }
    return dist[n];
}
int main()
{
    cin>>n>>m>>k;
    for(int i=0;i<m;i++)
    {
        int a,b,w;
        cin>>a>>b>>w;
        edges[i]={a,b,w};
    }
    int t=bellman_ford();
    if (t==0x3f3f3f3f)//说明最短路长度不存在
    {
        cout<<"impossible"<<endl;
    }
    else
    {
        cout<<t<<endl;
    }
    return 0;
}
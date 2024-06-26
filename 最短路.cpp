//最短路    n表示点的数量  m表示边的数量
//1 单源最短路  求一个点到其他所有点的最短的距离  从1号点到n号点的最短路
    //1.1 所有边权都是正数  （有两种方法，其实是一种，只是适用于不同的场景）
        //dijkstra基于贪心
        //1.1.1  朴素的dijkstra算法   （时间复杂度是n^2）  与边无关 适合于稠密图 
        //如果稠密图用堆优化版dijkstra算法  m和n^2差不多是一个级别  时间复杂度将是n^2logn
        //1.1.2  堆优化版的dijkstra算法  （时间复杂度是  mlogn）
        //如果是一个稀疏图 m和n是一个级别的  m和n都是10000级别  此时就不能用朴素版dijkstra算法  n^2为10^10
    //1.2 存在负权边
        //bellman-ford算法基于离散数学知识
        //1.2.1bellman-ford算法  时间复杂度为O(nm)
        //1.2.2  SPFA 是bellman-ford 算法的优化  平均的时间复杂度是线性的为 O(m)   最差的情况是O(nm)
        //虽然说SPFA算法是bellman-ford 算法的优化 但并不是所有情况下都可以用SPFA算法
        //比如说规定通过的变数小于等于k  那么就只能用bellman-Ford算法做


//2 多源汇最短路  源点就是起点  汇点一般来说就是终点   多源汇最短路 就是说不只有一个起点
//可能会有很多个询问  任选两个点  从一个点到另外一个点的最短距离  起点和终点都是不确定的
//只有一种做法 Floyd算法  时间复杂度为O(n^3)
//Floyd基于动态规划

//在以上算法中 并没有涉及到这个图是有向边还是无向边  因为不影响

//最短路算法 考察的侧重点是 建图同时也是难点 如何把问题抽象成最短路的问题

//朴素版dijkstra    集合s 存储当前已经确立最短路的点
    //1 初始化距离 dist[1]=0; dist[i]=正无穷
    //2 迭代循环的过程 for(i=0;i<n;i++)循环n次  找到不在s中的 距离最近的点  把这个点t加到s中 然后用t来更新其他点的距离
    //更新方式 t可以走到下一个点x  其实就是看dist[x]是不是大于dist[t]
    //就是看从1到t+从t到x 是不是大于从1 到x
    //如果大于 就更新  
    //每次都能确定最短距离  循环n次就能确定所有点的最短距离
    //当前还没有确定的点当中 距离最小的一个点那么这个点的距离一定是最短路

    //由于是一个稠密图  那么我们就使用稠密图来存储 
    //

//由于权值都是正的，所有自环不会出现在最短路里   重边只需要保留长度最短的边即可
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N=510;
int n,m;
int g[N][N];
int dist[N];//dijkstra算法里面的距离 表示的是从一号点走到每个点的距离是多少  当前的最短距离是多少
bool st[N];//表示每个点的最短路是不是已经确定了
int dijkstra()
{
    memset(dist,0x3f,sizeof dist);//初始化距离为正无穷
    dist[1]=0;//将一号点初始化为0；
    for(int i=0;i<n;i++)//迭代n次
    {
        //每次第一步先找最小值
        //找到当前没有确定最短路长度的点当中 距离最小的那一个
        int t=-1;//表示还没有确定

        //要从整体上来看这个循环 在所有st为false的点中找到dist最小的点
        //flase的意思是说，这个点的距离还没确定
        for(int j=1;j<=n;j++)
        {
            if(!st[j]&&(t==-1||dist[t]>dist[j]))//如果说当前这个点还没有确定最短路并且t=-1或当前这个t不是最短的的话 
            {
                t=j;//那么就把t赋值成j
            }
        }
        //if(t==n) break;  可以加这句进行优化，但是加不加影响不大？
        st[t]=true;//把t加到集合里面去

        //拿t来更新其他点的距离
        for(int j=1;j<=n;j++)
        {
            dist[j]=min(dist[j],dist[t]+g[t][j]);//从用1到t的距离+t到j的距离 来更新从1到j这条边
        }
    }
    if(dist[n]==0x3f3f3f3f)//如果从1到n是正无穷 说明是不连通的  (一开始少了一个3f导致出错)
    {
        return -1;
    }
    else
    {
        return dist[n];
    }
}
int main()
{
    cin>>n>>m;//读入点数和边数
    // for(int i=1;i<=n;i++)
    // {
    //     for(int j=1;i<=n;j++)
    //     {
    //         if(i==j)
    //         {
    //             g[i][j]=0;
    //         }
    //         else
    //         {
    //             g[i][j]=INF;//负无穷
    //         }
    //     }
    // }
    memset(g,0x3f,sizeof g);//和上面一长串代码原理相同
    while(m--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        g[a][b]=min(g[a][b],c);//因为可能有多条边 所有这一步是保留长度最短的边
    }
    int t=dijkstra();
    cout<<t<<endl;
    return 0;
}
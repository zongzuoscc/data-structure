//最小生成树对应的图都是无向图  有向图一般不会有
//最小生成树有两个算法  prim算法 普利姆算法   克鲁斯卡尔算法 kruskal
//prim算法 和 dijkstra算法很像 也是两种 
    //稠密图  朴素版prim  o(n^2)
    //稀疏图  堆优化版prim  o(mlogn)  一般不常用  因为kruskal算法 更清楚
//kruskal o(mlogm)  会先排序  
//稠密图 用朴素版 prim  稀疏图  用kruskal 算法

//二分图
//判别是不是二分图  染色法 o(m+n)
//匈牙利算法   o(mn)最坏情况  运行时间小于这个


//朴素prim
//先把所有距离初始化为正无穷
//n次迭代
//每次迭代 找到不在集合当中的最小的点
//在当前连通块当中所有的点  t=找到集合外距离最近的点
//用t更新其他点到集合的距离
//把t加到集合当中去
//有重边只保留长度最小的边
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N=510;
const int INF=0x3f3f3f3f;
int n,m;
int g[N][N];//邻接矩阵来存
int dist[N];
bool st[N];

int prim()
{
    memset(dist,0x3f,sizeof dist);
    int res=0;//存储生成树里面，最小生成树所有边长度之和
    for(int i=0;i<n;i++)
    {
        int t=-1;
        for(int j=1;j<=n;j++)
        {
            if(!st[j]&&(t==-1||dist[t]>dist[j]))
            {
                t=j;
            }
        }
        if(i&&dist[t]==INF)//如果不是第一个点并且 说明当前距离最近的点到集合的距离都是正无穷 也就是说当前图是不连通的 说明不存在最小生成树
        {
            return INF;
        }
        if (i)
        {
            res+=dist[t];
        }
        for(int j=1;j<=n;j++)
        {
            dist[j]=min(dist[j],g[t][j]);
        }
        st[t]=true;//把点加到树里面去
        
    }
    return res; 
}

int main()
{
    cin>>n>>m;
    memset(g,0x3f,sizeof g);
    while(m--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        g[a][b]=g[b][a]=min(g[a][b],c);
    }
    int t=prim();
    if(t==INF)
    {
        cout<<"impossible"<<endl;
    }
    else
    {
        cout<<t<<endl;
    }
    return 0;

}
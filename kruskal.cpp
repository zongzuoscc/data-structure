//将所有边权重按从小到大的顺序排列  这是kruskal算法的瓶颈 时间复杂度为 O(mlogm)  可以用快排来排序  或者直接调用 sort  常数非常小
//枚举每条边 ab 权重是c  如果当前a，b不连通的话  将这条边加入集合里面来
//kruskal算法 用到了并查集的知识
//其实接下来就是并查集的应用
//邻接表单链表用来存图
//并查集用来做kruskal算法
//堆用来做dijkstra算法

//kruskal 算法不需要用邻接表或者邻接矩阵来存图  只要把每条边存下来就可以了 可以开一个结构体来存

#include <iostream>
#include <algorithm>
using namespace std;
const int N=200010;
int n,m;
int p[N];
struct edge
{
    int a,b,w;  //a,b 是顶点 w是权重
    bool operator< (const edge& W)const// 重载小于号 方便排序
    {
        return w<W.w;
    }
}edges[N];

int find(int x)
{
    if(p[x]!=x)
    {
        p[x]=find(p[x]);
    }
    return p[x];
}

int main()
{
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int a,b,w;
        cin>>a>>b>>w;
        edges[i]={a,b,w};
    }
    sort(edges,edges+m);
    for(int i=1;i<=n;i++)//初始化并查集
    {
        p[i]=i;
    }
    int res=0,cnt=0;
    for(int i=0;i<m;i++)//从小到大枚举所有边
    {
        int a=edges[i].a,b=edges[i].b,w=edges[i].w;

        a=find(a);//找到a的祖宗节点
        b=find(b);
        //判断a和b是否连通 ，就是判断两个的根节点一样不一样
        if(a!=b)//如果两个祖宗节点不连通 就把这条边加进来
        {
            p[a]=b;//加进来这个点之后   把这两个点 所在的集合合并
            res+=w;//res存储的是最小生成树里所有边的权重之和    
            cnt++;//cnt存储的是当前加入了多少条边
        }        
    }
    if(cnt<n-1)
    {
        //说明这个图不连通
        puts("impossible");
    }
    else
    {
        cout<<res<<endl;//否则输出所有树边的长度之和
    }
    return 0;
}
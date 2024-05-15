//1.1.2  堆优化版的dijkstra算法  （时间复杂度是  mlogn）
//如果是一个稀疏图 m和n是一个级别的  m和n都是10000级别  此时就不能用朴素版dijkstra算法  n^2为10^10
//两重循环就会直接爆掉，无法运行
//在堆中修改一个数的时间复杂度是logn  那么一共要修改m次，则时间复杂度是mlogn
//可以用手写堆
//或者c++中的priority queue  优先队列不支持修改任意一个元素的操作
//存储方式改成邻接表  用邻接表 有重边也没事
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int N=1e6+10;//之前开的100010
int n,m;
int h[N],e[N],ne[N];
int w[N];//用于存储邻接表的权重
int idx;
int dist[N];//dijkstra算法里面的距离 表示的是从一号点走到每个点的距离是多少  当前的最短距离是多少
bool st[N];//表示每个点的最短路是不是已经确定了
void add(int a,int b,int c)
{
    e[idx]=b;//存储边
    w[idx]=c;//存储权重
    ne[idx]=h[a];
    h[a]=idx++;//头节点，下标存储从这个点到另一点的起始点
}
int dijkstra()
{
    memset(dist,0x3f,sizeof dist);//初始化距离为正无穷
    dist[1]=0;//将一号点初始化为0；
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> heap;
    //已经知道1号点的距离，把1号点放进来，更新其他点的距离
    heap.push({0,1});//距离是0，编号是1
    while(heap.size())//队列不空
    {
        auto t=heap.top();//每次找到当前距离最小的点 也就是堆的起点
        heap.pop();
        int ver=t.second;//用ver来代表点的编号
        int distance=t.first;//distance来代表距离

        if(st[ver]) //如果说当前这个点已经出现过，说明这个点是冗余备份 就没有必要再处理这个点，
        {
            continue;
        }
        st[ver]=true;//少了这句，加上之后ac了  可以提高效率
        //之后再用当前这个点来更新其他点
        for(int i=h[ver];i!=-1;i=ne[i])
        {
            int j=e[i];
            if(dist[j]>distance+w[i])
            {
                dist[j]=distance+w[i];
                heap.push({dist[j],j});
            }
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
    memset(h,-1,sizeof h);//和上面一长串代码原理相同
    while(m--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        add(a,b,c);
    }
    int t=dijkstra();
    cout<<t<<endl;
    return 0;
}
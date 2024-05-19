//只要是不存在负权边的情况下单源汇最短路问题都可以用spfa算法解决
//正权图建议用spfa，负权图spfa比较好用
//用宽搜来做优化
//bellman-ford 算法看起来很傻  每次迭代遍历所有边 然后来更新  每一次迭代不一定每一条边都会更新
//dist[b]=min(dist[b],dist[a]+w)  不一定都会把dist[b] 变小
//spfa是对上面这一操作做优化
//如果说dist[b]想在当前这一次迭代变小的话 一定是dist[a]变小了 如果a不变那么b一定不变
//只有a变小 b才会变小
//用宽搜来做优化，迭代的时候会用一个队列
//第一次先把起点放到队列里面去 只要队列不空  每一次，就是队列里面就是所有变小的a  队列里存的就是所有变小了的节点
//只要一个节点变小，我就把他放到队列里面  用它来更新后面所有的后继
//只要队列不空  只要队列里面还有节点变小 就执行迭代
//1 先从队列里取出队头


//在一般情况下(指出题人不故意设置难数据卡你的算法)spfa算法要比dijkstra算法要快
//正常情况下时间复杂度使O(n)但是可以故意设置数据把spfa算法卡成o(nm)的

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
int dist[N];//spfa算法里面的距离 表示的是从一号点走到每个点的距离是多少  当前的最短距离是多少
bool st[N];//表示每个点的最短路是不是已经确定了
void add(int a,int b,int c)
{
    e[idx]=b;//存储边
    w[idx]=c;//存储权重
    ne[idx]=h[a];
    h[a]=idx++;//头节点，下标存储从这个点到另一点的起始点
}
int spfa()
{
    memset(dist,0x3f,sizeof dist);
    dist[1]=0;
    queue<int> q;//存储所有待更新的点
    q.push(1);//把一号点放到队列里面去
    st[1]=true;//st数组存储的是当前这个点是不是在队列当中，防止队列当中存储重复的点

    while(q.size())
    {
        int t=q.front();
        q.pop();
        st[t]=false;//表示这个点不在队列里面了

        for(int i=h[t];i!=-1;i=ne[i])
        {
            int j=e[i];//表示当前这个点
            if(dist[j]>dist[t]+w[i])
            {
                dist[j]=dist[t]+w[i];
                if(!st[j])
                {
                    q.push(j);
                    st[j]=true;
                }
            }
        }
    }

    if(dist[n]==0x3f3f3f3f) return 0x3f3f3f3f;//这里yxc讲的使return -1 但是出错了，我自己魔改之后成功了。
    return dist[n];
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
    int t=spfa();
    if(t==0x3f3f3f3f)
    {
        cout<<"impossible"<<endl;   
    }
    else
    {
        cout<<t<<endl;
    }
    return 0;
}
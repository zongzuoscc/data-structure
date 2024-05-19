//求负环的思路和bellman-Ford算法是一样的  也是应用抽屉原理
//在更新dist数组的时候  dist[x]表示当前这个点到一号点的长度
//与此同时再记录另外一个东西 cnt数组  表示的是当前最短路的边的个数
//每次更新dist的时候  disr[x]=dist[t]+w[i]
//每次更新的时候把cnt[x]也更新一下 cnt[x]=cnt[t]+1
//如果某一次过程中cnt[x]>=n  意味着 从1 到x 至少经过了n条边 就表示从1到x至少经过n+1个点
//抽屉原理 一共只有n个点  所以一定有两个点的值是相同的  那就意味着路径上存在一个环  存在环一定是有原因的
//一定是因为这个环能够使得路径变短 否则这个环存在是没有意义的  所以这个环一定是负权的

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
int cnt[N]; 
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
    // memset(dist,0x3f,sizeof dist);
    // dist[1]=0;  不需要初始化了 因为求的不是距离的绝对值  求的是是否存在负环 
    queue<int> q;//存储所有待更新的点
    //q.push(1);//把一号点放到队列里面去
    //st[1]=true;//st数组存储的是当前这个点是不是在队列当中，防止队列当中存储重复的点
        //为了判断是否有负环  而不是判断是否有从1 开始的负环  那么就把所有点都放在队列里面
    for(int i=1;i<=n;i++)
    {
        st[i]=true;
        q.push(i);
    }
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
                cnt[j]=cnt[t]+1;
                if(cnt[j]>=n)
                {
                    return true;
                }
                if(!st[j])
                {
                    q.push(j);
                    st[j]=true;
                }
            }
        }
    }

    // if(dist[n]==0x3f3f3f3f) return 0x3f3f3f3f;//这里yxc讲的使return -1 但是出错了，我自己魔改之后成功了。
    // return dist[n];
    return false;
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
    if(spfa())
    {
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
    return 0;
}
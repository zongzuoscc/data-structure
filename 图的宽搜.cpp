//从起点开始  每次拓展一层节点
//第一次发现这个点的路径，就是起点到这个点的最短距离（由于题目中的权重都是1)
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N=100010;
int n;//表示点
int m;//表示边
int h[N],ne[N],e[N],idx;
int d[N];//距离
int q[N];//队列
void add(int a,int b)
{
    e[idx]=b;
    ne[idx]=h[a];
    h[a]=idx++;
}
int bfs()
{
    int hh=0,tt=0;
    q[0]=1;
    memset(d,-1,sizeof d);//初始化距离 -1 表示没有遍历过
    d[1]=0;//一开始只有第一个点被遍历过 他的值是0
    //接下来就是宽搜框架
    while(hh<=tt)
    {
        int t=q[hh++];
        for(int i=h[t];i!=-1;i=ne[i])
        {
            int j=e[i];//每次用j来表示当前这个点可以到达哪个点  
            if(d[j]==-1)//如果d[j]没有被遍历过 那么
            {
                d[j]=d[t]+1;
                q[++tt]=j;//把这个点加到队列里去 
            }
        }
    }
    return d[n];
}
int main()
{
    cin>>n>>m;
    memset(h,-1,sizeof h);
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        add(a,b);//这里是有向图所以只需要插入一次就好了
    }
    cout<<bfs()<<endl;
    return 0;
}
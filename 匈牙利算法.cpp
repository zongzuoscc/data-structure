//给定一个二分图
//可以在比较快的时间复杂度内告诉我们 左边和右边匹配成功的一个最大的数量是多少
//匹配成功是指（匹配指的是边的数量） 成功的匹配指的是 不存在两条边是公用一个点的  匈牙利算法可以返回匹配数量最大是多少

// 给定一个二分图，其中左半部包含 n1
//  个点（编号 1∼n1），右半部包含 n2个点（编号 1∼n2 ），二分图共包含 m 条边。
// 数据保证任意一条边的两个端点都不可能在同一部分中。
// 请你求出二分图的最大匹配数。
// 二分图的匹配：给定一个二分图 ，在 G的一个子图 M中，M的边集 {E}中的任意两条边都不依附于同一个顶点，则称 M是一个匹配。
// 二分图的最大匹配：所有匹配中包含边数最多的一组匹配被称为二分图的最大匹配，其边数即为最大匹配数。
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N=510,M=100010;
int n1,n2,m;
int h[N],e[M],ne[M],idx;//存邻接表
int match[N];  //右边的点对应的点
bool st[N];//判断重复 每次不要搜同一个点
void add(int a,int b)
{
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}
bool find(int x)
{
    for(int i=h[x];i!=-1;i=ne[i])
    {
        int j=e[i];
        if(!st[j])//如果之前这个点没有被匹配过
        {
            st[j]=true;
            if(match[j]==0||find(match[j]))//如果说还没有匹配过任何一个点,或者说 刚好这个点可以和别的点匹配
            {
                match[j]=x;
                return true;
            }
        }
    }
    return false;
}
int main()
{
    cin>>n1>>n2>>m;
    memset(h,-1,sizeof h);
    while(m--)
    {
        int a,b;
        cin>>a>>b;
        add(a,b);
    }
    int res=0;//存储匹配的数量
    for(int i=1;i<=n1;i++)
    {
        memset(st,false,sizeof st);
        if(find(i))  res++; 
    }
    cout<<res<<endl;
    return 0;
}
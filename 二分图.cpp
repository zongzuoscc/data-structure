//二分图 当且仅当图中不含奇数环（环当中边的数量是奇数）  这是二分图的必要性 
//染色法  交替染色  用深度优先遍历来做  （弹幕说 深度代码少，宽度便于理解）
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N=100010,M=200010;

int n,m;
int h[N],e[M],ne[M],idx;//邻接表来存储图
int color[N];
void add(int a,int b)
{
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}
bool dfs(int u,int c)
{
    color[u]=c;
    for(int i=h[u];i!=-1;i=ne[i])//从前往后遍历当前所有点的邻点
    {
        int j=e[i];
        if(!color[j])//如果当前这个点没有染过颜色
        {//那么就染成另外一种颜色  这里3-c的意思是如果是如果是1号颜色 那么3-1就是2号颜色  反之 是一号颜色
            if(!dfs(j,3-c)) return false;
        }
        else if(color[j]==c)//当前j染过颜色 就判断有没有矛盾   j的颜色和当前颜色相同 那么就有矛盾了  因为一条边的两边不能是一样的颜色    
        {
            return false;
        }
    }
    return true;
}
int main()
{
    cin>>n>>m;
    memset(h,-1,sizeof h);
    while(m--)
    {
        int a,b;
        cin>>a>>b;
        add(a,b),add(b,a);
    }
    bool flag=true;
    for(int i=1;i<=n;i++)
    {
        if(!color[i])
        {
            if(!dfs(i,1))//定义只要dfs返回的是false 那么就证明有矛盾发生 即一个点被两次染色
            {
                flag=false;
                break;
            }
        }
    }
    if(flag) puts("Yes");
    else puts("No");
    return 0;
}
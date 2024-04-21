//深度优先搜索  DFS  使用栈  stack
//这两种搜索都可以对空间进行遍历   搜索的结构都是像一棵树一样
//DFS 是先一直往下走，直到走到最下面，然后往回返，返回过程中如果遇到有某一个父节点的另一个子节点没有被搜索，那么优先先搜索这个子节点，
//直到搜索完成，再返回
//从空间上来看  DFS往下搜索的时候只需要记录这一条路径上的所有点  使用的空间和高度成正比  O(h)
//在空间上 DFS更有优势  但是DFS不具有最短路的性质
//从搜索树的角度来考虑  每一个DFS都对应一条搜索树
//算法思路比较奇怪的 对空间要求比较高的 一般都用DFS做
//DFS俗称暴搜  顺序很重要  把顺序想清楚  我们要用什么样的一个顺序 把所有的方案遍历一遍
//排列顺序 皇后
//假设一开始已经有n个空位  顺序就是从第一位开始填  dfs就是递归
//在回溯的时候记得恢复现场

//以下为全排列
#include <iostream>
using namespace std;
const int N=10;
int n;
bool st[N];//bool数组为真则表明该点已经用过了
int path[N];//用于记录方案 
void dfs(int u)
{
    if(u==n)//说明已经把所有位置都填满了
    {
        for(int i=0;i<n;i++)
        {
            cout<<path[i]<<" ";
        }
        cout<<endl;
        return;
    }
    //当u<n的时候说明还没填完，就需要枚举可以填那些数
    for(int i=1;i<=n;i++)
    {
        if(!st[i])//只有当前这个数没有被用过的时候 我们才会用这个数
        {
            path[u]=i;
            st[i]=true;
            //把状态处理好之后递归到下一层
            dfs(u+1);
            //恢复现场
            //path[u]=0;  这一句没什么用，可加可不加  因为path[u]上的数会被不断覆盖，所以不管是几都没问题
            st[i]=false;
        }
    }
    
}
int main()
{
    cin>>n;
    dfs(0);
    return 0;
}
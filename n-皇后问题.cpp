//这也是DFS
//有很多种搜索方式  第一种可以像全排列那样子搜索
//每一行，每一列，每一个对角线只能存在一个皇后使得它不能被其它任意一个皇后攻击到
//剪枝，提前判断当前方案是否合法，如果不合法直接停止不再继续递归
//以下为按照全排列的方式搜索n皇后的一种解法
//dfs没有一个经典的模板，重要的是顺序

#include <iostream>
using namespace std;
const int N=20;//开两倍，对角线的个数是2N-1
int n;
//bool数组为真则表明该点已经用过了
bool col[N];//每一列只能有一个 
bool dg[N];//正对角线
bool udg[N];//反对角线
char g[N][N];//用于记录方案 
void dfs(int u)
{
    if(u==n)
    {
        for(int i=0;i<n;i++)
        {
            cout<<g[i]<<endl;
        }
        cout<<endl;
        return;
    }    
    //当u<n的时候说明还没填完，就需要枚举可以填那些数
    for(int i=0;i<n;i++)
    {
        if(!col[i]&&!dg[u+i]&&!udg[n-u+i])//只有当前这个数没有被用过的时候 我们才会用这个数  这里一开始是u-n，导致输出结果一直错误
        {
            g[u][i]='Q';
            col[i]=dg[u+i]=udg[n-u+i]=true;//这里和下面一开始标注的全都是[i] 所以输出结果不正确，改为当前状态后解决
            //把状态处理好之后递归到下一层
            dfs(u+1);
            //恢复现场
            //path[u]=0;  这一句没什么用，可加可不加  因为path[u]上的数会被不断覆盖，所以不管是几都没问题
            col[i]=dg[u+i]=udg[n-u+i]=false;
            g[u][i]='.';
        }
    }
    
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            g[i][j]='.';
        }
    }
    dfs(0);
    return 0;
}
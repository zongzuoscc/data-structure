//相较于解法一，这是一种更原始的解法，更加接近问题原始的样貌
//这种做法是一个格子一个格子进行枚举
//最一开始的时候是空的然后枚举第一个格子 放是一个分支，不放是一个分支
//时间复杂度是n*n!这是最坏的情况
#include <iostream>
using namespace std;
const int N=20;//开两倍，对角线的个数是2N-1
int n;
//bool数组为真则表明该点已经用过了
bool row[N];
bool col[N];//每一列只能有一个 
bool dg[N];//正对角线
bool udg[N];//反对角线
char g[N][N];//用于记录方案 
void dfs(int x,int y,int s)
{
    //首先当前皇后的个数一定不会超过n
    if(y==n)//每次枚举完都会转向下一个格子，所以为了偷懒，直接将
    {
        y=0,x++;
    }
    if(x==n)//说明x已经枚举完最后一行了，就要停止了
    {
        if(s==n)//如果此时摆的皇后的个数等于n 说明找到了一组解
        {
            for(int i=0;i<n;i++)
            {
                puts(g[i]);
            }
            puts("");
        }
        return;
    }

    //枚举每种格子的选择
    //不放皇后，直接递归到下一个格子
    dfs(x,y+1,s);

    //放皇后，需要判断
    if(!row[x]&&!col[y]&&!dg[x+y]&&!udg[x-y+n])//每一行每一列，每一对角线都没有皇后
    {
        g[x][y]='Q';
        row[x]=col[y]=dg[x+y]=udg[x-y+n]=true;//每一行都已经放好皇后了
        dfs(x,y+1,s+1);
        row[x]=col[y]=dg[x+y]=udg[x-y+n]=false;//恢复现场
        g[x][y]='.';//将这个位置上的皇后清理掉
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
    dfs(0,0,0);
    return 0;
}
//思考两种不同搜索顺序的区别
//宽度优先搜索  BFS  使用队列  queue
//这两种搜索都可以对空间进行遍历   搜索的结构都是像一棵树一样
//BFS 是搜索完每一层才会搜索下一层
//从空间上来看  BFS是优先搜索每一层  那么所需要的空间就是 O(2^h)  
//BFS 每次搜索是一层一层往外扩展 所以第一次搜索到的一定是最近的点  因此有一个最短路的概念
//凡是涉及到最小步数 最短距离 最少操作几次 基本上都是BFS    
//可以搜到最短路  因为是一圈一圈往外搜索  第一次搜索到距离一定最小
//要求 图里面每条边权重都是一样的
//dp问题和最短路问题是互通的   最短路问题是包含dp问题的 dp问题是一个没有环存在的最短路问题
//深搜没有常用的框架 但是宽搜是有的   当所有边权重都是1的时候才可以用BFS  一般情况下要用专门的最短路算法来求最短路
//dp问题不会用最短路算法来求，因为最短路算法的时间复杂度比较高
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
const int N=110;
int n,m;
int g[N][N];//g数组存储的是图，地图
int d[N][N];//d数组存储的是每一个点到地图起点的距离
//bfs 里面一般要用到队列，可以直接使用stl，也可以自己实现队列
pair<int,int> q[N*N];
pair<int,int> pre[N][N];  //记录最短的路径  记录每一个点的前一个点是谁
int bfs()
{
    int hh=0,tt=0;
    q[0]={0,0};
    memset(d,-1,sizeof d);
    d[0][0]=0;  //表示已经走过
    int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};  //这里是用向量来进行没一个点左下右上的移动  这样能避免写四个判断语句
    while(hh<=tt)//队列不空
    {
        auto t=q[hh++];  //每一次取出来队头
        for(int i=0;i<4;i++)
        {
            int x=t.first+dx[i];
            int y=t.second+dy[i];
            if(x>=0&&x<n&&y>=0&&y<m&&g[x][y]==0&&d[x][y]==-1)  //这里的判断条件是 没有碰到地图的边界 并且这一点是可以走而且没有被走过的
            {
                d[x][y]=d[t.first][t.second]+1;
                pre[x][y]=t;
                q[++tt]={x,y};
            }
        }
    }

    //以下为输出路径的方式
    int x=n-1,y=m-1;
    while(x||y)
    {
        cout<<"("<<x<<","<<y<<")"<<" ";
        auto t=pre[x][y];
        x=t.first,y=t.second;
    }
    return d[n-1][m-1];
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>g[i][j];
        }
    }
    cout<<bfs()<<endl;
    return 0;
}

/*  以下为使用stl中的队列进行编写的代码
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
const int N = 110;
int n, m;
int g[N][N], d[N][N];
int bfs()
{
    queue<pair<int,int>> q;

    memset(d, -1, sizeof d);
    d[0][0] = 0;//表示已经走过了    
    q.push({0, 0});

    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};  //这里是向量表示

    while (q.size())  //队列不空
    {
        auto t = q.front();//   这里t的类型就是 pair<int,int>   每一次取出队头元素
        q.pop();

        for (int i = 0; i < 4; i ++ )  //每次枚举四个方向
        {
            int x = t.first + dx[i], y = t.second + dy[i];

            if (x >= 0 && x < n && y >= 0 && y < m && g[x][y] == 0 && d[x][y] == -1)
            {
                d[x][y] = d[t.first][t.second] + 1;
                q.push({x, y});
            }
        }
    }

    return d[n - 1][m - 1];
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i ++ )
        for (int j = 0; j < m; j ++ )
            cin >> g[i][j];

    cout << bfs() << endl;

    return 0;
}
*/
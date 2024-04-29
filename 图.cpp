//树和图有两种存储方式
//树是一种特殊的图  是无环连通图
//而图又分为两种  即有向图和无向图  无向图就是双向的有向图  所以只需要考虑有向图如何存储即可
//有向图的存储又分为两大类 
//（这一类用的比较少） 邻接矩阵 （就是开一个二维数组）   g[a,b]存储a到b这条边的一个信息   如果有权重的话 存储的就是权重 
//没有权重的话 就是一个bool值 true表示有边 false表示没有边  有重边的话 邻接矩阵不能存储重边  有重边就只能保留一条 一般来说保留一条就可以了
//因为如果要求最短路 只需要保留最短的边  用的比较少 因为浪费空间  空间复杂度是n^2  比较适合存储稠密

//用的较多的是邻接表  就是之前讲过的单链表  每一个点上都有一个单链表
//每一个点上存的东西就是这个点可以走到哪个点
//有几个点就开几个单链表

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N=100010;
const int M=200020;
int h[N];//存储的是n个链表的链表头
int e[M];//存储的是每一个节点的值是多少
int ne[M];//存储的是每一个节点的next指针是多少
int idx;
void add(int a,int b)
{
    e[idx]=b;//先把节点赋值
    ne[idx]=h[a];
    h[a]=idx++;
}
int main()
{
    memset(h,-1,sizeof h);//链表初始化

}
//以上就是树和图的存储  
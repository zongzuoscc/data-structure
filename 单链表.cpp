//用数组实现链表
//正常的链表  动态链表
// struct Node
// {
//     int val;
//     Node *next;
// };
//这种方式不讲，在面试中用的多。
//每次创建新链表都需要 new Node()
//new 一个新的节点非常慢，改进之后是可以用的
//讲两种链表，1用数组模拟单链表，（在笔试中用的最多的是邻接表，邻接表是n个链表，最主要应用是存储树和图）
//2用数组模拟双链表（用来优化某些问题）数组模拟链表的好处是速度快
#include <iostream>
using namespace std;
const int N =100010;
//head表示头节点的下标 
//e[i]表示结点i这一位置存储的值
//ne[i]表示节点i的next指针是多少,换句话说就是节点i的下一个位置在什么地方，就是节点i的下一个点的下标是什么
//idx表示当前已经用到了哪个点，存储当前已经用到哪个地址
//其实head和idx都是相当于是一个地址
int head,e[N],ne[N],idx;
//初始化
void init()
{
    head=-1;
    idx=0;
}
//将x插到头节点
void add_to_head(int x)
{
    //第一步将要插入的点的指针指向当前head指向的位置
    //第二步，将head指针删掉，然后指向插入的这个点
    e[idx]=x;//先把值存下来
    ne[idx]=head;
    head=idx;
    idx++;//这一个地址已经被用过了所以直接++,可以把这一行与上一行合起来·写，但是分开写更方便理解
}
//将idx插到下标是k这个点的后面
void add(int k,int x)
{
    e[idx]=x;
    ne[idx]=ne[k];//将要添加的点指向k之后的下一个点，由于数组是从0 开始，所以k位置数组的下标是k-1，k的下一个位置的下标是k
    ne[k]=idx;
    idx++;
}

//将下标是k的点后面的点删掉
void remove(int k)
{
    ne[k]=ne[ne[k]];//这一步就是相当于将当前位置的指针指向下一个的下一个
}
int main()
{
    int m;
    cin>>m;
    init();
    while(m--)
    {
        int k,x;
        char op;
        cin>>op;
        if(op=='H')
        {
            cin>>x;
            add_to_head(x);
        }
        else if (op=='D')
        {
            cin>>k;
            if(k==0)//这里的意思是删除头节点
            {
                head=ne[head];//这里没有完全懂
            }
            remove(k-1);
        }
        else
        {
            cin>>k>>x;
            add(k-1,x);
        }
    }
    for(int i=head;i!=-1;i=ne[i])
    {
        cout<<e[i]<<" ";
    }
    cout<<endl;
    return 0;
}
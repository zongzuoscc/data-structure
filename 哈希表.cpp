//哈希表的存储结构（分为两大类） 1 开放寻址法  2 拉链法  （这两种方法都很常用）
//常用的字符串哈希的方式
//把一个比较庞大的值域映射到一个小的空间
//弹幕里说 离散化是特殊的哈希  哈希是把所有的数放在小空间存起来，然后解决冲突，离散化是把要用到的抽取出来
//yxc说离散化是极其特殊的哈希，此处的是一般的哈希
//之前讲的离散化是要保序的

//拉链法  开一个一维数组来存储所有的哈希值
//哈希算法是一种期望算法  虽然每个槽都会拉一条链  但是在平均情况下来看 每条链的长度可以看作常数
//在一般情况下  哈希表的时间复杂度都可以看作o(1)
//在算法题里，一般不需要从哈希表中删除元素  一般只有添加和查找两个操作
//如果说要实现删除的话 不会真的把这个点删掉 一般情况下是开1个数组 在每个数上打一个标记 可以开一个bool变量

//h函数mol的那个数最好取成距离2的整次幂尽可能远的质数  这么取的话 冲突的概率是最小的

//拉链法就是单数组外加数组模拟链接表的写法
#include <iostream>
#include <cstring>
using namespace std;
const int N=10003;
int h[N];//这里按理来说表示的是哈希之后的值 也就是对应的槽
int e[N],ne[N];//拉链法的链其实就是之前讲的链表
int idx;//表示当前用到了哪个位置
void insert(int x)
{
    
    int k=(x%N+N)%N;//哈希值    
    //这一步的操作是防止x是负数 这样子能保证是正数
    e[idx]=x;
    ne[idx]=h[k];
    h[k]=idx++;//这里的h[k]相当于不同链表的头节点
}
bool find(int x)
{
    int k=(x%N+N)%N;
    for (int i=h[k];i!=-1;i=ne[i])
    {
        if(e[i]==x)
        {
            return true;
        }
    }
    return false;
}
int main()
{
    //以下为用于寻找质数的代码
    // for(int i=10000;;i++)
    // {
    //     bool flag=true;
    //     for(int j=2;j*j<=i;j++)
    //     {
    //         if(i%j==0)
    //         {
    //             flag=false;
    //             break;
    //         }
    //     }
    //     if(flag)
    //     {
    //         cout<<i<<endl;
    //         break;
    //     }
    // }
    int n;
    cin>>n;
    memset(h,-1,sizeof h);//先把所有的槽清空 赋值为-1
    while(n--)
    {
        char op[2];
        int x;
        cin>>op>>x;
        if(*op=='I')
        {
            insert(x);
        }
        else
        {
            if(find(x))
            {
                cout<<"Yes"<<endl;
            }
            else
            {
                cout<<"No"<<endl;
            }
        }
    }
    return 0;
}
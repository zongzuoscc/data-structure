//开放寻址法只开了一个数组，没有开链表 形式相对简单  数组的长度一般在题目给定的数的2~3倍
//哈希表里面一般不会用sort 否则会使得程序变慢   

#include <iostream>
#include <cstring>
using namespace std;
const int N=200003;
const int null=0x3f3f3f3f;
int h[N];
int find(int x)
{
    //和拉链法不同，开放寻址法最核心的操作是find操作
    //如果x在哈希表中存在的话，返回的就是他在哈希表中的位置
    //如果不存在的话，那么返回的是他应该在的位置
    int k=(x%N+N)%N;
    while(h[k]!=null&&h[k]!=x)//这个循环是一定会停止的  因为这个数组不可能都填满的，只有填满才有会死循环
    {
        k++;
        if(k==N)
        {
            k=0;
        }
    }
    return k;

}
int main()
{
    int n;
    cin>>n;
    memset(h,0x3f,sizeof h);//memset这个函数是按照字节来进行初始化的，一共有四个字节，每一个字节都是0x3f
    while(n--)
    {
        char op[2];
        int x;
        cin>>op>>x;
        int k=find(x);
        if(*op=='I')
        {
            h[k]=x;
        }
        else
        {
            if(h[k]!=null)
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
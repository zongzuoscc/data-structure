#include <iostream>
using namespace std;
const int N = 100010;//将N的值从10010改为100010，有N太小导致segmentation fault
int n,m;
int a[N],b[N];//a是b的前缀和,b是a的差分。差分是前缀和的逆运算
//差分是用于计算原数组的，b是原数组，a是b数组的和。
void insert (int l,int r,int c)
{
    b[l]+=c;
    b[r+1]-=c;
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        insert(i,i,a[i]);
        //关于如何理解这部分代码，就是将b[i]增加a[i]然后保证b[i]数组存储的是a[i]的前缀和
        //举个例子，假设insert(1,1,a[1])，那么此时b[1]=a[1]然后b[2]=-a[1]
        //当开始第二次循环时即insert(2,2,a[2])时，此时b[2]已经存储了-a[1]的值，再加上a[2]则
        //b[2]=a[2]-a[1]，而a[i]刚好是b前i项的和，所以通过这样的操作求出来b数组的值
    }
    while(m--)
    {
        int l,r,c;
        cin>>l>>r>>c;
        insert(l,r,c);
    }
    for(int i=1;i<=n;i++)
    {
        b[i]+=b[i-1];//这里的意义是得到新的进行操作后的前缀和，然后进行输出的
    }
    for(int i=1;i<=n;i++)
    {
        cout<<b[i]<<" ";
    }
    return 0;
}
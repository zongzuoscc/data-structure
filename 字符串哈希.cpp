//字符串哈希是一种特殊的哈希方式
//叫字符串前缀哈希法
//先预处理每个字符前缀的哈希
//特殊规定 h[0]=0
//从1到n是从高位到低位
//例如要求从L到R这一段的哈希值，那么就是h[R]=p^R-1+…………+p^0
//h[l-1]=p^l-2+…………+p^0  要把h[l-1]这一段往左移，移到和h[R]对齐为止
//所以直接将h[L-1]*p^R-L+1
//h要模2^64那么直接就用unsigned long long 来存储h 这样就不需要取模了  一旦溢出就相当于取模了
//与处理完之后就可以用O(1)的时间算出任意一段的哈希值了
//h[i]=h[i-1]*p+str[i];
//这个P一般取131 或者13331
//如何将字符串哈希，就是将他看成p进制的数
//预处理每个哈希的好处是可以用一个公式算出所有子串的哈希值 （有点类似前缀和）
//字符串哈希可以做到一些kmp做不到的

//kmp除了在循环节这类题目上比哈希具有优势外，其他地方不如哈希，但是也要注意，哈希有可能会遇到冲突，就是说，匹配好的两个哈希值相同，
//但是实际上里面的字符并不一定相同
//最核心的地方就是用k进制将一个字符串看成一个数字
#include <iostream>
using namespace std;
const int N=100010;
const int P=131;//取这个数不容易冲突
int n,m;
char str[N];
unsigned long long h[N];
unsigned long long p[N];//用来存储p的多少次方的
unsigned long long get(int l,int r)
{
    return h[r]-h[l-1]*p[r-l+1];
}
int main()
{
    cin>>n>>m;
    for (int i=1;i<=n;i++)
    {
        cin>>str[i];
    }
    p[0]=1;
    for(int i=1;i<=n;i++)
    {
        p[i]=p[i-1]*P;
        h[i]=h[i-1]*P+str[i];
    }
    while(m--)
    {
        int l1,r1,l2,r2;
        cin>>l1>>r1>>l2>>r2;
        if(get(l1,r1)==get(l2,r2))
        {
            cout<<"Yes"<<endl;
        }
        else
        {
            cout<<"No"<<endl;
        }
    }
    return 0;
}
//trie树，是用来高效的存储和查找字符串集合的数据结构，一般存储的字符都是同一类型的字符
//有一个根节点
//是数组模拟指针
#include <iostream>
using namespace std;
const int N=100010;
int son[N][26];//存储的是trie树中每一个节点的子节点
int cnt[N];//存储的是以当前这个点为结尾的单词有多少个
int idx;//存储当前用到哪个下标 下标是0的点，既是根节点，又是空节点，如果一个点没有子节点，也会让他指向0   idx++相当于new了一个新节点
char str[N];

void insert(char str[])//存储，也是插入操作
{
    int p=0;
    for(int i=0;str[i];i++)//由于c++字符串结尾是\0所以可以直接拿字符串位置来判断是否走到终点
    {
        int u=str[i]-'a';
        if(!son[p][u])
        {
            son[p][u]=++idx;//意思就是如果节点不存在，那么就创建节点
        }
        p=son[p][u];
    }
    cnt[p]++;
}

int query(char str[])//查询操作和插入操作是类似的
{
    int p=0;
    for(int i=0;str[i];i++)
    {
        int u=str[i]-'a';//先找到对应编号
        if(!son[p][u])
        {
            return 0;
        }
        p=son[p][u];
    }
    return cnt[p];//返回以p结尾的单词的数量
}

int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        char op[2];
        cin>>op>>str;
        if(op[0]=='I')
        {
            insert(str);
        }
        else
        {
            cout<<query(str)<<endl;
        }
    }
    return 0;
}
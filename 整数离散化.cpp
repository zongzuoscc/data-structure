// 假定有一个无限长的数轴，数轴上每个坐标上的数都是 0
// 现在，我们首先进行 n次操作，每次操作将某一位置 x上的数加 c
// 接下来，进行 m次询问，每个询问包含两个整数 l和 r，你需要求出在区间 [l,r]之间的所有数的和。
// 输入格式
// 第一行包含两个整数 n和 m
// 接下来 n行，每行包含两个整数 x和 c
// 再接下来 m行，每行包含两个整数 l和 r
// 输出格式
//共 m行，每行输出一个询问中所求的区间内数字和。
// 数据范围
// −10^9≤x≤10^9
// 1≤n,m≤10^5  
// −10^9≤l≤r≤10^9
// −10000≤c≤10000

//整数离散化用vector来做
//这是离散化与前缀和的结合
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int N=300010;//开三十万并不是避免re，
//总共离散化的数是n+2m，所以是30万
int a[N];//是存的数
int s[N];//前缀和
vector<int> alls;//是存储的所有需要离散化的值,是待离散化的数组
vector<pair<int,int>> add;//加上一个数
vector<pair<int,int>> query;//求
//以下为一个整数二分函数
int find(int x)
{
    int l=0,r=alls.size()-1;
    while(l<r)
    {
        int mid=(l+r)/2;
        if(alls[mid]>=x)
        {
            r=mid;
        }
        else
        {
            l=mid+1;
        }
    }
    return r+1;
}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        int x;//x是待离散化的数的位置
        int c;//c是需要加上的数
        cin>>x>>c;
        add.push_back({x,c});
        alls.push_back(x);
    }
    for(int i=0;i<m;i++)
    {
        int l,r;//两个区间的左右端点，也需要离散化，l和r是要求的左右端点的值
        cin>>l>>r;
        query.push_back({l,r});
        //将左右区间全部加入到待离散化的数组中去   为什么
        alls.push_back(l);
        alls.push_back(r);
        //此时所有需要用到的数组下标都已经放到数组s里面了
    }
    //将alls数组去重
    sort(alls.begin(),alls.end());
    alls.erase(unique(alls.begin(),alls.end()),alls.end());
    //处理插入
    for(auto item:add)
    {
        int x=find(item.first);
        a[x]+=item.second;//在要离散化的坐标上加上我们要加的数
    }
    //预处理前缀和
    for(int i=1;i<=alls.size();i++)//为什么是小于等于，因为循环开始时是从1开始的所以是小于等于
    {
        s[i]=s[i-1]+a[i];
    }
    //处理询问
    for(auto item:query)
    {
        int l=find(item.first);//左端点离散化后的值
        int r=find(item.second);//右端点离散化后的值
        cout<<s[r]-s[l-1]<<endl;
    }
    return 0;
}
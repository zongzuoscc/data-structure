#include <iostream>
using namespace std;
const int N=100010;
int a[N],s[N];
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        s[i]=s[i-1]+a[i];//提前求出每个s[i],s[i]是前a[i]的和，前缀和的初始化
    }
    while(m--)
    {
        int l,r;
        cin>>l>>r;
        cout<<s[r]-s[l-1]<<endl;//一个公式，用于求数组a从l加到r的和，区间和的计算
    }
    return 0;
}
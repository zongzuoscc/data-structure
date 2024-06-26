//暴力算法怎么做
//分析如何优化暴力算法
//s[N],比较长的串
//p[M]，比较短的串
//for(int i=1`;i<=n;i++)    从0或者1开始循环都可以，看个人习惯，一般来说从1开始  i枚举的是当前起点
//{
//   bool flag=true;
//   for(int j=1;j<=m;j++)  假设从s[i]开始，看能不能匹配成功
//   {
//       if(s[i]!=p[j])   弹幕说应该是s[i+j-1]!=p[j]
//       {
//           flag=false;
//           break;
//       }
//   }
//} 

//这个算法的时间复杂度是o(n)
#include <iostream>
using namespace std;
const int N=100010;
const int M=1000010;
int n,m;
char p[N];//短的串，去和长的串比，也是要求ne数组的串
char s[M];//长的串
int ne[N];
int main()
{
    cin>>n>>p+1>>m>>s+1;//下标从1开始所以读到p+1，s+1，这段代码和下面是等效的

    // cin>>n;
	// for(int i=1;i<=n;i++)
	// {
	// 	cin>>p[i];
	// }
	// cin>>m;
	// for(int i=1;i<=m;i++)
	// {
	// 	cin>>s[i];
	// }

    //求ne的过程，和匹配的过程类似  相当于是预处理，先求出ne[j]
    //其实和kmp匹配过程是类似的
    for(int i=2,j=0;i<=n;i++)
    {
        while(j&&p[i]!=p[j+1]) //如果说还么退到开始，并且，下一位仍然不匹配，那么
        {
            j=ne[j];
        }
        if(p[i]==p[j+1])//如果说匹配成功，那么j就前进一步 
        {
            j++;
        }
        ne[i]=j;//这里为什么要让ne[i]=j呢
    }
    for(int i=0;i<n;i++)
    {
        cout<<ne[i]<<" ";//输出ne方便理解
    }
    cout<<endl;

    //kmp匹配过程
    for(int i=1,j=0;i<=m;i++)
    {
        while(j&&s[i]!=p[j+1])//j没有退回起点并且当前的s[i]不能和下一个j的位置去匹配
        //前面都已经匹配正确了，但是下一位两个字母不相同了，移动完之后看新的j+1和原来的i是否匹配，直到匹配匹配为止，或者说j已经退回到开头
        {
            j=ne[j];
        }
        if(s[i]==p[j+1])//如果已经匹配了，那么j就可以移动到下一个位置
        {
            j++;
        }
        if(j==n)
        {
            //匹配成功,输出从第几个字符开始匹配成功的
            cout<<i-n+1<<" ";//这里+1与否看具体题目要求
            j=ne[j];
        }
    }
    return 0;
}
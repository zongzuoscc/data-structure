//最核心的用途是优化，暴力循环时间复杂度是o(n^2)双指针算法时间复杂度是O(n)
//看起来是循环了两次，但是实际上，循环的总次数加起来不超过2N
//实际上就是先想出朴素做法，暴力做法，然后再看暴力做法中两个指针的性质
//以下为最长连续不重复子序列题解
#include <iostream>
using namespace std;
const int N = 100010;
int a[N],s[N];

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int res=0;
    for(int i=0,j=0;i<n;i++)
    {
        s[a[i]]++;//用于储存重复元素个数，当大于1时开启循环
        while(s[a[i]]>1)//这个循环只有在遇到重复元素时才会开启，一旦重复元素被减去，就停止循环。
        {
            s[a[j]]--;
            j++;
        }
        res=max(res,i-j+1);
    }
    cout<<res;
    return 0;
}
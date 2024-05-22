// 这是一个专用于调试文件名为中文的cpp文件 
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
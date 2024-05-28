//试除法
//思路 从小到大枚举所有的因子

#include <iostream>
#include <algorithm>
using namespace std;
//最暴力的写法  但是在枚举i的时候，必然会出现合数，这是否会出现问题呢 因为要求的是质因数
//当枚举到i的时候就意味着 我们把2到i-1中所有的质因子都除干净了 当美剧到i的时候就意味着不含有任何从2到i-1的质因子了
//优化 n中最多只包含一个大于sqrt(n)的质因子
//所以在枚举的时候可以先把所有小于根号n的质因子枚举出来
//这样时间复杂度就降低到O(sqtr(n))了  时间复杂度最好的情况是logn 
void divide(int n)
{
    for(int i=2;i<=n/i;i++)
    {
        if(n%i==0)
        {
            int s=0;
            while(n%i==0)
            {
                n/=i;
                s++;//表示i的次数
            }
            cout<<i<<" "<<s<<endl;
        }
    }
    if(n>1)
    cout<<n<<" 1"<<endl;
    cout<<endl;
}
int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        int x;
        cin>>x;
        divide(x);
    }
    return 0;
}
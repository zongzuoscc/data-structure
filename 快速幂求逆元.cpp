// 若整数 b，m互质，并且对于任意的整数 a
// 如果满足 b/a，则存在一个整数 x，使得 ab≡a×x(modm)，则称 x为 b的模 m乘法逆元，记为 b−1(modm)。
// b存在乘法逆元的充要条件是 b与模数 m互质。当模数 m为质数时，b^m−2即为 b的乘法逆元。
//费马定理

//这道题不一定有解，如果b和p不互质那么就没有解
//因为如果b是p的倍数 那么b*x也一定是p的倍数  那么b*x mod p一定是0 就无解了

#include <iostream>
#include <algorithm>
using namespace std;

//a^k%p
int qmi(int a,int k,int p)
{
    int res=1;//a^k mod p
    while(k)
    {
        if(k&1)//如果当前k的末尾是1
        {
            res=(long long)res*a%p;
        }
        //a是不断反复平方的
        k>>=1;//把k的末位删掉，因为已经处理完了  右移一位，相当于将 k 除以 2 并去掉余数部分。
        a=(long long)a*a%p;//更新a为它的平方，并取模 p。这个步骤的作用是将 a 不断平方，以便处理更高位的 k。
    }
    return res;
}

int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        int a;//底数 即需要计算的底数
        int p;//模数 用于取模运算
        cin>>a>>p;
        int res=qmi(a,p-2,p);
        if(a%p) cout<<res<<endl;//这里的判断条件不能是res 因为当p=2时比较特殊 
        else
        {
            cout<<"impossible"<<endl;
        }
    }
    return 0;
}
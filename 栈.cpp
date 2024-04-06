//先进后出
//此处为自己用数组实现栈的操作，并不是用stl中的stack
//#include <iostream>

//using namespace std;

// const int N=100010;
//tt表示栈点下标，stk表示栈
// int stk[N],tt;
// int x;
//插入
//stk[++tt]=x;
//弹出
//t--

//判断栈是否为空
//if(tt>0) not empty
//else empty;

//栈顶
//stk[tt];

//具体的实现过程
#include <iostream>
#include <string>
using namespace std;
const int N = 100010;
int m;
int stk[N], tt;

int main()
{
    cin >> m;
    while (m -- )
    {
        string op;
        int x;

        cin >> op;
        if (op == "push")
        {
            cin >> x;
            stk[ ++ tt] = x;
        }
        else if (op == "pop") 
        {
            if(tt>0)
            {
                tt--;
            }
        }
        else if (op == "empty") cout << (tt ? "NO" : "YES") << endl;
        else cout << stk[tt] << endl;
    }

    return 0;
}
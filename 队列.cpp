//先进先出
// #include <iostream>
// using namespace std;
// const int N=100010;
//hh是队头，tt是队尾
//在队尾插入元素，在队头弹出元素
// int q[N],hh,tt=-1;
//插入
//q[++tt]=x;

//弹出
//hh++;

//判断是否为空
//if(hh<=tt) not empty;
//else empty;

//取出队头元素
//q[hh];

//取出队尾元素
//q[tt];
#include <iostream>
#include <string>
using namespace std;
const int N=100010;
int m;
int q[N], hh, tt = -1;

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
            q[ ++ tt] = x;
        }
        else if (op == "pop") hh ++ ;
        else if (op == "empty") cout << (hh <= tt ? "NO" : "YES") << endl;
        else cout << q[hh] << endl;
    }

    return 0;
}
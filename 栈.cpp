//先进后出
//此处为自己用数组实现栈的操作，并不是用stl中的stack
#include <iostream>

using namespace std;

const int N=100010;
//tt表示栈点下标，stk表示栈
int stk[N],tt;
int x;
//插入
//stk[++tt]=x;
//弹出
//t--

//判断栈是否为空
//if(tt>0) not empty
//else empty;

//栈顶
//stk[tt];
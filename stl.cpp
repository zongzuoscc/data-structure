/*
vector  变长数组，倍增的思想
    clear 清空
    fornt 返回第一个数
    back 返回最后一个数
    push_back()/pop_back()
    begin/end
    支持比较运算
    pair<int,int>
string  字符串 substr()  可以返回某一个字符串  c_str()  返回str对应的字符数组的头指针
    size  length
    empty
    clear
    substr(1,2)   第一个参数是起始位置  第二个参数是字符长度  只有c++是这样的，其他第二个参数全都是截止位置     
    如果说 第二个参数超过了字符串本身的长度，那么就输出到最后一个字符为止
queue,队列  
    back()
    empty()
    size()
    push() 队尾插入  
    front() 返回队头元素     
    pop()把队头弹出
    没有clear 函数   想要清空一个函数 直接让这个变量再等于 
priority_queue 堆优先队列  
    push()往对你里面插入一个元素 
    top()返回堆顶 
    pop()把堆顶弹出
    一般定义的堆默认是大根堆
    没有clear 函数
    有两种方式来定义小根堆
    1 向堆中插入-x  a.push(-x)
    2 直接定义成小根堆 queue<int,vector<int>,greater<int>>
stack 栈  同上
    没有empty
deque 双端队列  队头队尾都可以插入弹出  而且可以支持随机访问  用的不多，因为效率太低
    size
    empty
    clear
    front/back
    push_back/pop_back
    push_front/pop_front
    支持随机寻址
    支持begin end
set,map,multiset,multimap  基于 平衡二叉树实现（红黑树），动态维护有序序列
    size empty clear  
    begin / end 支持 ++ -- 操作 返回的是前驱和后继 O(logn )
    set/multiset
        支持insert函数 插入一个数
        find 查找一个数  如果这个数不存在的话 返回的是end迭代器
        count 返回的是某一个数的个数
        erase
            1 输入一个数  那么就删除所有这个数的节点  O(log n + k)k是x的个数
            2 输入一个迭代器  只删除这个迭代器
        lower_bound/upper_bound
        这两个操作不是相反的意思
            lower_bound 返回的是大于等于x的最小的数的迭代器
            upper_bound 返回的是大于x的最小的数的迭代器
    map/multimap
        insert  用的不多  插入的数是一个pair  map存储的是一个映射
        erase  pair或者迭代器都可以
        find
        []支持直接查找 时间复杂度O(logn )
unordered_set,unordered_map,unordered_multiset,unordered_multimap  基于哈希表来实现
    和上面类似
    绝大部分操作时间复杂度  增删改查是O(1)
    缺点是不支持lower_bound和upper_bound_bound  和++ -- 
bitset  压位
    c++的bool是一字节
    如果要开长度是1024的bool数组
    那么需要1024b的空间  但是如果压到每一位里面去 就只需要128b
    bitset<10000> s;
    ~s
    & | ^ 与或异或
    >>  <<  ==  !=
    []可以取出来
    count()返回有多少1
    any/none any() 判断是否至少有一个1 none 判断是否全为空
    set()  把所有位置变成1
    set(k,v) 把第k位 变成v
    reset 把所有位置变成0
    flip（k）  取反
empty 和size 是所有容器都有的  时间复杂度是O(1)
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    return 0;
}
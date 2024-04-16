/*
vector  变长数组，倍增的思想
    clear 清空
    fornt 返回第一个数
    back 返回最后一个数
    push_back()/pop_back()
    begin/end
    支持比较运算
string  字符串 substr()  可以返回某一个字符串  c_str()  返回str对应的字符数组的头指针
queue,队列  push() 队尾插入  front() 返回队头元素     pop()把队头弹出
priority_queue 堆优先队列  push()往对你里面插入一个元素 top()返回堆顶 pop()把堆顶弹出
stack 栈  同上
deque 双端队列  队头队尾都可以插入弹出  而且可以支持随机访问
set,map,multiset,multimap  基于 平衡二叉树实现（红黑树），动态维护有序序列
unordered_set,unordered_map,unordered_multiset,unordered_multimap  基于哈希表来实现
bitset  压位

empty 和size 是所有容器都有的  时间复杂度是O(1)
*/
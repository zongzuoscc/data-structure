//
#include <iostream>
#include <string>
using namespace std;
const int N=100010;
int e[N],l[N],r[N],idx;
int m;
void init()
{
    //0表示左端点，1表示右端点；
    r[0]=1,l[1]=0;
    idx=2;
}

//在下标是k的点的右边插入x
void add(int k,int x)
{
    e[idx]=x;
    r[idx]=r[k];//先把插入点右边的指针指好，即，插入点的右边指向插入前，k点的右边
    l[idx]=k;//插入点左边的指针指向k
    //以下两行不要写反，写反的话，r[k]已经更新了，会导致出错
    l[r[k]]=idx;//将k点之后那点的左指针指向插入的点
    r[k]=idx;//更新r右指针指向的位置，由原来的指向k+1改为指向插入的这一点
    idx++;//sb了我，忘记自增了，怪不得一直tle
}

//想在某一点左边插入，则直接调用add(l[k],x);

//删除第k个点
void remove(int k)
{
    r[l[k]]=r[k];//将这点的左边指向他的右边
    l[r[k]]=l[k];//将这点的右边指向他的左边
    //最好画图理解一下
}
int main()
{
    init();
    int m;
    cin >> m;
    while (m--) 
    {
        string op;
        cin >> op;
        int k, x;
        if (op == "L") 
        {
            cin >> x;
            add(0, x);
        } 
        else if (op == "R") 
        {
            cin >> x;
            add(l[1], x);
        } 
        else if (op == "D") 
        {
            cin >> k;
            remove(k + 1);
        } 
        else if (op == "IL") 
        {
            cin >> k >> x;
            add(l[k + 1], x);
        } 
        else 
        {
            cin >> k >> x;
            add(k + 1, x);
        }
    }

    for (int i = r[0]; i != 1; i = r[i]) cout << e[i] << ' ';
    cout << endl;

    return 0;
}
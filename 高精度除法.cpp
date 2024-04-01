#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
vector<int> div(vector<int> &a,int b,int &r)
{
    vector<int> c;
    r=0;
    for(int i=a.size()-1;i>=0;i--)
    {
        r=r*10+a[i];
        c.push_back(r/b);
        r%=b;
    }
    reverse(c.begin(),c.end());
    //由于输出时是倒序输出，而vector c中是正序存储，所以先用reverse函数将其反转，再去除前导0，最后返回
    while(c.size()>1&&c.back()==0)
    {
        c.pop_back();
    }
    return c;
}
int main()
{
    vector<int> a,c;
    int b;
    string A;
    cin>>A>>b;
    for(int i=A.size()-1;i>=0;i--)
    {
        a.push_back(A[i]-'0');
    }
    int r;//余数
    c=div(a,b,r);
    for(int i=c.size()-1;i>=0;i--)
    {
        cout<<c[i];
    }
    cout<<endl<<r<<endl;
    return 0;
}

/*
复习
vector<int> div(vector<int> &a,int b,int &r)
{
    vector<int> c;
    r=0;
    for(i=a.size()-1;i>=0;i--)
    {
        r=r*10+a[i];
        c.push_back(r/b);
        r%=b;
    }
    reverse(c.begin()c.end());
    for(c.size()>=1&&c.back==0)
    {
        c.pop_back();
    }
    return c;
}
*/
#include <iostream>
#include <vector>
using namespace std;
bool cmp(vector<int> &a,vector<int> &b)//只有在a.size()>b.size()时才返回true否则是false
{
    if(a.size()!=b.size())
    {
        return a.size()>b.size();
    }
    for(int i=a.size()-1;i>=0;i--)
    {
        if(a[i]!=b[i])
        {
            return a[i]>b[i];
        }
    }
    return true;
}
vector<int> sub(vector<int> &a,vector<int> &b)
{
    vector<int> c;
    for(int i=0,t=0;i<a.size();i++)
    {
        t=a[i]-t;//存储相减之后的值
        if(i<b.size()) t-=b[i];//a[i]-b[i]
        c.push_back((t+10)%10);//如果a[i]-b[i]大于等于0，那么则存储相减之后的值，因为+10之后大于10，所以%10保持数字不变，
        //如果a[i]-b[i]小于0，那么则借1(%10无影响)
        if(t<0) t=1;//在这里t=a[i]-b[i]，若为负值，那么则借了1，需要再下一轮循环时在高位减去1，则这里令t=1，否则t=0
        else t=0;
    }
    while(c.size()>1&&c.back()==0) c.pop_back();//去掉前导0，如果999-998则结果为001，需去掉前面的0输出
    return c;
}
int main()
{
    string A,B;
    vector<int> a,b,c;
    cin>>A>>B;
    for(int i=A.size()-1;i>=0;i--)
    {
        a.push_back(A[i]-'0');
    }
    for(int i=B.size()-1;i>=0;i--)
    {
        b.push_back(B[i]-'0');
    }
    if(cmp(a,b))//比较a，b大小，便于计算
    {
        c=sub(a,b);
        for(int i=c.size()-1;i>=0;i--)
        {
            cout<<c[i];
        }
    }
    else
    {
        cout<<"-";
        c=sub(b,a);
        for(int i=c.size()-1;i>=0;i--)
        {
            cout<<c[i];
        }
    }
    return 0;
}
/*
bool cmp(vector<int> &a,vector<int> &b)
{
    if(a.size!=b.size())
    {
        return a.size()>b.size();
    }
    for(int i=a.size()-1;i>=0;i--)
    {
        if(a[i]!=b[i])
        {
            return a[i]>b[i];
        }
    }
    return true;
}

vector<int> sub(vector<int> &a,vector<int> &b)
{
    vector<int> c;
    
    for(int i=0,t=0;i<a.size();i++)
    {
        t=a[i]-t;
        if(i<b.size())  t-=b[i];
        c.push_back((t+10)%10);
        if(t<0) t=1;
        else t=0;
    }
    while(c.size()>=1&&c.back()==0)
    {
        c.pop_back();
    }
    return c;
}

bool cmp(vector<int> &a,vector<int> &b)
{
    if(a.size()!=b.size())
    {
        return a.size()>b.size();
    }
    for(int i=a.size()-1;i>=0;i--)
    {
        if(a[i]!=b[i])
        {
            return a[i]>b[i];
        }
    }
    return true;
}

vector<int> sub(vector<int> &a,vector<int> &b)
{
    vector int c;
    for(int i=0,t=0;i<a.size();i++)
    {
        t=a[i]-t;
        if(i<b.size())
        {
            t-=b[i];
        }
        c.push_back((t+10)%10);
        if(t<0) t=1;
        else t=0;
    }
    while(c.size()>=1&&c.back()==0)
    {
        c.pop_back();
    }
    return c;
}
*/
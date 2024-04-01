// #include <iostream>
// #include <vector>
// #include <string>
// using namespace std;
// vector<int> mul(vector<int> &a,int b)
// {
//     vector<int> c;
//     int t=0;
//     for(int i=0;i<a.size()||t;i++)
//     {
//         if(i<a.size())
//         {
//             t+=a[i]*b;
//         }
//         c.push_back(t%10);
//         t/=10; 
//     }
//     return c;
// }
// int main()
// {
//     string A;
//     int b;
//     cin>>A>>b;
//     vector<int> a;
//     for(int i=A.size()-1;i>=0;i--)
//     {
//         a.push_back(A[i]-'0');
//     }
//     vector<int> c=mul(a,b);
//     for(int i=c.size()-1;i>=0;i--)
//     {
//         cout<<c[i];
//     }
//     return 0;
// }
//修改之后
#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<int> mul(vector<int> &a,int &b)
{
    vector<int> c;
    int t=0;
    for(int i=0;i<a.size()||t;i++)
    {
        if(i<a.size())
        {
            t+=a[i]*b;    
        }
        c.push_back(t%10);
        t/=10;
    }

    return c;
}
int main()
{
    string A;
    int b;
    cin>>A>>b;
    vector<int> a;
    if(b==0)
    {
        cout<<"0"<<endl;
        return 0;
    }
    else
    {
        for(int i=A.size()-1;i>=0;i--)
        {
            a.push_back(A[i]-'0');
        }
        vector<int> c=mul(a,b);
        for(int i=c.size()-1;i>=0;i--)
        {
            cout<<c[i];
        }
        return 0;
    }
}

/*
vector<int> mul(vector<int> &a,int b)
{
    vector<int> c;
    int t=0;
    for(int i=0;i<a.size()||t;i++)
    {
        if(i<a.size())
        {
            t=a[i]*b+t;
        }
        c.push_back(t%10);
        t/=10;
    }
    return c;
}
vector<int> mul(vector<int> &a,int b)
{
    vector<int> c;
    int t=0;
    for(int i=0;i<a.size()||t;i++)
    {
        if(i<a.size())
        {
            t=a[i]*b+t;
        }
        c.push_back(t%10);
        t/=10;
    }
    return c;
}
*/
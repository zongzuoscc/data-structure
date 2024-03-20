#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<int> add (vector<int> &a,vector<int> &b)
{
    vector<int> c;
    int t=0;
    for(int i=0;i<a.size()||i<b.size();i++)
    {
        if(i<a.size()) t+=a[i];
        if(i<b.size()) t+=b[i];
        c.push_back(t%10);
        t/=10;
    }
    if(t)
    {
        c.push_back(1);
    }
    return c;
}
int main()
{
    vector<int> a;
    vector<int> b;
    string A,B;
    cin>>A>>B;
    for(int i=A.size()-1;i>=0;i--)
    {
        a.push_back(A[i]-'0');
    }
    for(int i=B.size()-1;i>=0;i--)
    {
        b.push_back(B[i]-'0');
    }
    vector<int>  c=add(a,b);
    for(int i=c.size()-1;i>=0;i--)
    {
        cout<<c[i];
    }
    cout<<endl;
    return 0;
}
// #include <iostream>
// #include <vector>

// using namespace std;

// vector<int> add(vector<int> &A, vector<int> &B)
// {
//     if (A.size() < B.size()) return add(B, A);

//     vector<int> C;
//     int t = 0;
//     for (int i = 0; i < A.size(); i ++ )
//     {
//         t += A[i];
//         if (i < B.size()) t += B[i];
//         C.push_back(t % 10);
//         t /= 10;
//     }

//     if (t) C.push_back(t);
//     return C;
// }

// int main()
// {
//     string a, b;
//     vector<int> A, B;
//     cin >> a >> b;
//     for (int i = a.size() - 1; i >= 0; i -- ) A.push_back(a[i] - '0');
//     for (int i = b.size() - 1; i >= 0; i -- ) B.push_back(b[i] - '0');

//     auto C = add(A, B);

//     for (int i = C.size() - 1; i >= 0; i -- ) cout << C[i];
//     cout << endl;

//     return 0;
// }
/*
vector<int> add(vector<int> &a,vector<int> &b)
{
    vector<int> c;
    int t=0;
    for(int i=0;i<a.size()-1||i<b.size()-1;i++)
    {
        if(i<a.size()-1)
        {
            t+=a[i];
        }
        if(i<b.size()-1)
        {
            t+=b[i];
        }
        c.push_bakc(t%10);
        t/=10;
    }
    if(t)
    {
        c.push_back(1);
    }
    return c;  
}
*/
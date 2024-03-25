//右移>>， lowbit。
//x&-x==x&(~x+1)
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int lowbit(int i)
{
    return i&(~i+1);
}
int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        int i;
        int count=0;
        cin>>i;
        while(i)
        {
            i-=lowbit(i);
            count++;
        }
        cout<<count<<" ";
    }
    return 0;
}
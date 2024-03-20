#include <iostream>
using namespace std;
const int N = 100010;
int n,m;
int q[N];
//l=mid则需要补+1,r=mid则不需要补+1.因为(l+r)/2是整型，相除之后向下取整，
//如果循环到最后，l与r刚好相差1，则mid始终=l，循环到最后始终是[l,r]最后发生死循环，所以需要+1
//但是如果r=mid的话，就不会发生这种情况，因为循环到最后，结果为[l,l]
int main()  
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>q[i];
    }
    while(m--)
    {
        int x;//目标数值
        cin>>x;
        int l=0,r=n-1;
        while(l<r)
        {
            int mid=(l+r)/2;
            if(q[mid]>=x)
            {
                r=mid;
            }
            else
            {
                l=mid+1;
            }
        }
        if(q[l]!=x)
        {
            cout<<"-1 -1"<<endl;
        }
        else
        {
            cout<<l<<" ";
            int l=0,r=n-1;
            while(l<r)
            {
                int mid=(l+r+1)/2;
                if(q[mid]<=x)
                {
                    l=mid;
                }
                else
                {
                    r=mid-1;
                }
            }
            cout<<l<<endl;
        }
    }
    return 0;
}
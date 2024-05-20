//ʱ�䰴���ӵ� o(n^3)
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N=210;
const int INF=1e9;//�����
int n,m,Q;//Q��ѯ�ʸ���
int d[N][N];
void floyd()
{
    for(int k=1;k<=n;k++)
    {
        for(int j=1;j<=n;j++)
        {
            for(int i=1;i<=n;i++)
            {
                d[i][j]=min(d[i][j],d[k][j]+d[i][k]);
            }
        }
    }
}
int main()
{
    cin>>n>>m>>Q;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i==j)
            {
                d[i][j]=0;
            }
            else
            {
                d[i][j]=INF;
            }
        }
    }
    while(m--)
    {
        int a,b,w;
        cin>>a>>b>>w;
        d[a][b]=min(d[a][b],w);//����ж�����ֻ������С�ı߾ͺ���
    }
    floyd();
    while(Q--)
    {
        int a,b;
        cin>>a>>b;
        if(d[a][b]>INF/2)
        {
            cout<<"impossible"<<endl;
        }
        else
        {        
            cout<<d[a][b]<<endl; 
        }
    }
    return 0;
}
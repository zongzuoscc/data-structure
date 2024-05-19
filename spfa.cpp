//ֻҪ�ǲ����ڸ�Ȩ�ߵ�����µ�Դ�����·���ⶼ������spfa�㷨���
//��Ȩͼ������spfa����Ȩͼspfa�ȽϺ���
//�ÿ��������Ż�
//bellman-ford �㷨��������ɵ  ÿ�ε����������б� Ȼ��������  ÿһ�ε�����һ��ÿһ���߶������
//dist[b]=min(dist[b],dist[a]+w)  ��һ�������dist[b] ��С
//spfa�Ƕ�������һ�������Ż�
//���˵dist[b]���ڵ�ǰ��һ�ε�����С�Ļ� һ����dist[a]��С�� ���a������ôbһ������
//ֻ��a��С b�Ż��С
//�ÿ��������Ż���������ʱ�����һ������
//��һ���Ȱ����ŵ���������ȥ ֻҪ���в���  ÿһ�Σ����Ƕ�������������б�С��a  �������ľ������б�С�˵Ľڵ�
//ֻҪһ���ڵ��С���ҾͰ����ŵ���������  ���������º������еĺ��
//ֻҪ���в���  ֻҪ�������滹�нڵ��С ��ִ�е���
//1 �ȴӶ�����ȡ����ͷ


//��һ�������(ָ�����˲��������������ݿ�����㷨)spfa�㷨Ҫ��dijkstra�㷨Ҫ��
//���������ʱ�临�Ӷ�ʹO(n)���ǿ��Թ����������ݰ�spfa�㷨����o(nm)��

#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int N=1e6+10;//֮ǰ����100010 
int n,m;
int h[N],e[N],ne[N];
int w[N];//���ڴ洢�ڽӱ��Ȩ��
int idx;
int dist[N];//spfa�㷨����ľ��� ��ʾ���Ǵ�һ�ŵ��ߵ�ÿ����ľ����Ƕ���  ��ǰ����̾����Ƕ���
bool st[N];//��ʾÿ��������·�ǲ����Ѿ�ȷ����
void add(int a,int b,int c)
{
    e[idx]=b;//�洢��
    w[idx]=c;//�洢Ȩ��
    ne[idx]=h[a];
    h[a]=idx++;//ͷ�ڵ㣬�±�洢������㵽��һ�����ʼ��
}
int spfa()
{
    memset(dist,0x3f,sizeof dist);
    dist[1]=0;
    queue<int> q;//�洢���д����µĵ�
    q.push(1);//��һ�ŵ�ŵ���������ȥ
    st[1]=true;//st����洢���ǵ�ǰ������ǲ����ڶ��е��У���ֹ���е��д洢�ظ��ĵ�

    while(q.size())
    {
        int t=q.front();
        q.pop();
        st[t]=false;//��ʾ����㲻�ڶ���������

        for(int i=h[t];i!=-1;i=ne[i])
        {
            int j=e[i];//��ʾ��ǰ�����
            if(dist[j]>dist[t]+w[i])
            {
                dist[j]=dist[t]+w[i];
                if(!st[j])
                {
                    q.push(j);
                    st[j]=true;
                }
            }
        }
    }

    if(dist[n]==0x3f3f3f3f) return 0x3f3f3f3f;//����yxc����ʹreturn -1 ���ǳ����ˣ����Լ�ħ��֮��ɹ��ˡ�
    return dist[n];
}
int main()
{
    cin>>n>>m;//��������ͱ���
    memset(h,-1,sizeof h);//������һ��������ԭ����ͬ
    while(m--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        add(a,b,c);
    }
    int t=spfa();
    if(t==0x3f3f3f3f)
    {
        cout<<"impossible"<<endl;   
    }
    else
    {
        cout<<t<<endl;
    }
    return 0;
}
//这个算法用的不多，但是偶尔也会用到，所以需要学习
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 100010;
int n;
vector<pair<int,int>> segs;
void merge(vector<pair<int,int>> &segs)
{
    vector<pair<int,int>> res;
    sort(segs.begin(),segs.end());
    int st=-2e9,ed=-2e9;
    for(auto seg:segs)
    {
        if(ed<seg.first)
        {
            if(st!=-2e9)
            {
                res.push_back({st,ed});
            }
            st=seg.first,ed=seg.second;
        }
        else
        {
            ed=max(ed,seg.second);
        }
    }
    if(st!= -2e9)
    {
        res.push_back({st,ed});
    }
    segs=res;
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int l,r;
        cin>>l>>r;
        segs.push_back({l,r});
    }
    merge(segs);
    cout<<segs.size()<<endl;
}
//没太听懂，继续理解
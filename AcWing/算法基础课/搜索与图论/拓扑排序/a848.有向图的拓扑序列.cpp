//一个有向无环图，必然至少存在一个入度为0的点(反证法可证明)
//因此，对于这道题，其未说明是有环还是无环，我们需要自行判断
//那么只要它存在一个入度为0的点，我们就可以认为它无环
//且，如果这个图的拓扑序列存在，必然是从这个点开始
//也就是说，如果一个图有两个及以上的入度为0的点，那么这个图就不存在合法的拓扑序列
//然后从这个点开始进行BFS，就可以搜索到拓扑序列了（如果存在的话）
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N=100010;

int n,m;
//h存放点i的下一个点的下标，e存放点的名称，ne是下一个点的名字
int h[N],e[N],ne[N],idx;
//q为队列，d存放这个点的入度
int q[N],d[N];

void add(int a,int b)
{
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

bool topsort()
{
    int hh=0,tt=-1;
    for(int i=1;i<=n;i++)
    {
        if(!d[i]){
            q[++tt]=i;
        }
    }
    while(hh<=tt)
    {
        //取出队头，即入度为0的点
        int t=q[hh++];
        //
        for(int i=h[t];i!=-1;i=ne[i])
        {
            int j=e[i];
            d[j]--;
            if(d[j]==0) q[++tt]=j;
        }
    }
    return tt==n-1;
}

int main()
{
    cin>>n>>m;
    memset(h,-1,sizeof h);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        add(a,b);
        d[b]++;
    }
    for(int i=0;i<n;i++){
        
    }
    if(topsort())
    {
        for(int i=0;i<n;i++) printf("%d ",q[i]);
        puts("");
    }
    else puts("-1");
    
    return 0;
}
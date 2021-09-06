//在图中有负权边的情况下，dijkstra算法会失效
//原因见https://www.acwing.com/solution/content/6320/
//在这时候可使用Bellman-Ford算法
//循环k次，表示不超过k条边的最短路
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N=510,M=10010;

int n,m,k;
//backup存放上次迭代的结果
int dist[N],backup[N];

struct Edge
{
    int a,b,w;
} edges[M];

int bellman_ford()
{
    memset(dist,0x3f,sizeof dist);
    dist[1]=0;
    //每次迭代可以从出发点“走一步”
    for(int i=0;i<k;i++)
    {
        memcpy(backup,dist,sizeof dist);
        for(int j=0;j<m;j++){
            int a=edges[j].a,b=edges[j].b,w=edges[j].w;
            dist[b]=min(dist[b],backup[a]+w);
        }
    }
    if(dist[n]>0x3f3f3f3f/2) return 0x3f3f3f3f;
    return dist[n];
}

int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<m;i++){
        int a,b,w;
        scanf("%d%d%d",&a,&b,&w);
        edges[i]={a,b,w};
    }
    int t=bellman_ford();
    if(t==0x3f3f3f3f) puts("impossible");
    else printf("%d\n",t);
    
    return 0;
}
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

const int N=510;

int n,m;
int g[N][N];
int dist[N];
bool st[N];

int dijkstra(){
    memset(dist,0x3f,sizeof dist);
    dist[1]=0;
    //因为有n个点，进行n次迭代
    for(int i=0;i<n;i++){
        int t=-1;
        //找到尚未确定最短路的最小值的点
        for(int j=1;j<=n;j++){
            if(!st[j]&&(t==-1||dist[t]>dist[j])){
                t=j;
            }
        }
        //将其确定为最短路
        st[t]=true;
        //再使用这个点去更新其他点的dist
        for(int j=1;j<=n;j++){
            dist[j]=min(dist[j],dist[t]+g[t][j]);
        }
    }
    if(dist[n]==0x3f3f3f3f) return -1;
    return dist[n];
}

int main(){
    scanf("%d%d",&n,&m);
    memset(g,0x3f,sizeof g);
    while(m--){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        //注意可能有重边，选择其最小值
        g[a][b]=min(g[a][b],c);
    }
    int t=dijkstra();
    cout<<t;
    return 0;
}
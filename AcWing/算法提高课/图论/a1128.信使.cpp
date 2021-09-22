//一开始以为是最小生成树，实际上不是，因为信使之间是并行的
#include <iostream>
using namespace std;

const int N=110,INF=0x3f3f3f3f;
int g[N][N],dist[N];
int n,m;
bool st[N];

int prim()
{
    memset(dist, 0x3f, sizeof dist);

    int res = 0;
    for (int i = 0; i < n; i ++ )
    {
        int t = -1;
        for (int j = 1; j <= n; j ++ )
            if (!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;
        if(!i) t=1;
        if (i && dist[t] == INF) return INF;

        if (i) res += dist[t];
        st[t] = true;

        for (int j = 1; j <= n; j ++ ) dist[j] = min(dist[j], g[t][j]);
    }

    return res;
}
int main(){
    cin>>n>>m;
    memset(g,0x3f,sizeof g);
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        g[a][b]=g[b][a]=c;
    }
    int t=prim();
    if(t==INF) puts("-1");
    else cout<<t;
    return 0;
}



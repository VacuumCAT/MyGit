#include <iostream>
#include <cstring>
using namespace std;

const int N=2510;
int g[N][N];
int dist[N];
bool st[N];
int n,m;
int s,e;

void dijkstra(){
    memset(dist,0x3f,sizeof dist);
    dist[s]=0;
    for(int i=0;i<n;i++){
        int cur=-1;
        for(int j=1;j<=n;j++){
            if(st[j]) continue;
            if(cur==-1||dist[j]<dist[cur]) cur=j;
        }
        st[cur]=true;
        for(int j=1;j<=n;j++){
            dist[j]=min(dist[j],dist[cur]+g[cur][j]);
        }
    }
}

int main(){
    cin>>n>>m>>s>>e;
    memset(g,0x3f,sizeof g);
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        g[a][b]=g[b][a]=c;
    }
    dijkstra();
    cout<<dist[e];
    return 0;
}
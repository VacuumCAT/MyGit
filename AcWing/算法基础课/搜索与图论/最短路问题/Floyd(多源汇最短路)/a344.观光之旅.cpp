#include <iostream>
#include <cstring>
using namespace std;

const int N=110;
const int INF=0x3f3f3f3f;
int n,m,cnt;
int g[N][N],d[N][N];
int path[N],pos[N][N];
long long res=INF;

void get_path(int i, int j)
{
    if (pos[i][j] == 0) return;

    int k = pos[i][j];
    get_path(i, k);
    path[cnt ++ ] = k;
    get_path(k, j);
}

void floyd(){
    for(int k=1;k<=n;k++){
        for(int i=1;i<k;i++){
            for(int j=i+1;j<k;j++){
                if(res>(long long)d[i][j]+g[i][k]+g[k][j]){
                    res=d[i][j]+g[i][k]+g[k][j];
                    cnt=0;
                    path[cnt++]=k;
                    path[cnt++]=i;
                    get_path(i,j);
                    path[cnt++]=j;
                }
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(d[i][j] > d[i][k] + d[k][j])
                {
                    d[i][j] = d[i][k] + d[k][j] ;
                    pos[i][j] = k ; 
                }
            }
        }
    }
}

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j) d[i][j]=0;
            else d[i][j]=INF;
        }
    }
    for(int i=0;i<m;i++){
        int u,v,l;
        cin>>u>>v>>l;
        d[u][v]=d[v][u]=min(d[u][v],l);
    }
    memcpy(g,d,sizeof g);
    floyd();
    if(res==INF){
        cout<<"No solution.";
    }
    else{
        for(int i=0;i<cnt;i++) cout<<path[i]<<' ';
    }
    return 0;
}
#include <iostream>
#include <cstring>
using namespace std;
const int N=110;
int n,m;
//g数组存放地图，d数组存放距离
int g[N][N];
int d[N][N];
typedef pair<int,int> PII;
//使用q[N]模拟队列，队列是十分容易模拟的
//定义一个hh和tt作为头尾然后操作即可
PII q[N*N];

int bfs(){
    int hh=0,tt=0;
    q[0]={0,0};
    memset(d,-1,sizeof d);
    d[0][0]=0;
    int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};

    while(hh<=tt){
        auto t=q[hh++];
        for(int i=0;i<4;i++){
            int x=t.first+dx[i],y=t.second+dy[i];
            if(x>=0&&y>=0&&x<n&&y<m&&g[x][y]==0&&d[x][y]==-1){
                d[x][y]=d[t.first][t.second]+1;
                q[++tt]={x,y};
            }
        }
    }
    return d[n-1][m-1];
}

int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>g[i][j];
        }
    }
    cout<<bfs()<<endl;
    return 0;
}

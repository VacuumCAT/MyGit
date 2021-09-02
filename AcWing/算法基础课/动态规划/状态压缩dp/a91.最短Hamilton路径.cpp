//暴力做法：n!*n
//动态规划：所有从0到j，状态为i的路径的最短长度

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N=20,M=1<<N;
int n;
int w[N][N];
int f[M][N];

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>w[i][j];
        }
    }
    memset(f,0x3f,sizeof f);
    f[1][0]=0;
    for(int i=0;i<1<<n;i++){
        for(int j=0;j<n;j++){
            //如果i的第j位是1
            if(i>>j&1){
                for(int k=0;k<n;k++){
                    //i除去j这一点后，如果其第k位是1
                    if(i-(1<<j)>>k&1){
                        f[i][j]=min(f[i][j],f[i-(1<<j)][k]+w[k][j]);
                    }
                }
            }
        }
    }
    cout<<f[(1<<n)-1][n-1]<<endl;
    return 0;
}
#include <iostream>
using namespace std;

const int N=510;
int p[N][N];
int f[N][N];
int n;

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cin>>p[i][j];
        }
    }
    f[0][0]=p[0][0];
    for(int i=1;i<n;i++){
        for(int j=0;j<=i;j++){
            if(j==0){
                 f[i][j]=f[i-1][j]+p[i][j];
                 continue;
            }
            if(j==i){
                 f[i][j]=f[i-1][j-1]+p[i][j];
                 continue;
            }
            f[i][j]=max(f[i-1][j-1],f[i-1][j])+p[i][j];
        }
    }
    int ans=-0x3f3f3f3f;
    for(int i=0;i<n;i++){
        ans=max(ans,f[n-1][i]);
    }
    cout<<ans;
}
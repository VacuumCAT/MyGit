#include <iostream>
#include <cmath>
using namespace std;
typedef long long LL;

const int N=55;

int n,m;
int p[N][N];

int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&p[i][j]);
        }
    }
    LL ans=0;

    for(int i=0;i<n;i++){
        int ones=0;
        for(int j=0;j<m;j++){
            if(p[i][j]==1) ones++;
        }
        int zeros=m-ones;
        ans+=(LL)pow(2,ones)+(LL)pow(2,zeros)-2;
    }
    for(int i=0;i<m;i++){
        int ones=0;
        for(int j=0;j<n;j++){
            if(p[j][i]==1) ones++;
        }
        int zeros=n-ones;
        ans+=(LL)pow(2,ones)+(LL)pow(2,zeros)-2-n;
    }
    cout<<ans;
    return 0;
}
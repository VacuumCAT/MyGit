#include <iostream>
#include <algorithm>
using namespace std;

const int N=1010;

//f[i][j]代表了j体积下，前i个物品的最大价值
int f[N][N];
int v[N],w[N];
int n,m;

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>v[i]>>w[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            //如果装不下第i个物品
            if(j<v[i]){
                f[i][j]=f[i-1][j];
            }
            //能装得下第i个物品，但需要决定要不要装
            else{
                f[i][j]=max(f[i-1][j-v[i]]+w[i],f[i-1][j]);
            }
        }
    }
    cout<<f[n][m];
    return 0;
}
//滚动数组优化后代码
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010;

int n, m;
int v[N], w[N];
int f[N];

int main()
{
    cin >> n >> m;

    for (int i = 1; i <= n; i ++ ) cin >> v[i] >> w[i];

    for (int i = 1; i <= n; i ++ )
        for (int j = m; j >= v[i]; j -- )
            f[j] = max(f[j], f[j - v[i]] + w[i]);

    cout << f[m] << endl;

    return 0;
}

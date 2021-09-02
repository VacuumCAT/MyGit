#include <iostream>
using namespace std;

const int N=1010;
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
            f[i][j]=f[i-1][j];
            for(int k=0;j>=k*v[i];k++){
                f[i][j]=max(f[i][j],f[i-1][j-k*v[i]]+k*w[i]);
            }
        }
    }
    cout<<f[n][m];
    return 0;
}
//以上代码会TLE
//可以从二维优化到1维
//这个优化有两种理解方式
//一个是y总基础课的思想
//另一种就是认为，对f[j]来说，其更大的价值就可能是f[j-v[i]]+w[i]

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
        for (int j = v[i]; j <= m; j ++ )
            f[j] = max(f[j], f[j - v[i]] + w[i]);

    cout << f[m] << endl;

    return 0;
}
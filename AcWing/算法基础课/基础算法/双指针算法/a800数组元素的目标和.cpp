#include <iostream>
using namespace std;

const int N=100010;

int n,m,x;
int a[N],b[N];

int main(){
    cin>>n>>m>>x;
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    for(int i=0;i<m;i++) scanf("%d",&b[i]);
    for (int i = 0, j = m - 1; i < n; i ++ )
    {
        while (j >= 0 && a[i] + b[j] > x) j -- ;
        if (j >= 0 && a[i] + b[j] == x) cout << i << ' ' << j << endl;
    }
    return 0;
}
//当j“减过头了”，说明对于当前的i，j右边的都还是比需要的j大的
//又因为i是从0开始一步步走过来的，所以左边的i也“过大”
//因此令i++，继续找

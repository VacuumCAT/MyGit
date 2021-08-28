#include <iostream>
using namespace std;

const int N=100010;
int n,m;
int a[N],b[N];

int main(){
    cin>>n>>m;
    for(int i =0 ;i<n;i++) scanf("%d",&a[i]);
    for(int i =0 ;i<m;i++) scanf("%d",&b[i]);

    int i=n-1,j=m-1;
    while(j>=0){
        if(b[j]==a[i]) i--;
        j--;
    }
    if(i==-1) puts("Yes");
    else puts("No");
    return 0;
}

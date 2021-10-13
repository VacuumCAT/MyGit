#include <iostream>
#include <cstring>
using namespace std;

const int N=1010;

int f[N];
int p[N];
int n;

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>p[i];
        f[i]=1;
    }
    int ans=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(p[j]<p[i]) f[i]=max(f[i],f[j]+1);
        }
        ans=max(ans,f[i]);
    }
    cout<<ans;
    return 0;
}
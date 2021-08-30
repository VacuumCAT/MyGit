#include <iostream>
using namespace std;

const int N=10;

int path[N],n;

void dfs(int u,int state){
    if(u==n){
        for(int i=0;i<n;i++){
            printf("%d",path[i]);
        }
        puts("");
        return;
    }
    for(int i=0;i<n;i++){
        if(!(state>>i&1)){
            path[u]=i+1;
            dfs(u+1,state+(1<<i));
        }
    }
}

int main(){
    scanf("%d",&n);
    dfs(0,0);
    return 0;
}
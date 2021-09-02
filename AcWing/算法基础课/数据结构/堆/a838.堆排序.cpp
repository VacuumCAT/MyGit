#include <iostream>
#include <algorithm>

using namespace std;

const int N=100010;

int n,m;
int h[N],cnt;

void down(int u){
    int t=u;
    if(u*2<=cnt&&h[u*2]<h[t]) t=u*2;
    if(u*2+1<=cnt&&h[u*2+1]<h[t]) t=u*2+1;
    if(u!=t){
        swap(h[u],h[t]);
        down(t);
    }
}

void up(int u){
    while(u/2&&h[u/2]>h[u]){
        swap(h[u/2],h[u]);
        u/=2;
    }
}

int main()
{

    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&h[i]);
    }
    cnt=n;
    for(int i=n/2;i>=1;i--) down(i);
    //一个一个插入的建堆时间复杂度为O(nlongn)
    //从n/2开始一个个的down操作可达到O(n)
    while(m--){
        printf("%d ",h[1]);
        h[1]=h[cnt];
        cnt--;
        down(1);
    }

}
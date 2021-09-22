#include <iostream>
#include <cstring>
using namespace std;

const int N=100010;
int n,m;
//q为队列，d存放这个点的入度
int q[N],d[N];
//h存放点i的下一个点的下标，e存放点的名称，ne是下一个点的名字
int e[N],ne[N],h[N],idx;

void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

bool topsort()
{
    int hh=0,tt=-1;
    for(int i=1;i<=n;i++){
        //需要把所有入度为0的点加入
        if(d[i]==0){
            q[++tt]=i;
        } 
    }
    while(hh<=tt){
        //取出队头，即入度为0的点
        int t=q[hh++];
        for(int i=h[t];i!=-1;i=ne[i]){
            int j=e[i];
            d[j]--;
            if(d[j]==0) q[++tt]=j;
        }
    }
    return tt==n-1;
}

int main(){
    cin>>n>>m;
    memset(h,-1,sizeof h);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        add(a,b);
        d[b]++;
    }
    if(topsort()){
        for(int i=0;i<n;i++) printf("%d ",q[i]);
        puts("");
    }
    else puts("-1");
    return 0;
}
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int M=100010;
const int N=1010;
int p[N];
int n,m,INF=0x3f3f3f3f;

struct edge{
    int a,b,w;
    bool operator<(const edge &W){
        return w<W.w;
    } 
}edges[M];

int find(int x){
    if(p[x]!=x) return find(p[x]);
    return x;
}

int kruskal(){
    sort(edges,edges+m);
    int cnt,res;
    for(int i=0;i<m;i++){
        int a=edges[i].a,b=edges[i].b,w=edges[i].w;
        a=find(a),b=find(b);
        if(a!=b){
            p[a]=b;
            res+=w;
            cnt++;
        }
    }
    if(cnt<n-1) return INF;
    return res;
}

int main(){
    cin>>n>>m;
    int a,b,w;
    for(int i=0;i<m;i++){
        cin>>a>>b>>w;
        edges[i]={a,b,w};
    }
    int t=kruskal();
    cout<<t;
    return 0;
}
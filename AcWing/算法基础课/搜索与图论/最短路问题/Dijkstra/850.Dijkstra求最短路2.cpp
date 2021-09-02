//堆优化版本的Dijkstra算法
//在朴素版本中，我们需要遍历所有元素找到离0点最近的元素
//这个过程完全可以用堆实现，将这部分的时间复杂度从O(n^2)降到O(logn)（具体存疑）
//要注意是稠密图还是稀疏图
//稠密图，边m的数量与点的数量n的平方在同一数量级
//稀疏图，m与n同一数量级
//要注意，不管是朴素版本还是堆优化版本的Dijkstra算法，都不能用于负权图
//稀疏图用邻接表来存放即可
//邻接表存放图的介绍见搜索与图论视频课第一节01：24处
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

const int N=150010;

int n,m;
int h[N],w[N],e[N],ne[N],idx;
int dist[N];
bool st[N];

typedef pair<int,int> PII;
void add(int a,int b,int c){
    //邻接表插入操作：
    //建立一个新的点是b
    //这条边的权重为c
    //b指向a
    //h[a]指向b
    e[idx]=b,w[idx]=c,e,ne[idx]=h[a],h[a]=idx++;
}

int dijkstra(){
    memset(dist,0x3f,sizeof dist);
    dist[1]=0;
    priority_queue<PII,vector<PII>,greater<PII>> heap;
    //这里要用dist作为pair的第一个元素，令其按dist从小到大排序
    heap.push({0,1});
    while(!heap.empty()){
        auto t=heap.top();
        heap.pop();
        int ver=t.second,distance=t.first;
        if(st[ver]) continue;
        st[ver]=true;
        for(int i=h[ver];i!=-1;i=ne[i]){
            int j=e[i];
            if(dist[j]>distance+w[i]){
                dist[j]=distance+w[i];
                heap.push({dist[j],j});
            }
        }
    }
    if(dist[n]==0x3f3f3f3f) return -1;
    else return dist[n];
}

int main(){
    cin>>n>>m;
    memset(h,-1,sizeof h);
    while(m--){
        int a,b,c;
        cin>>a>>b>>c;
        add(a,b,c);
    }
    int t=dijkstra();
    cout<<t<<endl;
    return 0;
}
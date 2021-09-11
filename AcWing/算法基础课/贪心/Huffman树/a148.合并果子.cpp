//给定N个权值作为N个叶子结点，构造一棵二叉树。
//若该树的带权路径长度达到最小，称这样的二叉树为最优二叉树，也称为哈夫曼树(Huffman Tree)。
//哈夫曼树是带权路径长度最短的树，权值较大的结点离根较近。

#include <iostream>
#include <queue>
using namespace std;

int n;

int main(){
    cin>>n;
    priority_queue<int,vector<int>,greater<int>> heap;
    int x;
    int ans=0;
    for(int i=0;i<n;i++){
        cin>>x;
        heap.push(x);
    }
    while(heap.size()>=2){
        int a=heap.top();
        heap.pop();
        int b=heap.top();
        heap.pop();
        heap.push(a+b);
        ans+=(a+b);
    }
    cout<<ans;
    return 0;
}
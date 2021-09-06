#include <iostream>
#include <unordered_map>
using namespace std;

int n,m;
const int N=100010;
int q[N];

int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++) scanf("%d",&q[i]);
    unordered_map<int,pair<int,int>> set;

    for(int i=0;i<n;i++){
        if(set.count(q[i])==0){
            set[q[i]].first=i;
            set[q[i]].second=i;
        } 
        else set[q[i]].second++;
    }

    while(m--){
        int x;
        scanf("%d",&x);
        if(set.count(x)==0) cout<<"-1 -1"<<endl;
        else cout<<set[x].first<<' '<<set[x].second<<endl;
    }
    return 0;
} 